class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,true);
        vector<int>ans;
        isprime[0]=false;
        isprime[1]=false;
        if(n<2){
            return ans.size();
        }
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j = i*i ;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        for(int i = 2;i<n;i++){
            if(isprime[i]){
                ans.push_back(i);
            }
        }
        return ans.size();
    }
};