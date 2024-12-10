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
size_t Bank::addClient(size_t value) {
    Account account(clientAccounts.size(), value); // Account class is instantiable

    clientAccounts.insert(Client(account.getId(), account));
    cout << "Added client " << account.getId() << endl;
    cout << "Client value: " << account.getValue() << endl;
    return account.getId();
}

void Bank::removeClient(size_t id) {
    if (clientAccounts.find(id) == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    clientAccounts.erase(id);
}

void    Bank::displayClients() {
    cout << "The bank have " << clientAccounts.size() << " clients :" << endl;

    for (Clients::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        cout << "[" << it->second.getId() << "] - [" << it->second.getValue() << "]" << endl;
}

void    Bank::displayClient(size_t id) {
    Clients::iterator it = clientAccounts.find(id);

    if (it == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    cout << "[" << it->second.getId() << "] - [" << it->second.getValue() << "]" << endl;
}

const Account &Bank::getClient(size_t id) {
    Clients::iterator it = clientAccounts.find(id);

    if (it == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    return it->second;
}
/// ---