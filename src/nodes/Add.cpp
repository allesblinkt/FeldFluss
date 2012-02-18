#include "Add.h"

using namespace feld::fluss;

Add::Add() {
    name("Add");
    
    addInput(&_in1);
    addInput(&_in2);
    
    addOutput(&_out);
    
    state(ERROR);
}


Add::~Add() {
    
}

void Add::evaluate(float theDelta) {
	const double mySum = 1 + 1;
	_out.set(mySum);
}


REGISTER_NODE("add_number", Add)