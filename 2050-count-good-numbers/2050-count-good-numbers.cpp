class Solution {
public:
    static constexpr int mod = 1000000007;

    long long power(long long x, long long p) {
        long long result = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            p /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evensteps = (n + 1) / 2;
        long long oddsteps = n / 2;

        long long temp1 = power(5, evensteps);
        long long temp2 = power(4, oddsteps);

        return (temp1 * temp2) % mod;
    }
};
