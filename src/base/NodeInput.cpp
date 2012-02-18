#include "NodeInput.h"

using namespace feld::fluss;

template <class T>
NodeInput<T>::NodeInput() {
}


template <class T>
NodeInput<T>::~NodeInput() {
    
}


#include "cinder/Vector.h"


template class feld::fluss::NodeInput<double>;
template class feld::fluss::NodeInput<cinder::Vec3d>;