#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    vector<string> excuses = {
        "{name} couldn’t finish because the laptop updated for 6 hours.",
        "{name} lost Wi-Fi right before submission.",
        "{name}'s keyboard stopped working mysteriously.",
        "{name} accidentally opened YouTube and forgot the assignment.",
        "{name}'s laptop battery died at 100%.",
        "{name} was debugging life instead of code.",
        "{name} got stuck in an infinite loop of procrastination.",
        "{name}'s file got corrupted by unknown forces.",
        "{name} submitted the assignment to the wrong universe.",
        "{name} thought tomorrow was the deadline."
    };

    srand(time(0));

    int idx = rand() % excuses.size();

    string result = excuses[idx];

    // FIX: replace {name}
    size_t pos = result.find("{name}");
    while (pos != string::npos) {
        result.replace(pos, 6, name);
        pos = result.find("{name}", pos + name.size());
    }

    cout << result << "\n";

    return 0;
}
