#include "Worker.hpp"

//// Worker
/// Constructor & Destructor
Worker::Worker(const string &name, Position position, Statistic statistic) {
    this->name = Green + name + ResetColor;
    this->position = position;
    this->statistic = statistic;
    this->tool = NULL;

    std::cout << "Worker Constructor : " << this->name << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker Destructor : " << this->name << std::endl;
}
/// ---

/// Public methods

// Equip the tool to the worker if the worker is not equipped
void Worker::equip(Tool *tool) {
    if (this->tool != NULL)
        this->tool = NULL;

    this->tool = tool;
    tool->assign(this);

    cout << this->name << " equipped " << tool->getToolName() << endl;
}

// Work with the tool equipped, using the tool 1 time if possible
void Worker::work() {
    if (this->tool == NULL) {
        cout << this->name << " is not equipped" << endl;
        return;
    }

    if (this->tool->use())
        cout << this->name << " worked successfully" << endl;
    else {
        cout << this->name << " failed to work" << endl;
        this->unequip();
    }
}

// Unequip the tool from the worker if the worker is equipped
void Worker::unequip() {
    if (this->tool == NULL) {
        cout << this->name << " is not equipped" << endl;
        return;
    }

    cout << this->name << " unequipped " << this->tool->getToolName() << endl;

    this->tool->remove();
    this->tool = NULL;
}
/// ---

/// Getters

// Return the worker name
const string &Worker::getName() const {
    return this->name;
}

// Return the worker position
const Position &Worker::getPosition() const {
    return this->position;
}

// Return the worker statistic
const Statistic &Worker::getStatistic() const {
    return this->statistic;
}

// Return the worker tool
const Tool *Worker::getTool() const {
    return this->tool;
}
/// ---
//// ----