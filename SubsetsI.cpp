#include <iostream>
#include <vector>
using namespace std;

void backtrack(int idx, vector<string>& subset, vector<string>& palabras) {
	if (idx == palabras.size()) {
		cout << "{";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i];
			if (i != subset.size() - 1)
				cout << ",";
		}
		cout << "}\n";
		return;
	}
	subset.push_back(palabras[idx]);
	backtrack(idx + 1, subset, palabras);
	subset.pop_back();

	backtrack(idx + 1, subset, palabras);
}

bool casoDePrueba() {
	int n;
	cin >> n;

	if (!cin)
		return false;

	vector<string> palabras(n);
	for (int i = 0; i < n; i++)
		cin >> palabras[i];

	vector<string> subset;
	backtrack(0, subset, palabras); 

	return true;
}

int main() {
	while (casoDePrueba());
	return 0;
}