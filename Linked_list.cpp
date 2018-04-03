//
//  main.cpp
//  Singly Linked List Stack
//
//  Created by Siman Shrestha on 3/2/18.
//  Copyright © 2018 Training. All rights reserved.
//

#include<iostream>
#include "StopWatch.h"
#include "Linked_list.h"
#include <cstdlib>
using namespace std;

int main() {
    Linkedlist list; //Declare a linked list named list
    CStopWatch obj = CStopWatch(); //Start Stop Watch
    obj.Reset(); //Reset Clock
    float startTime = obj.GetElapsedSeconds();
    for(int i=0; i<10000; i++){//Pushing 10 million times
        if (i %10 == 0){//Print time elapsed every 10,000 iterations
            cout << obj.GetElapsedSeconds()<< endl;
        }
        int random_number = rand();
        list.push(random_number);
    }
    
    //End Stop Watch
    float endTime = obj.GetElapsedSeconds();
    //Printing total time
    cout << "Total time elapsed = " << endTime-startTime << endl;
    //Print out size of the stack
    cout << "Size: " << list.size() << endl;
}


