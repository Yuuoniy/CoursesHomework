 #include "tree.h"

Node* init_root(int value){//创建头节点
    Node *r = (Node*)malloc(sizeof(Node));
    r->value = value;
    r->left = NULL;
    r->right = NULL;
    return r;
}
Node* create_node(int value)//创建新的结点
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->left = NULL;
    newnode ->right = NULL;
    newnode->value = value;
    return newnode ;
}
void insert_node(Node *p, int value){
    if(value<=p->value){//如果小于 存入左子树
    	if(p->left==NULL)//向下查找没有东西了 可以插入
    		p->left = create_node(value);//将新创建的结点插入正确的地方
    	else  
    		insert_node(p->left,value);//否则继续从该结点的左子树向下查找
    } 
    else if(value>p->value){//如果大于 存入右子树
    	if(p->right==NULL)
    		p->right = create_node(value); 
    	else
    		insert_node(p->right,value);
    } 

} 
void traverse_tree_inorder(Node *p){//中序遍历
    if(p!=NULL){
        traverse_tree_inorder(p->left);//先输出左子树
      printf("%d ",p->value);
        traverse_tree_inorder(p->right);

    }

}

void recycle_nodes(Node *p){//后序遍历
    if(p!=NULL){
        recycle_nodes(p->left);
        recycle_nodes(p->right);
       free(p);
    }   

}
