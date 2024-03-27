#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

int main() {
    vector<int> arr = {2, 7, 3, 6, 4, 6, 7};
    int k = 9;
    buildMinHeap(arr);
    int count = 0;

    while (arr.size() > 1 && arr[0] < k) {
        int leastSweet = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        minHeapify(arr, arr.size(), 0);
        int secondLeastSweet = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        minHeapify(arr, arr.size(), 0);

        int mixedSweetness = leastSweet + 2 * secondLeastSweet;
        arr.push_back(mixedSweetness);
        minHeapify(arr, arr.size(), arr.size() - 1);
        count++;
    }

    if (arr[0] < k) {
        cout << -1 << endl; // it's impossible to increase the sweetness to k
    } else {
        cout << count << endl;
    }
}