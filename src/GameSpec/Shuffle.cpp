#include "Shuffle.h"

using GameSpecification::Shuffle;
using GameSpecification::BaseRule;
Shuffle::Shuffle() : BaseRule("shuffle"), _list(""){}

Shuffle::Shuffle(const std::string& list): BaseRule("shuffle"), _list(list){}

std::string Shuffle::getList() const{
    return _list;
}

void Shuffle::setList(const std::string& list){
    _list = list;
}
