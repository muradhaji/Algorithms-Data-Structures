#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canSum(int sum, vector<int> nums) {
		if(sum < 0) return false;
		if(sum == 0) return true;
		for(int num : nums)
			if(canSum(sum - num, nums))
				return true;
		return false;
	}
};

int main() {
	Solution test;
	cout << test.canSum(7, {2,3}) << endl;
	cout << test.canSum(7, {2,4,6});
	return 0;
}

