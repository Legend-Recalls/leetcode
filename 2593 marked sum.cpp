#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        // Min-heap to store pairs of (value, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Push all elements into the heap
        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i], i});
        }

        // Vector to keep track of marked elements
        vector<bool> marked(n, false);

        // Process the heap
        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();

            // If already marked, skip
            if (marked[index]) continue;

            // Add the value to the score
            score += value;

            // Mark the current element and its adjacent elements
            marked[index] = true;
            if (index > 0) marked[index - 1] = true; // Left neighbor
            if (index < n - 1) marked[index + 1] = true; // Right neighbor
        }

        return score;
    }
};
