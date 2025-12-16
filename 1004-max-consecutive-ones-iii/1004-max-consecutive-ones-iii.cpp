class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int countzero = 0;
        int length = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                countzero++;
                
            }
           while (countzero > k) {
                if (nums[i] == 0) {
                    countzero--;
                
                }
                i++;
            }
            length = max(length, (j - i + 1));
            j++;
        }       
        return length;
    }    
};
