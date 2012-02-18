#pragma once

#include "../base/Node.h"
#include "../base/NodeRegistry.h"

namespace feld { namespace fluss {
    
class Inv : public Node
{
public:
	Inv();
	~Inv();
    
	void evaluate(float theDelta);
    
private:
	NodeInput<double> _in;
    
	NodeOutput<double> _out;
    
    
};
    
} }

