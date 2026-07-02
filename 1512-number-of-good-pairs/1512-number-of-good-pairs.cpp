class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int , int> freq;
       int count = 0;

       for(int i=0;i<nums.size();i++){
        count += freq[nums[i]];
        freq[nums[i]]++;
       }
       return count ;

    }
};