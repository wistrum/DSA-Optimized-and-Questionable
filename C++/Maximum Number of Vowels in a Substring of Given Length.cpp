class Solution {
public:
    int maxVowels(string s, int k) {
        int max = 0;
        unordered_map<char, bool> vowel;
        vowel['a'] = true;
        vowel['e'] = true;
        vowel['i'] = true;
        vowel['o'] = true;
        vowel['u'] = true;
        int count = 0;
        for(int i = 0, j = 0 ; j < s.size(); j++){
            if(vowel[s[j]]) count++;

            if(j >= k){
                if(vowel[s[i]]) count--;
                i++;
            }
            max = count > max ? count : max;
        }
        return max;
    }
};