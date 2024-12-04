#pragma once

#include <iostream>
#include <map>
#include "Account.hpp"

using namespace std;

typedef map<int, Account *> Clients; // Id, Account
typedef pair<int, Account *> Client;

class Bank {
    private:
        int     liquidity;
        Clients clientAccounts;

    public:
        Bank();
        ~Bank();

        // Clients management
        void    addClient(Account &account);
        void    removeClient(int id);
        void    displayClients();
        void    displayClient(int id);

};