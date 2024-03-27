#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

long arrayManipulation(int n, vector<vector<int>> queries) {
    int max = 0;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(0);
    }
    
    for(size_t i = 0; i < queries.size(); i++){
        for(int j = queries[i][0] - 1; j < queries[i][1]; j++){
            arr[j] = arr[j] + queries[i][2];
        }
    }
    
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
                max = arr[i];
        }
    }
    return max;
} 


int main(){
    int elements, ops;
    vector<vector<int>> Array;

    cin >> elements >> ops;
    
    for(int j = 0; j < ops; j++){
        vector<int> arr;
        int num;
        for(int i = 0; i < 3; i++){
            cin >> num;
            arr.push_back(num);
        }
        Array.push_back(arr);
        arr.clear();   
    }
    cout << endl;
    for(int i=0; i < ops; i++){
        printArray(Array[i],3);
    }
    
    arrayManipulation(elements,Array);
    return 0;
}    