#include "Loop.h"

Loop::Loop(const std::string& loopType, const std::string& failCondition, std::vector<std::string> rules) : Rule("loop"), 
    _loopType(loopType), _failCondition(failCondition), _rules(rules){}

std::string Loop::getLoopType() const{
    return _loopType;
}

std::string Loop::getFailCondition() const{
    return _failCondition;
}

std::vector<std::string> Loop::getRules() const{
    return _rules;

}

void Loop::setLoopType(const std::string& loopType){
    _loopType = loopType;
}

void Loop::setFailCondition(const std::string& failCondition){
    _failCondition = failCondition;
}

void Loop::setRules(const std::vector<std::string>& rules){
    _rules = rules;
}