#pragma once

#include "../base/Node.h"
#include "cinder/Vector.h"
#include "../base/NodeRegistry.h"


namespace feld { namespace fluss {
    
class Vector : public Node {
    private:
        NodeInput<double> _inX;
        NodeInput<double> _inY;
        NodeInput<double> _inZ;
    
        NodeOutput<Vec3d> _out;

    
    public:
        Vector();
        ~Vector();
    
        void evaluate(float theDelta);
};
    
} }
