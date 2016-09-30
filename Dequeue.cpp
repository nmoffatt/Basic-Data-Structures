#include "Deque.h"

Deque::Deque()
{
	head=NULL;
	tail=NULL;
	len=0;
	
}

Deque::Deque(const Deque& old)
{   
	head=NULL;
	tail=NULL;
	len=0;
	
	Node* curr=old.head;
	insert_front(curr->data);
	curr=curr->next;
	
	while(curr!=NULL)
	{
		insert_back(curr->data);
		curr=curr->next;
	}
}

Deque& Deque::operator=(const Deque& old)
{
	if(this != &old)
	{
		Destroy();
		
		head=NULL;
		tail=NULL;
		len=0;
	
		Node* curr=old.head;
		insert_front(curr->data);
		curr=curr->next;
	
		while(curr!=NULL)
		{
			insert_back(curr->data);
			curr=curr->next;
		}
		
	}

	return *this;
}

Deque::~Deque()
{
	Node* temp;
	
	while(head!=NULL)
	{
		temp=head->next;
		delete head;
		head=temp;
	}
	
	Destroy();
}

void Deque::Destroy()
{
	Node* temp;
	
	while(head!=NULL)
	{
		temp=head->next;
		delete head;
		head=temp;
	}
}

void Deque::Print()
{
	Node* temp=head;
	
	for(int i=0;i<len;i++)
	{
		cout<<temp->data<<", ";
		temp=temp->next;
	}
	cout<<endl;
}
void Deque::insert_front(int value)
{
	Node* temp=new Node();
	temp->data=value;
	temp->next=NULL;
	
	if( empty() )
	{
		head=temp;
		tail=head;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	len++;
}

void Deque::insert_back(int value)
{
	Node* tmp=new Node();
	tmp->data=value;
	tmp->next=NULL;
	
	if( empty() )
	{
		head=tmp;
		tail=head;
	}
	else
	{
		tail->next=tmp;
		tail=tmp;
	}
	
	len++;
}

int Deque::remove_front()
{
	if( empty())
	{
		throw runtime_error("Exception: Queue is empty");
	}
	int value=head->data;
	
	Node* temp=head;
	if(head->next!=NULL)
	{
		head=head->next;
	}
	else
	{
		head=NULL;
		tail=NULL;
	}
	len--;
	
	delete temp;
	
	return value;
}

int Deque::remove_back()
{
	if(empty())
	{
		throw runtime_error("Exception: Queue is empty");
	}
	
	int value=tail->data;

	Node* tmp=head;
	
	if(head==tail)
	{
		head=NULL;
		tail=NULL;
		len=0;
	}
	else
	{
		while(tmp->next!=tail)
		{
			tmp=tmp->next;
		}
		
		delete tail;
		tail=tmp;
		tail->next=NULL;
		len--;
	}
	
	return value;
}

int Deque::peek_front() const
{
	if ( empty() )
	{
		throw runtime_error("Exception: Queue is empty");
	}
	
	return head->data;
}

int Deque::peek_back() const
{
	if ( empty() )
	{
		throw runtime_error("Exception: Queue is empty");
	}
	
	return tail->data;
}

int Deque::size() const
{
	return len;
}

bool Deque::empty() const
{
	if (size() == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

