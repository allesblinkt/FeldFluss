#pragma once

#include "../base/Node.h"
#include "../base/NodeRegistry.h"


namespace feld { namespace fluss {
    
class VectorComponents : public Node {
    private:
        NodeInput<Vec3d> _in;
    
        NodeOutput<double> _outX;
        NodeOutput<double> _outY;
        NodeOutput<double> _outZ;    

    
    public:
        VectorComponents();
        ~VectorComponents();
    
        void evaluate(float theDelta);
};
    
} }


