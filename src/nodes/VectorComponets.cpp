#include "VectorComponents.h"

using namespace feld::fluss;

VectorComponents::VectorComponents() {
    name("Components");
    
    addInput("vector", &_in);
    
    addOutput("x", &_outX);
    addOutput("y", &_outY);
    addOutput("z", &_outZ);

}


VectorComponents::~VectorComponents() {
    
}

void VectorComponents::evaluate(float theDelta) {
    const Vec3d* myV = NULL;

	_outX.value(myV->x);
    _outY.value(myV->y);
	_outZ.value(myV->z);
}


REGISTER_NODE("components_vector", VectorComponents)