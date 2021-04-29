#include <iostream>
#include <vector>
using namespace std;

class Fibonacci {
private:
	vector<int> dp;
	int solve(int n) {
		if(n < 2) return n;
		if(dp[n] != 0) return dp[n];
		dp[n] = solve(n-1) + solve(n-2);
		return dp[n];
	}
public:
	int nthNumber(int n) {
		dp.resize(n+1,0);
		return solve(n);
	}
};

int main() {
	int n;
	cin >> n;
	Fibonacci test;
	cout << test.nthNumber(n);
	return 0;
}

/*
Test case:
7
Output:
13
*/
