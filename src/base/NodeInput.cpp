#include "NodeInput.h"



template <class T>
NodeInput<T>::NodeInput() {
}


template <class T>
NodeInput<T>::~NodeInput() {
    
}


#include "cinder/Vector.h"


template class NodeInput<double>;
template class NodeInput<cinder::Vec3d>;