#include<iostream>
using namespace std;
void check_kth(int n, int k){
    int temp = 1<<(k-1); //left shift 1 binary by k-1
    if((temp & n)!=0)
    cout<<"set"; //if temp and 1 and logic is non zero 
    else
    cout<<"not set";//if it's zero.

//T.C = O(1)  S.C = O(1)
}

int main(){
    int n = 5, k = 1;

	check_kth(n, k);
    
	return 0;
}