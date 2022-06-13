#include <iostream>
#include <string>
using namespace std;

#define MAX		1000

int arr[MAX + 1];
float sum;
int n, cnt, tcase;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> tcase;
	while (tcase--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		sum /= n;
		for (int i = 0; i < n; i++) {
			if (arr[i] > sum) {
				cnt++;
			}
		}
		sum = (float)cnt / n * 100;
		cout << fixed;
		cout.precision(3);
		cout << sum << "\%\n";
		cout.unsetf(ios::fixed);
		sum = 0;
		cnt = 0;
	}

	return 0;
}
