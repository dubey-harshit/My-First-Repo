#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;


// There are two types of Polymorphism ---> Compile time and Run time 
//Function overloading --> many functions of same name but differ in attributes or datatypes or values

class A {
    public:
    void fuck(){
        cout<<"Boi";
    }
    void fuck(int x){
        cout<<"hoi";
    }
    void fuck(float x){
        cout<<"toi";
    }
}

//Operator overloading --> changing functionality of a operator acc to need

class B {
    private:
    int real=0,imag=0;
    public:
    B(int r=0,int i=0){
        real = r;
        imag = i;
    }
    B operator + (B &obj){
        B res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }
    void display(){
        cout<<real<<" i"<<imag<<endl;
    }
}

//Virtual Functions -> when two classes have same func and we inherit one to another then in one class only we have same func and 
//when we run it compiler get confused which to run so we put virtual before func to ignore it while running

class base {
    public:
    virtual void func(){
        cout<<"CSK";
    }
}
class derived {
    public:
    void func(){
        cout<<"mumbai ";
    }
}

void solve()
{
    ll n;cin>>n;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    B c1(1,2);
    B c2(2,3);
    B c3 = c1+c2;
    c3.display();
    base *baseptr;
    derived ab;
    baseptr = &ab;
    baseptr -> ab;

}