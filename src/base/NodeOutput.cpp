#include "NodeOutput.h"
#include "NodeInput.h"
#include "cinder/Vector.h"

#include <list>
#include <iterator>

using namespace std;
using namespace feld::fluss;

template <typename T>
NodeOutput<T>::NodeOutput() {
}

template <typename T>
NodeOutput<T>::~NodeOutput() {    
}


template <typename T>
void NodeOutput<T>::value(T theValue) { 
	_value = theValue;   
}


template <typename T>
T NodeOutput<T>::value() { 
	return _value;   
}


template <typename T>
void NodeOutput<T>::connect(NodeInputBase* theInput) {
    NodeInput<T>* myInput = dynamic_cast<NodeInput<T>*>(theInput);
    
    if(myInput != 0) {
        cout << "We are compatible" << endl;
        _connections.push_back(myInput);
    } else {
        cout << "We are not compatible" << endl;
    }
}


//template <typename T>
//void NodeOutput<T>::breakConnection(NodeInput<T>* theOther) {
//    for(typename std::list<NodeInput<T>* >::iterator it = _connections.begin(); it != _connections.end(); ++it) {
//        if(*it == theOther) {
//     		_connections.erase(it);
//     	}
//    }
//}




template class feld::fluss::NodeOutput<double>;
template class feld::fluss::NodeOutput<cinder::Vec3d>;