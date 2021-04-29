#include <iostream>
using namespace std;

class Factorial {
public:
	int calculate(int n) {
		int dp[n+1];
		dp[0] = 1;
		for(int i = 1 ; i <= n ; i++)
			dp[i] = dp[i-1] * i;
		return dp[n];
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
