
#include "NodeRegistry.h"


NodeRegistry::NodeRegistry() {
    
}


NodeRegistry& NodeRegistry::getInstance() {
    static NodeRegistry _instance;
    return _instance;
}


void NodeRegistry::printRegisteredNodes() {
    for(int i = 0; i < _registers.size(); i++) {
     // Node* = new _registers[i];
        
       // std::cout << _registers[i] << std::endl;
    }
    
    std::cout << "I has " << _registers.size() << " nodes registered";
}

void NodeRegistry::add(node_creator theCreator) {
    _registers.push_back(theCreator);
}


NodeRegistration::NodeRegistration(node_creator theCreator) {
    NodeRegistry::getInstance().add(theCreator);
}


