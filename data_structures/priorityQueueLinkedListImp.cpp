#include <iostream>
using namespace std;

typedef struct node {
    int data;
    int priority;
    struct node* next;
}Node;

Node* newNode(int d, int p){
    Node* temp =(Node*) malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

int peek(Node **head){
    return (*head)->data;
}

void pop(Node **head){
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node **head, int d, int p){
    Node* start = (*head);
    Node* temp = newNode(d,p);

    if((*head)->priority < p){
        temp->next = *head;
        (*head) = temp;
    } else{
        while(start->next != NULL && start->next->priority > p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

/*
Time Complexity ---> push(): O(N)
                ---> pop(): O(1)
                ---> peek(): O(1)
*/

