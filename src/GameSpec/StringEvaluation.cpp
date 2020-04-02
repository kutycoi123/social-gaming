#include "StringEvaluation.h"

using map_pair = std::pair<std::string, std::shared_ptr<StateValue>>;
using Map = std::unordered_map<std::string, std::shared_ptr<StateValue>>;

int precedence(const std::string& op){
	if(op == "==")
		return 1;
	if(op == "." || op == "contains")
		return 2;
	return 0;
}

std::string applyOp(const std::string& a, const std::string& b, const std::string& op, const GameState& gameState, Map& values){ 
	StateValue* val1 = nullptr;
	StateValue* val2 = nullptr;

	//Get value for a and b in values
	if(values.find(a) != values.end()){
		val1 = values[a].get();	
	}else{
		//TODO: Add code to get value for a in gameState
	}
	if(values.find(b) != values.end()){
		val2 = values[a].get();
	}else{
		//TODO: Add code to get value for b in gameState
	}

	if(op == "=="){
		bool result;
		if(val1 == nullptr || val2 == nullptr)
			result = false;	
		else{
			/*
			result = val1->compare(val2);
			*/
		}
		//Cache the result
		values.insert(map_pair(a+op+b, std::shared_ptr<StateValue>(new StateValueBoolean(result))));
	}else if(op == "."){
		//TODO: Find value with key as val2 inside val1. val1 should be StateValueMap, val2 should be a string field
		auto val1Casted = static_cast<StateValueMap*>(val1);
		auto val2Casted = static_cast<StateValueString*>(val2);
		
		auto result = val1Casted->getValue(val2Casted->getValue()).value();

		//Cache the result in map: 
		values.insert(map_pair(a+op+b, std::shared_ptr<StateValue>(result.lock())));
	}else if(op == "contains"){
		bool result;
		if(val1 == nullptr || val2 == nullptr)
			result = false;
		//TODO: Add code here to handle "contains"
		values.insert(map_pair(a+op+b, std::shared_ptr<StateValue>(new StateValueBoolean(result))));
	}else if(op == "!"){
		bool result;
		if(val1 == nullptr)
			result = false;
		//Add getNegationValue method for StateValueBoolean
		//result = static_cast<StateValueBoolean*>(val1)->getNegationValue();
		values.insert(map_pair(a+op+b, std::shared_ptr<StateValue>(new StateValueBoolean(result))));
	}
	/*
	else if(op == "collects"){

	}
	*/
	return a + op + b;
}

static bool evaluate(const GameState& gameState, const std::string& tokens){

	std::unordered_map<std::string, std::shared_ptr<StateValue>> values;
	//std::vector<std::string> tokens;
	unsigned int i; 
      
    // stack to store string literal values. 
    std::stack<std::string> literalValues; 

      
    // stack to store operators. 
    std::stack<std::string> ops; 
      
    for(i = 0; i < tokens.length(); i++){ 
          
        // Current token is a whitespace, 
        // skip it. 
        if(tokens[i] == ' ') 
            continue; 
          
        // Current token is an opening  
        // brace, push it to 'ops' 
        else if(tokens[i] == '('){ 
            ops.push("" + tokens[i]); 
        } 
          
        // Current token is a aphabetic letter or digit, push  
        // it to stack for strings 
        else if(isalpha(tokens[i]) || isdigit(tokens[i])){ 
            std::string val = ""; 
              
            while(i < tokens.length() &&  
                        (isalpha(tokens[i]) || isdigit(tokens[i]))) 
			{ 
				val += tokens[i];
                i++; 
            } 
			//In case of literal number, cache the value
			try{
				int numVal = stoi(val);
				values.insert(map_pair(val, std::shared_ptr<StateValue>(new StateValueNumber(numVal))));
			}catch(std::invalid_argument& e){

			}

			//Treat ".contains" as one operator "contains"
            if(val == "contains"){
				ops.pop(); //pop the "." out
				ops.push("contains");
			}else{
            	literalValues.push(val); 
			}
        } 
          
        // Closing brace encountered, solve  
        // entire brace. 
        else if(tokens[i] == ')') 
        { 
            while(!ops.empty() && ops.top() != "(") 
            { 
                std::string str1 = literalValues.top();
                literalValues.pop(); 
                  
				std::string str2 = literalValues.top();
                literalValues.pop(); 
                  
                std::string op = ops.top(); 
                ops.pop(); 
                  
                literalValues.push(applyOp(str1, str2, op, gameState, values)); 

            } 
              
            // pop opening brace. 
            if(!ops.empty()) 
               ops.pop(); 
        }
          
        // Current token is an operator. 
        else
        { 
            // While top of 'ops' has same or greater  
            // precedence to current token, which 
            // is an operator. Apply operator on top  
            // of 'ops' to top two elements in values stack. 
			std::string currentOp(1, tokens[i]);
			if(tokens[i] == '='){
				currentOp += tokens[i+1];
				i++;
			}
            while(!ops.empty() && precedence(ops.top()) 
                                >= precedence(currentOp)){ 
				std::string str2 = literalValues.top();
                literalValues.pop(); 
                  
				std::string str1 = literalValues.top();
                literalValues.pop(); 
                  
                std::string op = ops.top(); 
                ops.pop(); 
                  
                literalValues.push(applyOp(str1, str2, op, gameState, values)); 
            } 
              
            // Push current token to 'ops'. 
			ops.push(currentOp);
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    while(!ops.empty()){ 
		std::string str2 = literalValues.top();
        literalValues.pop(); 
                  
		std::string str1 = literalValues.top();
        literalValues.pop(); 
                  
        std::string op = ops.top(); 
        ops.pop(); 
                  
        literalValues.push(applyOp(str1, str2, op, gameState, values)); 

    } 
      
    // Top of 'values' contains result, return it. 
    return static_cast<StateValueBoolean*>(values[literalValues.top()].get())->getValue(); 	

}


