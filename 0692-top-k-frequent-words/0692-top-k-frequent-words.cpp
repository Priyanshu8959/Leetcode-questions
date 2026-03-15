class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,string> &a,const pair<int,string> &b){
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;

        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

        for(auto it : mp){
            int freq = it.second;
            string s = it.first;
            pq.push({freq, s});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};