// Time: O(n log n)
// Space: O(n)
// Algo intuition:
//      we first sort the position in descending order
//      we can then calculate the time it takes for the car to reach target
//      time = (target - position) / speed
//      we put this time onto a stack
//      then we find the time for the next car (moving in descending order)
//      we again calculate the time, now if the current time is less than top of
//      stack
//          this would imply that the first and the second car collide, hence in
//          this case both cars would become a fleet and would travel with the
//          slower speed, i.e., we don't push on stack in this case
//  (10 - 4) = 6 / 2 = 3
//  (10 - 2) = 8 / 3 = 2.66
//  stack.top() = 3
//  time = 
class Solution {
private:
    struct Comparator {
        bool operator() (const auto &p1, const auto &p2) {
            return p1.first > p2.first;
        }
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.begin(), pair.end(), Comparator());
        // or
        // sort(pair.rbegin(), pair.rend()) will sort in descending order

        // vector<double> stack;
        stack<double> stack;
        for (auto& p : pair) {
            // stack.push_back((double)(target - p.first) / p.second);
            // if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
            //     stack.pop_back();
            // }
            double time = (double) (target - p.first) / p.second;
            
            if (!stack.empty() && stack.top() >= time) {
                continue;
            } else {
                stack.push(time);
            }
        }
        return stack.size();
    }
};