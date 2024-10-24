#include<iostream>
using namespace std;
int remove_duplicate(int arr[], int n){
   int temp[n];
   temp[0] = arr[0]; //as always first element must be there
   int res =1;
   for(int i=1; i<n; i++){
    if(temp[res-1]!=arr[i]){
        temp[res++]=arr[i];
    }
   }
   for(int i=0;i<res; i++){
    arr[i] = temp[i]; //create a temporary array

   }
   return res;
}

int main(){
     int arr[] = {10, 20, 20, 30, 30, 30}, n = 6;

      cout<<"Before Removal"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<"arr["<<i<<"] = "<<arr[i]<<" "<<endl;
       }

       cout<<endl;

       n=remove_duplicate(arr, n);

       cout<<"After Removal"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<"arr["<<i<<"] = "<<arr[i]<<" "<<endl;
       }

       cout<<endl;

}
