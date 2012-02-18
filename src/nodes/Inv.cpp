#include "Inv.h"

using namespace feld::fluss;

Inv::Inv() {
    name("Invert");
    
    addInput(&_in);
    
    addOutput(&_out);
    
    state(WARNING);
}


Inv::~Inv() {
    
}

void Inv::evaluate(float theDelta) {
	const double myResult = 1 * -1;
	_out.set(myResult);
}


REGISTER_NODE("inverse_number", Inv)
