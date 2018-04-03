//
//  DoublingArray.h
//  Constant Stack Array
//
//  Created by Siman Shrestha on 3/2/18.
//  Copyright © 2018 Training. All rights reserved.
//

#ifndef DoublingArray_h
#define DoublingArray_h

//DOUBLING ARRAY IMPLEMENTATION

using namespace std;
template <class T>
class AbstractStack
{
private:
    T topStack; // Keeps track of the top of the stack and the size
    T max; //Maximum number of elements allowed in the Stack
    T *S; //Pointer to the Stack on the heap
    
public:
    AbstractStack(T num) { //CONSTRUCTOR
        topStack= -1;
        this->max = num;
        S = new T[max];
    }
    
    ~AbstractStack() {delete S; return; } // DESTRUCTOR
    
    bool isEmpty() {     //IS EMPTY FUNCTION
        if (topStack== -1) {
            cout << "The Stack is empty" << endl;
            return true;
        }
        else {
            cout << "Stack not empty" << endl;
            return false;
        }
    }
    
    int size(void) {      //SIZE FUNCTION
        return topStack+1;
    }
    
    T top () {      // TOP VALUE FUNCTION
        if (topStack == -1) {
            cout << "No elements currently in stack" << endl;
        }
        else {
            return S[topStack];
        }
        return 0;
    }
    
    T pop(){         //REMOVING THE TOP VALUE FUNCTION
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
        if (topStack + 1 == max) {
            T *temp = S;
            delete S;
            this->max *= 2;
            S = new T[max];
            for (int i = 0; i < topStack+1; i++) {
                S[i] = temp[i];
            }
            topStack++;
            S[topStack] = e;
            return;
        }
        else {
            topStack++;
            S[topStack] = e;
        }
    }
};

#endif /* DoublingArray_h */


