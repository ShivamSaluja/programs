programs
========

Programs in c
Palindrome Using 3 stacks(Stacks implemented using Linked List)

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
}*top1,*top2,*top3;

void push(struct node **top,int val)
{
    struct node *n1 =(struct node *)malloc(sizeof(struct node));   
    n1->val= val;   
    if(*top == NULL)
    {
        *top = n1;
        n1->next = NULL;
    }
    else
    {
        n1->next = *top;
        *top = n1;
    }   
}
int pop(struct node **top)
{
    int a;   
    struct node *save = *top;   
    *top = (*top)->next;   
    a = save->val;   
    free(save);
    return a;
       
}

void main()
{
    int num;
    int flag = 0;
    int digit,val,val1,val2;
    printf("Enter number");
    scanf("%d",&num);
    while(num != 0)
    {
        digit = num%10;
        num =num/10;
        push(&top1,digit);
        push(&top2,digit);   
    }
    while(top2 != NULL)
    {
         val = pop(&top2);
        push(&top3,val);
    }
    while(top3 != NULL)
    {
        val1= pop(&top3);
        printf("val 1 is %d\n",val1);       
        val2=pop(&top1);
        printf("val 2 is %d\n",val2);
             if(val1!=val2)
        flag = 1;               
    }   
    if(flag==1)
    printf("not palidrom\n");   
    else
    printf("palidrom\n");   
       
}
