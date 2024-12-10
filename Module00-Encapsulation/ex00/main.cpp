#include "Bank.hpp"
#include <vector>

int main() {
    // Account class isn't instantiable
    // Account accountA = Account(0, 100);

    Bank bank = Bank();
    vector<size_t> ids;

    ids.push_back(bank.addClient(100));
    ids.push_back(bank.addClient(200));

    try {
        bank.displayClient(0);
        bank.displayClient(1);
        bank.displayClient(2); // OOB exception
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        bank.addClient(-200); // Negative value exception
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    bank.displayClients();

    bank.removeClient(ids[0]);
    bank.displayClients();

    return 0;
}