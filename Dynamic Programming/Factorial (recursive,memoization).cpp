#include <iostream>
#include <vector>
using namespace std;

class Factorial {
private:
	vector<int> dp;
	int solve(int n) {
		if(n == 0) return 1;
		if(dp[n] != 0) return dp[n];
		dp[n] = n * solve(n-1);
		return dp[n];
	}
public:
	int calculate(int n) {
		dp.resize(n+1, 0);
		return solve(n);
	}
};

int main() {
	int n;
	cin >> n;
	Factorial test;
	cout << test.calculate(n);
	return 0;
}

/*
Test case:
7
Output:
5040
*/
