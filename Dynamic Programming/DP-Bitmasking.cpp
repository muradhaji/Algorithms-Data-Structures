#include <iostream>
#include <vector>
using namespace std;

class DPBitmask {
private:
	int n;
	vector<vector<int>> cost, dp;
	int solve(int j, int mask) {
		if(j < 0) return 0;
		if(dp[j][mask] != 0) return dp[j][mask];
		int mincost = INT_MAX;
		for(int p = 0 ; p < n ; p++)
			if(mask & (1<<p))
				mincost = min(mincost, cost[j][p] + solve(j-1, mask^(1<<p)));
		return dp[j][mask] = mincost;
	}
public:
	DPBitmask (int size): n(size) {
		cost.resize(n);
		for(int i = 0 ; i < n ; i++) {
			cost[i].resize(n);
			for(int j = 0 ; j < n ; j++)
				cin >> cost[i][j];
		}
		dp.resize(n);
		for(int i = 0 ; i < n ; i++)
			dp[i].resize((1<<n)-1);
	}
	int minCost() {
		return solve(n-1, (1<<n)-1);
	}
};

int main() {
	int n;
	cin >> n;
	DPBitmask test(n);
	cout << test.minCost();
	return 0;
}

/*
Test case:
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
Output:
13
*/

