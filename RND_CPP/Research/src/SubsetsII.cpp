#include "Runnable.h"
#include <vector>
#include <algorithm>
using namespace std;
class SubSetsII : public Runnable {

private:
    vector<vector<int>> ans;
    int prev = INT_MIN;
    void backtrack(vector<int>& nums, vector<int> ss, int start) {

        ans.push_back(ss);

        for (int i = start; i < nums.size(); i++) {
            if (prev == nums[i]) continue;

            ss.push_back(nums[i]);
            backtrack(nums, ss, i + 1);
            ss.pop_back();

            prev = nums[i];

        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ss;
        backtrack(nums, ss, 0);
        return ans;
    }

    // Inherited via Runnable
    virtual void Run() override
    {
        vector<int> input = { 1,2,2 };
        SubSetsII ss2;
        auto res = ss2.subsetsWithDup(input);
    }
};