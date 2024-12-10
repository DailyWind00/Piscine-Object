#include "Account.hpp"

/// Constructor & Destructor

Account::Account(size_t id, int value) {
    this->id = id;
    this->value = value;
    this->debt = 0;
}

Account::~Account() {
}
/// ---



/// Getters

const size_t & Account::getId() const {
    return this->id;
}

const size_t & Account::getValue() const {
    return this->value;
}

const size_t & Account::getDebt() const {
    return this->debt;
}
/// ---