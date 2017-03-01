//
//  main.cpp
//  20161215_链表
//
//  Created by jinyu on 2016/12/25.
//  Copyright © 2016年 jinyu. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    char name[20];
    long num;
    struct student *next;
}STU;

STU * creat(STU *head)
{
    STU *newnode;
    STU *p;
    newnode=(STU *)malloc(sizeof(STU));
    scanf("%s %ld",newnode->name,&newnode->num);
    p=head=newnode;
    newnode=(STU *)malloc(sizeof(STU));
    while(scanf("%s %ld",newnode->name,&newnode->num)!=EOF)
    {
        p->next=newnode;
        p=p->next;
        newnode=(STU *)malloc(sizeof(STU));
        
    }
    p->next=NULL;
    return head;
}

STU *insert(STU *head,STU *node)
{
    STU *p=head;
    STU *perp=p;
    if(head==NULL||node==NULL)
        return head;
    while(p->next)
    {
        
        if(p->num<node->num)
        {
            perp=p;
            p=p->next;
        }
        else if(p->num==node->num)
        {
            printf("%s already exist!\n",node->name);
            return head;
        }
        else
            break;
        
    }
    if(perp==head)
    {
        node->next=p;
        head=node;
    }
    else
    {
        node->next=perp->next;
        perp->next=node;
    }
    return head;
}
/*
 
STU *sort(STU *head,int i)
{
    STU st[i+1];
    STU *p=head;
    
    int j,k;
    for(j=0;j<i+1;j++)
    {
        st[j]=*p;
        p=p->next;
    }
    STU t;
    for(j=0;j<i;j++)
        for(k=0;k<i-j;k++)
        {
            if(st[k].num>st[k+1].num)
            {
                t=st[k];
                st[k]=st[k+1];
                st[k+1]=t;
            }
        }
    p=st;
    return p;

}
 */
int main()
{
    
    STU *head=NULL,*p;
    head=creat(head);
    if(head==NULL)
        return 1;
    p=head;
    int i=0;
    while(p)
    {
        printf("%s %ld\n",p->name,p->num);
        p=p->next;
        i++;
    }
   // head=sort(head,i);
    STU *node;
    scanf("%s %ld",node->name,&node->num);
    head=insert(head, node);
    p=head;
    while(p)
    {
        printf("%s %ld\n",p->name,p->num);
        p=p->next;
    }
    return 0;
    
}






































