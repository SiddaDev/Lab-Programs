#include<stdio.h>
//#include<alloc.h>

#include<stdlib.h>
#include<math.h>

//#include<process.h>

struct node{
	int cf;
	int px;
	int py;
	int pz;
	int flag;
	struct node *link;
};
typedef struct node *NODE;

NODE getnode(){
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL){
		printf("out of memory \n");
		exit(0);
	}
	return x;
}

void display(NODE head){
	NODE temp;
	if(head->link==head){
		printf("polynomial does not exist\n");
		return;
	}
	for(temp=head->link; temp!=head; temp=temp->link){
		printf("+%d x^%d y^%d z^%d", temp->cf,temp->px,temp->py,temp->pz);
		printf("\n");
	}
}

NODE insert_rear(float cf, float x, float y, float z, NODE head){
	NODE temp,cur;
	temp=getnode();
	temp->cf=cf;
	temp->px=x;
	temp->py=y;
	temp->pz=z;
	temp->flag=0;
	cur=head->link;
	while(cur->link!=head){
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=head;
	return head;
}

NODE read_poly(NODE head){
	int i;
	float px,py,pz,cf;
	printf("enter the co-eff as -999 to end the polynomial\n");
	for(i=1;;i++){
		printf("enter the %d term \n",i);
		printf("co-eff=");
		scanf("%f",&cf);
		if(cf==-999)
			break;
		printf("pow x=");
		scanf("%f",&px);
		printf("pow y=");
		scanf("%f",&py);
		printf("pow z=");
		scanf("%f",&pz);
		head=insert_rear(cf,px,py,pz,head);
 	}
	return head;
}

NODE add_poly(NODE n1, NODE n2, NODE n3){
	NODE p1,p2;
	int x1,x2,y1,y2,cf1,cf2,cf,z1,z2;
	p1=n1->link;
	while(p1!=n1){
		x1=p1->px;
 		y1=p1->py;
 		z1=p1->pz;
		cf1=p1->cf;
		p2=n2->link;
		while(p2!=n2){
			x2=p2->px;
			y2=p2->py;
 			z2=p2->pz;
			cf2=p2->cf;
		if(x1==x2 && y1==y2&& z1==z2)
			break;
 		p2=p2->link;
 	}
	if(p2!=n2){
		cf=cf1+cf2;
	 	p2->flag=1;
		if(cf!=0)
	 		n3=insert_rear(cf,x1,y1,z1,n3);
	}
	else
		n3=insert_rear(cf1,x1,y1,z1,n3);
 		p1=p1->link;
	}
 	p2=n2->link;
	while(p2!=n2){
		if(p2->flag==0){
			n3=insert_rear(p2->cf, p2->px, p2->py,p2->pz,n3);
 		}
	p2=p2->link;
 	}
	return n3;
}

void evaluate(NODE head){
	int x,y,z,sum=0;
	NODE temp=head->link;
	printf("Evaluate the resultant polynomial by giving values for X,Y and Z: ");
	scanf("%d %d %d",&x,&y,&z);
	while(temp!=head){
		sum=sum+temp->cf*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz);
		temp=temp->link;
	}
	printf("sum=%d\n",sum);
}

void main(){
	NODE n1,n2,n3,n4;
 	n1=getnode();
 	n2=getnode();
 	n3=getnode();
 	n4=getnode();
 	n1->link=n1;
 	n2->link=n2;
	n3->link=n3;
	n4->link=n4;
	printf("enter the first polynomial\n");
	n1=read_poly(n1);
	printf("enter the second polynomial\n");
	n2=read_poly(n2);
	n3=add_poly(n1,n2,n3);
	printf("the first polynomial is \n");
	display(n1);
	printf("the second polynomial is \n");
	display(n2);
	printf("the sum of two polynomials is \n");
	display(n3);
	printf("enter the  polynomial to evaluate\n");
	n4=read_poly(n4);
	evaluate(n4);
}
