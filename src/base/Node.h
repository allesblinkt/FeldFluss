#pragma once

#include "NodeInput.h"
#include "NodeOutput.h"
#include "NodeView.h"

#include <boost/any.hpp>

#include <vector>

enum NodeState { GOOD, WARNING, ERROR };

class NodeView;

class Node
{
public:
	Node();
	~Node();

	virtual void evaluate(float theDelta) = 0;

	std::vector<NodeInputBase*> inputs();
	std::vector<NodeOutputBase*> outputs();


	void addInput(NodeInputBase* theInput, std::string theName = "");
	void addOutput(NodeOutputBase* theOutput, std::string theName = "");


	bool forceEval();
	void forceEval(bool theFlag);

	std::string name();
	void name(std::string theName);
    
    NodeState state();
    void state(NodeState theState);
    
	NodeView* view();

	/* data */

private:
	NodeView* _view;
	std::string _name;
    NodeState _state;

	std::vector<NodeInputBase*> _inputs;
	std::vector<NodeOutputBase*> _outputs;

	bool _forceEval;
};



//template <class T> void Describe() {
//	T::DescribeYourself();
//}
//
//
//template <class T> Node* Create() {
//	return new T();
//}