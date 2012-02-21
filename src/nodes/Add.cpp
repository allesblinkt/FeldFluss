#include "Add.h"

using namespace feld::fluss;

Add::Add() {
    name("Add");
    
    addInput("first", &_in1);
    addInput("second", &_in2);
    
    addOutput("result", &_out);
    
    state(ERROR);
}


Add::~Add() {
    
}


void Add::evaluate(float theDelta) {
	const double mySum = 1 + 1;
	_out.value(mySum);
}


REGISTER_NODE("add_number", Add)