class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int pile : piles) {
                hours += (pile - 1) / mid + 1;
            }

            if (hours <= h) {
                right = mid;      // mid possible hai; smaller speed check karo
            } else {
                left = mid + 1;   // speed badhani padegi
            }
        }

        return left;
    }
};