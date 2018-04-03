#include <array>
#include <iostream>
#include "StopWatch.h"
#include "DoublingArray.h"

using namespace std;

int main(){
    AbstractStack<int> stack(100);
    CStopWatch obj = CStopWatch(); //Start Stop Watch
    obj.Reset(); //Reset Clock
    float startTime = obj.GetElapsedSeconds();
    for(int i=0; i<10000000; i++){//Pushing 10 million times
        if (i %10000 == 0){//Print time elapsed every 10,000 iterations
            cout << obj.GetElapsedSeconds()<< endl;
        }
        int random_number = rand();
        stack.push(random_number);
    }
    
    //End Stop Watch
    float endTime = obj.GetElapsedSeconds();
    //Printing total time
    cout << "Total time elapsed = " << endTime-startTime << endl;
    cout << "Size: " << stack.size() << endl;
    cout << "Top: " << stack.top() << endl;
}





