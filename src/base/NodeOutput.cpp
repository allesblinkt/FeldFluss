#include "NodeOutput.h"
#include "cinder/Vector.h"

template <class T>
NodeOutput<T>::NodeOutput() {
}

template <class T>
NodeOutput<T>::~NodeOutput() {    
}


template <class T>
void NodeOutput<T>::set(T theValue) { 
	_value = theValue;   
}


template <class T>
T NodeOutput<T>::get() { 
	return _value;   
}


template class NodeOutput<double>;
template class NodeOutput<cinder::Vec3d>;