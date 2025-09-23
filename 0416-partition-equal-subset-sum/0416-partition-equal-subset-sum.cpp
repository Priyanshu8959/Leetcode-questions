class Solution {
public:
bool sumOFsubset(vector<int>& nums,int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                t[0][j]=false;
            }
            if(j==0){
                t[i][0]= true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(nums[i-1]<=j){
                t[i][j]= t[i-1][j]||t[i-1][j-nums[i-1]];
            }
            else if(nums[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }
     return t[n][sum];
}
    bool canPartition(vector<int>& nums) {
       int sum =0;
       int n = nums.size();
       for(int i=0;i<n;i++){
            sum+=nums[i];
       } 
       if(sum%2!=0){
        return false;
       }
       else{
        return sumOFsubset(nums,nums.size(),sum/2);
       }
    }
};