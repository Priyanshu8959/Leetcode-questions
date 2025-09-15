class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // make a set of broken letters
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        int count = 0;    // answer
        bool canType = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                // end of word
                if (canType) count++;   // this word is good
                canType = true;         // reset for next word
            } else {
                if (broken.count(text[i])) {
                    canType = false;    // word has broken letter
                }
            }
        }
        return count;
    }
};
