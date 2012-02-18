#pragma once
#include "cinder/cairo/Cairo.h"
#include "Node.h"

namespace feld { namespace fluss {

using namespace ci;

class Node;

class NodeView
{
public:
	NodeView(Node &theNode);
	~NodeView();

	void draw(cairo::Context &theG);
	Vec2f* position();

    static const int PIN_WIDTH = 4;
    static const int PIN_HEIGHT = 4;

    static const int PIN_SPACING = 6;

    static const int NODE_BASE_WIDTH = 40;
    static const int NODE_HEIGHT = 20;


    
private:
    Vec2f _calculateSize();
    
	Node* _node;
	
	Vec2f _position;
	Vec2f _size;

    Font _font;

};

} }