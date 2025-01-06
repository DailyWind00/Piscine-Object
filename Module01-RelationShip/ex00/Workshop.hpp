#pragma once

#define COLOR_HEADER_CXX
#include "color.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include "Worker.hpp"

using namespace std;

template <typename ToolType>
class Workshop {
    private:
        string              name;
        string              toolName;
        vector<Worker *>    workers;

    public:
        Workshop(const string &name) {
            this->name = Yellow + name + ResetColor;
            this->toolName = ToolType::staticGetToolName();
            cout << "Workshop Constructor : " << this->name << " - " << this->toolName << endl;
        };

        ~Workshop() {
            cout << "Workshop Destructor: " << this->name << endl;
        };

        /// Public methods

        // Register a worker to the workshop
        void registerWorker(Worker &worker) {
            vector<Worker *>::iterator it = find(this->workers.begin(), this->workers.end(), &worker);
            if (it != this->workers.end()) {
                cout << this->name << " have already " << worker.getName() << " registered" << endl;
                return;
            }

            if (!worker.getTool<ToolType>()) {
                cout << this->name << " can't register " << worker.getName() << " without the right tool" << endl;
                return;
            }

            worker.workshops.push_back(static_cast<void *>(this));
            this->workers.push_back(&worker);
            cout << this->name << " registered " << worker.getName() << endl;
        }

        // Unregister a worker from the workshop
        void unregisterWorker(Worker &worker) {
            for (vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
                if ((*it)->getName() == worker.getName()) {
                    worker.workshops.erase(find(worker.workshops.begin(), worker.workshops.end(), this));
                    this->workers.erase(it);
                    cout << this->name << " unregistered " << worker.getName() << endl;
                    return;
                }
            }
            cout << this->name << " don't have " << worker.getName() << " registered" << endl;
        }

		// Launch a day of work in the workshop
		void executeWorkDay() {
			cout << this->name << " (" << this->toolName << ") is starting a work day :" << endl;
			for (vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
				cout << " - ";
				(*it)->work<ToolType>();
			}
		}

        /// Getters

        // Return the workshop name
        const string &getName() const {
            return this->name;
        }

        // Return the tool name
        const string &getToolName() const {
            return this->toolName;
        }
};