#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
    unordered_map<int, long long> acc;

public:

    bool CREATE(int id, long long money) {
        if (acc.find(id) == acc.end()) {
            acc[id] = money;
            return true;
        }
        acc[id] += money;
        return false;
    }

    bool DEBIT(int id, long long money) {
        if (acc.find(id) == acc.end()) return false;

        if (acc[id] < money) return false;

        acc[id] -= money;
        return true;
    }

    bool CREDIT(int id, long long money) {
        if (acc.find(id) == acc.end()) return false;

        acc[id] += money;
        return true;
    }

    long long BALANCE(int id) {
        if (acc.find(id) == acc.end()) return -1;
        return acc[id];
    }
};

int main() {
    int q;
    cin >> q;

    Bank b;

    while (q--) {
        string op;
        cin >> op;

        if (op == "CREATE") {
            int x; long long y;
            cin >> x >> y;
            cout << (b.CREATE(x, y) ? "true" : "false") << "\n";
        }
        else if (op == "DEBIT") {
            int x; long long y;
            cin >> x >> y;
            cout << (b.DEBIT(x, y) ? "true" : "false") << "\n";
        }
        else if (op == "CREDIT") {
            int x; long long y;
            cin >> x >> y;
            cout << (b.CREDIT(x, y) ? "true" : "false") << "\n";
        }
        else if (op == "BALANCE") {
            int x;
            cin >> x;
            cout << b.BALANCE(x) << "\n";
        }
    }

    return 0;
}
