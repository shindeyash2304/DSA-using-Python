class Solution {
public:
    // Find index of next strictly greater element to the right for each position
    vector<int> computeNextGreaterIndices(const vector<int>& nums) {
        int lengthOfArray = nums.size();
        vector<int> nextGreaterIndex(lengthOfArray, lengthOfArray); // default sentinel: no greater → n
        stack<int> indexStack;

        for (int readPos = lengthOfArray - 1; readPos >= 0; --readPos) {
            // Pop all elements ≤ current, since they can't be "next greater"
            while (!indexStack.empty() && nums[indexStack.top()] <= nums[readPos]) {
                indexStack.pop();
            }
            if (!indexStack.empty()) {
                nextGreaterIndex[readPos] = indexStack.top();
            }
            indexStack.push(readPos);
        }
        return nextGreaterIndex;
    }

    // Find index of previous strictly greater element to the left for each position
    vector<int> computePrevGreaterIndices(const vector<int>& nums) {
        int lengthOfArray = nums.size();
        vector<int> prevGreaterIndex(lengthOfArray, -1); // default sentinel: no greater → -1
        stack<int> indexStack;

        for (int readPos = 0; readPos < lengthOfArray; ++readPos) {
            while (!indexStack.empty() && nums[indexStack.top()] <= nums[readPos]) {
                indexStack.pop();
            }
            if (!indexStack.empty()) {
                prevGreaterIndex[readPos] = indexStack.top();
            }
            indexStack.push(readPos);
        }
        return prevGreaterIndex;
    }

    int longestSubarray(vector<int>& nums) {
        int total = nums.size();
        vector<int> nextGreater = computeNextGreaterIndices(nums);
        vector<int> prevGreater = computePrevGreaterIndices(nums);

        int bestValidLength = 0;
        for (int position = 0; position < total; ++position) {
            int windowLength = nextGreater[position] - prevGreater[position] - 1;
            // Check if the maximum element of this window (nums[position]) fits the condition
            if (windowLength >= nums[position]) {
                bestValidLength = max(bestValidLength, windowLength);
            }
        }
        return bestValidLength;
    }
};