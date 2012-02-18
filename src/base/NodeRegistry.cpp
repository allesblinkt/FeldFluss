
#include "NodeRegistry.h"


NodeRegistry::NodeRegistry() {
    
}


NodeRegistry& NodeRegistry::getInstance() {
    static NodeRegistry _instance;
    return _instance;
}


void NodeRegistry::printRegisteredNodes() {
    iterator<<#typename _Category#>, <#typename _Tp#>>
    
    for(int i = 0; i < _registers.size(); i++) {
     // Node* = new _registers[i];
        
      //  node_creator func = _registers[i];
        //Node* myNode = func();
        
        //cout << myNode->name() << endl;
    }
    
    cout << "I has " << _registers.size() << " nodes registered" << endl;
}


void NodeRegistry::add(string theIdentifier, node_creator theCreator) {
    _registers[theIdentifier] = theCreator;
}


NodeRegistration::NodeRegistration(string theIdentifier, node_creator theCreator) {
    NodeRegistry::getInstance().add(theIdentifier, theCreator);
}


