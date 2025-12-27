#include <iostream>
#include <vector>
using namespace std;

void backtrack(int idx, int n, vector<int>& multiset, int x) {
	if (idx == n+1) {
		cout << "{";
		for (int i = 0; i < multiset.size(); i++) {
			cout << multiset[i];
			if (i != multiset.size() - 1)
				cout << ",";
		}
		cout << "}\n";
		return;
	}

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < i; j++)
			multiset.push_back(idx);
		backtrack(idx+1, n, multiset, x);
		for (int j = 0; j < i; j++)
			multiset.pop_back();
	}
}

bool casoDePrueba() {
	int n, x;
	cin >> n;

	if (!cin)
		return false;

	cin >> x;

	vector<int> multiset;
	backtrack(1, n, multiset, x);

	return true; 
}

int main() {
	while (casoDePrueba());
	return 0;
}