#include<stdio.h>
#include<stdlib.h>
#define s 10
int queue[s];
int front=-1;
int rear=-1;
void enqueue()
{
int x;
printf("enter data:");
scanf("%d",&x);
if(rear==s-1)
 printf("overflow");
else if(front==-1 && rear==-1)
{
  front=rear=0;
  queue[rear]=x;
}
else
{
 rear++;
 queue[rear]=x;
}
}
void dequeue()
{
 if(front==-1 && rear==-1)
  printf("underflow");
 else if(front==rear)
   front=rear=-1;
 else 
 {printf("\npopped element:%d\n",queue[front]);
  front++; 
 } 
}
void peek()
{
if(front==-1 && rear==-1)
  printf("underflow");
else
  printf("peek element:%d\t",queue[front]);
}
void display()
{
 if(front==-1 && rear==-1)
   printf("underflow");
 else
 {
  for(int i=front;i<=rear;i++)
   printf("%d\t",queue[i]);
 }
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
 display();
 dequeue();
 
 display();
peek();
}
