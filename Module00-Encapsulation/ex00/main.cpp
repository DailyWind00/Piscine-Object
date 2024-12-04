#include "Bank.hpp"

int main() {
    Account accountA = Account(0, 100);
    Account accountB = Account(1, 100);

    Bank bank = Bank();
    bank.addClient(accountA);
    bank.addClient(accountB);

    bank.displayClients();

    bank.removeClient(0);
    bank.displayClients();

    return 0;
}