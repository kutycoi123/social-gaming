#ifndef ABSTRACTSPEC_H
#define ABSTRACTSPEC_H
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/variant.hpp>
namespace GameSpecification{
	/*
	struct NestedMap{
	    std::unordered_map<std::string, std::string> map;
	};
	*/	
	struct SpecValue{
		// TODO: may need to add more types when more details are provided
	    boost::variant<std::string, int, 
						bool, double, std::vector<std::string>,
						std::unordered_map<std::string, std::string>> value;
	};
	enum RuleType{
		ForEachType,LoopType,InparallelType,ParallelforType,
		SwitchType,WhenType,ExtendType,ReverseType,ShuffleType,
		SortType,DealType,DiscardType,AddType,TimerType,InputChoiceType,
		InputTextType,InputVoteType,MessageType,GlobalMessageType,
		ScoresType,CaseType,Unknown
	};
	static std::unordered_map<std::string,GameSpecification::RuleType> stringToRuleType = {
            {"foreach", GameSpecification::RuleType::ForEachType},
            {"loop", GameSpecification::RuleType::LoopType,},
            {"inparallel",GameSpecification::RuleType::InparallelType,},
            {"parallelfor",GameSpecification::RuleType::ParallelforType,},
            {"switch",GameSpecification::RuleType::SwitchType,},
            {"when",GameSpecification::RuleType::WhenType,},
            {"extend", GameSpecification::RuleType::ExtendType, },
            {"reverse",GameSpecification::RuleType::ReverseType, },
            {"shuffle",GameSpecification::RuleType::ShuffleType, },
            {"sort",GameSpecification::RuleType::SortType, },
            {"deal",GameSpecification::RuleType::DealType, },
            {"discard",GameSpecification::RuleType::DiscardType, },
            {"add",GameSpecification::RuleType::AddType, },
            {"timer",GameSpecification::RuleType::TimerType,},
            {"input-choice",GameSpecification::RuleType::InputChoiceType, },
            {"input-text",GameSpecification::RuleType::InputTextType, },
            {"message",GameSpecification::RuleType::MessageType, },
            {"global-message",GameSpecification::RuleType::GlobalMessageType, },
            {"scores",GameSpecification::RuleType::ScoresType, },
			{"case", GameSpecification::RuleType::CaseType},
            {"unknown",GameSpecification::RuleType::Unknown, }
    };
	static std::unordered_map<RuleType, std::string> ruleTypeToString = {
		{RuleType::ForEachType,"foreach"},
   	 	{RuleType::LoopType,"loop"},
   	 	{RuleType::InparallelType,"inparallel"},
   	 	{RuleType::ParallelforType,"parallelfor"},
   	 	{RuleType::SwitchType,"switch"},
   	 	{RuleType::WhenType,"when"},
   	 	{RuleType::ExtendType, "extend"},
   	 	{RuleType::ReverseType, "reverse"},
   	 	{RuleType::ShuffleType, "shuffle"},
   	 	{RuleType::SortType, "sort"},
   	 	{RuleType::DealType, "deal"},
   	 	{RuleType::DiscardType, "discard"},
   	 	{RuleType::AddType, "add"},
   	 	{RuleType::TimerType, "timer"},
   	 	{RuleType::InputChoiceType, "input-choice"},
   	 	{RuleType::InputTextType, "input-text"},
   	 	{RuleType::MessageType, "message"},
   	 	{RuleType::GlobalMessageType, "global-message"},
   	 	{RuleType::ScoresType, "scores"},
		{RuleType::CaseType, "case"},
   	 	{RuleType::Unknown, "unknown"}
	};	
	
	class AbstractSpec{
	public:
	    virtual void readSpec() = 0;
	};

}

#endif


