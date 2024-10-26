// A structure is a user-defined data type in C/C++. A structure creates a data type 
// that can be used to group items of possibly different types into a single type.

#include<bits/stdc++.h>
using namespace std;

void func(int* arr[], int n)

struct Structure{
    int rollno;          //These are called the data members of the struct
    int marks;
};

int main(){
    int n;cin>>n;
    struct Structure array[n];
    for(int c=0;c<n;c++){
        cin>>array[c].rollno;
        cin>>array[c].marks;
    }
    
    for(int c=0;c<n;c++){
        cout<<c+1<<" "<<"CH22B0"<<array[c].rollno<<" "<<array[c].marks<<endl;
    }
    


}