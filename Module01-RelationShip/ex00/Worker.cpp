#include "Worker.hpp"
#include "Workshop.hpp"

//// Worker
/// Constructor & Destructor
Worker::Worker(const string &name, Position position, Statistic statistic) {
    this->name = Green + name + ResetColor;
    this->position = position;
    this->statistic = statistic;

    std::cout << "Worker Constructor : " << this->name << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker Destructor : " << this->name << std::endl;
}
/// ---

/// Public methods

// Equip the tool to the worker
void Worker::equip(Tool &tool) {
    if (tool.assign(this)) {
        this->tool.push_back(&tool);
        cout << this->name << " equipped " << tool.getToolName() << endl;
    }
}

// List the workshops where the worker is registered
void Worker::listWorkshops() const {
    cout << "Workshops for " << name << ":" << endl;

    for (vector<void *>::const_iterator it = workshops.begin(); it != workshops.end(); ++it) {
        void *workshopPtr = *it;

        Workshop<Hammer> *curWorkshop = static_cast<Workshop<Hammer> *>(workshopPtr);
        if (curWorkshop) {
            cout << " - " << curWorkshop->getName() << " (" << curWorkshop->getToolName() << " Workshop)" << std::endl;
            continue;
        }

        cout << " - Unknown Workshop" << endl;
    }
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
/// ---
//// ----