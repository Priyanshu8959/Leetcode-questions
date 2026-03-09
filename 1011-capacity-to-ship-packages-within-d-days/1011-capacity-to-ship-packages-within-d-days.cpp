class Solution {
public:
bool canship(vector<int>& weights,int mid, int days){
    int n = weights.size();
    int sum = 0,count=1;
    for(int i= 0;i<n;i++){
        sum+=weights[i];
        if(sum>mid){
            count++;
             sum=weights[i];
        }
       
    }
    return count<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int sum = 0,ans = 0;
        for(int i = 0;i<weights.size();i++){
            sum+=weights[i];
        }
        int high = sum;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(canship(weights,mid,days)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans ;
    }

};