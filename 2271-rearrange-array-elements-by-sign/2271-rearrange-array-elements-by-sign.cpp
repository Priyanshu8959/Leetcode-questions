class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;
        vector<int>ans(n);
        for(auto it : nums){
            if(it>0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        int p=0;
        int r=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans[i]=pos[p];
                p++;
            }
            else{
                ans[i]=neg[r];
                r++;
            }
        }
        return ans;
    }
};