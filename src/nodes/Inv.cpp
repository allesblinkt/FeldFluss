#include "Inv.h"

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

