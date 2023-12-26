#include <iostream>
using namespace std;

void selectionsort(string arr[], int n) {
    int minindex;

    for (int i = 0; i < n - 1; i++) {
        minindex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        // Move the swap outside the inner loop
        swap(arr[minindex], arr[i]);
    }
}

// Modify the swap function to work with strings
void swap(string &x, string &y) {
    string temp = x;
    x = y;
    y = temp;
}

void print(string arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    string arr[3] = {"ali", "omnia", "nor"};
    int n = 3;
    selectionsort(arr, n);
    cout << "array after sorting: \n ";
    print(arr, n);
    return 0;
}


