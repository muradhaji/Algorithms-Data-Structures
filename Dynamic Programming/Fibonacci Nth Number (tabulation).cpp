#include <iostream>
using namespace std;

class Fibonacci {
public:
	int nthNumber(int n) {
		if(n == 0) return 0;
		int dp[n+1];
		dp[0] = 0;
		dp[1] = 1;
		for(int i = 2 ; i <= n ; i++)
			dp[i] = dp[i-1] + dp[i-2];
		return dp[n];
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
