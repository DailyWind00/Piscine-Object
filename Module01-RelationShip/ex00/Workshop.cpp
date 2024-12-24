#include "Workshop.hpp"

//// Workshop
/// Constructor & Destructor
Workshop::Workshop(const string &name) {
    this->name = Yellow + name + ResetColor;

    cout << "Workshop Constructor : " << this->name << endl;
}

Workshop::~Workshop() {
    cout << "Workshop Destructor: " << this->name << endl;
}
/// ---

/// Public methods

// Register a worker to the workshop
void Workshop::registerWorker(Worker &worker) {
    for (vector<Worker>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
        if (it->getName() == worker.getName()) {
            cout << this->name << " have already " << worker.getName() << " registered" << endl;
            return;
        }
    }
    this->workers.push_back(worker);
    cout << this->name << " registered " << worker.getName() << endl;
}

// Unregister a worker from the workshop
void Workshop::unregisterWorker(Worker &worker) {
    for (vector<Worker>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
        if (it->getName() == worker.getName()) {
            this->workers.erase(it);
            cout << this->name << " unregistered " << worker.getName() << endl;
            return;
        }
    }
    cout << this->name << " don't have " << worker.getName() << " registered" << endl;
}
/// ---
//// ----