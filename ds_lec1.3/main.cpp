#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int employeeID;
    int age;

    Employee(string x, int id, int ag) : name(x), employeeID(id), age(ag) {}
};

void swap(Employee &x, Employee &y) {
    Employee temp = x;
    x = y;
    y = temp;
}

void bubbleSort(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].employeeID > arr[j + 1].employeeID) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printEmployees(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << ", Employee age: " << arr[i].age << ", Employee ID: " << arr[i].employeeID << endl;
    }
}

int main() {
    const int size = 4;
    Employee employees[size] = {
        {"omnia", 32, 14},
        {"peter", 14, 45},
        {"nour", 1, 87},
        {"alaa", 03, 30}
    };

    bubbleSort(employees, size);

    cout << "Employees after sorting by employee ID:" << endl;
    printEmployees(employees, size);

    return 0;
}

