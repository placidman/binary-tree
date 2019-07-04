#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode * Insert(treeNode *node,int data);
treeNode * minsub(treeNode *node);
treeNode * deleteTreeElement(treeNode *node, int data);
treeNode * find(treeNode *node, int data);
void print(treeNode *node);




int main()
{
    treeNode *root = NULL;
	char fry;	
	fry='a';
	int number,x,q;
	while(fry!='q')
	{
		printf("\n Previous FRy %c)\n", fry);
		if (fry!='q')
		{
			printf("\n Give new choise \n");
			fry='a';
			fflush(stdin);
			fry=getchar();
			getchar();
			if (fry=='q') 
				{printf("\n QUIT \n");}
			if (fry=='i')
				{	 printf("\n INSERT \n");
					 printf("\n Add number :\t");
					 scanf("%d",&number);
					 getchar();
					 root=Insert(root,number);
					}
			if(fry=='p')
			{
				printf("\n Print \n");
				print(root);}
			
			if(fry=='f')
			{
				printf("\n find \n");
				printf("\n Search number :\t");
				scanf("%d",&x);
				getchar();
				root=find(root,x);}
			if(fry=='d')
			{
				printf("\n find \n");
				printf("\n Delete number :\t");
				scanf("%d",&q);
				getchar();
				root=deleteTreeElement(root,q);}
			
			}
        
}
}
treeNode * minsub(treeNode *node)
{
        
        if(node->left != NULL) 
        {
		
                 minsub(node->left);}
        else 
        {
                return node;}
}

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        
        return node;

}

treeNode * deleteTreeElement(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Not Found");
                return node;
        }
       if(data < node->data)
        {
                node->left = deleteTreeElement(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = deleteTreeElement(node->right, data);
        }
        else 
        {
               
                if(node->right != NULL && node->left != NULL)
                {
                        
                        temp = minsub(node->right);
                        node -> data = temp->data; 
                        
                        node -> right = deleteTreeElement(node->right,temp->data);
                }
                else
                {
                        
                        temp = node;
                        if(node->left == NULL)
                                {
									node = node->right;}
                        else if(node->right == NULL)
                                {
									node = node->left;}
                        free(temp); 
                }
        }
      
		

        return node;

}

treeNode * find(treeNode *node, int data)
{
        if(node==NULL)
        {
                printf("number does not exist in the Tree..");
                return NULL;
                
        }
        if(data > node->data)
        {
                
                return find(node->right,data);
                
        }
        else if(data < node->data)
        {
                
                return find(node->left,data);
        }
        else
        {
                printf("the %d exist ",node->data);
                return node;
        }
}

void print(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        print(node->left);
        printf("%d ",node->data);
        print(node->right);
}






