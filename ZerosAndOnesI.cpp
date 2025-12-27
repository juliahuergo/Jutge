#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& combinations, vector<int>& curr, int n) {
	if (curr.size() == n) {
		combinations.push_back(curr);
		return;
	}

	for (int i = 0; i <= 1; i++) { //concatenating 0 or 1
		curr.push_back(i);
		backtrack(combinations, curr, n);
		curr.pop_back();
	}
}

bool casoDePrueba() {
	int n;
	cin >> n;
	if (!cin)
		return false;

	vector<vector<int>> combinations;
	vector<int> curr;
	backtrack(combinations, curr, n);

	for (vector<int> comb : combinations) {
		for (int i = 0; i< comb.size(); i++) {
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