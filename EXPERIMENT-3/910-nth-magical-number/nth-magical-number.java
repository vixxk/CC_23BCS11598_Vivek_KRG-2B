class Solution {
    long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public int nthMagicalNumber(int n, int a, int b) {
        long s =Math.min(a,b);
        long e = n*s;
        long lcm = (a/gcd(a,b))*b;
         long mod = 1000000007L;
        while(s<e){
            long mid = s+(e-s)/2;
            long mc = (mid/a) + (mid/b) - (mid/lcm);
            if(mc>=n){
                e=mid;
            } else {
                s=mid+1;
            }
        }
        
        return (int)(s%mod);
    }
}