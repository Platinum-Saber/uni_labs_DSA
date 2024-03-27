#include <iostream>
#include <vector>

using namespace std;

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

void swap(int *pointer_1, int *pointer_2){
    int temp = *pointer_1;
    *pointer_1 = *pointer_2;
    *pointer_2 = temp;
}


int main(){
    vector<int> Array = getArray();

}


