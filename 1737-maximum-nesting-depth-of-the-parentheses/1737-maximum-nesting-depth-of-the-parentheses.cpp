class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int answer = INT_MIN;
        for(auto it : s){
 
            if(it=='('){
                count++;
            }
            answer=max(count,answer);
            if(it==')'){
                count--;
            }
        }
        return answer;
    }
};