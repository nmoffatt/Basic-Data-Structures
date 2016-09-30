#include <iostream>
#include "HashTable.h"

using std::cout;
using std::endl;
using std::vector;	
using std::invalid_argument;

HashTable::HashTable() : currSize(0), maxsize(101), LL(new LinkedList[maxsize])
{
	
}

HashTable::HashTable(int n) : currSize(0), maxsize(2*n), LL(new LinkedList[maxsize])
{
	
}

HashTable::HashTable(const HashTable& oldHash)
{
	currSize=oldHash.currSize;
	maxsize=oldHash.maxSize();
	
	LL=new LinkedList[maxsize];
	
	for(unsigned int i=0; i<(maxsize); i++)
	{
		if (!oldHash.LL[i].empty())
		{
			//cout<<"bucket"<<i<<": "<<endl;
			vector<string> List=oldHash.get(i);
			
			for (auto& str : List)
			{
				LL[i].insert_back(str);
			}
		}
		
			
	}
}

HashTable& HashTable::operator=(const HashTable & oldHash)
{
	
		if(this != &oldHash)
		{
			delete[] LL;
			currSize=0;
			maxsize=oldHash.maxSize();
			
			LL=new LinkedList[maxsize];
		
			for(unsigned long i=0;i<maxsize;i++)
			{
				if(!oldHash.LL[i].empty())
				{
					vector<string> List=oldHash.get(i);
			
					for (auto& str : List)
					{
						LL[i].insert_back(str);
						currSize++;
					}
				}
			}
		}
	
	
	
	return *this;
}

HashTable::~HashTable()
{
	delete[] LL;
}
/*
void HashTable::printTable()
{
	for(int i=0;i<maxsize;i++)
	{
		cout<<"Bucket "<<i+1<<":";
		LL[i].Print();
	}
}*/
float HashTable::loadFactor()
{
	float n=size();
	float N=maxSize();
	float lambda=n/N;

	return lambda;
}

size_t HashTable::compress(string st) const
{
	unsigned long code=hashCode(st);
	int n=maxsize;
	size_t index=code%n;
	
	return index;
}

unsigned long HashTable::hashCode(string st) const
{
	unsigned long code=0;
	
	for(int i=0;i<st.size();i++)
	{
		char c=st.at(i);
		
		for(int j=1;j<27;j++)
		{
			if(c==(64+j)||c==(96+j))
			{
				code=(code*37)+j;
			}
		}
	}
	
	return code;
}

bool HashTable::insert(string str)
{
	for(int i=0; i<str.size(); i++)
	{
		if (!std::isalpha(str[i])) 
		{
			throw invalid_argument( "Non alpha character, insertion failed" );
		}
	}
	
	if(!search(str))
	{
		unsigned long index=compress(str);
	
		LL[index].insert_back(str);
		currSize++;
				
		return true;
	}
	
	return false;
	
}

bool HashTable::remove(string str)
{
	for(int i=0; i<str.size(); i++)
	{
		if (!std::isalpha(str[i])) 
		{
			throw invalid_argument( "Non alpha character, removal failed" );
		}
	}
	
	if(search(str))
	{
		unsigned long index=compress(str);
	
		bool remove=LL[index].remove_item(str);	
		currSize--;
		
		return remove;
	}
}

bool HashTable::search(string str) const
{
	for(int i=0; i<str.size(); i++)
	{
		if (!std::isalpha(str[i])) 
		{
			throw invalid_argument( "Non alpha character, search failed" );
		}
	}
	
	size_t index=compress(str);
	
	bool found=LL[index].find(str);
	
	return found;
}

int HashTable::size() const
{
	if(currSize>0)
	{
		return currSize;
	}
return (-1);
}

int HashTable::maxSize() const
{
	if(maxsize>0)
	{
		return maxsize;
	}
return (-1);
}

vector<string> HashTable::get(unsigned long index) const
{
	vector<string> vec=LL[index].getVec();
		
	return vec;
}

vector<string> HashTable::setunion(const HashTable& otherhash) const
{
	vector<string> s_union;
	
	for(unsigned long i=0; i<maxsize; i++)
	{	
		if(!LL[i].empty())
		{
			vector<string> List=get(i);
			for (auto& str : List)
			{
				
				s_union.push_back(str);
				
			}
			
			
		}
		
	}
	for(unsigned long i=0; i<otherhash.maxSize(); i++)
	{	
		if(!otherhash.LL[i].empty())
		{
			vector<string> List=otherhash.get(i);
			for (auto& str : List)
			{
				if(!search(str))
				{
					s_union.push_back(str);
				}
					
			}
			
			
		}
		
	}
	
	return s_union;
}

vector<string> HashTable::intersection(const HashTable& otherhash) const
{
	vector<string> intersec;

	for(unsigned long i=0; i<maxsize; i++)
	{	
		if(!LL[i].empty())
		{
			vector<string> List=get(i);
			for (auto& str : List)
			{
				if(otherhash.search(str))
				{
					intersec.push_back(str);
				}
			}
			
			
		}
		
	}
	
	return intersec;
}

vector<string> HashTable::difference(const HashTable& otherhash) const
{
	vector<string> s_difference;
	
	for(unsigned long i=0; i<maxsize; i++)
	{
		if(!LL[i].empty())
		{
			vector<string> List=get(i);
			
			for (auto& str : List)
			{
				if(!otherhash.search(str))
				{
					s_difference.push_back(str);
				}
			}
		}
	}

	return s_difference;
}

