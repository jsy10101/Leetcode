// Time: O(n)
// Space: O(1)
vector<int> combine(vector<int>& arr1, vector<int>& arr2) {
    // ans is the answer
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}
