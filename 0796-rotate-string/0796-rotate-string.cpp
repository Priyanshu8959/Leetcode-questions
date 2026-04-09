class Solution {
public:
    bool rotateString(string s, string goal) {
int n = s.size();
string result = "";
int i= 0;
while(n--){
    if(s==goal){
        return true;
    }
    char first = s[0];
    s=s.substr(1);
    s=s+first;
    i++;
}
return false;
    }
};