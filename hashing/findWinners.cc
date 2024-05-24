// Time: O(n * log n)
//       - O(n) for building win_counts hashMap
//       - O(n * log n) sorting winners and players with only 1 loss
// Space: O()
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // unordered_map to store win and match counts
        unordered_map<int, pair<int, int>> win_counts;
        
        for (vector<int>& players: matches) {
            // If the player is seen for the first time, initialize their counts
            if (win_counts.find(players[0]) == win_counts.end()) {
                win_counts[players[0]] = {0, 0};
            }
            if (win_counts.find(players[1]) == win_counts.end()) {
                win_counts[players[1]] = {0, 0};
            }
            
            // Increase the match count for both players
            win_counts[players[0]].first++;
            win_counts[players[1]].first++;
            
            // Increase the win count for the winner (1st player)
            win_counts[players[0]].second++;
        }
        
        vector<vector<int>> ans(2);
        for (auto &[key, val]: win_counts) {
            // val.first is the number of matches, val.second is the number of wins
            // Player won all their matches
            if (val.first == val.second) {
                ans[0].push_back(key);
            } else if (val.first - val.second == 1) {
                ans[1].push_back(key);
            }
        }
        
        for (int i = 0; i < 2; ++i) {
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
