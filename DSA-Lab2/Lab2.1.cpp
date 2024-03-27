#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> insertionSort(vector<int> arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArray(arr, n);   
    }
    return arr;
}

int main(){
    int len, num;
    vector<int> arr, Array;

    cin >> len;
    for(int i = 0; i < len; i++){
    cin >> num;
    arr.push_back(num);
    }

    Array = insertionSort(arr, len);
    printArray(Array, len);
    return 0;   
}

