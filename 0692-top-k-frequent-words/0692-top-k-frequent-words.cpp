class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,string>& a,const pair<int,string>& b){
            if(a.first != b.first)
                return a.first > b.first;       // smaller freq first
            return a.second < b.second;         // lexicographically larger first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mp;

        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<string> ans(k);

        for(int i = k-1; i >= 0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};