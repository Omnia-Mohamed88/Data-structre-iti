#include <iostream>

using namespace std;
//                 arry      size of array
void selectionsort(int arr[], int n)
{
    int minIdx;
    for (int i=0 ; i< n-1 ; i++)
    {

        minIdx=i;
        for (int j = i+1 ; j<n ; j++)
            if (arr[j]< arr[minIdx])
            minIdx=j;
            swap(arr[minIdx],arr[i]);

    }


}
void swap(int &x , int &y){
    int temp = x;
    x=y;
    y=temp;
}
void print(int arr[] , int size)
{
    for (int i=0;i<size;i++)
        cout << arr[i]<<" ";
     cout<<endl;

}



int main()
{
    int arr[]={60,40,70,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr,n);
    cout<<"array after sorting: \n ";
    print(arr,n);
}
