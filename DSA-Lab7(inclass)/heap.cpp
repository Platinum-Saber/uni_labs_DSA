#include <iostream>
using namespace std;

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest;
    int l = left(root);
    int r = right(root);
    int i = root;
    if (l <= n && arr[l-1] > arr[i-1]){
        largest = l;
    }
    else{
        largest = i;
    }
    if (r <= n && arr[r-1] > arr[largest-1]){
        largest = r;
    }
    if (largest != i){
        int temp = arr[i-1];
        arr[i-1] = arr[largest-1];
        arr[largest-1] = temp;
        heapify(arr, n, largest);
    }
   
}

int buildHeap(int arr[], int n){
    for (int i = n/2 ; i >= 1; i--){
        heapify(arr, n, i);
    }
    return 0;
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
   
   for ( int i = n; i >= 1; i--)
   {
       int temp = arr[0];
       arr[0] = arr[i-1];
       arr[i-1] = temp;
       heapify(arr, i-1, 1);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int heap_arr[] = {4,17,3,12,9,6};
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array : ";
    displayArray(heap_arr,n);
   
    buildHeap(heap_arr, n);
    cout<<"Heapified array : ";
    displayArray(heap_arr,n);
    
    heapSort(heap_arr, n);
    cout << "Sorted array : ";
    displayArray(heap_arr, n);
}