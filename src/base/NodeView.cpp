#include "NodeView.h"
#include "cinder/CinderMath.h"
#include <iostream>

using namespace feld::fluss;

using namespace cinder;

NodeView::NodeView(Node &theNode) {
	_node = &theNode;
    
    _font = Font("Helvetica Neue", 10 );
}


void NodeView::draw(cairo::Context &theG) {
    _size = _calculateSize();

    
    
    
    cairo::GradientLinear myGradient(0, 0, 0, _size.y);
    
    if(_node->state() == WARNING) {
        myGradient.addColorStop(0.15, Colorf(0.518, 0.298, 0.298*0.5));
        myGradient.addColorStop(0.85, Colorf(0.898, 0.467, 0.0));
    } else if(_node->state() == ERROR) {
        myGradient.addColorStop(0.15, Colorf(0.5, 0, 0));
        myGradient.addColorStop(0.85, Colorf(0.8, 0, 0));

    } else {
        myGradient.addColorStop(0.15, Colorf(0.14, 0.12, 0.129));
        myGradient.addColorStop(0.85, Colorf(0.227, 0.188, 0.2));
        
    }

    
    
    
	Rectf myRect;
	myRect.set(0, 0, _size.x, _size.y);

    Vec2f myCorrection(0.5, 0.5);

    theG.translate(myCorrection);
   	theG.translate(_position);
    

    theG.setSourceRgb(0.7, 0.7, 0.7);
    
    theG.roundedRectangle(myRect, 2);
    theG.setLineWidth(1);
    theG.stroke();
    
    theG.translate(Vec2f(-0.5, -0.5));

    
    theG.setSource(myGradient);

//    theG.setSourceRgb(1.0, 1.0, 0);
    theG.roundedRectangle(myRect, 2);
    theG.fill(); 
    
    
    
    
    
    for(int i = 0; i < _node->inputs().size(); i++) {
        NodeInputBase *myInput = _node->inputs()[i];
        int myX = _size.x - (i * PIN_WIDTH + (i-1) * PIN_SPACING + PIN_SPACING + PIN_WIDTH);
        
        theG.setSourceRgb(0.8, 0.8, 0.8);
        theG.rectangle(myX - PIN_WIDTH, 0, PIN_WIDTH, PIN_HEIGHT);
        theG.fill();
        
        
        
    }
    
    
    
    for(int i = 0; i < _node->outputs().size(); i++) {
        NodeOutputBase *myOutput = _node->outputs()[i];
        
        int myX = _size.x - (i * PIN_WIDTH + (i-1) * PIN_SPACING + PIN_SPACING + PIN_WIDTH);
        
        theG.setSourceRgb(0.8, 0.8, 0.8);
        theG.rectangle(myX - PIN_WIDTH, _size.y - PIN_HEIGHT, PIN_WIDTH, PIN_HEIGHT);
        theG.fill();        
    }
    
    
    
    
    theG.translate(Vec2f(5, _size.y - 5));
    theG.setSourceRgb(0.8, 0.8, 0.8);
    theG.setFont( _font );
    theG.setFontSize( 10 );
    theG.showText( _node->name() );
    theG.fill();
    
    theG.setSourceRgb(1.0, 0, 0);

    
    

    
    

    theG.flush();
    
    //theG.popGroup();
}


Vec2f* NodeView::position() {
	return &_position;
}


Vec2f NodeView::_calculateSize() {
    const int myInputCount = _node->inputs().size();
    const int myOutputCount = _node->outputs().size();

    //std::cout << "I (" << _node->name() << ") has " << myInputCount << " inputs and " << myOutputCount << " outputs" << std::endl;

    int myMax = math<int>::max(myInputCount, myOutputCount);

    float myWidth = NODE_BASE_WIDTH + myMax * PIN_WIDTH + (myMax - 1) * PIN_SPACING;
    float myHeight = NODE_HEIGHT;

    Vec2f mySize;
    mySize.set(myWidth, myHeight);

    return mySize;
}


NodeView::~NodeView() {
	
}