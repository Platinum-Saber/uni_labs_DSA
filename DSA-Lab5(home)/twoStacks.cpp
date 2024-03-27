#include <iostream>
#include <vector>
using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int sum = 0;
    int lenA = a.size();
    int lenB = b.size();
    int ia = 0;
    int ib = 0;
    int count = 0;
    
    while(sum < maxSum && ia < lenA && ib < lenB){
        int ptrA = a[ia];
        int ptrB = b[ib];
        
        if(ptrA <= ptrB){
            sum += ptrA;
            if(sum <= maxSum){
                count++;
            }
            else{
                break;
            }
            
            if(ia < lenA-1){
                ia++;
            }
            else{
                ptrA = maxSum+1;
            }
            
        }
        else{
            sum += ptrB;
            if(sum <= maxSum){
                count++;
            }
            else{
                break;
            }
            if(ib < lenB-1){
                ib++;
            }
            else{
                ptrB = maxSum+1;
            }
            
        }
        
    }
    return count;

}