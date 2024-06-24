#include<stdio.h>
#define size 5
int top=-1;
int stack[size];
void push()
{
  int x;
  printf("enter data:");
  scanf("%d",&x);
  if(top==size-1)
  {
   printf("overflow");
  }
  else
  {
  top++;
  stack[top]=x;
  }
}
void pop()
{
int item;
 if(top==-1)
   printf("underflow");
 else
 {
   item=stack[top];
   printf("%d is popped element\n",item);
   top--;
   }
}
void peak()
{
printf("%d is peak element\n",stack[top]);
}
void display()
{
 int i;
 for(i=top;i>=0;i--)
 {
  printf("%d\t",stack[i]);
 }
}

void main()
{
 int d;
 printf("choose the operations 1:push,2:pop,3:peak,4:display ::");
 scanf("%d",&d);
 switch(d)
 {
  case 1:
  {
   push();
   push();
   push();
   //break;
  }
  case 2:
  {
   pop();
   //break;
  }
  case 3:
  {
   peak();
   //break;
  }
  case 4:
  {
   display();
   break;
  }
  default:
   printf("invalid operation");
  
 }
 
}
