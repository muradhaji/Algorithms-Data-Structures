#include <iostream>
using namespace std;

class Factorial {
public:
	int calculate(int n) {
		if(n == 0) return 1;
		return n * calculate(n-1);
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
