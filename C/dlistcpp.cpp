//Converting a doubly linked list C implementation to C++, replacing void pointer polymorphism with 
//Object-Orientated polymorphism paradigms in C++, namely templates.

//TODO: (Constructor that builds list?)


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
	node *head; //pointers to the head/tail nodes respectively
	node *tail;
	
public:
	doublylinkedlist(){}
	
	void append(T);
	void push(T);
	void pop();
	void drop(T);
	int size();
	*doublylinkedlist clone(T);
	void clear(T);
};

template<class T> 
void doublylinkedlist<T>::append(T item)
{ 
	node *p=new node; //create a pointer to a new node to append to the list
	p->data=item; //set p's data to the item argument
	p->prev=tail; //set p's previous to the tail of the list T
	p->next=NULL; //set the next element to NULL
	tail=p; //set the tail of T to this new node, p, we're appending to the end
}

template<class T> 
void doublylinkedlist<T>::push(T item)
{ 
	node *p=new node; //create a pointer to a new node to push to start of list
	p->data=item; //set p's data to the item argument
	p->prev=NULL; //set p's previous to the NULL
	p->next=head; //set the next element of p to the current head of list
	head=p; //set the head of the list to the new node created
}

template<class T> 
void doublylinkedlist<T>::pop()
{ 
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return NULL;
	}
	node *p=new node; //create a pointer that points to the head
	p=head; //make p = to head
	if(head->next != NULL){
		delete(head); //delete current head
		head = p->next; //make the 2nd element the new head 
		p->next->prev = NULL; //sever connection to the old head
		delete(p); //free the memory p points to
	}
}

template<class T> 
void doublylinkedlist<T>::drop(T item) 
{ 
	if(head==NULL) { 
		cout<<"List is empty"<<endl; 
		return; 
	} 
	if(head->data==item) { 
		head=head->next; 
		head->prev=NULL; 
		return; 
	} 
	if(tail->data==item) { 
		tail=tail->prev; 
		tail->next=NULL; 
		return; 
	} 
	node *p=head->next; //pointer to scan through node elements
	while(p!=NULL) { //while pointer is not null (while there is another element in list...)
		if(p->data==item) break;  //break while loop if you've found node to drop
		p=p->next; //otherwise jump to next node
	} 
	if(p==NULL) { 
	cout<<item<<"not found "<<endl; 
	return; 
	} 
	//sever connections to drop node and set up new connections
	(p->prev)->next=p->next; 
	(p->next)->prev=p->prev; 
	return; 
}

template<class T>
int doublylinkedlist<T>::size()
{
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return -1;
	}
	int count = 0; //set counter to 0
	node *p = head;
	while(p!=NULL){
		++count;
		p=p->next;
	}
	if(count == 1){
		cout<<"List is 1 element long"<<endl;
	}else{
		cout<<"List is "<<count<<" elements long"<<endl;
	}
	return count; 
}

template<class T>
void doublylinkedlist<T>::clear()
{
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	node *p = new node();
	p = head;
	while(p->next != NULL){
		head = p->next;
		cout<<"Deleting "<<head->data<<" from list"<<endl;
		delete(head);
		p=p->next;
	}	
	cout<<"All items deleted"<<endl;
}
