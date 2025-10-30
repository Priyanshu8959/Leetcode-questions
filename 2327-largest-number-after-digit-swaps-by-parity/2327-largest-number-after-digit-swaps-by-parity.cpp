class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        vector<int> oddDigits, evenDigits;

        for (char ch : str) {
            int digit = ch - '0';
            if (digit % 2 == 0)
                evenDigits.push_back(digit);
            else
                oddDigits.push_back(digit);
        }

        sort(evenDigits.rbegin(), evenDigits.rend());
        sort(oddDigits.rbegin(), oddDigits.rend());

        int evenIndex = 0, oddIndex = 0;
        for (char &ch : str) {
            int digit = ch - '0';
            if (digit % 2 == 0)
                ch = evenDigits[evenIndex++] + '0';
            else
                ch = oddDigits[oddIndex++] + '0';
        }

        return stoi(str);
    }
};
