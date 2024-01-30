
#include <iostream>
using namespace std;

struct node{
   int data;
   node *prev;
   node *next;
   node(int val) : data(val), prev(NULL), next(NULL) {}
};

class doublyLinkedlist{
    
    node *head = NULL;
    node *tail = NULL;
    
    public:
    
    void insert_at_End(int val)
   {
        node *newnode = new node(val);

       if(head == NULL)
       {
           newnode -> next = head;
           head = newnode;
           newnode -> prev = tail;
           tail = newnode;
       }
       else
       {
           tail -> next = newnode;
           newnode -> prev = tail;
           tail = newnode;
           tail -> next = NULL;
       }
   }
   void display()

{
	if(head == NULL)
	{
		printf("List is Empty ");
		return;
	}
	node *temp=head;
	
	while(temp != NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

   void insertAtBegining(int val)
   {
   	node *newnode = new node(val);
   	
   	newnode -> next = head;
   	if(head ==NULL)
   	{
   		tail = newnode;
	   }
	   else
	   {
	   	head -> prev = newnode;
	   }
   	head = newnode;
   	head -> prev = NULL;
   }
   
   void SearchAndDelete(int val)
   {
   	if(head == NULL)
   	{
   		cout<<"list is Empty" ;
   		return ;
	   }
	   node *temp = head;
	   do
	   {
	   	if(val == head -> data)
	   	{
	   		cout<<"\nDeleted Element is head: "<<head -> data <<endl;
	   		node *del = temp;
	   		temp = temp -> next;
	   		head = temp;
	   		head -> prev = NULL;
	   		cout<<"first";
	   		delete del;
	   		return;
		   }
		    if(val == temp -> data)
	   {
	       cout<<"\nDeleted Element is 2 : "<<temp -> data <<endl;
	       node *del = temp;
	       node *temp1=temp ->prev;
	       temp =temp -> next;
	       temp1->next=temp;
	       temp->prev=temp1;
	       delete del;
	      
	       return;
	   }
	   
	   if(val == tail -> data )
	   {
	   	
	   	cout<<"\nDeleted Element is  : "<<tail -> data <<endl;
	   	temp = tail;
	   	cout<<temp ->data;
	   	temp = temp ->prev;
	   	temp -> next = NULL;
	   	cout<<"last1";
	   	delete tail;
	   	tail = temp;
	   	
	   	return;
	   }
	   
		   temp = temp -> next;
		   
	   }while(temp != head);  
   }
   
   void InsertAtPos(int pos,int val)
   {
   	//cout<<"\n"<<pos;
   	int cnt =1;
   	node *tempp = head;
      do
     {
        cnt++;
        tempp = tempp -> next;
     } while (tempp != tail);
   	//cout<<"\n"<<cnt;
   	node *newnode = new node(val);
   	if(head == NULL)
   	{
   		cout<<"List is Empty";
   		return;
	   }
	   
	   if(pos == 1)
	   {
	   	insertAtBegining(val);
	   	return;
	   }
	   if(pos < 1 || pos > ++cnt)
	   {
	   	cout<<"Position is Invalid";
	   	return;
	   }
	   cnt--;
	   if(pos > cnt)
	   {
	   	insert_at_End(val);
	   	return;
	   }
       
	   node *temp = head;
	   for(int i=2;i<pos;i++)
	   {
	   	temp = temp -> next;
	   }
	   node *temp1 = temp -> next;
	   newnode -> next = temp1 ;
	   newnode -> prev = temp ;
	   temp -> next = newnode;
	   temp1 -> prev = newnode;
   }
   
};

int main() {
    
    doublyLinkedlist o;
    o.insert_at_End(4);
    o.insert_at_End(5);
    o.insert_at_End(6);
    o.insert_at_End(7);
   // o.display();
    o.insertAtBegining(3);
    o.insertAtBegining(2);
    o.insertAtBegining(1);
    o.display();
    
    o.SearchAndDelete(4);
    cout<<"\n";
    //o.display();
    o.InsertAtPos(7,9);
    cout<<"\n";
    o.display();
    cout<<"\n";
    return 0;
}