#include <iostream>
#include "Queue.h"
using namespace std;

class Tree{
public:
    Node *root;
    Tree(){root = NULL;}
    void CreateTree();
    void PreOrder(Node *p);
    void PreOrder(){PreOrder(root);}
    void PostOrder(Node *p);
    void InOrder(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *root);
};

void Tree::CreateTree(){
    Node *p, *t;
    int value;
    Queue Q(100);
    
    std::cout << "Enter root value";
    std::cin >> value;  
    root = new Node;
    root ->data = value;
    root -> lchild = nullptr;
    root -> rchild = nullptr;
    Q.enqueue(root);

    while (!Q.isEmpty()){
        p = Q.dequeue();
        std::cout << "Enter left child value of" << p->data;
        std::cin >> value; 
        if (value != -1){
            t = new Node;
            t -> data = value;
            t -> lchild = nullptr;
            t -> rchild = nullptr;
            p -> lchild = t;
            Q.enqueue(t);
        }
        std::cout << "Enter right child value of" << p->data;
        std::cin >> value; 
        if (value != -1){
            t = new Node;
            t -> data = value;
            t -> lchild = nullptr;
            t -> rchild = nullptr;
            p -> rchild = t;
            Q.enqueue(t);
        }
    }
}

void Tree::LevelOrder(Node *p){
    Queue Q(100);
    cout << root -> data; 
    Q.enqueue(root);

    while(!Q.isEmpty()){
        root = Q.dequeue();
        if (root -> lchild){
            std::cout << root -> lchild -> data << " ";
            Q.enqueue(root -> lchild);
        }
        if (root -> rchild){
            std::cout << root -> rchild -> data << " ";
            Q.enqueue(root -> rchild);
        }
    }
}

void Tree::PostOrder(Node* p){
    if (p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        std::cout << p -> data << " "; 
    }
}

void Tree::InOrder(Node *p){
    if (p){
        InOrder(p -> lchild);
        cout << p -> data << " ";
        InOrder(p -> rchild);
    }
}

void Tree::PreOrder(Node *p){
    if (p){
        cout << p -> data << " ";
        PreOrder(p -> lchild);
        PreOrder(p -> rchild);
    }
}

int Tree::Height(Node *root){
    int x = 0, y = 0;
    if (root == 0){
        return 0;
    }
    x = Height(root -> lchild);
    y = Height(root -> rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main(){
    
    return 0;
}