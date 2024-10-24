#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bubble(int arr[], int n){
    for(int i =0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++)
        if(arr[j]>arr[j+1])
        swap(&arr[j], &arr[j+1]);
    }
}
//Time Complexity: O(N2)

int main(){
    int arr[]={34,32,89,43,2,10,7,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);
    for(int i=0; i<n; i++){
        cout<<"arr["<<i<<"]  =  "<<arr[i]<<endl;
    }
}
