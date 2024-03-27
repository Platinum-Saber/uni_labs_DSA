#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> heap;
    unordered_map<int, int> count;
    int turns;
    cin >> turns;
    for (int i = 0; i < turns; i++){
        int key;
        int value;
        cin >> key;
        if(key == 1){
            cin >> value;
            heap.push(value);
            count[value]++;
        }
        else if (key == 2){
            cin >> value;
            if (count[value] > 0) {
                count[value]--;
            }
        }
        else if (key == 3){
            while (!heap.empty() && count[heap.top()] == 0) {
                heap.pop();
            }
            if (!heap.empty()) {
                cout << "min : " << heap.top() << endl;
            }
        }
    }
}