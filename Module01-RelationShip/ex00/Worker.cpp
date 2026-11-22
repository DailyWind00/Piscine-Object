#include "Worker.hpp"
#include "Workshop.hpp"

#pragma region Worker
# pragma region Constructor & Destructor

Worker::Worker(const string &name, Position coordonnee, Statistic stat) {
    this->name = Green + name + ResetColor;
    this->coordonnee = coordonnee;
    this->stat = stat;

    std::cout << "Worker Constructor : " << this->name << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker Destructor : " << this->name << std::endl;

	vector<Tool *> toolsToRemove = this->tool; // Copy the tools to avoid modifying the vector while iterating

    // for (vector<Tool *>::iterator it = toolsToRemove.begin(); it != toolsToRemove.end(); ++it) {
	// 	Tool *currentTool = *it;
	// 	if (currentTool) {
	// 		currentTool->remove();
	// 		cout << this->name << " unequipped " << currentTool->getToolName() << endl;
	// 	}
    // }

    for (vector<void *>::iterator it = workshops.begin(); it != workshops.end(); ++it) {
        Workshop<Hammer> *workshop = static_cast<Workshop<Hammer> *>(*it);
        if (workshop) {
            workshop->unregisterWorker(*this);
			cout << this->name << " unregistered from " << workshop->getName() << endl;
		}
    }
}

# pragma endregion Constructor & Destructor

# pragma region Public methods

// Equip the tool to the worker
void Worker::equip(Tool &tool) {
	Worker *currentWorker = tool.getCurrentWorker();

	if (currentWorker == this) return;
	if (currentWorker != NULL) {
		currentWorker->unequip(tool);
	}

    tool.assign(this);
    this->tool.push_back(&tool);
    cout << this->name << " equipped " << tool.getToolName() << endl;
}

// List the workshops where the worker is registered
void Worker::listWorkshops() const {
    cout << "Workshops for " << name << ":" << endl;

    for (vector<void *>::const_iterator it = workshops.begin(); it != workshops.end(); ++it) {
        void *workshopPtr = *it;

        Workshop<Hammer> *curWorkshop = static_cast<Workshop<Hammer> *>(workshopPtr); // We can force-cast into Hammer because the internal tool name is still kept
        if (curWorkshop) {
            cout << " - " << curWorkshop->getName() << " (" << curWorkshop->getToolName() << " Workshop)" << std::endl;
            continue;
        }

        cout << " - Unknown Workshop" << endl;
    }
}

void Worker::unequip(Tool &tool) {
	tool.remove();
	for (uint i = 0; i < this->tool.size(); i++) {
		if (this->tool[i] == &tool) {
			this->tool.erase(this->tool.begin() + i);
			break;
		}
	}
}

# pragma endregion Public methods

# pragma region Getters

// Return the worker name
const string &Worker::getName() const {
    return this->name;
}

// Return the worker position
const Position &Worker::getPosition() const {
    return this->coordonnee;
}

// Return the worker statistic
const Statistic &Worker::getStatistic() const {
    return this->stat;
}

# pragma endregion Getters
# pragma endregion Worker