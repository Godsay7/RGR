#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool CodeChain(const string& code) {
	int l = code.length();
	if (l < 5) {
		return false;
	}
	if (code[0] != '+') {
		return false;
	}
	int i = 1;
	while (i < l && isdigit(code[i])) {
		i++;
	}
	char arrBLet[15] = { 'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char arrTrueBLet[11] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K' };
	for (int n = i; n < l; n++) {
		for (int k = 0; k < 15; k++) {
			if (code[n] == arrBLet[k]) {
				return false;
			}
		}
	}
	while (i < l && isupper(code[i])) {
		i++;
	}

	for (int n = i; n < l; n++) {
		for (int k = 0; k < 11; k++) {
			if ((code[n] == '&' || code[n] == '^') && code[n + 1] == arrTrueBLet[k]) {
				return false;
				if (code[n] != '&' && code[n] != '^') {
					return false;
				}
			}
			if ((code[n] == '&' || code[n] == '^') && code[n - 1] == arrTrueBLet[k]) {
				return false;
				if (code[n] != '&' && code[n] != '^') {
					return false;
					if (isdigit(code[n])) {
						return false;
					}
				}
			}
		}
		if (isdigit(code[n])) {
			return false;
		}
	}
	return true;
}

int main() {
	string input;
	cout << "Enter the code chain: ";
	cin >> input;
	if (CodeChain(input)) {
		cout << "The code chain belongs to the language L(V)" << endl;
	}
	else {
		cout << "The code chain doesn't belong to language L(V)" << endl;
	}
	return 0;
}