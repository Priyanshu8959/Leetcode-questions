class Solution {
public:
    bool possible(vector<int>& bloomDay, long long guess ,int m, int k){
        int n = bloomDay.size();

        int count = 0,bouquets=0;
        for(int i = 0;i<n;i++){
            if(guess>=bloomDay[i]){
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            else{
                count = 0;
            }
        }
        return bouquets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long )m*k;
        long long n = bloomDay.size();
        if(total > n ){
            return -1;
        }

        int result=-1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());  
        int high = *max_element(bloomDay.begin(), bloomDay.end());
         
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                result = mid;
                high = mid -1;
            }
            else{

                low = mid +1;
            }
        }
        return result ;
    }
};