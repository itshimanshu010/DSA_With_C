#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodeType
{
    int coeff;
    int power;
    struct nodeType *next;
}node;
void printpoly(node *);
void readPolynomial(node **);
void addPoly(node *,node*,node**);
void addNode(node **,float,int);
void main()
{
    node *poly1,*poly2,*poly3;
    int choice, element,after,before;
    poly1=poly2=poly3=NULL;
    printf("\nEnter first Polynomial");
    readPolynomial(&poly1);
    printf("\nEnter second Polynomial");
    readPolynomial(&poly2);
    addPoly(poly1,poly2,&poly3);
    printf("\nSum of two polynomial\n ");
    printpoly(poly1);
    printf("\nand\n");
    printpoly(poly2);
    printf("\nis\n");
    printpoly(poly3);
    getch();
}

void addNode(node **ptr,float coef,int powe)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->coeff=coef;
    temp->power=powe;
    if(*ptr==NULL)
    {
	temp->next=NULL;
	*ptr=temp;
    }
    else
    {
	temp->next=*ptr;
	*ptr=temp;
    }
}

void readPolynomial(node **ptr)
{
    int coeffe,power2;
    printf("\nEnter the terms\n");
    while(1)
    {
	printf("\nEnter degree of x ");
	scanf("%d",&power2);
	printf("\nEnter its coeffecient ");
	scanf("%d",&coeffe);
	addNode(ptr,coeffe,power2);
	printf("\nAny more nodes (Y/N)");
	if(toupper(getch())!='Y')
	break;
    }
}

void printpoly(node *ptr)
{
    if(ptr!=NULL)
    {
    printf("%dx^%d",ptr->coeff,ptr->power);
    for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
    {
	if(ptr->coeff>0)
	printf("+");
	if(ptr->power==0)
	printf("%d",ptr->coeff);
	else if(ptr->power==1)
	printf("%dx",ptr->coeff);
	else
	printf("%dx^%d",ptr->coeff,ptr->power);
    }
    }
}

void addPoly(node *ptr1,node *ptr2,node **ptr3)
{
    int powe;
    float coef;
    while((ptr1!=NULL)&&(ptr2!=NULL))
    {
	    if(ptr1->power>ptr2->power)
	    {
	        coef=ptr1->coeff;
	        powe=ptr1->power;
	        ptr1=ptr1->next;
	    }
	    else
	        if(ptr1->power<ptr2->power)
	        {
	        coef=ptr2->coeff;
	        powe=ptr2->power;
	        ptr2=ptr2->next;
	        }
	
            else
	        {
                coef=ptr1->coeff+ptr2->coeff;
	            powe=ptr1->power;
	            ptr1=ptr1->next;
	            ptr2=ptr2->next;

	        }


	        if(coef!=0)
	        addNode(ptr3,coef,powe);
    }
    
     if(ptr1==NULL)
        {
	    for(;ptr2!=NULL;ptr2=ptr2->next)
	    addNode(ptr3,ptr2->coeff,ptr2->power);
        }
     else
       if(ptr2==NULL)
        {
	    for(;ptr1!=NULL;ptr1=ptr1->next)
	    addNode(ptr3,ptr1->coeff,ptr1->power);
        }
}
