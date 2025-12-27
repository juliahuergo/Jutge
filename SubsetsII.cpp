#include <iostream>
#include <vector>
using namespace std;

void backtrack(int idx, int m, vector<string>& subset, vector<string>& palabras) {
	if (subset.size() > m || subset.size() + (palabras.size()-idx) < m)
		return;
	
	if (subset.size() == m) {
		cout << "{";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i];
			if (i != subset.size() - 1)
				cout << ",";
		}
		cout << "}\n";
		return;
	}

	if (idx < palabras.size()) {
		subset.push_back(palabras[idx]);
		backtrack(idx + 1, m, subset, palabras);
		subset.pop_back();

		backtrack(idx + 1, m, subset, palabras);
	}
	
}

bool casoDePrueba() {
	int m, n;
	cin >> m;

	if (!cin)
		return false;

	cin >> n;

	vector<string> palabras(n);
	for (int i = 0; i < n; i++)
		cin >> palabras[i];

	vector<string> subset;
	backtrack(0, m, subset, palabras);

	return true;
}

int main() {
	while (casoDePrueba());
	return 0;
}