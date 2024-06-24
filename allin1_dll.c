#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*prev;
struct node*next;
};
struct node*head=NULL;
struct node*newnode()
{
 struct node*nn;
 nn=(struct node*)malloc(sizeof(struct node));
 printf("enter data:");
 scanf("%d",&nn->data);
 nn->next=nn->prev=NULL;
 return nn;
}
struct node*createnode()
{
 struct node*nn,*temp;
 nn=newnode();
 if(head==NULL)
   head=temp=nn;
 else
 {
  temp->next=nn;
  nn->prev=temp;
  temp=nn;
 }
}

struct node*ins_head(){
struct node*nn;
 nn=newnode();
 if(head==NULL)
   head=nn;
 else
 {
  nn->next=head;
  head->prev=nn;
  head=nn;
 }
}
struct node*ins_tail()
{
 struct node*nn,*temp=head;
 nn=newnode();
 while(temp->next!=0)
   temp=temp->next;
 temp->next=nn;
 nn->prev=temp;
 temp=nn;
}
void ins_pos()
{
int c=0,pos,i;
printf("enter poistion:");
scanf("%d",&pos);
struct node*temp,*nn;;
temp=head;
while(temp!=NULL)
{
 c++;
 temp=temp->next;
}
printf("length:%d\n",c);
nn=newnode();
if(pos<1 || pos>c+1)
  printf("invalid position\n");
else if(pos==1)
{
  nn->next=head;
  head->prev=nn;
  head=nn;
}
else if(pos==c+1)
{
 temp=head;
 while(temp->next!=NULL)
 {
  temp=temp->next;
 }
   temp->next=nn;
   nn->prev=temp;
   temp=nn;
}
else
{
temp=head;
 for(i=1;i<pos-1;i++)
 {
 temp=temp->next;
 }
    nn->prev=temp;
    nn->next=temp->next;
    temp->next->prev=nn;
    temp->next=nn;
}
}
void del_head()
{
 struct node*temp;
temp=head;

 head=temp->next;
 temp->next->prev=NULL;
 free(temp);
}
void del_tail()
{
 struct node*temp;
 temp=head;
 while(temp->next!=NULL)
 {
  temp=temp->next;
 }
 temp->prev->next=NULL;
 free(temp);
}
void del_pos()
{
struct node*temp;
temp=head;
 int pos,i,c=0;
 printf("enter position:");
 scanf("%d",&pos);
 while(temp!=NULL)
 {
 struct node*temp;
 temp=head;
 while(temp!=NULL)
 {
 
  temp=temp->next;
 }
 if(pos==1)
 {
  head=head->next;
  head->prev=NULL;
  free(temp);
 }
 else if(pos<1 || pos>c)
  printf("invalid position");
 else if(pos==c)
 {
 while(temp->next!=NULL)
  temp=temp->next;
 temp->prev->next=NULL;
 free(temp);
 }
 else{
 for(i=1;i<pos;i++)
 {
 temp=temp->next;
 }
 temp->prev->next=temp->next;
 temp->next->prev=temp->prev;
 free(temp);
 }
 }
}
void display()
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

