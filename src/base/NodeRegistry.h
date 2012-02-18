#pragma once
#include <map>
#include <iostream>
#include "Node.h"

namespace feld { namespace fluss {

using namespace std;

template<class T> 
Node* node_factory() {
    return new T;
}


typedef Node* (*node_creator)(void);


class NodeRegistry {
public:
    void add(string theIdentifier, node_creator theCreator);
    void printRegisteredNodes();

    static NodeRegistry& getInstance();
private:
    NodeRegistry();
    map<string, node_creator> _registers;
};


class NodeRegistration {    
public:
    NodeRegistration(string theIdentifier, node_creator theCreator);
};

} }

#define REGISTER_NODE(theIdentifier, theNodeClass) NodeRegistration  _node_registration_ ## theNodeClass(theIdentifier, &node_factory<theNodeClass>);