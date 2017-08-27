
//C Program to do Linear LinkedList operations.

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;
node* Insert(node *,int);
void printlist(node *);
node* insert1(node*,int,int);
node* delete(node *,int);
node* reverse(node *);
int main(){
	int a;
	int n,x,p;
	node* head=NULL;
	while (1){
		printf("\n1.Insert at the begining\n2.Insert at nth position\n3.Insert at tail\n4.print the list\n5.Delete at nth position.\n6.Reverse the list\n");
		printf("Enter your option: ");
		scanf("%d",&a);
	    switch(a){
			case 1:
				printf("Inserting at the begining...\n");
				printf("Enter the element to be inserted:         \n");
				scanf("%d", &n);
				printf("%d",n);	
				head = Insert(head,n);
				//printlist(head);
				printf("Inserted!!\n");
				break;
			case 2:
				printf("Enter the position: ");
				scanf("%d",&x);
				printf("\nEnter the element: ");
				scanf("%d",&n);
				head=insert1(head,n,x);
			case 4:
				printf("List:\n");
				printlist(head);
				break;
			case 5:
				printf("Enter the position to be deleted: ");
				scanf("%d",&p);
				head=delete(head,p);
				printlist(head);
				break;
			case 6:
				head=reverse(head);
				printlist(head);
				break;
			default:
				return 0;
		}
	}
	return 0;
}
	
node* Insert(node* head,int data){
	node* temp= (node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=head;
	head=temp;
	return head;
}
void printlist(node* head){
	node* temp1=head;
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		temp1=temp1->next;
    }
}

node* insert1(node* head,int data,int x){
	node* temp1=head;
	node* temp= (node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	int value=0;
	if(x==0){		
		head=temp;
		temp->next=temp1;		
	}
	
	else{
		while(temp1->next!=NULL){
			value++;
			if(value==x){
				temp->next = temp1->next;
				temp1->next=temp;
			}
			temp1=temp1->next;
		}
	}
			
	/*printf("%d",temp->data);
	printf("%p",temp->next);
	printf("%p",head);*/
	
	
	return head;
	
}

node* delete(node* head,int p){
	node* temp1=head;
	int value=0;
	if(head==NULL){
		printf("There are no element to delete");
	}
	while(temp1->next!=NULL){
		value++;
		if(value==p){
			node* del = temp1->next;
			temp1->next = del->next;
			free (del);
		}
		temp1=temp1->next;
	}
return head;
}
		
node* reverse(node* head){
	node *current,*next,*prev;
	current=head;
	prev=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}
	