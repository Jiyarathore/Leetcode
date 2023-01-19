class Solution {
public:
    int findIntegers(int n) {
        int fib[31]; // 31 bits to represemt a no. of 1e9 numver
        fib[0]=1;
        fib[1]=2;
        
        for(int i=2;i<30;i++){
            fib[i]=fib[i-1] + fib[i-2];
        }
        int ans=0,count=30,prev_bit_one =0;
        
        while(count>=0){
            if(n & (1<<count)){// we did left shift because we have to find at what location in input number if it's a binary representation we have a 1 bit
                ans+=fib[count];
                if(prev_bit_one) return ans;
                prev_bit_one =1;
            }
            else{
                prev_bit_one=0;
            }
            count--;
        }
        return ans+1;
    }
};