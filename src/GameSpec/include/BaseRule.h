#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <iostream>
#include "GameState.h"
#include "AbstractSpec.h"

// Forward dependancy declaration
// TODO: Remove when circular dependency between GameState and GameSpec is resolved
class GameState;

namespace GameSpecification{

    struct Type{
        std::string str;
        int i;
        bool b;
        double d;
        std::vector<ValueType> vect;
        std::unordered_map<std::string, ValueType> map;
    };

    struct Visit_Type : public boost::static_visitor<Type>{

        Type operator()(int& existing) const {
            Type a;
            a.i = existing;
            return a;

        };

        Type operator()(double& d) const{
            Type a;
            a.d = d;
            return a;
        };

        Type operator()(std::string& s) const{
            Type a;
            a.str = s;
            return a;
        };

        Type operator()(bool& b) const{
            Type a;
            a.b = b;
            return a;
        };

        Type operator()(std::vector<ValueType>& vvt) const{
            Type a;
            a.vect =  vvt;
            return a;
        };

        Type operator()(std::unordered_map<std::string, ValueType> const& umvt) const {
            Type a;
            a.map =  umvt;
            return a;
        };

    };
	class BaseRule : public std::enable_shared_from_this<BaseRule>{
		public:
			BaseRule();
			BaseRule(RuleType);
			std::string getRuleName() const;
			RuleType getRuleType() const;
            std::vector<std::shared_ptr<BaseRule>> getSubRules() const ;
			std::shared_ptr<BaseRule> getPtr() ;
			void setNextPtr(const std::shared_ptr<BaseRule>&);
			std::shared_ptr<BaseRule> getNextPtr() const;
            void addSubRule(std::shared_ptr<BaseRule> rule);
			void setParentPtr(const std::shared_ptr<BaseRule>&);
			std::shared_ptr<BaseRule> getParentPtr() const;
			virtual void process(GameState& gameState) = 0;

		protected:

			RuleType ruleType;
			std::shared_ptr<BaseRule> next;
			std::shared_ptr<BaseRule> parent;
            std::vector<std::shared_ptr<BaseRule>> subRules;
	};
}
#endif
