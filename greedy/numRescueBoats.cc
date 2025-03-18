// Time: O(n * log n)
// Space: O (log n)

// Algo intuition:
//       sort the people array so that we greedily choose the heaviest person to fit with the lightest person
class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
    
            unsigned int numBoats = 0;
            int beg = 0;
            int end = people.size() - 1;
    
            while (beg <= end) {
                if (people[beg] + people[end] <= limit) {
                    beg++;
                }
                end--;
                numBoats++;
            }
    
            return numBoats;    
        }
    };