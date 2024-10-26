// QUESTIONS
// 1. What do you understand by thread and give one example in C++?

// ANSWER
// 0. In every application there is a default thread which is main(), in side this we create other threads.
// 1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
//    For example:
//    (a) The browser has multiple tabs that can be different threads. 
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

#include <thread>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>
#define long long ll
using namespace std;
using namespace std::chrono;

ll findodd(ll start , ll end){
    ll sum=0;
    for(ll i = start;i<=end ; i++){
        if(i&1==1){
            sum+=i;
        }
    }return sum;
}
ll findeven(ll start , ll end){
    ll sum=0;
    for(ll i = start;i<=end ; i++){
        if(i&1==0){
            sum+=i;
        }
    }return sum;
}

int main(){
    ll start = 1 , end = 1900000000;
    auto startTime = high_resolution_clock::now();

    std::thread t1(findeven, start, end);
    std::thread t2(findodd, start, odd);

    t1.join();        // It will join the thread with main thread otherwise it will not wait for these thread to complete their process
    t2.join();        

    // findodd(start,end);
    // findeven(start,end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime-startTime);
    cout<<duration.count()/100000<<endl;

    //Lamda Functions

    auto fun = [](int x){
        while(x--){
            cout<<x<<Endl;
        }
    };
}

