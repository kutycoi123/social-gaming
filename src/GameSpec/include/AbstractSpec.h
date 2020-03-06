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
	
	class AbstractSpec{
	public:
	    virtual void readSpec() = 0;
	};

}

#endif


