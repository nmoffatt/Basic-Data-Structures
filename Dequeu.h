

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::runtime_error;

class Node
{
	public:
		Node* next;
		int data;
};

class Deque
{
	private:
		//member vars
		Node* head;
		Node* tail;
		int len;
	
	public:
		//member function declarations
		Deque();
		Deque(const Deque&);
		~Deque();
		void Print();
		Deque& operator=(const Deque&);
		void insert_front(int value);
		void insert_back(int value);
		int remove_front();
		int remove_back();
		int peek_front() const;
		int peek_back() const;
		bool empty() const;
		int size() const;
		//helper function
		void Destroy();
};

#endif


