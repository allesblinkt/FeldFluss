#pragma once

#include "../base/Node.h"
#include "../base/NodeRegistry.h"


class VectorComponents : public Node
{
public:
	VectorComponents();
	~VectorComponents();
    
	void evaluate(float theDelta);
    
private:
	NodeInput<Vec3d> _in;
    
	NodeOutput<double> _outX;
    NodeOutput<double> _outY;
	NodeOutput<double> _outZ;

    
    
};



