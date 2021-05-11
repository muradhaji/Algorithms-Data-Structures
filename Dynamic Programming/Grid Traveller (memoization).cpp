#include <iostream>
#include <vector>
using namespace std;

class GridTraveller {
private:
	int m, n;
	vector<vector<int>> dp;
	int solve(int m, int n) {
		if(m < 0 || n < 0) return 0;
		if(m == 0 && n == 0) return 1;
		if(dp[m][n] != 0) return dp[m][n];
		dp[m][n] = dp[n][m] = solve(m-1,n) + solve(m,n-1);
		return dp[m][n];
	}
public:
	GridTraveller(int m, int n) : m(m), n(n) {
		dp.resize(m);
		for(int i = 0 ; i < m ; i++)
			dp[i].resize(n);
	}
	int numOfWays() {
		return solve(m-1, n-1);
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	GridTraveller test(m,n);
	cout << test.numOfWays();
	return 0;
}

/*
Test case:
2 3
Output:
3
*/

