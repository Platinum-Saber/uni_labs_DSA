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

void arrDelete(vector<int>& arr, int& n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            arr.erase(arr.begin() + i);
        }
    }
    n--;
}
void arrInsert(vector<int>& arr, int& n, int key){
    arr.push_back(key);
    n++;
}

int newCookie(vector<int>& arr, int n, int k, int& count){
    if(arr[0] >= k){
        cout << "Sweetness : " << arr[0] << " is greater than or equal to " << k << endl;
        return 0;
    }
    else{
        if (arr[0] < k && n > 1) {
            int sweetness = arr[0] + 2 * arr[1];
            arrDelete(arr, n, arr[0]);
            arrDelete(arr, n, arr[0]);
            n -= 2;

            cout << "After deletion : ";
            displayArray(arr, n);

            arrInsert(arr, n, sweetness);
            cout << "After insertion : ";
            displayArray(arr, n);
            count++;
            newCookie(arr, n, k, count);
        } else {
            cout << "Sweetness : " << arr[0] << " is less than " << k << endl;
            return -1;
        }

    }
    return count;
    
    
}

// main program
void main()
{
    vector<int> arr = {2,7,3,6,4,6};
    int n = 6;
    heapSort(arr, n);
    cout << "Sorted array : ";
    displayArray(arr, n);
    int count = 0;
    int n = arr.size();
    
    newCookie(arr, n, 19, count);
    cout << "Total turns : " << count << endl;  
}