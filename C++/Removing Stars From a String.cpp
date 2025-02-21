class Solution {
public:
    string removeStars(string s) {
        string starfree;
        int i = 0;
        while(i < s.size()){
            s[i] == '*' ? starfree.erase(starfree.size() - 1, 1) : starfree += s[i];
            i++;
        }
        return starfree;
    }
};