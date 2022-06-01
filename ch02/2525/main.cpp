#include <iostream>
#include <string>
using namespace std;

//#define MAX		10000000

//int arr[MAX + 1];
int h, m, cookingtime;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> h >> m >> cookingtime;

	if (m + cookingtime < 60) {
		cout << h << m + cookingtime;
	} else if ((m + cookingtime == 60) && h <= 22) {
	return 0;
}
