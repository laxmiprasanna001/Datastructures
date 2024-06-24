#include<stdlib.h>
#include<stdio.h>
struct node{
int data;
struct node*next;
};
struct node*rear=0;
struct node*front=0;
void enqueue()
{
 int x;
 printf("enter data:");
 scanf("%d",&x);
 struct node*nn;
 nn=(struct node*)malloc(sizeof(struct node));
 nn->data=x;
 nn->next=NULL;
 if(rear==0 && front==0)
 {
  rear=front=nn;
  rear->next=front;
 }
 else
 {
  rear->next=nn;
  rear=nn;
  rear->next=front;
 }
}
void dequeue()
{
 struct node*temp;
 temp=front;
 if(rear==0 && front==0)
 {
  printf("underflow");
 }
 else{
 front=front->next;
 rear->next=front;
 }
}
void display()
{
 struct node*temp;
 temp=front;
 if(rear==0 && front==0)
 {
  printf("underflow");
 }
 else
 {
  while(temp->next!=front)
  {
   printf("%d\t",temp->data);
   temp=temp->next;
  }
  printf("%d",temp->data);
 }
}
void peek()
{
 if(rear==0 && front==0)
  printf("empty");
 else
  printf("peek:%d",front->data);
}
void main()
{
 int n,i;
 printf("enter no.of pushes:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  enqueue();
 }
 dequeue();
 display();
 peek();
}
