class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        // Frequency of characters in s1
        for (char ch : s1) {
            s1Freq[ch - 'a']++;
        }

        int windowSize = s1.size();

        // Create the first window
        for (int i = 0; i < windowSize; i++) {
            windowFreq[s2[i] - 'a']++;
        }

        if (s1Freq == windowFreq) {
            return true;
        }

        // Slide the window
        for (int right = windowSize; right < s2.size(); right++) {
            // Add the new character
            windowFreq[s2[right] - 'a']++;

            // Remove the character leaving the window
            int left = right - windowSize;
            windowFreq[s2[left] - 'a']--;

            if (s1Freq == windowFreq) {
                return true;
            }
        }

        return false;
    }
};