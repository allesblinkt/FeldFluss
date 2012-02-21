#pragma once

#include "NodePortBase.h"

namespace feld { namespace fluss {

template<typename T> class NodeOutput;

class NodeInputBase : public NodePortBase  { 
    private:
    

    public:
        virtual void foo() = 0; //TODO: remove me
};

    
template<typename T>
class NodeInput : public NodeInputBase
{
    private:
        NodeOutput<T>* _connection;
    
    
    public:
        NodeInput();
        ~NodeInput();
        void foo(); //TODO: remove me

};

} }