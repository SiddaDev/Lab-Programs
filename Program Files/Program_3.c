#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 10

int top=-1,j=-1, a[10],b[10];

void push(){
    int data;
	if(top==max-1){
		printf("Stack Overflow\n");
		return;
	}
	printf("Enter the element to be inserted: ");
	scanf("%d",&data);
	b[++j]=a[++top]=data;
}

void pop(){
	if(top==-1){
	 	printf("Stack Underflow\n");
		return;
      	}
      	printf("Data %d is deleted\n",a[top]);
      	b[j--]=a[top--];
}

void Palindrome(){
    	int flag=0,i;
      	for(i=0;i<=top;i++){
		if(a[i] == b[j--])
		flag = 1;
      	}
     	if (flag == 1){
        	printf("Entered nums in stack is palindrome\n");
          	j=top;
      	}else{
        	printf("Entered nums in stack is not a palindrome\n");
           	j=top;
        }
}

void Display(){
	int i;
  	if(top == -1){
		printf("Stack is empty\n");
     		return;
  	}
  	 printf("Elements of the stack are :");
   	 for(i=top;i>=0;i--)
  		 printf("\t%d",a[i]);
	printf("\n");
}

void main(){
	int i, item, ch;
   	while(1){
		printf("1.Push \t 2.Pop \t 3.Palindrome \t 4.Display \t 5.Exit \n");
		printf("Enter the choice: ");
		scanf("%d",&ch);
		switch(ch){
	    		case 1:push();
		   	break;
	    		case 2:pop();
		   	break;
	    		case 3:Palindrome();
		   	break;
	    		case 4:Display();
		   	break;
	    		case 5:exit(0);
	    		default: printf("wrong entry");
		}
   	}
}
