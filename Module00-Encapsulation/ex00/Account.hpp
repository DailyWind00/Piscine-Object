#pragma once

#include <iostream>

using namespace std;

class Account {
    friend class Bank; // Only Bank can set private members

    private:
        size_t id;
        size_t value;
        size_t debt;

        Account(size_t id, int value); // Constructor is private for encapsulation with Bank

    public:
        ~Account();

        // Getters

        const size_t & getId() const;
        const size_t & getValue() const;
        const size_t & getDebt() const;
};