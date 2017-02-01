#pragma once
#include <vector>
#include <string>
#include <list>

class HashChain
{
	const int _m;
	int Hash(const std::string&);
	std::vector<std::list<std::string>> _arr;
public:
	HashChain(int m) : _arr(m), _m(m) {};
	void Add(const std::string&);
	void Del(const std::string&);
	std::string Find(const std::string&);
	std::string Check(const int&) const;
};

