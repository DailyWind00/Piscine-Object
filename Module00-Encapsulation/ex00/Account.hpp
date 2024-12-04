#pragma once

#include <iostream>

using namespace std;

class Account {
    private:
        int id;
        int value;

    public:
        Account(int id, int value);
        ~Account();

        // Getters
        int getId() const;
        int getValue() const;
};

ostream& operator<<(ostream& os, Account *account);