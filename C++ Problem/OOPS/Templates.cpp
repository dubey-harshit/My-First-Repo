#include<bits/stdc++.h>
#include<sstream>
using namespace std;  
//Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries. 

//1.There are two places where we can apply templates.
//    a. Function templates     b. Class templates
//2. Templates are the way to write generic programs.
//3. The main point is we pass data type as parameter to function or class.

int maxint(int x , int y){
    return x>y?x:y;
}
char maxchar(char x , char y){     // Here we applying same func but with different data types 
    return x>y?x:y;
}

template <typename T>
T maxtemp(T x, T y){    //This is a func template here we can save time and our effort by using template
    return x>y?x:y;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int x = 180,y=10;
   cout<< maxint(x,y)<<endl;
   char c1 = 'a',c2 = 'b';
   cout<<char(maxchar(c1,c1))<<endl;

   cout<<maxtemp<int>(x,y)<<endl;   //syntax to assign datatype to func templates
   cout<<maxtemp<char>(c1,c2)<<endl;
}

// Templates Specialization in C++
//Sometimes we need to specialize template for particular datatype
//We can specialize both function and templates

template <typename T>
T addall(vector<T> list){
    T count = 0;
    for(auto &elem: list){
        count+=elem;
    }
    return count;
}
//this is working for all integers and decimals but if datatype is string or for
//any particular datatype we want to do something else then we need to specialize

template <>
string addall(vector<string> list){
    int count = 0;
    for(const string &elem: list){
        for(const &char: elem){
            count+=char;
        }
    }
    ostringstream 0str;
    0str << count;
    string strcount = 0str.str();
    return strcount;
}

//Why we are using ostringstream instead of strings

//Streams are buffers. They are not equal to char arrays, such as std::string, which is basically
//an object containing a pointer to an array of chars. Streams have their intrinsic functions, manipulators, states, and operators, already at hand. 
//A string object in comparison will have some deficiencies, e.g., with outputting numbers, lack of handy functions like endl, troublesome concatenation, 
//esp. with function effects (results, returned by functions), etc. String objects are simply cumbersome for that.

//Now std::ostringstream is a comfortable and easy-to-set buffer for formatting and preparation of much data in textual form (including numbers) for the 
//further combined output. Moreover, in comparison to simple ostream object cout, you may have a couple of such buffers and juggle them as you need.