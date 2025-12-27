#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<vector<int>>& combinations, vector<int>& curr, int n, int o, vector<int>& contadores) {
	if (curr.size() == n && contadores[1] == o) {
		combinations.push_back(curr);
		return;
	}

	for (int i = 0; i <= 1; i++) {
		if ((i == 1 && contadores[i] < o) ||(i==0 && contadores[i] < n-o)) {
			curr.push_back(i);
			contadores[i]++;
			backtracking(combinations, curr, n, o, contadores);
			curr.pop_back();
			contadores[i]--;
		}
	}
}

bool casoDePrueba() {
	int n, o;
	cin >> n;

	if (!cin)
		return false;

	cin >> o;

	vector<vector<int>> combinations;
	vector<int> curr;
	vector<int> contadores = { 0,0 };
	backtracking(combinations, curr, n, o, contadores); 

	for (vector<int> comb : combinations) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i];
			if (i != comb.size() - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return true;
}

int main() {
	while (casoDePrueba());
	return 0;
}