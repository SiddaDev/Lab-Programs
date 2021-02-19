#include<stdio.h>
//#include<conio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

float stack[10];
int top=-1;

void push(float num){
	stack[++top]=num;
}

float pop(){
	return(stack[top--]);
}

float eval(char postfix[]){
	int i;
	float op1,op2;
	char symb;
     	for(i=0;i<strlen(postfix);i++){
		symb=postfix[i];
	 	if (isdigit(symb))
	    		push(symb-'0');
	 	else{
	   		op2=pop();
	   		op1=pop();
	   		switch(symb){
				case '+' : push(op1+op2);
					   break;
				case '-' : push(op1-op2);
					   break;
				case '*' : push(op1*op2);
					   break;
				case '/' : push(op1/op2);
					   break;
	   		}
	  	}
	}
	return pop();
}

void main(){
	float val;
	char postfix[20];
    	printf("Enter a valid postfix expression: ");
//    	gets(postfix);
	scanf("%s",&postfix);
    	printf("The result of postfix expression %s is = %f\n",postfix,eval(postfix));
}
