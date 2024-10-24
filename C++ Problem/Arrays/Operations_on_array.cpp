//Basic operations on an array

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};      // Declare and initialize of array

    int n = sizeof(arr) / sizeof(arr[0]);   //  size of the array

    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The third element is: " << arr[2] << endl;
    arr[2] = 35; // Acces,Modifying the third element
    cout << "The updated third element is: " << arr[2] << endl;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Sum of array elements is: " << sum << endl; 

    return 0;
}
