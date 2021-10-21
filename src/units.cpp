#include "units.h"

unit::unit(_type t,std::string s){
    type = t;
    name = s;
}

unit::unit(_type t,std::string s, int pr){
    type = t;
    name = s;
    prior = pr;
}

environment::environment(){
    _defined[0]._childs.push_back(unit(_type::_num,"3.1415926535"));
    _defined[0]._childs.push_back(unit(_type::_num,"2.7182818284"));
}

void environment::add(unit & _unit){
    _defined.push_back(_unit);
}

unit environment::get(std::string _name){
    unit result;
    for (unit iter : _defined){
        if(iter.name == _name){
            result = iter;
        }
    }
    return result;
}

bool environment::have(std::string _name){
    for (unit iter : _defined){
        if(iter.name == _name){
            return true;
        }
    }
    return false;
}