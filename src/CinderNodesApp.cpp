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


#include "nodes/Add.h"
#include "nodes/Inv.h"
#include "nodes/VectorComponents.h"
#include "nodes/Vector.h"

using namespace feld::fluss;


class CinderNodesApp : public AppBasic {
public:
    void prepareSettings( Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
  	Add addNode;
    vector<Node*> _nodes;
};


void CinderNodesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( WIDTH, HEIGHT );
	settings->setResizable( false );
}


void CinderNodesApp::setup()
{
    for(int j = 0; j < 20; j++){
        
        for(int i = 0; i < 10; i++){
            
            Vec2i myPos;
            myPos.set(i * 120, j * 25);
            
            
            Node* myNode;
            
            if(i % 4 == 0) {
                myNode = new Add();
            } 
            
            if(i % 4 == 1) {
                myNode = new Inv();
            } 
            
            if(i % 4 == 2) {
                myNode = new VectorComponents();
            }         
            
            if(i % 4 == 3) {
                myNode = new Vector();
            }    
            
            myNode->view()->position()->set(myPos);

            _nodes.push_back(myNode);
            
            
            
            
        }
    }
    
    
    NodeRegistry::getInstance().printRegisteredNodes();
   
}

void CinderNodesApp::mouseDown( MouseEvent event )
{
}

void CinderNodesApp::update()
{
}

void CinderNodesApp::draw()
{    
    
    std::cout << getAverageFps() << std::endl;
    
    cairo::Context myG( cairo::createWindowSurface() );
	myG.setSourceRgb( 0.486, 0.498, 0.486 );
    myG.paint();
    
    
    
    for(int i= 0; i < _nodes.size(); i++){
     
        Node* myNode = _nodes[i];
        
        
        if(i == 0) {
            myNode->view()->position()->set(getMousePos());
        }
        
        
        myG.identityMatrix();
        
        myNode->view()->draw(myG);

    
    }
    
        

    
       
    
}


CINDER_APP_BASIC( CinderNodesApp, Renderer2d )
