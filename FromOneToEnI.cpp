#include <iostream>
#include <vector>
using namespace std;

void backtrack(const int n, vector<int>& permutation, int idx, vector<bool>& contiene) {
	if (permutation.size() == n) {
		cout << "(";
		for (int i = 0; i < n; i++) {
			cout << permutation[i];
			if (i != permutation.size() - 1)
				cout << ",";
		}
		cout << ")\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!contiene[i-1]) {
			permutation.push_back(i);
			contiene[i - 1] = true;
			
			backtrack(n, permutation, idx, contiene);

			permutation.pop_back();
			contiene[i - 1] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> permutation;
	vector<bool> contiene(n, false);
	backtrack(n, permutation, 1, contiene);

	return 0;
}