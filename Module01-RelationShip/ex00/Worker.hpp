#pragma once

#define COLOR_HEADER_CXX
#include "color.h"

#include <iostream>
#include <vector>
#include "Tools.hpp"
class Tool;
template <typename ToolType>
class Workshop;

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
    template <typename ToolType>
    friend class Workshop;

    private:
        string          name;
        Position        position;
        Statistic       statistic;
        vector<Tool *>  tool;
        vector<void *>  workshops;

    public:
        Worker(const string &name, Position position, Statistic statistic);
        ~Worker();

        /// Public methods

        void    equip(Tool &tool);
        void    listWorkshops() const;

        // Work with the tools equipped, using the first correct tool 1 time if possible
        template <typename ToolType>
        void work() {
            Tool *useTool = this->getTool<ToolType>();

            if (!useTool) {
                cout << this->name << " don't have the tools to work with" << endl;
                return;
            }

            if (useTool->use())
                cout << this->name << " worked successfully (" << useTool->getToolName() << " have " << useTool->getNumberOfUses() << " use lefts)" << endl;
            else
                cout << this->name << " failed to work" << endl;
        }

        // Unequip the tool from the worker if the worker is equipped
        template <typename ToolType>
        void unequip() {
            Tool *useTool = this->getTool<ToolType>();

            if (!useTool) {
                cout << this->name << " don't have any tool to unequip" << endl;
                return;
            }

            cout << this->name << " unequipped a " << useTool->getToolName() << endl;

            useTool->remove();
            for (uint i = 0; i < this->tool.size(); i++) {
                if (dynamic_cast<const ToolType*>(this->tool[i]) != NULL) {
                    this->tool.erase(this->tool.begin() + i);
                    break;
                }  
            }
        }

        /// Getters

        const string &getName() const;
        const Position &getPosition() const;
        const Statistic &getStatistic() const;

        // Return the first tool not broken of the specified type
        template <typename ToolType>
        ToolType *getTool() const {
            for (uint i = 0; i < this->tool.size(); i++) {
				ToolType *currentTool = dynamic_cast<ToolType *>(this->tool[i]);
                if (currentTool != NULL && currentTool->getNumberOfUses() > 0)
                    return currentTool;
            }
            return NULL;
        }
};

