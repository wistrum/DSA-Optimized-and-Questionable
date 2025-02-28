//Worst case time complexity: O(n^2)
//Can be reduced to O(n) by using a linked list instead of vector.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> out;
        int j = asteroids.size() - 2;
        while(j >= 0 && j < asteroids.size() - 1){
            cout<<j<<endl;
            if(asteroids[j] > 0 && asteroids[j + 1] < 0){
                if(abs(asteroids[j]) > abs(asteroids[j + 1])){
                    asteroids.erase(asteroids.begin() + j + 1);
                    if(asteroids.size() - 1 == j) j--;
                    continue;
                } 
                else if(abs(asteroids[j]) < abs(asteroids[j + 1])){
                    asteroids.erase(asteroids.begin() + j);
                    j--;
                    continue;
                }
                else if(abs(asteroids[j]) == abs(asteroids[j + 1])){
                    asteroids.erase(asteroids.begin() + j + 1);
                    asteroids.erase(asteroids.begin() + j);
                    j--;
                    if(asteroids.size() - 1 == j){
                        j--;
                    }
                    continue;
                }
            }
            j--;
        }
        return asteroids;
    }
};