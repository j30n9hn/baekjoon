#include <iostream>
#include <string>
using namespace std;

//#define MAX		10000000

//int arr[MAX + 1];
int num1, num2, num3;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int max = 0;
	setup();
	cin >> num1 >> num2 >> num3;

	if ((num1 == num2) && (num2 == num3)) {
		cout << 10000 + (num1 * 1000);
	} else if ((num1 == num2) && (num2 != num3)) {
		cout << 1000 + (num1 * 100);
	} else if ((num2 == num3) && (num3 != num1)) {
		cout << 1000 + (num2 * 100);
	} else if ((num3 == num1) && (num1 != num2)) {
		cout << 1000 + (num3 * 100);
	} else {
		if ((num1 > num2) && (num1 > num3)) {
			cout << num1 * 100;
		} else if ((num2 > num1) && (num2 > num3)) {
			cout << num2 * 100;
		} else {
			cout << num3 * 100;
		}
	}




	return 0;
}
