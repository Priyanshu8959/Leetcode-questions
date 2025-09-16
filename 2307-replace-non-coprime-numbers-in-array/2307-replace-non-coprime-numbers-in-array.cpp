class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            ans.push_back(x);
            while (ans.size() > 1) {
                int a = ans[ans.size() - 2];
                int b = ans.back();
                int g = gcd(a, b);
                if (g > 1) {
                    ans.pop_back();
                    ans.pop_back();
                    long long lcm = (1LL * a / g) * b;  
                    ans.push_back((int) lcm);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
