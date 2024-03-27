int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int sum = 0;
    int lenA = a.size();
    int lenB = b.size();
    int ia = 0;
    int ib = 0;
    int count = 0;
    int ptrA = a[0];
    int ptrB = b[0];
    
    while(sum <= maxSum && ia < lenA && ib < lenB){
        if(ptrA <= ptrB){
            if (ptrA != -1){
                sum += ptrA;
                if(sum <= maxSum){
                    count++;
                }
                else{
                    break;
                }
            
                if(ia < lenA-1){
                    ia++;
                    ptrA = a[ia];
                }
                else{
                    ptrA = -1;
                }
                
            }
            
            
        }
        else{
            if(ptrB != -1){
                sum += ptrB;
                if(sum <= maxSum){
                    count++;
                }
                else{
                    break;
                }
                if(ib < lenB-1){
                    ib++;
                    ptrB = b[ib];
                }
                else{
                    ptrB = -1;
                }
                
            }
            
            
        }
        
    }
    return count;

}
