#include "VectorComponents.h"

VectorComponents::VectorComponents() {
    name("VecComponents");
    
    addInput(&_in, "Vector");
    
    addOutput(&_outX, "x");
    addOutput(&_outY, "y");
    addOutput(&_outZ, "z");

}


VectorComponents::~VectorComponents() {
    
}

void VectorComponents::evaluate(float theDelta) {
    const Vec3d* myV = NULL;

	_outX.set(myV->x);
    _outY.set(myV->y);
	_outZ.set(myV->z);
}

