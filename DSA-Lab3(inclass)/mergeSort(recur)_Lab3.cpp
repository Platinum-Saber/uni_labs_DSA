#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


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

void printArray(vector<int> arr){
    int len = arr.size();
    for(int i = 0; i < len; i++){
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
  /*int Num;
    vector<int> Arr;
    while(cin >> Num){
        Arr.push_back(Num);
        if (cin.peek() == '\n'){
            break;
        }
    } */