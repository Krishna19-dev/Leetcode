class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        int required = 0;

        // Store frequencies of characters in t
        for (char ch : t) {
            if (need[ch] == 0) {
                required++;
            }

            need[ch]++;
        }

        int left = 0;
        int formed = 0;

        int minLength = INT_MAX;
        int startIndex = 0;

        for (int right = 0; right < s.length(); right++) {
            char rightChar = s[right];

            window[rightChar]++;

            // This character has reached its required frequency
            if (need[rightChar] > 0 &&
                window[rightChar] == need[rightChar]) {
                formed++;
            }

            // Current window contains all required characters
            while (formed == required) {
                int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    startIndex = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                // Removing this character makes the window invalid
                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};