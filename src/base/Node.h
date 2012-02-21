#pragma once

#include "NodeInput.h"
#include "NodeOutput.h"
#include "NodeView.h"

#include <boost/any.hpp>

#include <vector>

using namespace std;

namespace feld { namespace fluss { 

class NodeView;

enum NodeState { GOOD, WARNING, ERROR };



class Node
{
public:
	Node();
	~Node();

	virtual void evaluate(float theDelta) = 0;

	std::map<string, NodeInputBase*>& inputs();
	std::map<string, NodeOutputBase*>& outputs();


	void addInput(string theIdentifier, NodeInputBase* theInput);
	void addOutput(string theIdentifier, NodeOutputBase* theOutput);


    vector<Node*> connectionsUp();
    vector<Node*> connectionsDown();
    
    
    bool isDirty();
    void flagDirty(bool theFlag);
    
    
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

	std::map<string, NodeInputBase*> _inputs;
	std::map<string, NodeOutputBase*> _outputs;

	bool _forceEval;
};

} }

//template <class T> void Describe() {
//	T::DescribeYourself();
//}
//
//
//template <class T> Node* Create() {
//	return new T();
//}