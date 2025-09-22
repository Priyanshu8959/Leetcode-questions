class Solution {
public:
    int fib(int n) {
        //using dp 
        if(n<=1)return n;//base condintion
        int t[n+1];
        t[0]=0;
        t[1]=1;
        for(int i=2;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        return t[n];
    }
};