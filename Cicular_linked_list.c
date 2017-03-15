#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
//  int *p;
    struct node *prev;
    struct node *next;
};

struct linklist{
    int pos;
    int max_pos;
    struct node *nodadd;
};
void createnode(struct linklist *linklist1,struct linklist *first);

void delete(struct linklist *linklist1,struct linklist *first){
    int pos;
    int i;
    if(linklist1->nodadd->prev != NULL){
       linklist1->nodadd = linklist1->nodadd->prev;//inorder to prevent changes in showlist made for insert function
    }
    showlist(linklist1,first);
    printf("enter the element position to be deleted \n");
    scanf("%d",&pos);
    if(pos < linklist1->max_pos){
    //printf("the element being pointed is %d and pos is %d and max pos is %d\n", linklist1->nodadd->val,linklist1->pos,linklist1->max_pos);
    if(linklist1->max_pos == 2 && pos ==1){
        struct node *temp;
        temp = linklist1->nodadd;
        linklist1->nodadd = NULL;
        linklist1->pos = 0;
        linklist1->max_pos = 1;
        first->nodadd = NULL;
        //printf("first node is deleted %p %p\n",first,linklist1);
        free(temp);
        //printf("first node is deleted after temp\n");

    }
    else if(linklist1->max_pos == 3 && pos == 2){
        first->nodadd->next->next =NULL;
  first->nodadd->next->prev =NULL;
        struct node *temp;
        temp = first->nodadd->next;
        first->nodadd->next = NULL;
        first->nodadd->prev =NULL;
        free(temp);
        linklist1->nodadd = first->nodadd;
        linklist1->pos = 1;
        linklist1->max_pos = 2;
    }
    else if(linklist1->max_pos == 3 && pos == 1){
        first->nodadd = first->nodadd->next;
        first->nodadd->next->next =NULL;
        first->nodadd->next->prev =NULL;
        struct node *temp;
        temp = first->nodadd->next;
        first->nodadd->next = NULL;
        first->nodadd->prev =NULL;
        free(temp);
        linklist1->nodadd = first->nodadd;
        linklist1->pos = 1;
        linklist1->max_pos = 2;
    }
    else if(linklist1->pos == pos){
        linklist1->nodadd =linklist1->nodadd->prev;
        if(linklist1->pos != 1){
                linklist1->pos = linklist1->pos -1;
        }
        else if(pos == 1) {
                    linklist1->pos = linklist1->max_pos-2;
        }
        linklist1->max_pos = linklist1->max_pos-1;
        //printf("the element to be before deleted is %d and prev pos is %d\n", linklist1->nodadd->val,linklist1->pos);
        struct node *temp,*temp2;
        struct linklist *temp1 =(struct linklist *)malloc(sizeof(struct linklist));
        if(pos == 1){
                temp1->nodadd = linklist1->nodadd;
                first->nodadd = first->nodadd->next;
        }
        else {
                temp1->nodadd = first->nodadd;
                for(i = 1 ; i < pos-1; i++){
                        temp1->nodadd = temp1->nodadd->next;
                }
        }
        //printf("the element to be delated is %d and pos is %d\n",temp1->nodadd->next->val,pos);
        temp = temp1->nodadd->next;
        temp2 = temp1->nodadd;
        temp1->nodadd->next = temp1->nodadd->next->next;
        temp1->nodadd->next->prev = temp2;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
        //printf("the value of temp1 in delete %d and temp next is %d\n",temp1->nodadd->val,temp1->nodadd->next->val);
    }
    else{
        //struct linklist *temp1;
        //printf("first node is deleted in last else\n");
        struct node *temp,*temp2;
        struct linklist *temp1 =(struct linklist *)malloc(sizeof(struct linklist));
        if(pos == 1){
                //linklist1->nodadd = linklist1->nodadd->prev;
                temp1->nodadd = first->nodadd->prev;
                first->nodadd =first->nodadd->next;
                //printf("the value of last node in delete %d and first node is %d\n",first->nodadd->prev->val,first->nodadd->val);
                //linklist1->pos = linklist1->max_pos-2;
        }
        else {
                temp1->nodadd = first->nodadd;
                for(i = 1 ; i < pos-1; i++){
                    temp1->nodadd = temp1->nodadd->next;
                }
        }
        //printf("the element to be delated is %d and pos is %d\n",temp1->nodadd->next->val,pos);
        temp  = temp1->nodadd->next;
        temp2 = temp1->nodadd;
        temp1->nodadd->next = temp1->nodadd->next->next;
        temp1->nodadd->next->prev = temp2;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
        //printf("the value of temp1 in delete %d and temp next is %d\n",temp1->nodadd->val,temp1->nodadd->next->val);
        if(linklist1->pos == 1) {
                linklist1->pos = linklist1->max_pos -2;
        }
        if(linklist1->pos > pos){
                linklist1->pos = linklist1->pos-1;
        }

        linklist1->max_pos = linklist1->max_pos-1;
        //free(temp->nodadd->next);
    }
    if(first->nodadd !=NULL){
      if(linklist1->nodadd->prev!=NULL){
        linklist1->nodadd = linklist1->nodadd->prev;//function showlist balance this move
        //printf("First value is %d\n",first->nodadd->val);
       }
      //printf("first node is deleted this is before last few lines\n");
      showlist(linklist1,first);
    }
    else if(first->nodadd == NULL){
        printf("\nThe List is empty\n");
    }
        createnode(linklist1,first);
    }
    else{
 printf("\n Invalid positon plz reenter the position\n");
 if(linklist1->nodadd->next != NULL){
  linklist1->nodadd = linklist1->nodadd->next; 
 } 
 delete(linklist1,first);
    }
}
void createnode(struct linklist *linklist1,struct linklist *first){
    int num;
    int pos;
    int ch;
    printf("\npress 1 to delete ,2 to insert and 3 to exit \n");
    scanf("%d",&ch);
    switch(ch){
    case 1 :
        if(linklist1->nodadd == NULL){
            printf("Sorry no element in list \n");
            createnode(linklist1,first);
        }
 else
            delete(linklist1,first);
        break;
    case 2 :
        /*printf("%d\n",linklist1->pos);
        if(linklist1->nodadd != NULL)
            printf("%d\n",linklist1->nodadd->val);
        printf("%d\n",linklist1->max_pos);
        */
        printf("enter the number and position of num\n");
        scanf("%d %d",&num,&pos);
        if(pos > (linklist1->max_pos) || pos <=0){
            printf("invalid pos \n");
        }
        else if(pos == 1 && linklist1->nodadd == NULL){
            struct node *node1;
            node1 = (struct node*)malloc(sizeof(struct node));
            node1->val = num;
            node1->prev = NULL;
            node1->next = NULL;
            linklist1->pos =1;
            linklist1->max_pos = 2;
            linklist1->nodadd = node1;
            first->nodadd = node1;
        }
        else if(pos == 1 && linklist1->nodadd->next == NULL){
            struct node *node1;
            node1 = (struct node*)malloc(sizeof(struct node));
            node1->val = num;
            node1->next = linklist1->nodadd;
            node1->prev = linklist1->nodadd;
            linklist1->nodadd->next = node1;
            linklist1->nodadd->prev = node1;
            first->nodadd = node1;
            linklist1->pos = 2;
            linklist1->nodadd = node1;
            linklist1->max_pos = linklist1->max_pos+1;
        }
        else if(pos == 2 && linklist1->nodadd->next == NULL){
            struct node  *node1 = (struct node *)malloc(sizeof(struct node));
            node1->prev = linklist1->nodadd;
            node1->next = linklist1->nodadd;
            node1->val  = num;
            printf("the value in node is %d %d",node1->val,num);
            linklist1->nodadd->next = node1;
            linklist1->nodadd->prev = node1;
            linklist1->pos = 1;
            linklist1->max_pos = linklist1->max_pos +1;
            linklist1->nodadd = node1;
        }
        else{
            int traverse;
            int temp = linklist1->pos;
            //printf("\ntemp in create node causing warning is %d\n", temp);
            if(pos >= linklist1->pos){
                if(pos == linklist1->pos){
                    linklist1->nodadd = linklist1->nodadd->prev;
                    if(linklist1->pos !=1);
                        linklist1->pos = (linklist1->pos) - 1;
                }
                int traverse = pos - (linklist1->pos);
                while(traverse > 1){
                  linklist1->nodadd =linklist1->nodadd->next;
                  traverse = traverse -1;
                  linklist1->pos = (linklist1->pos)+1;
                }
                struct node  *node1 = (struct node *)malloc(sizeof(struct node));
                struct node  *temp  = linklist1->nodadd->next;
                linklist1->nodadd->next->prev = node1;//new line added test it once
                linklist1->nodadd->next = node1;
                node1->prev = linklist1->nodadd;
                node1->next = temp;
                node1->val  = num;
                if(pos == 1)
                  first->nodadd = node1;
                if(pos != temp->val)
                  linklist1->pos = (linklist1->pos)+1;
                linklist1->max_pos = linklist1->max_pos +1;
            }
     else{
                 int traverse = linklist1->pos - pos;
                 while(traverse > -1){
                     linklist1->nodadd = linklist1->nodadd->prev;
                     traverse = traverse -1;
                     if(linklist1->pos ==1)
                       linklist1->pos = linklist1->max_pos-1;
                     else
                       linklist1->pos = (linklist1->pos) - 1;
                 }
                struct node  *node1 = (struct node *)malloc(sizeof(struct node));
                struct node  *temp  = linklist1->nodadd->next;
                temp->prev = node1;
                linklist1->nodadd->next = node1;
                node1->prev = linklist1->nodadd;
                node1->next = temp;
                node1->val  = num;
                if(linklist1->pos == linklist1->max_pos -1){
                  linklist1->pos = 1;
                  first->nodadd = node1;
                }
                else{
                  linklist1->pos = (linklist1->pos)+1;
                }
                linklist1->max_pos = linklist1->max_pos +1;
           }
       }
       showlist(linklist1,first);
       createnode(linklist1,first);
       break;
    case 3 :
       exit(0);
    default :
        printf("invaid input\n");
        createnode(linklist1,first);
    }
}

