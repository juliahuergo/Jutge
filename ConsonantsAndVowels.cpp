#include <iostream>
#include <vector>
using namespace std;

void backtrack(const int n, int idx, const vector<char>& consonants, const vector<char>& vowels, vector<char>& word, vector<bool>& contieneC, vector<bool>& contieneV) {
	if (word.size() == n * 2) {
		for (int i = 0; i < word.size(); i++)
			cout << word[i];
		cout << "\n";

		return;
	}

	//if idx%2==0 CONSONANT

	for (int i = 0; i < n; i++) {
		if (idx % 2 == 0) { ///añadir consonante
			if (!contieneC[i]) {
				word.push_back(consonants[i]);
				contieneC[i] = true;
				backtrack(n, idx + 1, consonants, vowels, word, contieneC, contieneV);
				word.pop_back();
				contieneC[i] = false;
			}
		}
		else { //añadir vocal
			if (!contieneV[i]) {
				word.push_back(vowels[i]);
				contieneV[i] = true;
				backtrack(n, idx + 1, consonants, vowels, word, contieneC, contieneV);
				word.pop_back();
				contieneV[i] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<char> consonants(n);
	for (int i = 0; i < n; i++)
		cin >> consonants[i];

	vector<char> vowels(n);
	for (int i = 0; i < n; i++)
		cin >> vowels[i];

	vector<char> word;

	vector<bool> contieneC(n, false);
	vector<bool> contieneV(n, false);

	backtrack(n, 0, consonants, vowels, word, contieneC, contieneV);

	return 0;
}