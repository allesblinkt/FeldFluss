#pragma once
#include "Node.h"
#include "NodeInput.h"
#include "NodeOutput.h"

#include <list>

namespace feld { namespace fluss {

    class Fluss {   
    public:
        Fluss();
        void update();
        void addNode(Node* theNode);
        
        ~Fluss();
        
    private:
        list<Node*> _nodes;
        
    };
    
} }
