#pragma once
#include "NodeInputBase.h"

namespace feld { namespace fluss {

template<class T>
class NodeInput : public NodeInputBase
{
public:
	NodeInput();
	~NodeInput();
};

} }