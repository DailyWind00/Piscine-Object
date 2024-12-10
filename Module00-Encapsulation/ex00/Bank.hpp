#pragma once

#include <iostream>
#include <map>
#include "Account.hpp"

using namespace std;

typedef map<size_t, Account> Clients; // Id, Account
typedef pair<size_t, Account> Client;

class Bank {
    private:
        int     liquidity;
        Clients clientAccounts;

    public:
        Bank();
        ~Bank();


        // Clients management

        size_t          addClient(size_t value); // Setter
        void            removeClient(size_t id);
        void            displayClients();
        void            displayClient(size_t id);
        const Account & getClient(size_t id);   // Getter

};