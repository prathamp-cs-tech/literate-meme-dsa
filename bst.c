#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int item;
    struct node *right;
};

struct node* createNode(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node *root, int value){
    if (root==NULL){
        return createNode(value);
    }
    if(value < root->item){
        root->left=insert(root->left,value);
    }
    else if (value > root->item){
        root->right=insert(root->right,value);
    }
    return root;
}

