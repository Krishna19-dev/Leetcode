class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int length = 0;

        // Last ke extra spaces skip karo
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Last word ke characters count karo
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};