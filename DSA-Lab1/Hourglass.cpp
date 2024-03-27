#include <iostream>
using namespace std;
int main(){
    int sum; 
    int arr[4][4] = {{5,1,1,0},{0,1,1,1},{0,0,1,1},{1,1,0,0}};
    int height = sizeof(arr)/sizeof(arr[0]);
    int length = sizeof(arr[0])/sizeof(arr[0][0]);
    int max = 0;
    for(int down = 0; down < height - 2; down++){
        for(int right = 0; right < length - 2; right++){
            int sum1 = arr[down][right] + arr[down][right + 1]+  arr[down][right + 2];
            int sum2 = arr[down + 1][right + 1];
            int sum3 = arr[down + 2][right] + arr[down + 2][right + 1] + arr[down + 2][right + 2];
            sum = sum1 + sum2 + sum3;
            if(sum > max){
                max = sum;
            }
        }
     }
     cout << max;
}