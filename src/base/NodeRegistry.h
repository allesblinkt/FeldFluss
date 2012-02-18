#pragma once
#include <vector>
#include <iostream>
#include "Node.h"


template<class T> 
Node* node_factory() {
    return new T;
}


typedef Node* (*node_creator)(void);


class NodeRegistry {
public:
    void add(node_creator theCreator);
    void printRegisteredNodes();

    static NodeRegistry& getInstance();
private:
    NodeRegistry();
    std::vector<node_creator> _registers;
};


class NodeRegistration {    
public:
    NodeRegistration(node_creator theCreator);
};


#define REGISTER_NODE(nodeClass) NodeRegistration  _node_registration_ ## nodeClass(&node_factory<nodeClass>);