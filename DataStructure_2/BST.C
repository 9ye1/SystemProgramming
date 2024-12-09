#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    struct _node *left, *right;
}Node;

Node* makeNode(int key){
    Node* newNode = malloc(sizeof(Node));
    newNode->key=key;
    newNode->left = newNode->right=NULL;
}
Node* insert(Node* node, int key){
    if(node == NULL){
        return makeNode(key);
    }
    if(node->key < key){
        node->right = insert(node->right, key);
    }else{
        node->left = insert(node->left, key);
    }
    return node;

}
Node* search(Node* node, int key){
    if(node == NULL || node->key == key){
        return node;
    }
    if(node->key < key){
        return search(node->right, key);
    }else{
        return search(node->left, key);
    }
}
Node* findSmallest(Node* node){
    if(node==NULL) return NULL;
    if(node->left)
        return findSmallest(node->left);
    return node;
}

Node* removeNode(Node* node, int key){
    if(node->key < key){
        node->right = removeNode(node->right, key);
    }else if(node->key > key){
        node->left = removeNode(node->left, key);
    }else{
        if(node->left == NULL && node->right ==NULL){
            free(node);
            return NULL;
        }
        else if(node->left && node->right==NULL){
            Node* a = node->left;
            free(node);
            return a;
        }
        else if(node->right && node->left == NULL){
            return node->right;
        }
        else{
            Node* smallest = findSmallest(node->right);
            node->key = smallest->key;
            node->right = removeNode(node->right, smallest->key);
        }
    }
    return node;
}

void postorder(Node* node){
    if(node->left) postorder(node->left);
    if(node->right) postorder(node->right);
    printf("%d", node->key);
}

int main(){
    Node* root = NULL;

    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,30);

    postorder(root); //10,30,20(

    //Node* node = findSmallest(root);
    //printf("%d", node->key);

    root = removeNode(root, 10);



    return 0;
}