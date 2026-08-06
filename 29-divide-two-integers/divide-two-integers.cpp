// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if(dividend==divisor)
//         return 1;
//         bool sign=true;
//         if(dividend>=0&&divisor<0) sign=false;
//         else if(dividend<=0&&divisor>0) sign=false;
//         long n=abs(dividend);
//         long d=abs(divisor);
//         divisor=abs(divisor);
//         long quotient=0;
//         while(n>=d){
//             int cnt=0;
//             while(n>=(d<<(cnt+1))){
//                 cnt+=1;
//             }
//             quotient+=1<<cnt;
//             n-=(d<<cnt);
//         }
//         if(quotient==(1<<31)&&sign){
//             return INT_MAX;
//         }
//         if(quotient==(1<<31)&&!sign){
//             return INT_MIN;
//         }
//         return sign?quotient:-quotient;
        
//     }
// };

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit signed integer overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == divisor) {
            return 1;
        }

        // Determine the sign of the quotient
        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;

        // Use long long and llabs to safely handle INT_MIN without overflow
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        
        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            // Shifting 64-bit d prevents overflow during bitwise shift
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += (1LL << cnt); // Use 1LL instead of 1 to avoid 32-bit overflow
            n -= (d << cnt);          // Subtract to decrease n
        }

        return sign ? quotient : -quotient;
    }
};