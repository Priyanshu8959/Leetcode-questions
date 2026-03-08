class Solution {
public:
int maxivalue(vector<int>& piles) {
        int maxi = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long  totaltime(vector<int>& piles, int speed) {
    long long   time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += ceil((double)piles[i] / (double)speed);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
         int low = 1;
        int high = maxivalue(piles);
        while (low <= high) {
            int mid = (low + high) / 2;
            long long  caltime = totaltime(piles, mid);
            if (caltime <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low ;
    }
};