// Time: O( (k + n) * log n )
// Space: O(n) (heap)

// Algo intuition:
//      we want to greedily choose the maxProfitable project first given the projects we can afford at any given time
//      create a vector called projects to store the capital and profit and then sort it (sort by capital)
//      add the list of projects profit into a heap (in order to choose max profit at that time)
//      if heap is empty, we can't choose any project and return w (current capital)
//      else add the profit of the most profitable project to w
//      for heap, we do atmost n pushes (list of available capital projects)
//      and atmost k pops therefore ((k + n) * log n) time

class Solution {
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            vector<pair<int, int>> projects;
            int n = int(profits.size());
    
            for (int i = 0; i < n; ++i) {
                projects.push_back({capital[i], profits[i]});
            }
    
            sort(projects.begin(), projects.end());
    
            priority_queue<int> heap;
            int i = 0;
            
            for (int j = 0; j < k; ++j) {
                while (i < n && projects[i].first <= w) {
                    heap.push(projects[i].second);
                    ++i;
                }
    
                if (heap.empty()) return w;
    
                // add the most profitable project's profit to capital w
                w += heap.top();
                heap.pop();
            }
    
            return w;
        }
    };