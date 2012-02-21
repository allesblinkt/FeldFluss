#include "Node.h"
#include <iostream>

using namespace feld::fluss;

Node::Node() {
	_view = new NodeView(*this);
	
	name("Untitled");
    state(GOOD);
}


Node::~Node() {
	delete _view;
}



std::map<string, NodeInputBase*>& Node::inputs() {
	return _inputs;
}


std::map<string, NodeOutputBase*>& Node::outputs() {
	return _outputs;
}


void Node::addInput(std::string theIdentifier, NodeInputBase* theInput) {
    _inputs[theIdentifier] = theInput;
    theInput->name(theIdentifier);
    theInput->node(this);
}


void Node::addOutput(string theIdentifier, NodeOutputBase* theOutput) {
    _outputs[theIdentifier] = theOutput;
    theOutput->name(theIdentifier);
    theOutput->node(this);
}


vector<Node*> Node::connectionsUp() {
    vector<Node*> myConnections;
    
    map<string, NodeInputBase*>::iterator myIt;
    for(myIt = _inputs.begin(); myIt != _inputs.end(); myIt++) {        
        NodeInputBase* myInput = myIt->second;

        //myInput-> 
        
        // TODO: continue here.
    }

    
}

vector<Node*> Node::connectionsDown() {
    
}


NodeView* Node::view() {
	return _view;
} 


std::string Node::name() {
	return _name;
} 


void Node::name(string theName) {
	_name = theName;
} 


bool Node::forceEval() {
	return _forceEval;
} 


void Node::forceEval(bool theFlag) {
	_forceEval = theFlag;
} 


NodeState Node::state() {
	return _state;
}


void Node::state(NodeState theState) {
	_state = theState;
}