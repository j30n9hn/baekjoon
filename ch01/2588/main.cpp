#include <iostream>
#include <string>
using namespace std;

//#define MAX		10000000

//int arr[MAX + 1];
int one, two, three, four, five;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> one >> two;
	five = one * (two / 100);
	two -= two / 100 * 100;
	four = one * (two / 10);
	two -= two / 10 * 10;
	three = one * two;

	cout << three << "\n";
	cout << four << "\n";
	cout << five << "\n";
	cout << three + (four * 10) + (five * 100);
	return 0;
}
