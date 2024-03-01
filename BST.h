// An integer binary search tree

struct TreeNode {         
   int data; // node value                                  
   struct TreeNode *leftPtr; // pointer to left subtree
   struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode *TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes
void insertNode( BST *, int );


void insertNode_R(TreeNodePtr *t, int value){
   if(*t == NULL){
      *t = (TreeNodePtr) malloc(sizeof(struct TreeNode));
	   if(*t){
	      (*t)->leftPtr = NULL;
		   (*t)->rightPtr = NULL;
		   (*t)->data = value;
      }
      else printf("ERROR ON MALLOC!!!\n");
   }

   else{
     if((*t)->data>=value) insertNode_R(&(*t)->leftPtr, value);
     else insertNode_R(&(*t)->rightPtr, value);
   }
}


void insertNode( BST *b, int value ){
	TreeNodePtr t = b->root, new_node;
	int inserted = 0;

	new_node = (TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr = NULL;
		new_node->rightPtr = NULL;
		new_node->data = value;

		/*First Node*/
		if(b->size == 0) b->root = new_node;

		else{
         while(!inserted){
            if(t->data >= value){
               if(t->leftPtr != NULL) t = t->leftPtr;
               else{
                  t->leftPtr = new_node;
                  inserted = 1;
               } 
               /* move/insert to the left*/
            }

            else{
               if(t->rightPtr != NULL) t = t->rightPtr;
               else{
                  t->rightPtr = new_node;
                  inserted = 1;
               } 
	            /* move/insert to the right*/
            }

         }//end while		
      }//end else;
   b->size++;
   }
   else printf("ERROR ON MALLOC!!!\n");
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder(treePtr->leftPtr); //Recursion to the left
 
      printf("%3d", treePtr->data);  //print the value 
   
      inOrder(treePtr->rightPtr); //Recursion to the right
   } // end if                          
} // end 

void preOrder( TreeNodePtr treePtr )
{
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        

      printf("%3d", treePtr->data);  //print the value 

      preOrder(treePtr->leftPtr); //Recursion to the left
   
      preOrder(treePtr->rightPtr); //Recursion to the right
   } // end if 
}

void postOrder( TreeNodePtr treePtr )
{
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        

      postOrder(treePtr->leftPtr); //Recursion to the left
   
      postOrder(treePtr->rightPtr); //Recursion to the right

      printf("%3d", treePtr->data);  //print the value 
   } // end if 
}

void tree( TreeNodePtr treePtr, int depht )
{
   if( treePtr != NULL ){
      tree(treePtr->rightPtr, depht+1);
      
      for(int i = 0; i < depht; i++) printf("   ");
      printf("%2d\n", treePtr->data);

      tree(treePtr->leftPtr, depht+1);

   }

}
