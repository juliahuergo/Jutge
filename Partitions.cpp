#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void backtrack(int idx, const vector<string>& palabras, vector<vector<string>>& subsets) {
	if (idx == palabras.size()) {
		for (int i = 0; i < subsets.size(); i++) {
			cout << "subset " << i + 1 << ": {";
			for (int j = 0; j < subsets[i].size(); j++) {
				cout << subsets[i][j];
				if (j != subsets[i].size() - 1)
					cout << ",";
			}
			cout << "}\n";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < subsets.size(); i++) {
		subsets[i].push_back(palabras[idx]);
		backtrack(idx + 1, palabras, subsets);
		subsets[i].pop_back();
	}
	
}

bool casoDePrueba() {
	int n, p;
	cin >> n;

	if (!cin)
		return false;


	vector<string> palabras(n);
	for (int i = 0; i < n; i++) {
		cin >> palabras[i];
	}

	cin >> p;

	vector<vector<string>> subsets(p);
	backtrack(0, palabras, subsets);

	return true;
}

int main() {
	while (casoDePrueba());
	return 0;
}
