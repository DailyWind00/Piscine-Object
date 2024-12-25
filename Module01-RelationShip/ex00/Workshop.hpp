#pragma once

#define COLOR_HEADER_CXX
#include "color.h"

#include <iostream>
#include <vector>
#include "Worker.hpp"

using namespace std;

template <typename ToolType>
class Workshop {
    private:
        string name;
        vector<Worker *>    workers;

    public:
        Workshop(const string &name) {
            this->name = Yellow + name + ResetColor;
            cout << "Workshop Constructor : " << this->name << " - " << ToolType::staticGetToolName() << endl;
        };

        ~Workshop() {
            cout << "Workshop Destructor: " << this->name << endl;
        };

        /// Public methods

        // Register a worker to the workshop
        void registerWorker(Worker &worker) {
            for (vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
                if ((*it)->getName() == worker.getName()) {
                    cout << this->name << " have already " << worker.getName() << " registered" << endl;
                    return;
                }
            }

            if (!worker.getTool<ToolType>()) {
                cout << this->name << " can't register " << worker.getName() << " without the right tool" << endl;
                return;
            }

            this->workers.push_back(&worker);
            cout << this->name << " registered " << worker.getName() << endl;
        }

        // Unregister a worker from the workshop
        void unregisterWorker(Worker &worker) {
            for (vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
                if ((*it)->getName() == worker.getName()) {
                    this->workers.erase(it);
                    cout << this->name << " unregistered " << worker.getName() << endl;
                    return;
                }
            }
            cout << this->name << " don't have " << worker.getName() << " registered" << endl;
        }
};