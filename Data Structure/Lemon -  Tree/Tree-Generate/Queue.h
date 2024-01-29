#ifndef __QUEUE_CPP_H__
#define __QUEUE_CPP_H__
#include <iostream>

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){front=rear=-1; size = 10; Q = new Node*[size]; }
    Queue(int size){front=rear=-1; this->size = size; Q = new Node*[this->size];}
    void enqueue(Node* x);
    Node* dequeue();
    void display();
    bool isEmpty(){return front == rear;}
};

void Queue::enqueue(Node *x){
    if (rear == size - 1){
        std::cout << "Queue Full" << std::endl;
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue(){
    Node* x = NULL;
    if (front == rear){
        std::cout << "Queue is empty" << std::endl;
    }
    else{
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::display(){
    for (int i = front + 1; i <= rear; i++)
        std::cout << Q[i];
    std::cout<<std::endl;
}


#endif
/* __QUEUE_CPP_H__ */