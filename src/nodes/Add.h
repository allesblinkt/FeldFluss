#pragma once

#include "../base/Node.h"
#include "../base/NodeRegistry.h"


namespace feld { namespace fluss {
    
class Add : public Node {        
    private:
        NodeInput<double> _in1;
        NodeInput<double> _in2;
        
        NodeOutput<double> _out;
        
    
    public:       
        Add();
        ~Add();
        
        void evaluate(float theDelta);

};
    
} }


