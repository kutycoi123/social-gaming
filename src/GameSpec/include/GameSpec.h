//GameSpec.h
#ifndef GAMESPEC_H
#define GAMESPEC_H

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/variant.hpp>
#include <nlohmann/json.hpp>

#include "AbstractConfig.h"
#include "Rule.h"
#include <string>

struct NestedMap{
    std::unordered_map<std::string, std::string> map;
};

struct SpecValue{
    boost::variant<std::vector<std::string>, std::string, bool, double, NestedMap, int> value;//TODO: may need to add more types when more details are provided
};

class GameSpec : AbstractSpec{
public:
    GameSpec();
    GameSpec(const std::string&);
    std::vector<Rule> getRules() const;
    std::string getSpecFilePath() const;	
    void addRule(Rule);
    void setSpecFilePath(const std::string&);
    void readSpec(); //override
    void parseGameSpec(const nlohmann::json&); 
    void addConstantSpec(const std::string&, const SpecValue& );
    void addVariableSpec(const std::string&, const SpecValue& );
    void addPerPlayerSpec(const std::string&, const SpecValue& );
    void addPerAudienceSpec(const std::string&, const SpecValue& );
private:
    std::vector<Rule> _rules; 
    std::string _specFilePath;
    std::unordered_map<std::string, SpecValue> _constants;
    std::unordered_map<std::string, SpecValue> _variables;
    std::unordered_map<std::string, SpecValue> _perPlayer;
    std::unordered_map<std::string, SpecValue> _perAudience;  
	
};




#endif





