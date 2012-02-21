#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/ImageIo.h"
#include "cinder/Utilities.h"

const int WIDTH = 1280;
const int HEIGHT = 720;


using namespace ci;
using namespace ci::app;
using namespace std;


#include "base/NodeRegistry.h"

#include "base/Fluss.h"

#include "nodes/Add.h"
#include "nodes/Inv.h"
#include "nodes/VectorComponents.h"
#include "nodes/Vector.h"

using namespace feld::fluss;


class FeldFlussApp : public AppBasic {
    public:
        void prepareSettings( Settings *settings);
        void setup();
        void mouseDown( MouseEvent event );	
        void update();
        void draw();

        Fluss fluss;    
};


void FeldFlussApp::prepareSettings( Settings *settings ) {
	settings->setWindowSize( WIDTH, HEIGHT );
	settings->setResizable( false );
}


void FeldFlussApp::setup() {
    NodeRegistry::getInstance().printRegisteredNodes();
    
    
    Vector* myVectorNode = new Vector();
    myVectorNode->view()->position()->set(50, 50);
    fluss.addNode(myVectorNode);
    
    
    Add* myAddNode = new Add();
    myAddNode->view()->position()->set(50, 100);
    fluss.addNode(myAddNode);
 
    
    VectorComponents* myVComponents = new VectorComponents();
    myVComponents->view()->position()->set(50, 150);
    fluss.addNode(myVComponents);

    
    
    
    
    /* Testing */
    myVComponents->outputs()["x"]->connect( myAddNode->inputs()["first"] );
    myVectorNode->outputs()["vector"]->connect( myAddNode->inputs()["second"] );

   
}

void FeldFlussApp::mouseDown( MouseEvent event ) {
}


void FeldFlussApp::update() {
    fluss.update();
}


void FeldFlussApp::draw() {    
    
    // std::cout << getAverageFps() << std::endl;
    
    cairo::Context myG( cairo::createWindowSurface() );
    myG.setSourceRgb( 0.486, 0.498, 0.486 );
    myG.paint();
    
    list<Node*> myNodes = fluss.nodes();
    
    for(list<Node*>::iterator it = myNodes.begin(); it != myNodes.end(); ++it) {
        Node* myNode = *it;
        
        myG.identityMatrix();
        
        myNode->view()->draw(myG);
        
    }

}


CINDER_APP_BASIC( FeldFlussApp, Renderer2d )
