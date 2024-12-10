#pragma once

#include <iostream>
#include <map>
#include "Account.hpp"

using namespace std;

typedef map<size_t, Account> Clients; // Id, Account
typedef pair<size_t, Account> Client;

class Bank {
    private:
        long long   liquidity;
        Clients     clientAccounts;

    public:
        Bank();
        Bank(long long baseLiquidity);
        ~Bank();

        // Bank informations (Getters)

        long long       getBankLiquidity() const;
        void            displayClients();
        void            displayClient(size_t id);
        const Account & operator[](size_t id);


        // Clients management (Setters)

        size_t          addClient(size_t value);
        void            removeClient(size_t id);


        // Clients interactions
        void            reserveLoan(size_t id, size_t value);
        void            repayLoan(size_t id, size_t value);
        void            transfer(size_t from, size_t to, size_t value);

};