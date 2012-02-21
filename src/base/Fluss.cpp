#include "Fluss.h"

using namespace feld::fluss;


Fluss::Fluss() {
    
}


void Fluss::addNode(Node* theNode) {
	_nodes.push_back(theNode);
}


void Fluss::update() {
	list<Node*> myNodes(_nodes);
	list<Node*> mySort;


    for(list<Node*>::iterator it = myNodes.begin(); it != myNodes.end(); ++it) {
       myNodes.erase(it);
    }

}


Fluss::~Fluss() {
    
}