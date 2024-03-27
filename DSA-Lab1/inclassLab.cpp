#include <iostream>
#include <vector>
using namespace std;

vector<int> getInput(){
    vector<int> array;
    int Num;
    while(cin >> Num){
        array.push_back(Num);
        if(cin.peek() == '\n'){
            break;
        }
    }
    return array;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(vector<int> arr, int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function to rearrange array (find the partition point)
int partition(vector<int> array, int low, int high) {
    
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(vector<int>array, int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


int main() {
  vector<int> data = getInput();
  int n = data.size();
  quickSort(data, 0, n - 1);
  printArray(data, n);
}