#include "Bank.hpp"
#include <vector>

int main() {
    // Account class isn't instantiable outside Bank
    // Account accountA = Account(0, 100);

    Bank bank = Bank(10000);
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

    // Unique id check
    bank.displayClients();
    bank.removeClient(ids[0]);
    bank.displayClients();
    ids.push_back(bank.addClient(42)); // Reuse id 0
    bank.displayClients();

    try {
        Account account = bank[ids[1]];
        cout << "Account " << account.getId() << " value: " << account.getValue() << endl;

        bank[ids[0]]; // OOB exception
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    cout << endl;

    // Clients interactions
    bank.reserveLoan(ids[1], 50);
    bank.displayClient(ids[1]);
    cout << "Bank liquidity: " << bank.getBankLiquidity() << endl;
    bank.repayLoan(ids[1], 25);
    bank.displayClient(ids[1]);
    bank.transfer(ids[1], ids[0], 10);
    bank.repayLoan(ids[1], 1000); // Round to max debt
    bank.displayClient(ids[1]);
    bank.displayClient(ids[0]);


    cout << "Bank liquidity: " << bank.getBankLiquidity() << endl;

    try {
        bank.reserveLoan(ids[0], 9999999999); // Not enough liquidity
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        bank.transfer(ids[0], ids[1], 9999999999); // Not enough value
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}