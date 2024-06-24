#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*top=NULL;
void push()
{
 struct node*nn;
 nn=(struct node*)malloc(sizeof(struct node));
 printf("enter data:");
 scanf("%d",&nn->data);
 nn->next=top;
 top=nn;
}
void display()
{
 struct node*temp;
 temp=top;
 if(top==NULL)
 {
  printf("stack is empty");
 }
 else
  
  {
   while(temp!=NULL)
   {
   printf("%d\t",temp->data);
   temp=temp->next;
  }
  }
}
void pop()
{
 struct node*temp;
 temp=top;
 if(top==NULL)
 {
  printf("stack is empty");
 }
 else
 {
  printf("popped element:%d\n",top->data);
  top=top->next;
  free(temp);
 }
 
}
void peak()
{
 if(top==0)
   printf("stack is empty");
 else
  printf("peak element:%d\n",top->data);
}
void main()
{
 push();
 push();
 push();
 printf("before pop:");
 display();
 pop();
 peak();
 display();
}

