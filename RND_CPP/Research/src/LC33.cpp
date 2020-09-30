#include "Runnable.h"
#include <vector>
using namespace std;
class LC33 : public Runnable {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		return find(nums, 0, nums.size() - 1, target);
	}

	int find(vector<int>& nums, int s, int e, int target) {
		if (s > e || (nums[s] <= nums[e] && (nums[s] > target))) return -1;
		int m = s + (e - s) / 2;
		if (nums[m] == target)
			return m;

		int x = find(nums, s, m - 1, target);
		int y = x > -1 ? x : find(nums, m + 1, e, target);
		return y;
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
		auto  r = search(v, 0);
		std::cout << r << std::endl;
	}
};