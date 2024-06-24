#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*head=NULL,*temp=NULL;
struct node*newnode()
{
 struct node*nn;
nn=(struct node*)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&nn->data);
nn->next=NULL;
return nn;
}
struct node*createnode()
{
 struct node*nn;
  nn=(struct node*)malloc(sizeof(struct node));
  printf("enter data:");
  scanf("%d",&nn->data);
  if(head==NULL)
  {
   head=temp=nn;
   temp->next=head;
  }
  else
  {
   temp->next=nn;
   temp=nn;
   temp->next=head;
  }

}

struct node*ins_head()
{
struct node*nn;
 nn=newnode();
 nn->next=head;
 head=nn;
 temp->next=head;
}
struct node*ins_tail()
{
 struct node*nn;
 nn=newnode();
 temp->next=nn;
 nn->next=head;
}
void ins_pos()
{
struct node*nn,*ptr;
 nn=newnode();
 ptr=head;
 int c=0,i;
 ptr=head;
 do
 {
   c++;
   ptr=ptr->next;
 }while(ptr !=head);
 int pos;
 printf("enter position:");
 scanf("%d",&pos);
 if(pos==1)
 {
   nn->next=head;
   head=nn;
   temp->next=head;
 }
 else if(pos<1 || pos>=c+2)
 {
  printf("invalid position");
 }
 else if(pos==c+1)
 {
   temp->next=nn;
   temp=nn;
   temp->next=head;
 }
 else
 {
   for(i=1;i<=pos-1;i++)
   {
    temp=temp->next;
   }
   nn->next=temp->next;
   temp->next=nn;
 }
}

void del_head()
{
 struct node*ptr;
 ptr=head;
 head=head->next;
 free(ptr);
 temp->next=head;
}
void del_tail()
{
 struct node*ptr;
  ptr=head;
  while(ptr->next->next!=head)
  {
  ptr=ptr->next;
  }
  free(ptr->next);
  ptr->next=head;
}
void del_pos()
{
struct node*ptr,*temp1;
 ptr=head;
 int c=0;
 do
 {
 
  ptr=ptr->next;
  c++;
 }while(ptr!=head);
 int pos,i;
 ptr=head;
 printf("%d",c);
 printf("enter position:");
 
 scanf("%d",&pos);
 if(pos<1 || pos>c)
 {
   printf("invalid position");
 }
 else if(pos==1)
 {
  head=head->next;
  temp->next=head;
  free(ptr);
 }
 else if(pos==c)
 {
  while(ptr->next->next!=head)
 {
  ptr=ptr->next;
 }
 free(ptr->next);
 ptr->next=head;
 }
 else
 {
 ptr=head;
 temp1=head;
  for(i=1;i<pos-1;i++)
  {
   ptr=ptr->next;
   temp1=temp1->next;
  }
    temp1=temp1->next;
    ptr->next=ptr->next->next;
    free(temp1);
 }
}
void display()
{
 struct node*temp;
 temp=head;
 do
 {
   printf("%d\t",temp->data);
   temp=temp->next;
 }while(temp!=head);
 
}
void main()
{
 int n,i,a;
 printf("enter no.of nodes:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 createnode();
 }
 printf("enter required operation::'1.creation and traversal,2.insert_head,3.insert_tail,4.insert_pos,5.del_head,6.del_tail,7.del_pos'");
 scanf("%d",&a);
 switch(a)
 {
 case 1:
 {
 printf("creation and traversal\n");
 display();
 printf("\n");
 break;
 }
 case 2:
 {
 printf("insertion at head\n");
 ins_head();
 display();
 printf("\n");
 break;
 }
 case 3:
 {
 printf("insertion at tail\n");
 ins_tail();
 display();
 printf("\n");
 break;
 }
 case 4:
 {
 printf("insertion at pos\n");
 ins_pos();
 display();
 printf("\n");
 break;
 }
 case 5:
 {
 printf("deletion at head\n");
 del_head();
 display();
 printf("\n");
 break;
 }
 case 6:
 {
 printf("deletion at tail\n");
 del_tail();
 display();
 printf("\n");
 break;
 }
 case 7:
 {
 printf("deletion at pos\n");
 del_pos();
 display();
 printf("\n");
 break;
 }
 default:
   printf("invalid input");
 }
}

