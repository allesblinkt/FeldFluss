#pragma once
#include <string>

namespace feld { namespace fluss {

class NodePortBase
{
public:
	std::string name();
	void name(std::string theName);


protected:
	std::string _name;

};

} }