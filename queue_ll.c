#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*rear=NULL;
struct node*front=NULL;
void enqueue()
{
 struct node*nn;
 nn=(struct node*)malloc(sizeof(struct node));
 int x;
 printf("enter data:");
 scanf("%d",&x);
 nn->data=x;
 nn->next=NULL;
 if(rear==0 && front==0)
   rear=front=nn;
 else 
 {
    rear->next=nn;
    rear=nn;
 }  
}
void dequeue()
{
 if(rear==0 && front==0)
  printf("underflow");
 else 
 {
  struct node*temp;
  temp=front;
  printf("popped element:%d\n",temp->data);
  front=front->next;
  free(temp);
 }
}
void peek()
{
 if(front==0 && rear==0)
   printf("underflow");
 else
   printf("peek:%d",front->data);
}
void display()
{
 struct node*temp;
 temp=front;
 while(temp!=0)
 {
  printf("%d\t",temp->data);
  temp=temp->next;
 }
}
void main()
{
 int n,i;
 printf("enter no.of nodes:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  enqueue();
 } 
 display();
 dequeue();
 display();
 peek();
}
