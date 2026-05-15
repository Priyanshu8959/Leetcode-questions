class Solution {
public:
void solve(int n,vector<string>&ans,string s){
    if(n==0){
        ans.push_back(s);
        return;
    }
    if(s.empty() || s.back()=='1'){
    solve(n-1,ans,s+'1');
    solve(n-1,ans,s+'0');
    }
    else{
        solve(n-1,ans,s+'1');
    }
     
}
    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(n,ans,"");
        return ans;
    }
};