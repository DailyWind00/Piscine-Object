#pragma once

#include <iostream>

using namespace std;

class Account {
    friend class Bank; // Only Bank can set private members

    private:
        size_t id;
        int value;

        // Private Constructor
        Account(size_t id, int value);

    public:
        ~Account();

        // Getters
        size_t getId() const;
        int getValue() const;
};