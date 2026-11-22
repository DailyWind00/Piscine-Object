#include "Tools.hpp"
#include "Worker.hpp"

#pragma region Shovel
# pragma region Constructor & Destructor

Shovel::Shovel(uint numberOfUses) {
    this->toolName = Orange + "Shovel" + ResetColor;
    this->numberOfUses = numberOfUses;
    this->currentWorker = NULL;

    cout << "Tool Constructor : " << this->toolName << endl;
}

Shovel::~Shovel() {
    cout << "Tool Destructor : " << this->toolName << endl;
}

# pragma endregion Constructor & Destructor

# pragma region Public Methods

// Assign the shovel to a worker
// Return true if the shovel is assigned, false otherwise
void Shovel::assign(Worker *worker) {
	if (this->currentWorker == worker) {
		cout << this->toolName << " is already assigned to " << this->currentWorker->getName() << endl;
		return;
	}
    else
		cout << this->toolName << " assigned on " << worker->getName() << endl;

    this->currentWorker = worker;
    return;
}

// Use the shovel
// Return true if the shovel is used, false otherwise
bool Shovel::use() {
    if (this->currentWorker == NULL) {
        cout << this->toolName << " is not equipped" << endl;
        return false;
    }

    if (this->numberOfUses > 0) {
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

    cout << this->toolName << " has been removed from " << this->currentWorker->getName() << endl;
	this->currentWorker = NULL;
    return true;
}

# pragma endregion Public Methods



# pragma region Getters

// Return the shovel name
const string &Shovel::getToolName() const {
    return this->toolName;
}

// Return the number of uses of the shovel
const uint &Shovel::getNumberOfUses() const {
    return this->numberOfUses;
}

// Return the current worker
Worker *Shovel::getCurrentWorker() const {
    return this->currentWorker;
}

// Return the shovel name (static)
const string Shovel::staticGetToolName() {
    return Orange + "Shovel" + ResetColor;
}

# pragma endregion Getters
#pragma endregion Shovel


#pragma region Hammer
# pragma region Constructor & Destructor

Hammer::Hammer(uint numberOfUses) {
    this->toolName = Orange + "Hammer" + ResetColor;
    this->numberOfUses = numberOfUses;
    this->currentWorker = NULL;

    cout << "Tool Constructor : " << this->toolName << endl;
}

Hammer::~Hammer() {
    cout << "Tool Destructor : " << this->toolName << endl;
}

# pragma endregion Constructor & Destructor

# pragma region Public methods

// Assign the hammer to a worker
// Return true if the hammer is assigned, false otherwise
void Hammer::assign(Worker *worker) {
	if (this->currentWorker == worker) {
		cout << this->toolName << " is already assigned to " << this->currentWorker->getName() << endl;
		return;
	}
    else if (this->currentWorker != NULL) {
		this->currentWorker->unequip(*this);
		cout << this->toolName << " assigned on " << worker->getName() << "(previously assigned to " << currentWorker->getName() << ")" << endl;
	}
    else
		cout << this->toolName << " assigned on " << worker->getName() << endl;

    this->currentWorker = worker;
    return;
}

// Use the hammer
// Return true if the hammer is used, false otherwise
bool Hammer::use() {
    if (this->currentWorker == NULL) {
        cout << this->toolName << " is not equipped" << endl;
        return false;
    }

    if (this->numberOfUses > 0) {
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

    cout << this->toolName << " has been removed from " << this->currentWorker->getName() << endl;
	this->currentWorker = NULL;
    return true;
}

# pragma endregion Public methods

# pragma region Getters

// Return the hammer name
const string &Hammer::getToolName() const {
    return this->toolName;
}

// Return the number of uses of the hammer
const uint &Hammer::getNumberOfUses() const {
    return this->numberOfUses;
}

// Return the current worker
Worker *Hammer::getCurrentWorker() const {
    return this->currentWorker;
}

// Return the hammer name (static)
const string Hammer::staticGetToolName() {
    return Orange + "Hammer" + ResetColor;
}

# pragma endregion Getters
#pragma endregion Hammer
//// ----