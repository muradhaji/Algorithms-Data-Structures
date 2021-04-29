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
		for(int i = 1 ; i < m ; i++)
			cost[i][0] += cost[i-1][0];
		for(int j = 1 ; j < n ; j++)
			cost[0][j] += cost[0][j-1];
		for(int i = 1 ; i < m ; i++)
			for(int j = 1 ; j < n ; j++)
				cost[i][j] += min(cost[i-1][j-1], cost[i-1][j], cost[i][j-1]);
		return cost[m-1][n-1];
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
