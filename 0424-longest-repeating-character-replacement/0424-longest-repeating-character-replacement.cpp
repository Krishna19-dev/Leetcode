class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frequency(26, 0);

        int left = 0;
        int maxFrequency = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            frequency[s[right] - 'A']++;

            maxFrequency = max(
                maxFrequency,
                frequency[s[right] - 'A']
            );

            while ((right - left + 1) - maxFrequency > k) {
                frequency[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};