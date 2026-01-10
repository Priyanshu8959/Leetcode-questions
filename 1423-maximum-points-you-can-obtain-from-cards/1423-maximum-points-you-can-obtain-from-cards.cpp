class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;

        for (int x : cardPoints) totalSum += x;

        // If we take all cards
        if (k == n) return totalSum;

        int windowSize = n - k;
        int i = 0, j = 0;
        int windowSum = 0;
        int minWindowSum = INT_MAX;

        while (j < n) {
            windowSum += cardPoints[j];

            if (j - i + 1 < windowSize) {
                j++;
            }
            else if (j - i + 1 == windowSize) {
                minWindowSum = min(minWindowSum, windowSum);

                windowSum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return totalSum - minWindowSum;
    }
};
