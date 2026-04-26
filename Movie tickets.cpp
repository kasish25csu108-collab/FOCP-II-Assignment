#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> data;
    int limit = 100;

public:

    bool BOOK(int user, int movie) {
        // already booked
        if (data[movie].find(user) != data[movie].end())
            return false;

        // no seats left
        if (data[movie].size() == limit)
            return false;

        data[movie].insert(user);
        return true;
    }

    bool CANCEL(int user, int movie) {
        if (data[movie].find(user) == data[movie].end())
            return false;

        data[movie].erase(user);
        return true;
    }

    bool IS_BOOKED(int user, int movie) {
        return data[movie].find(user) != data[movie].end();
    }

    int AVAILABLE_TICKETS(int movie) {
        return limit - data[movie].size();
    }
};

int main() {
    int q;
    cin >> q;

    MovieTicket obj;

    while (q--) {
        string type;
        cin >> type;

        if (type == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (obj.BOOK(x, y) ? "true" : "false") << "\n";
        }
        else if (type == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (obj.CANCEL(x, y) ? "true" : "false") << "\n";
        }
        else if (type == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (obj.IS_BOOKED(x, y) ? "true" : "false") << "\n";
        }
        else if (type == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << obj.AVAILABLE_TICKETS(y) << "\n";
        }
    }

    return 0;
}
