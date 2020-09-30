#include "Runnable.h"
#include <vector>
#include <iostream>
namespace permutations {
    using namespace std;
    
    class Solution : public Runnable {
    public:
        vector<vector<int>> result;
        void solve(vector<int> nums, int index, int length) {
            if (index >= length) {
                result.push_back(nums);
                return;
            }

            for (int i = index; i < length; i++) {
                std::cout << "swaping i= " << i << " index= " << index << std::endl;
                swap(nums[i], nums[index]);
                solve(nums, index + 1, length);
                //swap(nums[i], nums[index]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            solve(nums, 0, nums.size());
            return result;
        }

        // Inherited via Runnable
        virtual void Run() override
        {
            vector<int> arr = { 1, 2, 3};
            auto ans = permute(arr);
        }
    };
}