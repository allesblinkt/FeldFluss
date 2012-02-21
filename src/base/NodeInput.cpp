#include "NodeInput.h"

using namespace feld::fluss;

template <typename T>
NodeInput<T>::NodeInput() {
}


template <typename T>
NodeInput<T>::~NodeInput() {
    
}


template <typename T>
void NodeInput<T>::foo() {
    // TODO: remove me
}



#include "cinder/Vector.h"


template class feld::fluss::NodeInput<double>;
template class feld::fluss::NodeInput<cinder::Vec3d>;