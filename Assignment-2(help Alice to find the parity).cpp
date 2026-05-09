#include <iostream>
using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;

    if (L % 2 == 1 && R % 2 == 1)
        cout << "odd";
    else
        cout << "even";

    return 0;
}
