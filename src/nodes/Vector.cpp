#include "Vector.h"

Vector::Vector() {
    name("Vector");
    
    addInput(&_inX, "x");
    addInput(&_inY, "y");
    addInput(&_inZ, "z");
    
    addOutput(&_out, "Vector");    
}


Vector::~Vector() {
    
}

void Vector::evaluate(float theDelta) {
    const Vec3d myV(0, 0, 0);
    
	_out.set(myV);
}

REGISTER_NODE(Vector)