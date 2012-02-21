ArrayList<Node> nodes;
ArrayList<Node> result;

void setup() {
  size(500, 500);
    
  nodes = new ArrayList<Node>();
  result = new ArrayList<Node>();


  Node myANode = new Node("a");
  nodes.add(myANode);

  Node myBNode = new Node("b");
  nodes.add(myBNode);

  Node myCNode = new Node("c");
  nodes.add(myCNode);

  Node myDNode = new Node("d");
  nodes.add(myDNode);
  
  Node myENode = new Node("e");
  nodes.add(myENode);
  
  Node myFNode = new Node("f");
  nodes.add(myFNode);

  makeConnection(myANode, myBNode);
  makeConnection(myDNode, myBNode);

  makeConnection(myBNode, myCNode);
  makeConnection(myENode, myDNode);

  makeConnection(myCNode, myFNode);
//  makeConnection(myFNode, myANode); // CYCLE! 



  noLoop();
}


void makeConnection(Node theA, Node theB) {
  theA.downConnections().add(theB);
  theB.upConnections().add(theA);
}


void draw() {
  
  
  background(20);

  ArrayList<Node> myLowNodes = new ArrayList<Node>();

  /* Reset and determine highest nodes */
  for (Node myNode:nodes) {

    myNode.visited = false;
    if (myNode.downConnections().size() == 0) {
      myLowNodes.add(myNode);
    }
  }





  //myNodes.addAll(nodes);


  for (Node myNode:myLowNodes) {

    traverseUp(myNode, null);
  }



  for (Node myNode:result) {

    myNode.draw();
    print(myNode.name + " -> ");
  }

  println("");
}



void traverseUp(Node theNode, ArrayList<Node> theSequenceNodes) {
  theNode.visited = true;

  for (Node myNode:theNode.upConnections()) {
    if (myNode.visited == false) {
      traverseUp(myNode, null);
    }
  }

  result.add(theNode);
}

