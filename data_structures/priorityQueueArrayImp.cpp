
#include <bitstring.h>
using namespace std;

struct item {
    int value;
    int priority;
};

item pr[100000];
int size = -1; // pointer to the last index


// Function to insert new element into priority queue 
void enqueue(int value, int priority){
      
      // increase size of the array
      size++;

      //insert the element
      pr[size].value = value;
      pr[size].priority = priority;
}

// Function to check the top element

int peek(){

    int highestPriority = __INT_MIN__;
    int ind = -1;

    for(int i =0; i<= size; i++){
       if(highestPriority == pr[i].priority 
       && ind > -1 
       && pr[ind].value < pr[i].value){
          highestPriority == pr[i].priority;
          ind = i;
       }

       else if(highestPriority < pr[i].priority) {
             highestPriority = pr[i].priority;
             ind = 0;
       }
    }

    return ind;
}

/*
Time complexity ---> enqueue(): O(1)
                ---> dequeue(): O(N)
                ---> peek(): O(N)
*/
