#pragma once

#include <map>

template <class T>
class Model {

    std::map<std::string, T*> map;

    public:
    void addToModel(std::string name, T* object) { map[name] = object; };
    T* operator[] (std::string key) { return map[key]; };

};