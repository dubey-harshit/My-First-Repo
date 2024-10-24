#include<iostream>
using namespace std;

int partition(int arr[],int si,int ei){
    int pivot = arr[ei];
    int i = si-1;
    for(int j=si; j<ei; j++){
        if(arr[j]<pivot)
        {
            i++; //swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = arr[i];
}
    }
    //swap pivot 
    i++;
    int temp = arr[i];
    arr[i]= arr[ei];
    arr[ei] = temp;
    return i;


}
int quick(int arr[], int si, int ei){
    if(si<ei){
    int pi=partition(arr,si,ei); //pi= pivot_index
    quick(arr,si, pi-1);
    quick(arr,pi+1,ei);
}
}
int main(){
    int arr[]={2,1,3,0,6,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);
     quick(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}