#include <stdio.h>
#include <stdlib.h> 
#include "linkedList.h"

node* FindNode(int position);

bool insert(int position, int value)
{
	node *prePt = head,*Pt;
	
	if(position==0)
	{
		if(size==0)
		{
			node *temp=(node*)malloc(sizeof(node));
			temp->value=value;		
			temp->next = NULL;	 		
			head =temp;			
		}		
		else {
    Pt = (node*)malloc(sizeof(node));
			Pt->value = value;
			Pt->next = head;
			head = Pt;
		}
		size++;
		return true;
	}
    else if(position<=size&&position>0){	
   Pt = (node*)malloc(sizeof(node));
		Pt->value = value;
		prePt = FindNode(position);	 
		Pt->next = prePt->next;
		prePt->next = Pt;	
		size++;
		return true;		
	}	
	else 
		return false;
}

int get(int position)
{
	node *Pt = head;
	int i = 0;
    while(i<position&&Pt!=NULL)
    {
    	Pt = Pt->next;
    	i++;
   	}
	return (Pt->value);
} 

node* FindNode(int position)
{
	node *Pt = head;
	int i = 0;
	while(i<position-1&&Pt!=NULL)
	{
		Pt = Pt->next;
		i++;
	}
	return Pt;
}
void clear()
{
	 node *temp;
  node *p;
   while (head!=NULL)//当还有头结点存在时
   {
      p=head;//头结点是待删除结点
      head=head->next;//先连
      free(p);//后断
   }
}

