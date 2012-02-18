#include "Node.h"
#include <iostream>

using namespace feld::fluss;

Node::Node() {
    //std::cout << "Node constructor" << std::endl;
	_view = new NodeView(*this);
	
	name("Untitled");
    state(GOOD);
}


Node::~Node() {
	delete _view;
}



std::vector<NodeInputBase*> Node::inputs() {
	return _inputs;
}


std::vector<NodeOutputBase*> Node::outputs() {
	return _outputs;
}


void Node::addInput(NodeInputBase* theInput, std::string theName) {
    theInput->name(theName);
	_inputs.push_back(theInput);
}


void Node::addOutput(NodeOutputBase* theOutput, std::string theName) {
    theOutput->name(theName);
	_outputs.push_back(theOutput);
}


NodeView* Node::view() {
	return _view;
} 


std::string Node::name() {
	return _name;
} 


void Node::name(std::string theName) {
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