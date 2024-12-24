#pragma once

#define COLOR_HEADER_CXX
#include "color.h"

#include <iostream>
#include "Tools.hpp"
class Tool;

using namespace std;

typedef struct Position {
    int x;
    int y;
    int z;
} Position;

typedef struct Statistic {
    int level;
    int exp;
} Statistic;

class Worker {
    private:
        string      name;
        Position    position;
        Statistic   statistic;
        Tool        *tool;

    public:
        Worker(const string &name, Position position, Statistic statistic);
        ~Worker();

        // Public methods

        void equip(Tool *tool);
        void work();
        void unequip();

        // Getters

        const string &getName() const;
        const Position &getPosition() const;
        const Statistic &getStatistic() const;
        const Tool *getTool() const;
};

