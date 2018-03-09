//Programme for binary search in linked list
#include <iostream>
using namespace std;

struct node{
	int data;
	node *prev;
	node *next;
};

class linkedlist{
	private:
	node *head;
	node *tail;
	public:
	linkedlist(){
	head=NULL;
	tail=NULL;
	}
	
	//Addition function - function for inserting a node at the end
    void addnode ( int n){
        node *temp=new node;
        temp->data=n;
        temp->next=NULL;
        //If the linked list is empty 
        if (head==NULL){
            head=temp;
            tail=temp;
        }
        //If the linked list is not empty
        else
        tail->next=temp;
        tail=temp;
        }

    //Counting function - function for counting the number of elements in the linked list
    int countnode(){
        node *temp;
        temp=head;
        int length=0;
        if (head==NULL){
            cout<<"The list is empty"<<"\n";
        }
        else if(head!=NULL){
            while(temp!=NULL) {
        	    length++;
                temp=temp->next;
            }
            cout<<"The number of elements in the linkedlist are : "<<length<<"\n";
        }
        return length;
    }

//Sorting function - function for bubble sorting the linked list
    int bubblesort(int n){
    	node *cur=new node;
    	node *p=new node;
    	for(int i=0; i<n; i++){
    		p=head;
    		for(int j=0; j<(n-i)-1; j++){
    			if(p->data>p->next->data){
    				cur->data=p->data;
    				p->data=p->next->data;
    				p->next->data=cur->data;
    			}
    			p=p->next;
    		}
    	}
    	return 0;
    }
    
    //Display function - function for dispalying the linked list
    void display(){
    	node *temp=new node;
    	temp=head;
    	if(head!=NULL){
    		while(temp!=NULL){
    			cout<<temp->data<<"->";
    			temp=temp->next;
    		}
    		cout<<"NULL"<<endl;
    	}
    }
    
    //Searching function - function to search an node using binary search
    int binarysearch (int left, int right, int n2){
    	while(left<=right){
    		int mid=(left+right)/2;
    		node *middle=new node;
    		middle=head;
    		for(int i=0; i<mid; i++){
    			middle=middle->next;
    		}
    		if(middle->data==n2){
    			return mid+1;
    		}
    		else if(middle->data>n2){
    			right=mid-1;
    		}
    		else if(middle->data<n2){
    			left=mid+1;
    		}
    	}
    	return -1;
    }
};

int main(){
	int n,num;
	linkedlist l;
	l.addnode(43);	
	l.addnode(42);
	l.addnode(56);
	l.addnode(40);
	l.addnode(54);
	l.display();
	n=l.countnode();
	l.bubblesort(n);
	l.display();
	num=43;
	int pos=l.binarysearch(0,n-1,num);
            if (pos==-1)
            {
	   cout<<"Element is not found "<<endl;
            }
            else
               cout<<"The element is found at "<<pos<<" th position "<<endl;
    return 0;
}
 
