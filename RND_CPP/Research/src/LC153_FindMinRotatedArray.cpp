#include "Runnable.h"
#include <vector>

using namespace std;
class LC153_FindMinRotatedArray : public Runnable {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return INT_MAX;

		return find(nums, 0, nums.size() - 1, INT_MAX);

	}

	int find(vector<int>& nums, int s, int e, int min) {
		if (s > e || (nums[s] <= nums[e] && nums[s] > min)) return min;
		int m = s + (e - s) / 2;
		if (nums[m] < min)
			min = nums[m];

		int x = find(nums, s, m-1, min);
		int y = find(nums, m + 1, e, min);
		return x <= y ? x : y;
		
	}

	// Inherited via Runnable
	virtual void Run() override
	{
		std::vector<int> v;
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		auto  r = findMin(v);
		std::cout << r << std::endl;
	}
};