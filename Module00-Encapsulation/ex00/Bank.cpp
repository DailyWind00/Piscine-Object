#include "Bank.hpp"

/// Constructor & Destructor
Bank::Bank() {
    this->liquidity = 0;
}

Bank::Bank(long long baseLiquidity) {
    this->liquidity = baseLiquidity;
}

Bank::~Bank() {
    clientAccounts.clear();
}
/// ---



/// Bank informations
long long Bank::getBankLiquidity() const {
    return liquidity;
}

void    Bank::displayClients() {
    cout << "│ The bank have " << clientAccounts.size() << " clients :" << endl;

    for (Clients::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        displayClient(it->first);
}

void    Bank::displayClient(size_t id) {
    Clients::iterator it = clientAccounts.find(id);

    if (it == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    cout << "│ Client id : " << it->second.getId();
    cout << "\t│ value : " << it->second.getValue();
    cout << "\t│ debt : " << it->second.getDebt() << endl;
}

const Account &Bank::operator[](size_t id) {
    Clients::iterator it = clientAccounts.find(id);

    if (it == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    return it->second;
}
/// ---



/// Clients management

// Create a new client with a value
// Return the client unique id
size_t Bank::addClient(size_t value) {
    size_t id = 0;
    for (Clients::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it, ++id) {
        if (it->first != id)
            break;
    }
    Account account(id, value); // Account class is instantiable inside Bank

    clientAccounts.insert(Client(account.getId(), account));

    cout << "Added client " << account.getId() << endl;
    cout << "Client value: " << account.getValue() << endl;

    return account.getId();
}

// Remove a client by id
void Bank::removeClient(size_t id) {
    if (clientAccounts.find(id) == clientAccounts.end())
        throw invalid_argument("Client does not exist");

    clientAccounts.erase(id);
}
/// ---



/// Clients interactions

// Reserve a loan for a client by id
void Bank::reserveLoan(size_t id, size_t value) {
    Clients::iterator it = clientAccounts.find(id);

    if (it == clientAccounts.end())
        throw invalid_argument("Client does not exist");
    if (liquidity < (long long)value)
        throw invalid_argument("Not enough liquidity");
    if (it->second.getDebt())
        throw invalid_argument("Client already have a debt");

    it->second.value += value;
    it->second.debt += value;
    liquidity -= value;
}

// Repay a loan for a client by id
void Bank::repayLoan(size_t id, size_t value) {
    Clients::iterator it = clientAccounts.find(id);

    if (it == clientAccounts.end())
        throw invalid_argument("Client does not exist");
    if (value > it->second.getDebt())
        value = it->second.getDebt(); // Repay only the debt
    if (it->second.getValue() < value)
        throw invalid_argument("Client does not have enough value to repay");

    it->second.value -= value;
    it->second.debt -= value;
    liquidity += value;
}

// Transfer value between two clients by id
void Bank::transfer(size_t from, size_t to, size_t value) {
    Clients::iterator itFrom = clientAccounts.find(from);
    Clients::iterator itTo = clientAccounts.find(to);

    if (itFrom == clientAccounts.end() || itTo == clientAccounts.end())
        throw invalid_argument("Client does not exist");
    if (itFrom->second.getValue() < value)
        throw invalid_argument("Client does not have enough value to transfer");

    itFrom->second.value -= value;
    itTo->second.value += value * 0.95; // Bank take 5% of the transfer
    liquidity += value * 0.05;
}
/// ---