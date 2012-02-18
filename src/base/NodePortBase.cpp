#include "NodePortBase.h"

using namespace feld::fluss;

std::string NodePortBase::name() {
	return _name;
}


void NodePortBase::name(std::string theName) {
	_name = theName;
}