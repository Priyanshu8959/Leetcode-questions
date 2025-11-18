class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int add = 0;
        for(auto it : s){
            if(it=='('){
                open++;
            }
            else if(open>0){
                open--;
            }
            else{
                add++;
            }
        }
        return abs(open+add);
    }
};