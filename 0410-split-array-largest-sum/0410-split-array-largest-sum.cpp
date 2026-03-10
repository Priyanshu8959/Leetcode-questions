class Solution {
public:
bool possible (vector<int>& nums, int k,int mid){
    int sum = 0,split=1; 
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }
        else{
            split++;
            sum=nums[i];
        }
    }
    return split<=k;
}
    int splitArray(vector<int>& nums, int k) {
     int low = *max_element(nums.begin(),nums.end()),high = 0;
     for(int i=0;i<nums.size();i++){
          high += nums[i];
     }   
     int ans = 0;
     while(low<=high){
        int mid = low + (high-low)/2;
        if(possible(nums,k,mid)){
            ans=mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
     }
     return ans ;
    }
};