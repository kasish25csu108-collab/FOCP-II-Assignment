#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched careers.",
        "If procrastination were a sport, {name} would win gold.",
        "{name}'s code has more bugs than a jungle.",
        "{name} doesn't debug code, just stares at it.",
        "Even Google asks {name} for wrong answers.",
        "{name}'s logic is like WiFi - weak and unstable.",
        "{name} compiles emotions better than code.",
        "{name}'s program runs... eventually.",
        "{name} treats errors like suggestions.",
        "{name} vs bugs is a never-ending love story."
    };

    string name;
    cout << "=== AI Roast Generator ===" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    // ✅ FIX: Initialize random seed only once
    srand(time(0));

    char choice;

    do {
        int index = rand() % roasts.size();

        string roast = roasts[index];

        // Replace {name}
        size_t pos = roast.find("{name}");
        if (pos != string::npos) {
            roast.replace(pos, 6, name);
        }

        cout << "\nRoast: " << roast << endl;

        cout << "\nWant another roast? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThanks for using AI Roast Generator!" << endl;

    return 0;
}
