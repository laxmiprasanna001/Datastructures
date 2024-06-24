#include<stdio.h>
#define s 20
int queue[s];
int front=-1;
int rear=-1;
void enqueue()
{
int x;
printf("enter data:");
scanf("%d",&x);
if(rear==-1 && front==-1)
{
 front=rear=0;
 queue[rear]=x;
}
else if(((rear+1)%s)==front)
  printf("queue is full");
else 
{
 rear=(rear+1)%s;
 queue[rear]=x;
}
}
void dequeue()
{
 if(front==-1 && rear==-1)
   printf("underflow");
 else if(rear==front)
   front=rear=-1;
 else
  front=(front+1)%s;
}
void display()
{
int i=front;
 if(rear==-1 && front==-1)
   printf("empty");
 else
 {
  while(i!=rear)
  {
  
   printf("%d ",queue[i]);
   i=(i+1)%s;
  }
    printf("%d",queue[rear]);
    printf("\n");
 }
}
void peek()
{
 if(rear==-1 && front==-1)
   printf("empty");
 else
   printf("%d",queue[front]);
}
void main()
{
 int n,i;
 printf("no.of values:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  enqueue();
 display();
 dequeue();
 display();
 peek();
}
















