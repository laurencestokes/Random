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
	
	void createlist(T []);
	void append(T);
	void push(T);
	void pop();
	void drop(T);
	int size();
	*doublylinkedlist clone(T);
	void clear(T);
};

template<class T> 
void doublylinkedlist<T>::createlist(T x[])
	
	if(x == NULL){
		cout<<"Input Array is Empty"<<endl;
		return;
	}
	int arrLength = sizeof(x)/sizeof(x[0]); //get size of array passed into initial list
	node *q; 
	node *p=new node; //create first node
	node p->data=x[0]; //first element of array argument passed is data for first node
	p->next=NULL; 
	p->prev=NULL; 
	for(int i=1;i<arrLength;i++) { //loop through for as many items as there are in the input array
		q=p; 
		p=p->next=new node; 
		p->data=x[i]; 
		p->next=NULL; 
		p->prev=q; 
	} 
	tail=p; 
} 

template<class T> 
void doublylinkedlist<T>::append(T item)
{ 
	node *p=new node; //create a pointer to a new node to append to the list
	p->data=item; //set p's data to the item 
	p->next=NULL;
	if(head == NULL){
		p->prev=NULL;
		head=p;
	}
	if(tail == NULL){
		p->prev=head; //set p's previous to the head of the list T
	}
	if(head != NULL && tail != NULL){
		p->prev=tail;
		tail=p;
	}
}

template<class T> 
void doublylinkedlist<T>::push(T item)
{ 
	node *p=new node; //create a pointer to a new node to push to start of list
	p->data=item; //set p's data to the item argument
	p->prev=NULL; //set p's previous to the NULL
	if(head == NULL){
		p->next=NULL; 
	}else{
		p->next=head;
	}
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
