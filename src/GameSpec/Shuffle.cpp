#include "Shuffle.h"

Shuffle::Shuffle() : Rule("shuffle"), _list(""){}

Shuffle::Shuffle(const std::string& list): Rule("shuffle"), _list(list){}

std::string Shuffle::getList() const{
    return _list;
}

void Shuffle::setList(const std::string& list){
    _list = list;
}