#ifndef STRINGSET_H
#define STRINGSET_H

#include <string>

using std::string;

class StringSet
{
	private:
		//member vars
		int currSize;
		int maxSize;
		string* arr;
	
	public:
		//member function declarations
		StringSet();
		StringSet(const StringSet &);
		~StringSet();
		bool insert(string str);
		bool remove(string str);
		int find(string) const;
		int size() const;
		StringSet setunion(const StringSet&) const;
		StringSet intersection(const StringSet &) const;
		StringSet difference(const StringSet &) const;
		StringSet& operator=(const StringSet&)=delete;
};

#endif
