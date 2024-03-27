#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> merge(vector<int>& leftArr, vector<int>& rightArr) {
    int lenL = leftArr.size();
    int lenR = rightArr.size();
    vector<int> mergedArr(lenL + lenR);
    int l = 0, r = 0, m = 0;

    while (l < lenL && r < lenR) {
        if (leftArr[l] < rightArr[r]) {
            mergedArr[m] = leftArr[l];
            l++;
        } else {
            mergedArr[m] = rightArr[r];
            r++;
        }
        m++;
    }

    while (l < lenL) {
        mergedArr[m] = leftArr[l];
        l++;
        m++;
    }

    while (r < lenR) {
        mergedArr[m] = rightArr[r];
        r++;
        m++;
    }

    return mergedArr;
}

vector<int> mergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int currentSize = 1; currentSize < n; currentSize *= 2) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize) {
            int mid = min(leftStart + currentSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currentSize - 1, n - 1);

            vector<int> leftArr(arr.begin() + leftStart, arr.begin() + mid + 1);
            vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + rightEnd + 1);

            vector<int> mergedArr = merge(leftArr, rightArr);

            // Copy the merged array back to the original array
            int mergedArrLen = mergedArr.size();
            for (int i = 0; i < mergedArrLen; i++) {
                arr[leftStart + i] = mergedArr[i];
            }
        }
    }

    return arr;
}

void printArray(const vector<int>& arr) {
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<std::string> in;
    //open input file
    string data;
    fstream file;
    file.open("input_arr.txt", ios::in);
    if (file.is_open())
    {
        string data;
        while (getline(file, data))
        {
            in.push_back(data);
        }
    }
    file.close();
    int n = in.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        string a = in[i];
        stringstream stream(a);
        vector<int> Arr;
        int num;
        while(stream)
        {
            stream >> num;
            Arr.push_back(num);
        }

        //start clock
        auto start = high_resolution_clock::now();

        (mergeSort(Arr));

        //stop clock
        auto stop = high_resolution_clock::now();
        //calc time
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << duration.count() << endl;

    }  
    return 0;

}




/*int main(){
    int num;
    vector<int> Arr;
    while(cin >> num){
        Arr.push_back(num);
        if (cin.peek() == '\n'){
            break;
        }
    }

    //start clock
    auto start = high_resolution_clock::now();

    printArray(mergeSort(Arr));

    //stop clock
    auto stop = high_resolution_clock::now();
    
    //calc time
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}*/
