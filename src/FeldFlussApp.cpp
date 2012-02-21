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


void FeldFlussApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( WIDTH, HEIGHT );
	settings->setResizable( false );
}


void FeldFlussApp::setup()
{
//    for(int j = 0; j < 20; j++){
//        
//        for(int i = 0; i < 10; i++){
//            
//            Vec2i myPos;
//            myPos.set(i * 120, j * 25);
//            
//            
//            Node* myNode;
//            
//            if(i % 4 == 0) {
//                myNode = new Add();
//            } 
//            
//            if(i % 4 == 1) {
//                myNode = new Inv();
//            } 
//            
//            if(i % 4 == 2) {
//                myNode = new VectorComponents();
//            }         
//            
//            if(i % 4 == 3) {
//                myNode = new Vector();
//            }    
//            
//            myNode->view()->position()->set(myPos);
//
//            
//            fluss.addNode(myNode);
//            
//            
//        }
//    }
    
    
    NodeRegistry::getInstance().printRegisteredNodes();
    
    Vector* myVectorNode = new Vector();
    fluss.addNode(myVectorNode);
    
    Add* myAddNode = new Add();
    fluss.addNode(myAddNode);
    
    VectorComponents* myVComponents = new VectorComponents();
    fluss.addNode(myVComponents);

    
    
    /* Testing */
    cout << "Name is " << myVComponents->outputs()["x"]->name() << endl;
    //myVComponents->outputs()["x"]->connect(myAddNode->inputs()["in1"]);
    cout << typeid(myVComponents->outputs()["x"]).name() << endl;
   
    
    NodeOutput<double>* myDoubleOut = dynamic_cast<NodeOutput<double>*>(myVComponents->outputs()["x"]);
    
    if(myDoubleOut == 0) {
        cout << "Cast failed" << endl;
    } else {
        cout << "Foo" << endl;
    }
    
    
    NodeOutput<Vec3d>* myVectorOut = dynamic_cast<NodeOutput<Vec3d>*>(myVComponents->outputs()["x"]);
    
    if(myVectorOut == 0) {
        cout << "Cast failed" << endl;
    } else {
        cout << "Foo" << endl;
    }
    
    
    myVComponents->outputs()["x"]->connect( myAddNode->inputs()["first"] );
    myVectorNode->outputs()["vector"]->connect( myAddNode->inputs()["second"] );

   
}

void FeldFlussApp::mouseDown( MouseEvent event )
{
}

void FeldFlussApp::update()
{
    fluss.update();
}

void FeldFlussApp::draw()
{    
    
 //    std::cout << getAverageFps() << std::endl;
    
 //    cairo::Context myG( cairo::createWindowSurface() );
	// myG.setSourceRgb( 0.486, 0.498, 0.486 );
 //    myG.paint();
    
    
    
 //    for(int i= 0; i < _nodes.size(); i++){
     
 //        Node* myNode = _nodes[i];
        
        
 //        if(i == 0) {
 //            myNode->view()->position()->set(getMousePos());
 //        }
        
        
 //        myG.identityMatrix();
        
 //        myNode->view()->draw(myG);

    
 //    }
    
        

    
       
    
}


CINDER_APP_BASIC( FeldFlussApp, Renderer2d )
