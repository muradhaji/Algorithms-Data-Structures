#include <iostream>
using namespace std;

class GridTraveller {
private:
	int solve(int m, int n) {
		if(m < 0 || n < 0) return 0;
		if(m == 0 && n == 0) return 1;
		return solve(m-1,n) + solve(m,n-1);
	}
public:
	int numOfWays(int m, int n) {
		return solve(m-1, n-1);
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	GridTraveller test;
	cout << test.numOfWays(m,n);
	return 0;
}

/*
Test case:
2 3
Output:
3
*/

