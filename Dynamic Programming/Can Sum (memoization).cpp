#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int sum;
	vector<int> dp, nums;
	bool solve(int sum, vector<int> nums) {
		if(sum < 0) return false;
		if(sum == 0) return true;
		if(dp[sum] != -1) return dp[sum];
		for(int num : nums) {
			if(solve(sum - num, nums)) {
				dp[sum] = true;
				return true;
			}
		}
		dp[sum] = false;
		return false;
	}
public:
	Solution(int sum, vector<int> nums) : sum(sum), nums(nums) {
		this->dp.assign(sum+1, -1);
	}
	bool canSum() {
		return solve(sum, nums);
	}
};

int main() {
	Solution test1(7, {2,3}), test2(7, {2,4});
	cout << test1.canSum() << endl;
	cout << test2.canSum();
	return 0;
}

