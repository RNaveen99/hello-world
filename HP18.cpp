/*
 * Developer : Naveen Rohilla
 * Objective : HP18
 */
 
 
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		int * arr = new int [n];
		int index = 0, temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (temp % a == 0 || temp % b == 0) {
				arr[index++] = temp;
			}
		}
		
		if (a == b) {
			cout << "BOB\n";
			continue;
		}
		
		bool bobTurn = true, deleted = false;
		
		for (int i = 0; i < index; i++) {
			if (arr[i] % b == 0 && arr[i] % a == 0) {
				arr[i] = 0;
				deleted = true;
				bobTurn = false;
			}
		}
		while (true) {
			deleted = false;
			if (bobTurn) {
				for (int i = 0; i < index; i++) {
					if (arr[i] && arr[i] % a == 0) {
						arr[i] = 0;
						deleted = true;
						bobTurn = false;
						break;
					}
				}
				if (! deleted) {
					cout << "ALICE\n";
					break;
				}
			}
			else {
				for (int i = 0; i < index; i++) {
					if (arr[i] && arr[i] % b == 0) {
						arr[i] = 0;
						deleted = true;
						bobTurn = true;
						break;
					}
				}
				if (! deleted) {
					cout << "BOB\n";
					break;
				}
			}
		}
	}
	return 0;
}
