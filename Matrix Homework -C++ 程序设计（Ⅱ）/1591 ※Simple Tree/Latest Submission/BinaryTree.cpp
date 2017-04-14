#include <cstdlib>
#include <cstring>
#include "BinaryTree.hpp"

    // 此处四个函数均为辅助函数
 void BinaryTree::MemoryDelete(node* p){
        if(p!=NULL){
            MemoryDelete(p->left);
            MemoryDelete(p->right);
            delete p;
          //  p = NULL;
        }
    }
   // 内存处理的辅助函数
 void  BinaryTree::BuildTree(const node* Source_Root, node* &Target_Root){
 	if(Source_Root==NULL){
 		Target_Root = NULL;
 	}
 	else{
        Target_Root = new node (Source_Root->ele);
        if(Source_Root->left)
            BuildTree(Source_Root->left,Target_Root->left);
        if(Source_Root->right)
            BuildTree(Source_Root->right,Target_Root->right);   
    }
}// 拷贝构造函数的辅助函数

 void BinaryTree::BuildTree(const int* arr,int len, node* &root){
}  // 数组构建树的辅助函数
 void BinaryTree::preorder(const node* p){
        if(p){
            cout<< p->ele <<" ";
            preorder(p->left);
            // cout<< p->ele <<" ";
            preorder(p->right);
        }

    }    // 输出的辅助函数

BinaryTree::BinaryTree(){
	root = NULL;
}
BinaryTree::BinaryTree(const BinaryTree& other){
    root = NULL;
    if(other.root){
    	BuildTree(other.root,root);
    }
}

BinaryTree::BinaryTree(const int* arr, int len){
    root = NULL;
    for(int i = 0;i<len;i++){
    	insert(arr[i]);
    }
}
void BinaryTree::ResetTree(const int* arr, int len){
    clear();
    for(int i = 0;i<len;i++){
        insert(arr[i]);
    }
}  
BinaryTree::~BinaryTree(){
    if(root!=NULL)
        MemoryDelete(root);
}
void BinaryTree::clear(){
    MemoryDelete(root);
    root = NULL;
}
void BinaryTree::insert(int ele){
    if(root==NULL){
        root = new node(ele);
        return ;
    }
	node* temp = root;
    while(temp){
    	if(ele<(temp->ele)){
            if(temp->left ==NULL){
                temp->left = new node(ele);
                return;
            }
            else
    		  temp = temp->left;
    	}
    	else if(ele>(temp->ele)){
            if(temp->right==NULL){
                temp->right = new node(ele);
                return;
            }
            else
    		  temp = temp->right;
    	}
        else
            return;
    	
    }
}
  // 按值插入
void BinaryTree::Delete(int ele){
    if(root==NULL)
        return;
   // char flag = 'l';
    int find = 0;
	node *temp = root;
    node *tempfather = root;
	while(temp){
		if(temp->ele==ele){
            find = 1;
			break;
        }
		else if(ele<(temp->ele)){
                tempfather = temp;
    			temp = temp->left;
              //  flag = 'l';
    		}
    	else{
            tempfather = temp;
            temp = temp->right;
         //   flag = 'r';
        }
       		
    	}
    if(!find){//如果没有找到
        return;
    }
    if(temp->left==NULL&&temp->right==NULL){
        if(temp==root){
            root = NULL;
        }
        else if(temp==tempfather->right){
            tempfather->right = NULL;
        }
        else 
            tempfather->left = NULL;
        delete temp;
        temp = NULL;
        return ;
    }
    else if(temp->left==NULL){
            if(temp==root){
                root = root->right;
            }
            else if(tempfather->left==temp)
                tempfather->left = temp->right;
            else
                tempfather->right = temp->right;
        
        delete temp;
        temp = NULL;
        return ;
    }
    else{//在左子树中找中序下的最后一个节点
        int haveright = 0;
        node *findr = temp->left;
        node *parent = temp;
        while(findr->right){
            parent = findr;
            findr = findr->right;
            haveright = 1;//
        }

        if(haveright){
            temp->ele = findr->ele;
            //替换节点
            parent->right = findr->left;
            delete findr;
            findr = NULL;
            return ;
         }
        else{
            temp->ele = findr->ele;
            parent->left = findr->left;
            delete findr;
            temp = NULL;
        }
        }
    }
	

 // 暗值删除
void BinaryTree::print(){
    if(root)
        preorder(root);
    cout<<endl;
}
