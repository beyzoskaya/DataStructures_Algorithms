#include <iostream>
using namespace std;

struct QNode
{
    int data;
    QNode *next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue
{
    QNode *front;
    QNode *rear;
    Queue()
    {
        rear = front = NULL;
    }

    void enqueue(int x)
    {
        QNode *temp = new QNode();

        if(rear == NULL)
        {
            rear->next = temp;
            rear = temp;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if(front == rear){
            return;
        }

        QNode *temp = front;
        front = front->next;
            if(front == NULL){
                rear = NULL;
            }
            delete(temp);
    }
}