class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int p = 0;
        int q = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                p--;
                p = max(p,0);
            }
            else{
                s[p]=s[i];
                p++;
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                q--;
                q = max(q,0);
            }
             else{
                t[q]=t[i];
                q++;
            }
        }

        if(p!=q){
            return false;
        }
        else{
            for(int i=0;i<q;i++){
                if(s[i]!=t[i]){
                    return false;
                }
            }
            return true;
        }
         
    }
};