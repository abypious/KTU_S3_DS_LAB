#include<stdio.h> 
#include<conio.h> 
#include<malloc.h> 
typedef struct node
    { 
    int coeff;
    int exp;
    struct node*link;
    }
NODE; NODE

*poly1=NULL, *poly2=NULL, *poly=NULL; 

void create(NODE*);
void show(NODE*);
void polyadd(NODE*,NODE*,NODE*); 

void main()
{
clrscr();
printf("\n\t\tPROGRAM TO ADD TWO POLYNOMIALS\n"); 
printf("\t\t \n");
poly=(NODE*)malloc(sizeof(NODE)); 
poly1=(NODE*)malloc(sizeof(NODE)); 
poly2=(NODE*)malloc(sizeof(NODE)); 
printf("\n\t\tEnter 1st polynomial: "); create(poly1);
printf("\n\t\t1st polynomial is: "); show(poly1);
printf("\n\t\tEnter 2nd polynomial: "); create(poly2);
printf("\n\t\t2nd polynomial is:"); show(poly2); polyadd(poly1,poly2,poly);
printf("\n\t\tNew polynomial is:"); show(poly);
getch();
}

void create(NODE*ptr)
{ 
char c; printf("\n"); 

do
{ 
printf("\t\tEnter the Coefficient: ");
scanf("%d",&ptr->coeff); 
printf("\t\tEnter the Exponent value: "); 
scanf("%d",&ptr->exp);
ptr->link=(NODE*)malloc(sizeof(NODE));
ptr=ptr->link;
ptr->link=NULL;
printf("\t\tDo you want to continue(y/n) "); scanf(" %c",&c);
}
while(c=='y'||c=='Y');
}

void show(NODE*ptr)
{
printf("\n\t\ t"); while(ptr->link!=NULL)
{
if(ptr->exp==0) printf("%d",ptr->coeff); 
else
printf("%dX^%d+",ptr->coeff,ptr->exp);
ptr=ptr->link;
}
}

void polyadd(NODE*ptr1,NODE*ptr2,NODE*ptr)
{
while(ptr1->link!=NULL&&ptr2->link!=NULL)
{
if(ptr1->exp>ptr2->exp)
{
ptr->coeff=ptr1->coeff; 
ptr->exp=ptr1->exp; 
ptr1=ptr1->link;
ptr->link=(NODE*)malloc(sizeof(NODE)); 
ptr=ptr->link;
ptr->link=NULL;
}
else if(ptr1->exp<ptr2->exp)
{
ptr->coeff=ptr2->coeff; 
ptr->exp=ptr2->exp; 
ptr2=ptr2->link;
ptr->link=(NODE*)malloc(sizeof(NODE)); 
ptr=ptr->link; 
ptr->link=NULL;
}
else
{
ptr->coeff=ptr1->coeff+ptr2->coeff; 
ptr->exp=ptr1->exp;
ptr1=ptr1->link; 
ptr2=ptr2->link;
ptr->link=(NODE*)malloc(sizeof(NODE)); 
ptr=ptr->link;
ptr->link=NULL;
}
}
if(ptr1->link!=NULL)
{
while(ptr1->link!=NULL)
{
ptr->coeff=ptr1->coeff; 
ptr->exp=ptr1->exp; 
ptr1=ptr1->link;
ptr->link=(NODE*)malloc(sizeof(NODE)); 
ptr=ptr->link;
ptr->link=NULL;
}
}
else if(ptr2->link!=NULL)
 
{
while(ptr2->link != NULL)
{
ptr->coeff=ptr2->coeff; 
ptr->exp=ptr2->exp; 
ptr2=ptr2->link;
ptr->link=(NODE*)malloc(sizeof(NODE)); 
ptr=ptr->link;
ptr->link=NULL;
}
}
}