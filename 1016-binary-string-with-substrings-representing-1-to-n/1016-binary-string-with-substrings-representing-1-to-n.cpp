class Solution {
public:
// doont think about sliding window , think like convert each number into binary and check in string 
    bool queryString(string s, int n) {
         
        for(int i=n;i>(n/2);i--){
            string ans = "";
            int nums = i;
            while(nums>0){
                ans=char('0'+ nums%2)+ans;
                nums/=2;
            }
            if(s.find(ans)==string::npos){
                return false;
            }
        }
        return true;
    }
};