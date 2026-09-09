class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {

            // sequence tabhi start karenge
            // jab num-1 exist nahi karta
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int count = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};