class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int halfLength = n / 2;

        vector<int> frequency(26, 0);

        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        int oddCount = 0;
        char middleCharacter = '\0';

        for (int i = 0; i < 26; i++) {
            if (frequency[i] % 2 == 1) {
                oddCount++;
                middleCharacter = char('a' + i);
            }
        }

        // Palindromic permutation is impossible
        if (oddCount > 1) {
            return "";
        }

        if (n % 2 == 0 && oddCount != 0) {
            return "";
        }

        vector<int> halfFrequency(26);

        for (int i = 0; i < 26; i++) {
            halfFrequency[i] = frequency[i] / 2;
        }

        string targetHalf = target.substr(0, halfLength);
        vector<int> remaining = halfFrequency;

        int matched = 0;

        // Match target's first half
        while (matched < halfLength) {
            int character = targetHalf[matched] - 'a';

            if (remaining[character] == 0) {
                break;
            }

            remaining[character]--;
            matched++;
        }

        // Exact first half is possible
        if (matched == halfLength) {
            string palindrome = buildPalindrome(
                targetHalf,
                middleCharacter,
                n
            );

            if (palindrome > target) {
                return palindrome;
            }

            remaining.assign(26, 0);
        }

        int startPosition;

        if (matched == halfLength) {
            startPosition = halfLength - 1;
        } else {
            startPosition = matched;
        }

        // Find the rightmost position that can be increased
        for (int position = startPosition; position >= 0; position--) {
            if (position < matched) {
                remaining[targetHalf[position] - 'a']++;
            }

            int currentCharacter = targetHalf[position] - 'a';

            for (int nextCharacter = currentCharacter + 1;
                 nextCharacter < 26;
                 nextCharacter++) {

                if (remaining[nextCharacter] == 0) {
                    continue;
                }

                vector<int> updatedRemaining = remaining;
                updatedRemaining[nextCharacter]--;

                string firstHalf = targetHalf.substr(0, position);
                firstHalf += char('a' + nextCharacter);

                // Smallest possible suffix
                for (int character = 0; character < 26; character++) {
                    firstHalf.append(
                        updatedRemaining[character],
                        char('a' + character)
                    );
                }

                return buildPalindrome(
                    firstHalf,
                    middleCharacter,
                    n
                );
            }
        }

        return "";
    }

private:
    string buildPalindrome(
        const string& firstHalf,
        char middleCharacter,
        int n
    ) {
        string result = firstHalf;

        if (n % 2 == 1) {
            result += middleCharacter;
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        result += secondHalf;

        return result;
    }
};