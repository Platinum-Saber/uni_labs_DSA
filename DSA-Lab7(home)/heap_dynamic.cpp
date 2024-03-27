#include <iostream>
#include <vector>
#include <string>
using namespace std;


// function to heapify the tree
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
}

void heapSort(vector<int> &arr, int n){
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void displayArray(vector<int> arr, int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

void heapInsert(vector<int>& arr, int& n, int key){
    arr.push_back(key);
    n++;
    buildHeap(arr, n);
}

void heapDelete(vector<int>& arr, int& n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            arr.erase(arr.begin() + i);
        }
    }
    n--;
    buildHeap(arr, n);
}
// main program
int main()
{
    vector<int> heap_arr;
    int n = 0;
    int turns;
    cin >> turns;
    for (int i = 0; i < turns; i++){
        int key;
        int value;
        cin >> key;
        if(key == 1){
            cin >> value;
            heapInsert(heap_arr, n, value);
        }
        else if (key == 2){
            cin >> value;
            heapDelete(heap_arr, n, value);
        }
        else if (key == 3){
            heapSort(heap_arr, n);
            cout << "min : " << heap_arr[0] << endl;
        }
    }
   
    
    cout << "Sorted array : ";
    displayArray(heap_arr, n);
}