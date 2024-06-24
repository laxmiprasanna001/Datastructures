#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*head=NULL;
struct node*createnode(){
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
else
{
 temp->next=nn;
 temp=nn;
 
}
}
void search()
{
 int ele,flag=0;
 struct node*temp;
 printf("enter element be searched:");
 scanf("%d",&ele);
 temp=head;
 while(temp!=NULL)
 {
 if(temp->data==ele)
 {
   flag=1;
 }
 
    
   temp=temp->next;
 }
 if(flag==1)
   printf("element found");
 else
  printf("not found");
}
int main()
{
struct node*nn;
int i,n;
printf("enter no.of nodes:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 nn=createnode();
}
search();
}



