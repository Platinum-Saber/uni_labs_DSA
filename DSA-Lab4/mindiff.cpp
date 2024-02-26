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

vector<int> merge(vector<int> leftArr, vector<int> rightArr){
    int lenL, lenR;
    lenL = leftArr.size();
    lenR = rightArr.size();

    vector<int> mergedArr(lenL + lenR);
    int l = 0, r = 0, m = 0;
    while(l < lenL && r < lenR){
        if(leftArr[l] < rightArr[r]){
            mergedArr[m] = leftArr[l];
            l++;
        }
        else{
            mergedArr[m] = rightArr[r];
            r++;
        }
        m++;
    }
    while(l < lenL){
        mergedArr[m] = leftArr[l];
        l++;
        m++;
    }
    while(r < lenR){
        mergedArr[m] = rightArr[r];
        r++;
        m++;
    }
    return mergedArr;
}

vector<int> mergeSort(vector<int> arr){
    if(arr.size() < 2){
        return arr;
    }

    int arrLen = arr.size();
    int midIndex = arrLen / 2;
    vector<int> leftArr(midIndex);
    vector<int> rightArr(arrLen - midIndex);

    //vector<int> leftArr(arr.begin(), arr.begin() + midIndex);
    //vector<int> rightArr(arr.begin() + midIndex, arr.end());


    for(int i = 0; i < midIndex; i++){
        leftArr[i] = arr[i];
    }
    for(int j = midIndex; j < arrLen; j++){
        rightArr[j-midIndex] = arr[j];
    }

    leftArr = mergeSort(leftArr);
    rightArr = mergeSort(rightArr);
    return merge(leftArr,rightArr); 
}

// vector<int> bubbleSort(vector<int> arr, int length){
//     for (int j = length - 1; j > 0; j--){
//         int swapped = 0;
//         for (int i = 0; i < j ; i++){
//             if (arr[i]>arr[i+1]){
//                 swap(arr[i], arr[i+1]);
//                 swapped = 1;
//             }
//         }
//         if(swapped == 0){
//             break;
//         }      
//     }
//     return arr;
// }

vector<int> closestNumbers(vector<int> arr) {
    int len = arr.size();
    //vector<int> sorted_arr = bubbleSort(arr, len);
    vector<int> sorted_arr = mergeSort(arr);
    vector<int> diffs, minDiffPairs;
    vector<vector<int>> sortedPairs(len);
    
    for(int i = 0; i < len-1; i++){
        sortedPairs[i] = {sorted_arr[i], sorted_arr[i+1]};
        int gap = sortedPairs[i][0] - sortedPairs[i][1];
        if (gap < 0){
            gap = -gap;
        }
        diffs.push_back(gap);
    }
    int min = diffs[0];
    for(int j = 0; j < len-1; j++){
        if (min > diffs[j]){
            min = diffs[j];
        }
    }

    for(int k = 0; k < len-1; k++){
        if(min == diffs[k]){
            minDiffPairs.push_back(sortedPairs[k][0]);
            minDiffPairs.push_back(sortedPairs[k][1]);
            
        }
    }
    return minDiffPairs;
}

int main(){
    vector<int> arr = {2, 3, 7, 1, 4, 5};
    vector<int> Array = closestNumbers(arr);
    printArray(Array);
}


