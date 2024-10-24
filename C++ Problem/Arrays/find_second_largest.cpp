
#include <iostream>
using namespace std;

// returns the index of second largest
// if second largest does not exist return -1
int secondLargest(int arr[], int n) {
	int index;
	int max = arr[0];
	int second_max =0;
	for(int i=0; i<n; i++){
		if(arr[i]>max){
			max = arr[i];
			index = i;
		}
	}
	for(int i=0; i<n; i++){
		if(i!= index){
			if(arr[i]>second_max){
				second_max = arr[i];
			}
		}
	}
	return second_max;
}

int main() {
	int arr[] = {10, 12, 20, 4};
	int index = secondLargest(arr, sizeof(arr)/sizeof(arr[0]));
	if (index == -1)
		cout << "Second Largest do not exist";
	else
		cout << "Second largest : " << index;
}
//Time Complexity: O(n). 
