//std::promise 
//  a. Used to set values or exceptions

//std::future
//  a. Used to get values from promise 
//  b. Ask promise if the value is availble
//  c. Wait for the promise

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#define long long ll
using namespace std;

void findOdd(std::promise<ll> && OddSumPromise, ll start, ll end){
    ll OddSum = 0;
    for(ll i=start; i<=end; i++){
        if(i & 1){
            OddSum += i;
        }
    }
    OddSumPromise.set_value(OddSum);
}

int main(){
    ll start =0;end= 19000000;

    std::promise<ll> OddSum;
    std::future<ll> OddFuture = OddSum.get_future();
    cout<<"Thread created"<<endl;

    std::thread t(findOdd, std::move(OddSum), start, end);

    cout<<"Waiting for the result"<<endl;

    cout<<"OddSum": <<OddFuture.get()<<endl;
}

//In threads till now we are using promise and future to get values from it
//We first make a promise and then send it to the thread it just set the value in the promise just like a gift wrap and and future is
//made from the promise which will wait till the value is availbale and we can get through it


