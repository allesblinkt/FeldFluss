
#include "NodeRegistry.h"

using namespace feld::fluss;


NodeRegistry::NodeRegistry() {
    
}


NodeRegistry& NodeRegistry::getInstance() {
    static NodeRegistry _instance;
    return _instance;
}


void NodeRegistry::printRegisteredNodes() {
    cout << "I has " << _registers.size() << " nodes registered" << endl;
    
    map<string, node_creator>::iterator myIt;
    for(myIt = _registers.begin(); myIt != _registers.end(); myIt++) {
        string myIdentifier = myIt->first;

        node_creator myCreator = myIt->second;
        Node* myNode = myCreator();
        
        cout << "[" << myIdentifier << "] " << myNode->name() << endl;

        delete myNode;
    }
    
}


void NodeRegistry::add(string theIdentifier, node_creator theCreator) {
    _registers[theIdentifier] = theCreator;
}


NodeRegistration::NodeRegistration(string theIdentifier, node_creator theCreator) {
    NodeRegistry::getInstance().add(theIdentifier, theCreator);
}


