#include <iostream>
#include "StringSet.h"

using std::cout;
using std::endl;	

StringSet::StringSet() : currSize(0), maxSize(4), arr(new string[maxSize])
{
}

StringSet::StringSet(const StringSet& oldarr)
{		
		currSize=oldarr.currSize;
		maxSize=oldarr.maxSize;
		
		arr=new string[maxSize];
		
		for(int i=0;i<(currSize);i++)
		{
			arr[i]=oldarr.arr[i];

		}
			
}

StringSet::~StringSet()
{
	if(arr!=NULL)
	{
		delete [] arr;
	}
}

bool StringSet::insert(string str)
{
	if(currSize < maxSize)
	{
		arr[currSize]=str;
		currSize++;
				
		return true;
	}
	else
	{
		string* newarr=new string[2*maxSize];
			
		int i;
		for (i=0;i<currSize;i++)
		{
			newarr[i]=arr[i];
		}
			
		delete[] arr; 
			
		arr=newarr;
		maxSize=2*maxSize;
			
		arr[currSize]=str;
		currSize++;
			
		return true;
			
	}
	
}

bool StringSet::remove(string str)
{
	int where=find(str);
	
	if(where>(-1))
	{
		if(where!=(currSize-1))
		{
			arr[where]=arr[currSize-1];
			
		}
		
		currSize--;
		return true;
	}
	else 
	{
		return false;
	}
}

int StringSet::find(string str) const
{
	int found=(-1);
	int i;
	
	for (i=0;i<currSize;i++)
	{
		if(arr[i]==str)
		{
			found=i;
		}
	}
	return found;
}

int StringSet::size() const
{
	if(currSize>0)
	{
		return currSize;
	}
return (-1);
}

StringSet StringSet::setunion(const StringSet& otherarr) const
{
	StringSet newarr(otherarr);
	
	for(int i=0;i<currSize;i++)
	{
		newarr.insert(arr[i]);
	}

	return newarr;
}

StringSet StringSet::intersection(const StringSet& otherarr) const
{
	StringSet newarr;
	
	int otherSize=otherarr.size();

	for(int i=0;i<currSize;i++)
	{	
		for(int j=0;j<otherSize;j++)
		{
			if(arr[i]==otherarr.arr[j])
			{
				newarr.insert(arr[i]);
			}
		}
	}
	
	return newarr;
}

StringSet StringSet::difference(const StringSet& otherarr) const
{
	StringSet newarr;
	
	cout<<endl;
	
	int match=(-1);
	
	for (int i=0; i<currSize;i++)
	{
		newarr.insert(arr[i]);
	}
	for(int i=0;i<currSize;i++)
	{
		match=otherarr.find(arr[i]);
		if(match!=(-1))
		{
			newarr.remove(arr[match]);
			match=(-1);
		}
	}
	
	return newarr;
}












































