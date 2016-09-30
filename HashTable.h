

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string.h>
#include <cstddef>
#include <vector>
#include <cctype>
#include <stdexcept>
#include "LinkedList.h"

using std::string;
using std::size_t;

class HashTable
{
	private:
		//member vars
		int currSize;
		int maxsize;
		LinkedList* LL;
		unsigned long hashCode(string st) const;
		size_t compress(string st) const;
	
	public:
		//member function declarations
		HashTable();
		HashTable(int n);
		HashTable(const HashTable& oldHash);
		~HashTable();
		bool insert(string str);
		bool remove(string str);
		bool search(string str) const;
		vector<string> get(unsigned long index) const;
		int size() const;
		int maxSize() const;
		float loadFactor();
		vector<string> setunion(const HashTable&) const;
		vector<string> intersection(const HashTable &) const;
		vector<string> difference(const HashTable &) const;
		//HashTable& operator=(const HashTable &)=delete;
		HashTable& operator=(const HashTable & oldHash);
		//void printTable(); //helper func
};

#endif


