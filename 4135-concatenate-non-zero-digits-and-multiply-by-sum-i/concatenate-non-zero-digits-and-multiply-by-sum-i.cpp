class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long ans = 0;
        long long lastdigit = 0;
        while(n>0){
            lastdigit = n%10;
            n = n/10;
            if(lastdigit != 0){
                ans = ans*10 + lastdigit;
                sum += lastdigit;
            }
        }
        long long x = 0;
        while(ans>0){
            int lastdigit2 = ans%10;
            x = x*10 + lastdigit2;
            ans = ans/10;
        }
        return x*sum;
    }
};