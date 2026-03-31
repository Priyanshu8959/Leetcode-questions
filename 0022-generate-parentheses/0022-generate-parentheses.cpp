class Solution {
public:
    void helper(string temp, int open, int close, int n,
                   vector<string>& res) {
        if ( open==n && close==n) {
            res.push_back(temp);
            return;
        }
        if (open < n){
            temp.push_back('(');
             helper (temp, open + 1, close, n, res);
             temp.pop_back();
        }
            
             
        if (close < open){
            temp.push_back(')');
          helper(temp , open, close + 1, n, res); 
          temp.pop_back(); 
        }
     }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", 0, 0, n, res);
        return res;
    }
};