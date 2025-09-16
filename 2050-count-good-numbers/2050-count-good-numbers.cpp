class Solution {
private:
    static constexpr int mod = 1000000007;

    // fast exponentiation helper
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long part1 = power(5, evenCount);
        long long part2 = power(4, oddCount);

        return (part1 * part2) % mod;
    }
};
