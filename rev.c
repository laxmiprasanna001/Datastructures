#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*head=NULL;
struct node*createnode()
{
  struct node*nn,*temp;
  nn=(struct node*)malloc(sizeof(struct node));
  printf("enter data:");
  scanf("%d",&nn->data);
  nn->next=NULL;
  if(head==NULL)
  {
    head=nn;
    temp=nn;
  }
  else{
    temp->next=nn;
    temp=nn;
  }
}

void rev()
{
 struct node*prevnode=NULL,*currnode,*nextnode;
 currnode=nextnode=head;
 while(nextnode!=NULL)
 {
 nextnode=currnode->next;
 currnode->next=prevnode;
 prevnode=currnode;
 currnode=nextnode;
 }
 head=prevnode;
 
}
void print()
{
 struct node*temp;
 temp=head;
 while(temp!=NULL)
 {
  printf("%d\t",temp->data);
  temp=temp->next;
 }
}
void main()
{
 int n,i;
 struct node*nn;
 printf("enter no.of nodes:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  createnode();
 }
  print();
  printf("\n");
  rev();
 print();
}
