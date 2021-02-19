#include<stdio.h>
//#include<conio.h>

void TOH(int n,char x,char y,char z){
	if(n>0){
		TOH(n-1,x,z,y);
  		printf("Move disk %d from %c -> %c\n",n,x,y);
  		TOH(n-1,z,y,x);
 	}
}
void main(){
	int n;
	printf("Enter number of plates: ");
 	scanf("%d",&n);
 	TOH(n,'A','B','C');
}
