#include<stdio.h>
//#include<conio.h>
#include<string.h>
#define MAX 20

char stack[MAX];
int top=-1;

void push(char item){
	stack[++top]=item;
}

char pop(){
	return stack[top--];
}

int prcd(char symbol){
	switch(symbol){
		case '^':           return 4;
		case '*': case '/': return 3;
		case '+': case '-': return 2;
		case '(': case ')': case '#': return 1;
	}
}

void convertip(char infix[],char postfix[]){
	int i,symbol,j=0;
	push('#');
	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
    		switch(symbol){
			case '(' : push(symbol); break;
			case ')' :while(stack[top]!='('){
				postfix[j]=pop();
				j++;
				}
			pop();
			break;
			case '-':case '*':case '+':case '/':case '^':while(prcd(symbol)<=prcd(stack[top])){
		   	postfix[j]=pop();
		   	j++;
		 	}
		 	push(symbol);
			break;
			default: postfix[j++] = symbol;
		}
	}
	while(stack[top]!='#'){
		postfix[j]=pop();
		j++;
	}
 	postfix[j]='\0';
}

void main(){
	char infix[20],postfix[20];
   	printf("Enter the valid infix expression: ");
//   	gets(infix);
	scanf("%s",&infix);
  	convertip(infix,postfix);
   	printf("The corresponding postfix expression is: ");
//   	puts(postfix);
	printf("%s\n",postfix);
}
