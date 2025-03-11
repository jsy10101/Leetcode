// Time: O(n * log n)
// Space: O(log n) // if quicksort used
class Solution {
    public:
        bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
            // intuition is to use the asteroids with greater mass in the end
            // best way is to sort the array of asteriods and choose the smallest
    
            sort(asteroids.begin(), asteroids.end());
            long m = mass;
            for (auto asteroid: asteroids) {
                if (asteroid > m) {
                    return false;
                }
                m += asteroid;
            }
    
            return true;
        }
    };