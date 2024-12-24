#pragma once

#define COLOR_HEADER_CXX
#include "color.h"

#include <iostream>
#include <vector>
#include "Worker.hpp"

using namespace std;

class Workshop {
    private:
        string name;
        vector<Worker> workers;

    public:
        Workshop(const string &name);
        ~Workshop();

        /// Public methods

        void registerWorker(Worker &worker);
        void unregisterWorker(Worker &worker);
};