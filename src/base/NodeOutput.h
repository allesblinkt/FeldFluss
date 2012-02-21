#pragma once

#include "NodePortBase.h"

#include <list>


using namespace std;

namespace feld { namespace fluss {

template<typename T> class NodeInput;
class NodeInputBase;
  
    
class NodeOutputBase : public NodePortBase  { 
    private:
    
    public:
        virtual void connect(NodeInputBase* theInput) = 0;
        //virtual void breakConnection(NodeInputBase* theOther) = 0;
};
    
    
template<typename T>
class NodeOutput : public NodeOutputBase {
    private:
        T _value;
        list<NodeInput<T>*> _connections;
    
    
    public:
        NodeOutput();
        ~NodeOutput();

        void value(T theValue);
        T value();
        
        void connect(NodeInputBase* theInput);

};

} }