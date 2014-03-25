//Converting a doubly linked list C implementation to C++, replacing void pointer polymorphism with 
//Object-Orientated polymorphism paradigms in C++, namely templates.

#include <iostream>

using namepsace std;

template<class T>
class doublylinkedlist
{
private:
	struct node
	{
		T data;
		node *prev;
		node *next;
	}
public:
	doublylinkedlist(){}
	
	//class methods to be implemented outside of class definition
	void append(T);
	void push(T);
	void pop();
	bool contains(T);
	void drop(T);
	void reverse();
	void clone();
};

template<class T> 
void doublylinkedlist<T>::append(T item)
{ 
	node *p=new node; 
	p->data=item; 
	p->prev=tail; 
	p->next=NULL; 
	tail=p; 
}
	
