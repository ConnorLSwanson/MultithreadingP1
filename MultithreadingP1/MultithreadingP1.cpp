// MultithreadingP1.cpp 
// Connor Swanson 
// Activision Blizzard
// 8/3/2022

#include <iostream>
#include <thread>
#include <random>

using namespace std;

int num = 0;
int i = 0;
int rng = 0;
bool endLoop = false;

/* I used two threads to output to the screen to better visualize how they work at the same time.
   The interesting part is that they often overlap the outputs.  I thought that using this_thread::yield() 
   might make a difference and let the outputs finish before the new thread starts, but that does not 
   seem to be the case.  */

void AdditionThread1()
{    
    srand((unsigned)time(0));
    while (i < 200)
    {
        i++;
        this_thread::yield();
        cout << "i = " << i << endl;
    }
}

void AdditionThread2()
{
    srand((unsigned)time(0));
    while (num < 200)
    {
        num++;
        this_thread::yield();
        cout << "num = " << num << endl;
    }
}

int main()
{    
    char input;
    thread Add1(AdditionThread1);
    thread Add2(AdditionThread2);

        
    Add1.join();
    Add2.join();
    return 0;
}

