#include<iostream>
using namespace std;


class Node 
{
	public:
	//Data	
	int data;
	//Pointer to next node
	Node *next;
	//Pointer to previous node
	Node *prev;
	//Pointer that makes ptr to NULL
	Node()
	{
		next = NULL;
		prev = NULL;
	}
};

class dlinkedlist
{
	public:
	//Head + Nodes inside linked with each other
	
	//Head and Tail -> Node type pointer
	
	Node *head;
	Node *tail;

	//Construct
	dlinkedlist(){
		head = NULL;
		tail = NULL;
	}
	
	//Insert
	void insert(int value);
	void insertat(int pos,int value);
	void del();
	void delat(int pos);
	int count();
	void display();
};

void dlinkedlist::insert(int value)
{
	Node *ptr = new Node;
	ptr->data = value;
	if (head==NULL)
	{head = ptr;}
	else
	{ptr->prev = tail;
	 tail->next = ptr;}
	tail = ptr;
}

void dlinkedlist::insertat(int pos,int value)
{
	if( pos>this->count() )
	cout<<"Linkedlist doesnot have this many elements"<<endl;
	else
	{
	//Creat a node
	Node *temp = new Node;
	//Shorting the data
	temp->data = value;
	if (pos==1)
	//Moving pointers like magic!
	{
		head->prev = temp;
		temp->next = head;
		temp->prev = NULL;
		head = temp;
	}
	else
	// Update the code for 1st pos.
	{	
		int i =1;
		Node *ptr = head;
		while(i<pos-1)
		{ptr = ptr->next;i++;}
		temp->prev = ptr;
		temp->next = ptr->next;
		ptr->next = temp;
		if(temp->next!= NULL)
		temp->next->prev = temp;
	}
	}
}

void dlinkedlist::del()
{
	Node *ptr = head;
	while(ptr->next!= tail)
	{ptr = ptr->next;}
	tail = ptr;
	ptr=ptr->next;
	tail->next = NULL;
	ptr->prev = NULL;
	delete ptr;
}

void dlinkedlist::delat(int pos)
{
	if( pos>this->count() )
	cout<<"Linkedlist Does not have that many elements"<<endl;
	else
	{
		Node *ptr = head;int i =1;
		while(i<pos)
		{ptr = ptr->next;i++;}
		
		if (ptr!= head)
		{ptr->prev->next = ptr->next;}
		
		if (ptr!= tail)
		{ptr->next->prev = ptr->prev;}
		
		ptr->next = NULL;
		ptr->prev = NULL;
		delete ptr;
		
	}
	
	
}

int dlinkedlist::count()
{
	Node *ptr = head;int i =0;
	while(ptr!= NULL)
	{
		i+=1;
		ptr = ptr->next;
	}
	return i;
}
//Display
void dlinkedlist::display()
{
	Node *ptr = head;
	while(ptr!= NULL)
	{
		cout<< ptr->data<< "->";
		ptr = ptr->next;
	}
	cout<< "NULL" <<endl;
}

int main()
{
	dlinkedlist dl;
	dl.insert(1);dl.insert(2);dl.insert(3);dl.insert(4);dl.insert(5);
	dl.display();
	dl.insertat(3,7);
	dl.display();
	dl.insertat(9,9);
	dl.del();
	dl.display();
	dl.delat(3);dl.display();	
	return 0;
}

