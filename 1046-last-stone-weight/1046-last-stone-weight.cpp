class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int e1 = pq.top();
            pq.pop();
            int e2 = pq.top();
            pq.pop();
            int subs = abs(e1-e2);
            if(subs>0){
                pq.push(subs);
            }
             if(pq.size()==0){
                return 0;
            }
        }
        return pq.top();
    }
};