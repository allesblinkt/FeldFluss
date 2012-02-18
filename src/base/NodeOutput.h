#pragma once
#include "NodeOutputBase.h"

namespace feld { namespace fluss {

template<class T>
class NodeOutput : public NodeOutputBase
{
public:
	NodeOutput();
	~NodeOutput();

	void set(T theValue);
	T get();


private:
	T _value;
};

} }