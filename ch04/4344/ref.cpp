#include <iostream>
#include <string>
using namespace std;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int n1, n2;

	// basic input and output
	//cin >> n1 >> n2;			// 5 10
	//cout << n1 << " " << n2;	// 5 10

	// string
	//string s;

	//cin >> s;						// helloworld
	//cout << s << "\n";				// helloworld
	//cout << s.length() << "\n";		// 10
	
	// dynamic allocated array
	//const int length = 5;
	//int *arr = new int[length];		// int array of 5 slots
	//int *arr2 = new int[5] { 1, 2, 3, 4, 5 };	// initialization
	//int *arr3 = new int[5]();		// fill array with zeroes 

	//delete[] arr;					// deallocate (free)
	
	// range-based iteration
	int arr4[] = { 10, 20, 30, 40, 50 };
	
	for (const int& el : arr4) {
		cout << el << "\n";
	}

	return 0;
}
