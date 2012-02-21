#include "Vector.h"

using namespace feld::fluss;

Vector::Vector() {
    name("Vector");
    
    addInput("x", &_inX);
    addInput("y", &_inY);
    addInput("z", &_inZ);
    
    addOutput("vector", &_out);    
}


Vector::~Vector() {
    
}


void Vector::evaluate(float theDelta) {
    const Vec3d myV(0, 0, 0);
    
	_out.value(myV);
}


REGISTER_NODE("vector", Vector)