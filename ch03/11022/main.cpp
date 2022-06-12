#include <iostream>
#include <string>
using namespace std;

//#define MAX           10000000

//int arr[MAX + 1];
int n, m, tcase;

void setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
}

int main() {
        setup();
        cin >> tcase;

        for (int i = 0; i < tcase; i++) {
                cin >> n >> m;
                cout << "Case #" << i + 1 << ": " << n << " + " << m << " = " << n + m << "\n";
        }

        return 0;
}
