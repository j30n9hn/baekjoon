#include <iostream>
#include <string>
using namespace std;

#define MAX		10000000

int arr[MAX + 1];
int n;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int cycle(int n) {
	int left, right;
	int temp;
	int cnt;

	temp = n;
	for (cnt = 1; ; cnt++) {
		left = temp / 10;
		right = temp % 10;
		temp = ((left + right) % 10) + (right * 10);
		if (temp == n) {
			break;
		}
	}
	return cnt;
}

int main() {
	setup();
	
	cin >> n;
	cout << cycle(n);

	return 0;
}
