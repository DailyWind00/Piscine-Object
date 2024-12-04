#include "Account.hpp"

/// Constructor & Destructor
Account::Account(int id, int value) {
    this->id = id;
    this->value = value;
}

Account::~Account() {
}
/// ---



/// Getters
int Account::getId() const {
    return this->id;
}

int Account::getValue() const {
    return this->value;
}
/// ---



ostream& operator<<(ostream& os, Account *account) {
    os << "[" << account->getId() << "] - [" << account->getValue() << "]";
    return os;
}