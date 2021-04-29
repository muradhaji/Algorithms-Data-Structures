#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c) {
	if(a < b) return (a < c) ? a : c;
	else return (b < c) ? b : c;
}

class MinCostPath {
private:
	vector<vector<int>> cost;
public:
	MinCostPath(int n, int m) {
		int a;
		for(int i = 0 ; i < m ; i++) {
			vector<int> temp;
			for(int j = 0 ; j < n ; j++) {
				cin >> a;
				temp.push_back(a);
			}
			cost.push_back(temp);
		}
	}
	int MinCost() {
		int m = cost.size(), n = cost[0].size();
		int dp[m][n];
		dp[0][0] = cost[0][0];
		for(int i = 1 ; i < m ; i++)
			dp[i][0] = dp[i-1][0] + cost[i][0];
		for(int j = 1 ; j < n ; j++)
			dp[0][j] = dp[0][j-1] + cost[0][j];
		for(int i = 1 ; i < m ; i++)
			for(int j = 1 ; j < n ; j++)
				dp[i][j] = cost[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
		return dp[m-1][n-1];
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	MinCostPath test(m, n);
	cout << test.MinCost();
	return 0;
}

/*
Test case:
3 3
1 2 3
4 8 2
1 5 3
Output:
8
*/
