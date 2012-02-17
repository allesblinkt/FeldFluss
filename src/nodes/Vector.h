#pragma once

#include "../base/Node.h"
#include "cinder/Vector.h"

class Vector : public Node
{
public:
	Vector();
	~Vector();
    
	void evaluate(float theDelta);
    
private:
	NodeInput<double> _inX;
    NodeInput<double> _inY;
	NodeInput<double> _inZ;

	NodeOutput<Vec3d> _out;
};