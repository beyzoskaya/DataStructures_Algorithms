#include <iostream>

using namespace std;

struct Queue
{
    int front;
    int rear;
    int capacity;
    int *queue;

    Queue()
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }
    ~Queue() 
    { 
        delete[] queue;
    }

    void enqueue(int data)
    {
        if(capacity == rear){
            cout << "Queue is full" << endl;
            return ;
        } else {
            queue[rear] = data;
            rear ++;
        }
        return;
    }

    void dequeue()
    {
        if(front == rear)
        {
            cout << "Queue is empty" << endl;
        } else {
            for(int i = 0; i < rear -1; i++){
                queue[i] = queue[i+1];
            }

            rear--;
        }
        return;
    }

    void display()
    {
        int i;
        if(front == rear){
            cout << "Queue is empty" << endl;
        } else {
            for(int i = 0; i < rear -1; i++){
                cout << queue[i] << endl;
                return;
            }
        }
    }
};
