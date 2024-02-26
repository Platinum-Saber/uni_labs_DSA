#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}

vector<int> getArray(){
    int n, num;
    vector<int> arr; 
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }
    return arr;
}

int main(){
    vector<int> Array = getArray();
    int pivot = Array[0];
    vector<int> midArray = {pivot};
    vector<int> leftArray, rightArray, newArray;

    Array.erase(Array.begin());
    for (int num : Array){
        if (num < pivot){
            leftArray.push_back(num);
        }
        else{
            rightArray.push_back(num);
        }
    }

    for(int l : leftArray){
        newArray.push_back(l);
    }

    newArray.push_back(pivot);

    for(int r : rightArray){
        newArray.push_back(r);
    }
    printArray(newArray);   

}


