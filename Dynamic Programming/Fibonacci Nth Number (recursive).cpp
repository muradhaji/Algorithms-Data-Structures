#include <iostream>
using namespace std;

class Fibonacci {
private:
	int solve(int n) {
		if(n < 2) return n;
		return solve(n-1) + solve(n-2);
	}
public:
	int nthNumber(int n) {
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
