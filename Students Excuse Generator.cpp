#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;
    cin >> name;

    vector<string> excuses = {
        "{name} forgot homework",
        "{name} laptop crashed",
        "{name} had no internet"
    };

    srand(time(0));

    int idx = rand() % excuses.size();

    cout << excuses[idx] << endl;

    return 0;
}
