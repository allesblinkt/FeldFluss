#pragma once
#include "../base/Node.h"


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