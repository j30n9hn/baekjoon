#include <iostream>
#include <string>
using namespace std;

//#define MAX		10000000

//int arr[MAX + 1];
int n;
int sum = 0;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum;
	return 0;
}
