#pragma once

#include <string>
#include <vector>

using namespace std;

namespace feld { namespace fluss {

class Node;
    
class NodePortBase
{
    private:
    
    protected:
        std::string _name;
        Node* _node;
    
    
    public:
        std::string name();
        void name(string theName);
        
        Node* node();
        void node(Node* theNode);



};

} }