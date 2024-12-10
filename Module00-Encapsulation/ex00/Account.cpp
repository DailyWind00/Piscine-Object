#include "Account.hpp"

/// Constructor & Destructor
Account::Account(size_t id, int value) {
    this->id = id;
    this->value = value;
}

Account::~Account() {
}
/// ---



/// Getters
size_t Account::getId() const {
    return this->id;
}

int Account::getValue() const {
    return this->value;
}
/// ---