#pragma once

#include "../base/Node.h"
#include "../base/NodeRegistry.h"

namespace feld { namespace fluss {
    
class Inv : public Node
{
    private:
        NodeInput<double> _in;
        NodeOutput<double> _out;
    
    
    public:
        Inv();
        ~Inv();
    
        void evaluate(float theDelta);
      
};
    
} }

