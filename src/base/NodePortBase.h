#pragma once
#include <string>

class NodePortBase
{
public:
	std::string name();
	void name(std::string theName);


protected:
	std::string _name;

};