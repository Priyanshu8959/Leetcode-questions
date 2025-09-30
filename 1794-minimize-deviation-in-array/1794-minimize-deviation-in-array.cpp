class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
      priority_queue<int>pq;
      int mx= INT_MIN;
      int mn = INT_MAX;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]%2!=0){
            nums[i]*=2;
        }
        mx=max(nums[i],mx);
        mn= min(nums[i],mn);
      }  
      int mindevn = mx-mn;
      for(auto it :nums){
        pq.push(it);
      }
      while((pq.top())%2==0){
        int top = pq.top();
        pq.pop();
        mindevn=min(mindevn,top-mn);
        top/=2;
        mn=min(mn,top);
        pq.push(top);
      }
      mindevn = min(mindevn,pq.top()-mn);
      return mindevn;
    }
};