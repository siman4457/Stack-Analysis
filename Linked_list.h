//  Data Structures and Algorithms - 221
//  Stack.h
//  PA_1
//  Created by Siman Shrestha on 2/24/18.

#ifndef Stack_ls_h
#define Stack_ls_h
using namespace std;


//LINKED LIST IMPLEMENTATION

struct node {
    int data;
    node *next;
};

class Linkedlist {
private:
    //head and tail pointers
    node *head;
    node *tail;
    
    int topStack; //keeps track of top element and size
    
public:
    //CONSTRUCTOR
    Linkedlist() {
        head = NULL;
        tail = NULL;
        topStack = -1; //Frist element is at index -1
    }
    
    bool isEmpty (){
        if (topStack == -1) {
            cout << "Stack is empty" << endl;
            return true;
        }
        else {
            cout << "Stack not empty" << endl;
            return false;
        }
    }
    
    void pop () {
        try{
            int tempValue;
            if (head == NULL) {
                cout << "Error: Empty Stack" << endl;
                return;
            }
            node *temp = head;
            tempValue = temp->data;
            head = head->next;
            delete(temp);
            cout << "Removed Value: " << tempValue << endl;
            topStack--;
            return;
            }
        catch(exception){
            cout << "Error: The Stack is empty!" << endl;
        }
    }
    
    int top() {
        return head->data;
    }
    
    void push(int val) {
        node *newNode = new node;
        node *previous = head;
        newNode->data = val;
        newNode->next = previous;
        head = newNode;
        topStack++;
        return;
    }
    
    //Returns the size of the stack
    int size() {
        return topStack + 1; //Have to add one since I defined the first element as -1.
    }
    
    //Not necessary for implementation of a linked list. This helps to see what's in the stack for debugging.
    void print(){
        node *current;
        current = head;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

#endif /* Stack_ls_h */
