#include "Bank.hpp"

/// Constructor & Destructor
Bank::Bank() {
    this->liquidity = 0;
}

Bank::~Bank() {
    clientAccounts.clear();
}
/// ---



/// Clients management
void Bank::addClient(Account &account) {
    if (clientAccounts.find(account.getId()) != clientAccounts.end())
        throw invalid_argument("Client already exists");

    clientAccounts.insert(Client(account.getId(), &account));
    cout << "Added client " << account.getId() << endl;
    cout << "Client value: " << account.getValue() << endl;
}

void Bank::removeClient(int id) {
    if (clientAccounts.find(id) == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    clientAccounts.erase(id);
}

void    Bank::displayClients() {
    cout << "The bank have " << clientAccounts.size() << " clients :" << endl;
    for (Clients::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        cout << it->second << endl;
}

void    Bank::displayClient(int id) {
    if (clientAccounts.find(id) == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    cout << clientAccounts[id] << endl;
}
/// ---