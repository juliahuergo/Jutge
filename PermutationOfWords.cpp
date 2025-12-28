#include <iostream>
#include <vector>
using namespace std;

void backtrack(const int n, vector<string>& permutation, vector<bool>& contiene, const vector<string>& palabras) {
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

	for (int i = 0; i < n; i++) {
		if (!contiene[i]) {
			permutation.push_back(palabras[i]);
			contiene[i] = true;

			backtrack(n, permutation, contiene, palabras);

			permutation.pop_back();
			contiene[i] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> palabras(n);
	for (int i = 0; i < n; i++)
		cin >> palabras[i];

	vector<string> permutation;
	vector<bool> contiene(n, false);
	backtrack(n, permutation, contiene, palabras);

	return 0;
}