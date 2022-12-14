#include<bits/stdc++.h>

using namespace std;
class Node{
	
	public:
		int data;
		Node* next;
	
	Node(int data){
	this -> data = data;
	this -> next = NULL;
	}
	
};
Node* insertAtHead(Node* &head){
	int data;
	cout<<"enter the data for the insertion at head : ";
	cin>>data;
	Node* temp = new Node(data);
	temp -> next = head;
	head = temp;
	return head;
}

Node* insertAtTail(Node* head){
	int data;
	cout<<"enter the data for the insertion at tail : ";
	cin>>data;
	Node* temp = new Node(data);
	head -> next = temp;
	return temp;
}

void insertAtMid(Node* head){
	int data;
	cout<<"enter the data for the insertion at mid : ";
	cin>>data;
	Node* temp = new Node(data);
	int pos;
	cout<<"At which poition you want to insert new node? : ";
	cin>>pos;
	int curr = 1;
	Node* s = head;
	Node* prev;
	while(curr != pos){
		prev = s;
		s = s -> next;
		curr++;
	}
	prev -> next = temp;
	temp -> next = s;
	
}

Node* deleteAtHead(Node* &head){
	Node* temp = head;
	head = head->next;
	free(temp);
	return head; 
}



void deleteAtTail(Node* head){
	Node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp ->next = NULL;
	
}

Node* deleteAtMid(Node* &head){
	Node* s = head;
	Node* prev;
	int pos;
	cout<<"At which poition you want to delete the node? : ";
	cin>>pos;
	if(pos == 1){
		head = deleteAtHead(head);
		return head;
	}
	int curr = 1;
	while(curr != pos){
		prev = s;
		s=s->next;
		curr++;
	}
	prev->next = s->next;
	return head;
	
}

void display(Node* head){
	
	
	Node* temp = head;
	while(temp != NULL){
		cout<< temp->data<<" ";
		temp = temp->next;
	}
}

Node* reverse(Node* head){
	
	if(head==NULL || head->next==NULL)
	return head;
	
	Node* first = head->next;
	Node* new_head = reverse(head->next);
	first->next = head;
	head->next= NULL;
	return new_head;
}

void MidNode(Node* head){
	Node* slow = head;
	Node* fast = head;
	Node* prev = head;
	while(fast != NULL && fast->next != NULL){
		prev = slow;
		slow = slow->next;
		fast = fast->next;
		if(fast->next!=NULL)
		fast = fast->next;
	}
	cout<<"the mid node is : "<<prev->data<<endl;
}

void nthNode(Node* head){
	int n;
	cout<<"which node to print from the end : ";
	cin>>n;
	Node* temp = head;
	Node* s = head;
	int c=n;
	while(c>0){
		temp = temp->next;
		c--;
	}
	while(temp!=NULL){
		s=s->next;
		temp=temp->next;
	}
	cout<<"The nth node from the end is : "<<s->data<<endl;
}

int main(){
	int c=5;
	int data;
	cout<<"enter the data : ";
	cin>>data;			
	Node* node1 = new Node(data);
	Node* head = node1;
	//for the insertion at the head of the node--
	while(c!=0){
	head = insertAtHead(head);
	c--;
	}

	display(head);	
	
}

