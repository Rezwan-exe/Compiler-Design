#include <iostream>
using namespace std;


int main() {
   int n;
   cout << "Enter number of elements: ";
   cin >> n;


   int arr[n];
   double sum = 0;


   cout << "Enter " << n << " elements:\n";
   for (int i = 0; i < n; i++) {
       cin >> arr[i];
       sum += arr[i];
   }


   double average = sum / n;
   cout << "Average value = " << average << endl;


   return 0;
}
