#include <iostream>
#include <vector>
using namespace std;

void backtrack(const int n, vector<string>& permutation, const vector<string>& palabras) {
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
		
		permutation.push_back(palabras[i]);
		

		backtrack(n, permutation, palabras);

		permutation.pop_back();
		
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> palabras(n);
	for (int i = 0; i < n; i++)
		cin >> palabras[i];

	vector<string> permutation;
	backtrack(n, permutation, palabras);

	return 0;
}