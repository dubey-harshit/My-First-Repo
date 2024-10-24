#include<iostream>
using namespace std;
int max_1s(bool arr[],int n){
    int count =0;
    for(int i=0; i<n; i++)
    if (arr[i+1] == arr[i] == 1)
    count ++;
    return count;

}
int main(){
    bool arr[]={1,0,1,1,0,1,1,1};
    int res=max_1s(arr,sizeof(arr)/sizeof(arr[0]) );
    cout<<res;

    return 0;
}