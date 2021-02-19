#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
int MAX=4, count;
struct student{
	char usn[10];
	char name[30];
	char branch[5];
	int sem;
	char phno[10];
	struct student *next;	//Self referential pointer.
};

typedef struct student NODE;

int countnodes(NODE *head){
	NODE *p;
	count=0;
	p=head;
	while(p!=NULL){
		p=p->next;
		count++;
	}
	return count;
}
NODE* getnode(NODE *head){
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));	//Create first NODE
	printf("Enter USN, Name, Branch, Sem, Ph.No\n");
//gets(newnode->usn);
	scanf("%s %s %s %d %s",&(newnode->usn),&(newnode->name),&(newnode->branch),&(newnode->sem),&(newnode->phno));
//gets(newnode->name);
//flushall();
//gets(newnode->branch);
//scanf("%d",&(newnode->sem));
//flushall();
//gets(newnode->phno);
	newnode->next=NULL;
	head=newnode;
	return head;
}
NODE* display(NODE *head){
	NODE *p;
 	if(head == NULL)
		printf("No student data");
	else{
		p=head;
		printf("\n----STUDENT DATA----");
		printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPh.NO.");
		while(p!=NULL){
			printf("\n%s\t%s\t\t%s\t%d\t%s", p->usn, p->name, p->branch, p->sem, p->phno);
			p = p->next;
		}
		printf("\nThe no. of nodes in list is: %d",countnodes(head));
		printf("\n");
	}
	return head;
}

NODE* create(NODE *head){
	NODE *newnode;
	if(head==NULL){
		newnode=getnode(head);
		head=newnode;
	}
	else{
		newnode=getnode(head);
		newnode->next=head;
		head=newnode;
	}
	return head;
}

NODE* insert_front(NODE *head){
	if(countnodes(head)==MAX)
		printf("List is Full / Overflow!!");
	else{
		head=create(head);
	}
}
NODE* insert_rear(NODE *head){
	NODE *p, *newnode;
	p=head;
	if(countnodes(head) == MAX)
		printf("List is Full(QUEUE)!!");
	else if(head == NULL){
		newnode= getnode(head);
		head=newnode;
	}
	else{
		newnode=getnode(head);
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newnode;
	}
	return head;
}
NODE* insert(NODE *head){
	int ch;
	do{
		printf("1.Insert at Front(First)\t2.Insert at End(Rear/Last)\t3.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: head=insert_front(head);
			break;
			case 2: head=insert_rear(head);
			break;
			case 3: break;
		}
		head=display(head);
	}while(ch!=3);
	return head;
}
NODE* delete_front(NODE *head){
	NODE *p;
	if(head==NULL)
		printf("List is Empty/Underflow (STACK/QUEUE)");
	else{
		head=head->next; //Set 2nd NODE as head free(p);
		printf("\nFront(first)node is deleted");
	}
	return head;
}

NODE* delete_rear(NODE *head){
	NODE *p, *q; p=head;
	while(p->next!=NULL){
		q=p;
		p=p->next; //Go upto -1 NODE which you want to delete
	}
	free(p);//Delete last NODE...
	q->next=NULL;
	printf("Last(end) entry is deleted"); return head;
}
NODE* del(NODE *head){
	int ch;
	do{
		printf("1.Delete from Front(First)\t2. Delete from End(Rear/Last))\t3.Exit"); printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: head=delete_front(head);
			break;
			case 2: head=delete_rear(head);
			break;
			case 3: break;
		}
	head=display(head);
	}while(ch!=3);
	return head;
}
NODE* stack(NODE *head){
	int ch;
	do{
		printf("\nSSL used as Stack...\n");
		printf("1.Insert at Front(PUSH) \t 2.Delete from Front(POP))\t3.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: head=insert_front(head);
			break;
			case 2: head=delete_front(head);
			break;
			case 3: break;
		}
		head=display(head);
	}while(ch!=3);
	return head;
}
NODE* queue(NODE *head){
	int ch;
	do{
		printf("SSL used as Queue...\n");
		printf("1.Insert at Rear(INSERT) \t 2.Delete from Front(DELETE))\t3.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
	switch(ch){
		case 1: head=insert_rear(head);
		break;
		case 2: head=delete_front(head);
		break;
		case 3: break;
	}
	head=display(head);
	}while(ch!=3);
	return head;
}

void main(){
	int ch, i, n;
	NODE *head;
	head=NULL;
//clrscr();
	printf("*----------Student Database-----------*");
	do{
		printf("\n1.Create\t 2.Display\t 3.Insert\t 4.Delete\t 5.Stack\t 6.Queue\t 7.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
	switch(ch){
		case 1: printf("How many student data you want to create: ");
		scanf("%d", &n);
		for(i=0;i<n;i++){
			head=create(head);
		}
		break;
		case 2: head=display(head);  //Call to Display...
		break;
		case 3: head=insert(head);	//Call to Insert...
		break;
		case 4: head=del(head);	//Call to delete
		break;
		case 5: head=stack(head);
		break;
		case 6: head=queue(head);
		break;
		case 7: exit(0);
		}
	}while(ch!=7);
}
