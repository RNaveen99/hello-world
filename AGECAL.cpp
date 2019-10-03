/*
 * Author : Naveen Rohilla
 * Objective : AGECAL
 */
 
 
#include <iostream>
using namespace std;
void yearZero(int yb, int mb, int db, int yc, int mc, int dc, int & days, int * arr, int n) {
	for (int i = mb; i <= mc; i++) {
		days += arr[i];
	}
	if (db != 1) {
		days = days - db + 1;
	}
	if (dc != arr[mc]) {
		days = days - arr[mc] + dc;
	}
}

void yearNonZero(int yb, int mb, int db, int yc, int mc, int dc, int & days, int * arr, int n, int sum) {
	//	Birthday year
	for (int i = mb; i <= n; i++) {
		days += arr[i];
	}
	if (db != 1) {
		days = days - db + 1;
	}
	if (yb % 4 == 0) {
		days++;
	}
	
	//	Current year
	for (int i = 1; i <= mc; i++) {
		days += arr[i];
	}
	if (dc != arr[mc]) {
		days = days - arr[mc] + dc;
	}
	
	//	Years in between
	for (int i = yb + 1; i < yc; i++) {
		days += sum;
		if (i % 4 == 0) {
			days++;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int * arr = new int [n + 1];
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		int yb, mb, db;
		cin >> yb >> mb >> db;
		int yc, mc, dc;
		cin >> yc >> mc >> dc;
		
		int days = 0;
		int years = yc - yb;
		if (years == 0) {
			yearZero(yb, mb, db, yc, mc, dc, days, arr, n);
		}
		else {
			yearNonZero(yb, mb, db, yc, mc, dc, days, arr, n, sum);
		}
		cout << days << "\n";
	}
	return 0;
}