void showlist(struct linklist *linklist1,struct linklist *first){
    if(first->nodadd != NULL){
    int i;
    struct linklist *temp=(struct linklist *)malloc(sizeof(struct linklist)) ;
    temp->nodadd = first->nodadd;
    printf("The list is as follows \n");
    //printf("element at pos first is%d\n",first->nodadd->val);
    //printf("temp val in showlist is %d and linkist1 val is: %d\n",temp->nodadd->val , linklist1->nodadd->val);
    for(i =1; i <=(linklist1->max_pos);i++){
        if(i < linklist1->max_pos){
            printf(" the val is :%d and position is : %d \n", temp->nodadd->val,i);
            if(temp->nodadd->next != NULL)
                temp->nodadd = temp->nodadd->next;
        }
        if(linklist1->nodadd->next!=NULL)  //after insertion of new element to make t point at same element
            linklist1->nodadd = linklist1->nodadd->next;
    }
    //printf("\nin showlist last the element being pointed is %d and pos is %d and first is %d\n",linklist1->nodadd->val , linklist1->pos,first->nodadd->val);
}
}
void main(){
    int val;
    int num;
    int i;
    struct linklist *linklist1;
    linklist1 = (struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *first = (struct linklist *)malloc(sizeof(struct linklist));
    linklist1->pos = 0;
    linklist1->max_pos =1;
    linklist1->nodadd = NULL;
//    printf("enter 1 to insert\n");
//    scanf("%d",&val);
    printf("%d\n",linklist1->pos);
            //showlist(linklist1);
            createnode(linklist1,first);
/*          case 2:
            showlist();
            printf("enter the num pos to be deleated");
            scanf("%d",&pos);
            deletenode(pos);
        */
}
