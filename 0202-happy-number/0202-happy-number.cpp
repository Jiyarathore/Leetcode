class Solution {
public:
    
//     Time Complexity O(logn)
//     Space Complexity O(logn) hash table unordered set space
    
//     int nextNumber(int n){
//         int newNumber=0;
//         while(n!=0){
// int num=n%10;
//             newNumber+=num*num;
//             n=n/10;
//         }
//         return newNumber;
//     }
    
//     bool isHappy(int n) {
//         unordered_set<int>set;
//         while(n!=1 && set.count(n)==0){
//             set.insert(n);
//             n=nextNumber(n);
//         }
//         return n==1;
//     }
    
//     Floyd's Cycle Finding ALgo/ Hare-Tortoise algorithm
    
    int nextNumber(int n){
        int newNumber=0;
        while(n!=0){
            int num=n%10;
            newNumber += num*num;
            n=n/10;
        }
        return newNumber;
    }
    
    bool isHappy(int n){
        int slowPointer=n;
        int fastPointer=nextNumber(n);
        
        while(fastPointer!=1 && fastPointer != slowPointer){
            slowPointer=nextNumber(slowPointer);
            fastPointer=nextNumber(nextNumber(fastPointer));
        }
        return fastPointer==1;
    }
};