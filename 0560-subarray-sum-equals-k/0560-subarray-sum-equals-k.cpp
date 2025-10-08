class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : arr) {
            sum += it;
            count =count + mp[sum - k];
            mp[sum]++; 
        }
        return count;
    }
};