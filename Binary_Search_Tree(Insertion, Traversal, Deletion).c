  //Binary Search Tree(Insertion,traversal,deletion)- Input the names of cities and insert them in to tree.
  //Traverse the tree and also delete elements from the tree.

  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>

  struct node{
   char city[20];
   struct node *left;
   struct node *right;
   struct node *parent;
  };


  void display(struct node *);
  struct node * delete(struct node *root,char del[20]); 

  struct node * insert(char city[20],struct node *root){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   struct node *prev = (struct node *)malloc(sizeof(struct node));
   struct node *new = (struct node *)malloc(sizeof(struct node));
   strcpy(new->city,city);
   new->left = NULL;
   new->right = NULL;
   if(root->parent == NULL){
                          //printf("inside root if\n");
    root = new;
    new->parent = root;
  }
  else{
   int right=0;
   int left =0;
   temp = root;
   while(temp != NULL ){
     prev = temp;
     left = 0;
     right = 0;
     if(strcmp(temp->city,new->city) < 0){
      //printf("insertion in right\n");
      temp = temp->right;       
      right = 1;
    }
    else{
      //printf("insertion in left\n");
      temp = temp->left;
      left = 1;
    }   
  }
  if(right == 1){ 
    //printf("inside right\n");
    //printf("parent %s \n",prev->city);
    prev->right = new;
    new->parent = prev;
    right =0;
    left = 0;
  }
  if(left == 1){
    //printf("inside left\n");
    //printf("parent %s \n",prev->city);
    prev->left = new;
    new->parent = prev;
    right =0;
    left =0;
  }
  }
  return root;
  }

  void display(struct node *current){
   if(current !=NULL){
    display(current->left);
    printf("%s \n",current->city);
    display(current->right);
  }
  }

  void main(){
   char city[20];
   struct node *root = (struct node *)malloc(sizeof(struct node));
   root->left = NULL;
   root->right = NULL;
   root->parent = NULL;
   int i;
   int num;
   char del[20];
   int ch=0;
   while(1){
     printf("press 1 to insert,2 to delete and 3 to exit\n");
     scanf("%d",&ch);
     switch(ch){
       case 1 : 
       printf("Enter the number of elements you wana insert in tree \n");
       scanf("%d",&num);
       for(i=0;i<num;i++){
         printf("Enter the name of the city\n"); 
         scanf("%s",city);
         root = insert( city , root);
     //printf("root city is %s\n",root->city);
       }
       printf("the list is as follows\n");
       display(root);
       break;
       case 2 :
       printf("enter the number of elements you wana delete\n");
       scanf("%d",&num);
       for(i=0;i<num;i++){
         printf("Enter the city to be deleated \n");
         scanf("%s",del);
         root = delete( root , del);
         printf("the list is as follows\n");   
         display(root);
       }
       break;
       case 3 :
       exit(0);
       break;
       default :
       printf("invalid input\n");  
       break;
     }
   }
  }


  struct node * delete(struct node *root,char del[20]){
   int flag;
   int right = 0;
   int left = 0 ;
   int rt =0;
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp = root;
   struct node *prev =(struct node *)malloc(sizeof(struct node));
   struct node *temp2 =(struct node *)malloc(sizeof(struct node));
   while(temp != NULL){
   //printf("current city to be compared is %s\n",temp->city);
   //printf("left child is left %s and right child is %s and parent is %s\n",temp->left->city,temp->right->city,temp->parent->city);
    if(strcmp(temp->city,del) == 0){
     //printf("the city to be deleated is %s right value= %d left value = %d\n",temp->city,right,left);
     if(temp == root){
      rt = 1;
    }
    if(temp->right == NULL && temp->left == NULL && (right ==1 || rt == 1)){
      if(rt == 1){
       printf("tree is empty \n");
       rt = 0;
       temp->parent = NULL;
       free(temp);
     }
     else{
       //printf("the node has no child and is the right child\n");
       temp->parent->right = NULL;  
       temp->parent = NULL;
       right = 0;
       left  = 0;
       free(temp);
     }
   }
   else if(temp->right == NULL && temp->left == NULL && (left == 1 || rt==1)){
    if(rt == 1){
     printf("TREE IS EMPTY\n");
     rt = 0;
     temp->parent = NULL;
     free(temp);
   }
   else{    
       //printf("the node has no child and is the left child\n");
     temp->parent->left = NULL;
     temp->parent = NULL;
     right = 0;
     left = 0;
     free(temp);
   }
  }
  else if(temp->right == NULL && (left == 1 || rt == 1)){
      //printf("the node has left child and is left child to its parent\n");
    if(rt == 1){
     root =root->left;
     root->parent = root;
     temp->left = NULL;
     temp->right = NULL;
     rt = 0;
     free(temp);   
   }
   else{
       //printf("the parent of node to be deleted is %s\n",temp->parent->city);
     temp->parent->left = temp->left;
       //printf("new left child of parent is %s\n",temp->parent->left->city);
       //printf("original parent of left child is %s\n",temp->left->parent->city);
     temp->left->parent = temp->parent;
       //printf("the new parent is %s\n",temp->left->parent->city);
     temp->left = NULL;
     temp->parent = NULL;
     left = 0;
     right = 0;
     free(temp);
   }
  }
  else if(temp->right == NULL && (right == 1 || rt == 1)){
    printf("the node has left child and is right child to its parent\n");
    if(rt == 1){
     root = root->left;
     root->parent = root;
     temp->left = NULL;
     temp->parent = NULL;
     rt =0;
     free(temp);
   }
   else{
       //printf("the parent of node to be deleted is %s\n",temp->parent->city);
     temp->parent->right = temp->left;
       //printf("new right child of parent is %s\n",temp->parent->right->city);
     temp->left->parent = temp->parent;
     temp->left = NULL;
     temp->parent = NULL;
     left =0;
     right =0;
     free(temp);
   }
  }
  else if(temp->left == NULL && (right ==1 || rt == 1)){
      //printf("the node has right child and itself is a right child\n");
    if(rt == 1){
     root = root->right;
     root->parent = root;
     temp->left = NULL;
     temp->parent = NULL;
     rt = 0;
     free(temp);
   }
   else{
     temp->parent->right = temp->right;
     temp->right->parent = temp->parent;
     temp->right = NULL;
     temp->parent =NULL;
     left = 0;
     right = 0;
     free(temp); 
   }
  }
  else if(temp->left == NULL && (left == 1 || rt == 1)){
      //printf("the node has right child and itself is left child\n");
    if(rt == 1){
     root = root->right;
     root->parent = root;
     temp->left = NULL;
     temp->parent = NULL;
     rt = 0;
     free(temp);
   }
   else{
     temp->parent->left = temp->right;
     temp->right->parent = temp->parent;
     temp->right = NULL;
     temp->parent = NULL;
     left = 0;
     right = 0;
     free(temp);
   }
  }
  else{
      //printf("the city to be delated has both left and right child\n");
    prev = temp;
    temp = temp->right;
    printf("the right child of city to be deleated is %s\n",temp->city);
    if(temp->left == NULL && (left == 1 || rt == 1)){
     if(rt == 1 ){
      root = root->right;
      root->parent = root;
      root->left  = prev->left;
      prev->left->parent = root;
      prev->left = NULL;
      prev->right = NULL;
      prev->parent = NULL;
      rt = 0;
      free(prev);
    }
    else{
      prev->parent->left =prev->right;
      prev->right->parent = prev->parent;
      prev->left->parent = prev->right;
      prev->right->left = prev->left;
      prev->parent =NULL;
      prev->left = NULL;
      prev->right =  NULL;
      right = 0;
      left = 0;
      free(prev);  
    } 
    break;         
  }
  if(temp->left == NULL && right == 1){   
       //printf("the child of city to be deleated has no left child and itself is a right child\n");
    prev->parent->right =prev->right;
    prev->right->parent = prev->parent;
    prev->left->parent = prev->right;
    prev->right->left = prev->left;
    prev->parent =NULL;
    prev->left = NULL;
    prev->right =  NULL;
    right = 0;
    left = 0;
    free(prev);
    break;
  }                                                           
  else{
   temp = temp->left;
  }
      //printf("before while left child been pionted is %s  and its left child is %s\n",temp->city,temp->left->city);
  while(temp->left != NULL){
   temp = temp->left;
  }
      //printf("the child to be replaced with the child to be deleated is %s\n",temp->city);
  if(temp->right == NULL && (left == 1 ||rt == 1)){
       //printf("the child has no further child and is in the left subtree of del child\n");
   if(rt == 1){
    root = temp;
    rt = 0 ;
    temp->parent->left = NULL;
    temp->left = prev->left;
    temp->right = prev->right;
    temp->parent = root;
    prev->left->parent = root;
    prev->right->parent = root;
    prev->left = NULL;
    prev->right = NULL;
    prev->parent = NULL;
    left = 0;
    right = 0;
    free(prev);
    
  }
  else{
    temp->parent = prev->parent;
    temp->parent->left = NULL;
    temp->left = prev->left;
    temp->right = prev->right;
    temp->parent = prev->parent;
    prev->left->parent = temp;
    prev->right->parent = temp;
    prev->parent->left = temp;
    prev->left = NULL;
    prev->right = NULL;
    prev->parent = NULL;
    left = 0;
    right = 0;
    free(prev);
  }
  }
  else if(temp->right == NULL && right == 1){
       //printf("no further children of the child and it is in left right\n ");
   temp->parent->left = NULL;
   temp->left = prev->left;
   temp->right = prev->right;
   temp->parent = prev->parent;
   prev->left->parent = temp;
   prev->right->parent = temp;
   prev->parent->right = temp;
   prev->left = NULL;
   prev->right = NULL;
   prev->parent = NULL;
   left = 0;
   right = 0;
   free(prev);
  }       
  else if(temp->right != NULL && (right == 1 || rt == 1)){
       //printf("the child has further a right child and is in right subtree of del\n");
   if(rt == 1){
    root  = temp;
    rt = 0; 
    temp->parent->left = temp->right;
    temp->right->parent = temp->parent;
    temp->left = prev->left;
    temp->right = prev->right;
    temp->parent = root;
    prev->left->parent = root;
    prev->right->parent = root;
    prev->left = NULL;
    prev->right = NULL;
    prev->parent = NULL;
    left = 0;
    right = 0;
    free(prev);
  }
  else{
    temp->parent->left = temp->right;
    temp->right->parent = temp->parent;
    temp->left = prev->left;
    temp->right = prev->right;
    temp->parent = prev->parent;
    prev->left->parent = temp;
    prev->right->parent = temp;
    prev->parent->right = temp;
    prev->left = NULL;
    prev->right = NULL;
    prev->parent = NULL;
    left = 0;
    right = 0;
    free(prev);
  } 
  }
  else if(temp->right != NULL && left == 1){
                                          //printf("the child has further children and is in left subtree of del\n");
   temp->parent->left = temp->right;
   temp->right->parent = temp->parent;
   temp->left = prev->left;
   temp->right = prev->right;
   temp->parent = prev->parent;
   prev->left->parent = temp;
   prev->right->parent = temp;
   prev->parent->left = temp;
   prev->left = NULL;
   prev->right = NULL;
   prev->parent = NULL;
   left = 0;
   right = 0;
   free(prev);
  }
  }
  return root;
  }  
  else{
   if(strcmp(temp->city,del)>0){
    temp = temp->left;
    left = 1;
    right = 0;
    rt  = 0;
  }
  else if(strcmp(temp->city,del)<0){
    temp = temp->right;
    right =1;
    left = 0;
    rt = 0;    
  }
  }

  }
  return root;
  }
