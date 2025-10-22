#include <iostream>
using namespace std;
//uwybcvahkbcu
 
int main() {
    for(int j=0;j<3;j++){
    int data;
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
    int first = 0, last = 24, mid, position = -1;
 
    cout << "Enter number to search: ";
    cin >> data;
 
 
    while (first <= last) {
        mid = (first + last) / 2;
 
        if (data == arr[mid]) {
            position = mid;
            break;
        } 
        else if (data > arr[mid]) {
            first = mid + 1;
        } 
        else {
            last = mid - 1;
        }
    }
 
    if (position != -1) {
        cout << data << " found at index " << position << endl;
    } 
    else {
        cout << data << " not found in the array." << endl;
    }
    
    }
 
 
    return 0;
}