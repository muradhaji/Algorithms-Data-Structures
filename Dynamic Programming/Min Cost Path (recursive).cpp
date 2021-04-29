#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c) {
    if (a < b) return (a < c) ? a : c;
    else return (b < c) ? b : c;
}

class MinCostPath {
private:
	vector<vector<int>> cost;
	int solve(int m, int n) {
		if(m < 0 || n < 0)
			return INT_MAX;
		else if(m == 0 && n == 0)
			return cost[m][n];
		else
			return cost[m][n] + min(solve(m-1,n), solve(m, n-1), solve(m-1, n-1));
	}
public:
	MinCostPath(int m, int n) {
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
		int m = this->cost.size(), n = this->cost[0].size();
		return solve(m-1, n-1);
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
