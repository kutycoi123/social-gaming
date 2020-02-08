#ifndef ABSTRACTSPEC_H
#define ABSTRACTSPEC_H
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/variant.hpp>
namespace GameSpecification{

	struct NestedMap{
	    std::unordered_map<std::string, std::string> map;
	};
	
	struct SpecValue{
	    boost::variant<std::vector<std::string>, std::string, bool, double, NestedMap> value;//TODO: may need to add more types when more details are provided
	};
	
	class AbstractSpec{
	public:
	    virtual void readSpec() = 0;
	};

}

#endif


