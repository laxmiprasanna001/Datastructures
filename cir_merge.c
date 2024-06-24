#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*head1=NULL,*head2=NULL,*temp1,*temp2;
struct node*createnode_1()
{
  struct node*nn;
  nn=(struct node*)malloc(sizeof(struct node));
  printf("enter data:");
  scanf("%d",&nn->data);
  if(head1==NULL)
  {
   head1=temp1=nn;
   temp1->next=head1;
  }
  else
  {
   temp1->next=nn;
   temp1=nn;
   temp1->next=head1;
  }
}
struct node*createnode_2()
{
  struct node*nn;
  nn=(struct node*)malloc(sizeof(struct node));
  printf("enter data:");
  scanf("%d",&nn->data);
  if(head2==NULL)
  {
   head2=temp2=nn;
   temp2->next=head2;
  }
  else
  {
   temp2->next=nn;
   temp2=nn;
   temp2->next=head2;
  }
}
void merge()
{
  temp1->next=head2;
  temp2->next=head1;
}
void display()
{
 struct node*temp1;
 temp1=head1;
 do
 {
   printf("%d\t",temp1->data);
   temp1=temp1->next;
 }while(temp1!=head1);
}
void main()
{
 int n,i;
 printf("enter no.of nodes:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
   createnode_1();
 }
 int m,j;
 printf("enter no.of nodes:");
 scanf("%d",&m);
 for(j=1;j<=m;j++)
 {
  createnode_2();
 }
 merge();
 display();
}

