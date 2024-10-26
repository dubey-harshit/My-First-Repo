// 1.It runs a function asynchronously (potentialy in a new thread) and returns
//   a std::future that will hold the result
// 2.There are three launch policies for creating task:
//      a. std::launch::async          // Threading
//      b. std::launch::deffered       // Not threading
//      c. std::launch::async | std::launch::deferred

// How it works:
// 1. It automatically creates a thread (or picksfrom internal thread pool) and a promote object for us.
// 2. Then passes the std::promise object to thread function and returns the associated std::future object
// 3. When our passed argumetn function exits then its value will be set in this promise object,
//    so eventually return value will be availbale in std::future object

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#define long long ll
using namespace std;

ll findOdd(ll start, ll end){     //Here need not to send any promise and simply we can return value
    ll OddSum = 0;
    for(ll i=start; i<=end; i++){
        if(i & 1){
            OddSum += i;
        }
    }
    return OddSum;
}

int main(){
    ll start =0;end= 19000000;

    //std::promise<ll> OddSum;  No need of this
    std::future<ll> OddFuture = std::async(std::launch::async, findOdd, start, end);
    cout<<"Thread created"<<endl;

    //std::thread t(findOdd, std::move(OddSum), start, end);

    cout<<"Waiting for the result"<<endl;

    cout<<"OddSum": <<OddFuture.get()<<endl;
}