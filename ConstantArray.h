//
//  ConstantArray.h
//  Constant Stack Array
//
//  Created by Siman Shrestha on 3/2/18.
//  Copyright © 2018 Training. All rights reserved.
//

#ifndef ConstantArray_h
#define ConstantArray_h

//CONSTANT INCREMENTING ARRAY IMPLEMENTATION

using namespace std;

template <class T>
class AbstractStack
{
private:
    T topStack; //Keeps track of top of the stack
    T max; //Maximum number of elements allowed in the Stack
    T *S; //Pointer to the Stack on the heap
    
public:
    //CONSTRUCTOR
    AbstractStack(T num) {
        topStack= -1;
        this->max = num;
        S = new T[max];
    }
    
    // DESTRUCTOR
    ~AbstractStack() {delete S; return; }
    
    //Check if the Stack is empty
    bool isEmpty() {
        if (topStack== -1) {
            cout << "The Stack is Empty" << endl;
            return true;
        }
        else {
            cout << "The Stack is NOT Empty" << endl;
            return false;
        }
    }
    
    int size(void) {
        return topStack+1; //Size of the stack is topStack+1 since topStack is initialized to -1.
    }
    
    T top () {
        if (topStack == -1) {
            cout << "Stack is Empty" << endl;
        }
        else {
            return S[topStack];
        }
        return 0;
    }
    
    T pop(){
        try{
        if (isEmpty()) {
            throw exception();
            return 0;
        }
        else {
            topStack--;
            return S[topStack];
        }
        }
        catch (exception)
        {
            cout << "Error: The stack is empty!"<< endl;
        }
    }
    
    void push ( T e ) {
        if (topStack + 1 == max) { //If stack is full add a constant size of spaces
            T *temp = S;
            delete S;
            this->max = max + 5;
            S = new T[max];
            for (int i = 0; i < topStack+1; i++) {
                S[i] = temp[i];
            }
            //Increment top stack to keep track of size
            topStack++;
            S[topStack] = e ;
            return;
        }
        else {
            //Increment value of topStack to keep up with the top
            topStack++;
            //Push e (random value) to the Stack
            S[topStack] = e;
        }
    }
};

#endif /* ConstantArray_h */

