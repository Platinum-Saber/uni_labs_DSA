#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> bubbleSort(vector<int> arr, int length){
    for (int j = length - 1; j > 0; j--){
        int swapped = 0;
        for (int i = 0; i < j ; i++){
            if (arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }      
    }
    return arr;
}

int main(){
    vector<int> arr = {2,7,3,6,4,6, 7};
    int n = arr.size();
    int k = 9;
    vector<int> Array = bubbleSort(arr, n);
    printArray(Array, n);
    int sweetness = Array[0] +(2 * Array[1]);
    int count = 0;

    while(n > 2 && sweetness < k) {
        Array.erase(arr.begin());
        Array.erase(arr.begin());
        Array.push_back(sweetness);
        n = Array.size();
        Array = bubbleSort(arr, n);
        printArray(Array, n);
        sweetness = Array[0] + 2 * Array[1];
        count++;
    }
    cout << count << endl;
    

}