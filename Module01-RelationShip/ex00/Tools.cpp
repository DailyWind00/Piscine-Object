#include "Tools.hpp"
#include "Worker.hpp"

//// Shovel
/// Constructor & Destructor
Shovel::Shovel(uint numberOfUses) {
    this->toolName = Orange + "Shovel" + ResetColor;
    this->numberOfUses = numberOfUses;
    this->currentWorker = NULL;

    cout << "Tool Constructor : " << this->toolName << endl;
}

Shovel::~Shovel() {
    cout << "Tool Destructor : " << this->toolName << endl;
}
/// ---

/// Public methods

// Assign the shovel to a worker
// Return true if the shovel is assigned, false otherwise
bool Shovel::assign(Worker *worker) {
    if (this->currentWorker != NULL) {
        cout << this->toolName << " is already assigned" << endl;
        return false;
    }

    this->currentWorker = worker;
    cout << this->toolName << " assigned on " << this->currentWorker->getName() << endl;
    return true;
}

// Use the shovel
// Return true if the shovel is used, false otherwise
bool Shovel::use() {
    if (this->currentWorker == NULL) {
        cout << this->toolName << " is not equipped" << endl;
        return false;
    }

    if (this->numberOfUses > 0) {
        cout << this->toolName << " used" << endl;
        this->numberOfUses--;
        return true;
    }
    cout << this->toolName << " is broken" << endl;
    return false;
}

// Remove the shovel from the worker
// Return true if the shovel is removed, false otherwise
bool Shovel::remove() {
    if (this->currentWorker == NULL) {
        cout << this->toolName << " is not equipped" << endl;
        return false;
    }

    this->currentWorker = NULL;
    cout << this->toolName << " removed" << endl;
    return true;
}
/// ---

/// Getters

// Return the shovel name
const string &Shovel::getToolName() const {
    return this->toolName;
}

// Return the number of uses of the shovel
const uint &Shovel::getNumberOfUses() const {
    return this->numberOfUses;
}

// Return the current worker
const Worker *Shovel::getCurrentWorker() const {
    return this->currentWorker;
}
/// ---
//// ----





//// Hammer
/// Constructor & Destructor
Hammer::Hammer(uint numberOfUses) {
    this->toolName = Orange + "Hammer" + ResetColor;
    this->numberOfUses = numberOfUses;
    this->currentWorker = NULL;

    cout << "Tool Constructor : " << this->toolName << endl;
}

Hammer::~Hammer() {
    cout << "Tool Destructor : " << this->toolName << endl;
}
/// ---

/// Public methods

// Assign the hammer to a worker
// Return true if the hammer is assigned, false otherwise
bool Hammer::assign(Worker *worker) {
    if (this->currentWorker != NULL) {
        cout << this->toolName << " is already assigned" << endl;
        return false;
    }

    this->currentWorker = worker;
    cout << this->toolName << " assigned on " << this->currentWorker->getName() << endl;
    return true;
}

// Use the hammer
// Return true if the hammer is used, false otherwise
bool Hammer::use() {
    if (this->currentWorker == NULL) {
        cout << this->toolName << " is not equipped" << endl;
        return false;
    }

    if (this->numberOfUses > 0) {
        cout << this->toolName << " used" << endl;
        this->numberOfUses--;
        return true;
    }
    cout << this->toolName << " is broken" << endl;
    return false;
}

// Remove the hammer from the worker
// Return true if the hammer is removed, false otherwise
bool Hammer::remove() {
    if (this->currentWorker == NULL) {
        cout << this->toolName << " is not equipped" << endl;
        return false;
    }

    this->currentWorker = NULL;
    cout << this->toolName << " removed" << endl;
    return true;
}
/// ---

/// Getters

// Return the hammer name
const string &Hammer::getToolName() const {
    return this->toolName;
}

// Return the number of uses of the hammer
const uint &Hammer::getNumberOfUses() const {
    return this->numberOfUses;
}

// Return the current worker
const Worker *Hammer::getCurrentWorker() const {
    return this->currentWorker;
}
/// ---
//// ----