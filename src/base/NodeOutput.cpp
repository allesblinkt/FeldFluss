#include "NodeOutput.h"
#include "cinder/Vector.h"

using namespace feld::fluss;

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


template class feld::fluss::NodeOutput<double>;
template class feld::fluss::NodeOutput<cinder::Vec3d>;