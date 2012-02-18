#pragma once

#include "../base/Node.h"
#include "../base/NodeRegistry.h"

class Add : public Node
{
public:
	Add();
	~Add();

	void evaluate(float theDelta);
    
private:
	NodeInput<double> _in1;
	NodeInput<double> _in2;

	NodeOutput<double> _out;


};


