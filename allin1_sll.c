
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*head=NULL;
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
 struct node*nn,*temp;
 nn=newnode();
 if(head==NULL)
   head=temp=nn;
 else
 {
  temp->next=nn;
  temp=nn;
 }
}

struct node*ins_head(){
struct node* nn;
nn=newnode();

if(head==NULL)
{
 head=nn;
}
else{
 nn->next=head;
 head=nn;
}
}
struct node*ins_tail()
{
 struct node*nn,*ptr=head;
 nn=newnode();
  while(ptr->next!=NULL)
  {
  ptr=ptr->next;
  }
  ptr->next=nn;
}
void ins_pos()
{
struct node*nn,*temp;
int c=0,pos;
printf("enter the position:");
scanf("%d",&pos);
nn=newnode();
temp=head;
while(temp!=0)
{
 temp=temp->next;
 c++;
}
if(pos==1)
{
 nn->next=head;
 head=nn;
}
else if(pos<=c+1)
{
temp=head;
 for(c=1;c<pos-1 && temp!=NULL;c++)
 {
  temp=temp->next;
 }
 nn->next=temp->next;
 temp->next=nn;
}
else
{
 printf("invalid positoin");
}

}
void del_head()
{
 struct node*temp;
 temp=head;
 if(head==NULL)
   printf("list is empty");
 else
 {
 head=head->next;
 free(temp);
 }
}
void del_tail()
{
 struct node*temp;
 temp=head;
 if(head==NULL)
   printf("list is empty");
 else
 {
 while(temp->next->next!=NULL)
 {
 temp=temp->next;
 }
 free(temp->next);
 temp->next=NULL;
}
}
void del_pos()
{
struct node*nn,*ptr,*temp;
int c=0,pos;
printf("enter the position:");
scanf("%d",&pos);
temp=head;
while(temp!=0)
{
 temp=temp->next;
 c++;
}
 ptr=temp=head;
if(pos>c || pos<0)
{
 printf("invalid position");
}
else if(pos==1)
{
 head=head->next;
 free(temp);
}
else
{
 for(c=1;c<pos-1 && temp!=NULL;c++)
 {
  temp=temp->next;
 }
 ptr=temp->next;
 temp->next=ptr->next;
 free(ptr);
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
 int t;
 do{
 printf("enter required operation:'1.traversal,2.insert at head,3.insert at tail,4.insert at pos,5.del at head,6.del at tail,7.del at pos'");
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
   printf("invalid input\n");
 }
 printf("enter 1 to continue, 0 to exit");
 scanf("%d",&t);
 }while(t);
}

