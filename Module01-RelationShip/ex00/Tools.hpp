#pragma once

#define COLOR_HEADER_CXX
#include "color.h"

#include <iostream>
#include "Worker.hpp"
class Worker;

typedef unsigned int uint;
using namespace std;

class Tool {
    protected:
        string  toolName;
        uint    numberOfUses;
        Worker  *currentWorker;

    public:
        // Public methods

        virtual bool assign(Worker *worker) = 0;
        virtual bool use() = 0;
        virtual bool remove() = 0;

        // Getters
        virtual const string &getToolName() const = 0;
        virtual const uint &getNumberOfUses() const = 0;
        virtual const Worker *getCurrentWorker() const = 0;
};

class Shovel : public Tool {
    public:
        Shovel(uint numberOfUses = 0);
        ~Shovel();
        
        // Public methods

        bool assign(Worker *worker);
        bool use();
        bool remove();

        // Getters
        const string &getToolName() const;
        const uint &getNumberOfUses() const;
        const Worker *getCurrentWorker() const;
};