public class Node {
  ArrayList<Node> _myDownConnections = new ArrayList<Node>();
  
  ArrayList<Node> _myUpConnections = new ArrayList<Node>();
  
  String name = "";
  boolean visited = false;
  
  PVector position;
  
  public Node(String theName) {
     name = theName; 
     
     position = new PVector( random(width), random(height) );
  }
  
  
  void draw() {
    noFill();
    stroke(255);
    rectMode(CENTER);
    rect(position.x, position.y, 20,20);

    
    for(Node myNode:downConnections()) {
       line(this.position.x, this.position.y, myNode.position.x, myNode.position.y);
       ellipseMode(CENTER);
       ellipse(myNode.position.x, myNode.position.y, 3, 3);
    }
     
    fill(255);
    noStroke();
    text(name, position.x, position.y);
  }
  

  ArrayList<Node> upConnections() {
     return _myUpConnections; 
  }
  
  
  ArrayList<Node> downConnections() {
     return _myDownConnections; 
  }
  
}
