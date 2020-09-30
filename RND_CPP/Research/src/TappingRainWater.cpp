#include "Runnable.h"

#include <vector>
#include <algorithm>
using namespace std;

struct TappigRainWater : public Runnable {
public:
	int trap(vector<int>& height) {

		int size = height.size();
		if (size < 3) return 0;

		vector<int> arr(size);
		arr[0] = height[0];

		for (int i = 1; i < size; i++) {
			arr[i] = max(arr[i - 1], height[i]);
		}

		int total = 0;

		int right = 0;
		for (int j = size - 1; j >= 0; j--) {

			right = max(height[j], right);
			int sum = (min(right, arr[j]) - height[j]);
			if (sum >= 0)
				total += sum;
		}
		return total;
	}

	// Inherited via Runnable
	virtual void Run() override
	{
		vector<int> heights;
		/*heights.push_back(0);
		heights.push_back(1);
		heights.push_back(0);
		heights.push_back(2);
		heights.push_back(1);
		heights.push_back(0);
		heights.push_back(1);
		heights.push_back(3);
		heights.push_back(2);
		heights.push_back(1);
		heights.push_back(2);
		heights.push_back(1);*/

		heights.push_back(2);
		heights.push_back(0);
		heights.push_back(2);

		auto result = trap(heights);
		_ASSERTE(result == 2);
	}
};