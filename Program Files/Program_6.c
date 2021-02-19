#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

#define MAX 10
int CQ[MAX], n;
int r = -1;
int f = 0,ct=0;

void addq(){
    int item;
    if (ct == n){
	printf("Queue Overflow\n");
       	return;
    }
    printf("Enter the element for adding in queue: ");
    r = (r+1)%n;
    scanf("%d", &CQ[r]);
    ct++;
}

void deleteq(){
	if (ct == 0){
		printf("Queue Underflow\n");
		return ;
    	}
	printf("Element deleted from queue is : %d\n", CQ[f]);
	f=(f+1)%n;
	ct--;
}

void display(){
    	int i,k=f;
    	if (ct == 0){
       		printf("Queue is empty\n");
      	 	return;
    	}
    	printf("contents of Queue are :\n");
    	for (i = 0; i < ct; i++){
       		printf("%d\t", CQ[k]);
       		k=(k+1)%n;
    	}
	printf("\n");
}

int main(){
    	int choice;
    	printf("Enter the size of the array: ");
    	scanf("%d",&n);
   	 while (1){
		printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice){
	    		case 1: addq();
	    			break;
	    		case 2: deleteq();
	    			break;
	    		case 3: display();
	    			break;
	    		case 4: exit(1);
	    		default:printf("Wrong choice\n");
		}
    	}
}
