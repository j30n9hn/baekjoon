#include <iostream>
#include <string>
using namespace std;

//#define MAX		10000000

//int arr[MAX + 1];
int x, y;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> x >> y;

	if (x > 0 && y > 0) {
		cout << 1;
	} else if (x < 0 && y > 0) {
		cout << 2;
	} else if (x < 0 && y < 0) {
		cout << 3;
	} else {
		cout << 4;
	}

	return 0;
}
