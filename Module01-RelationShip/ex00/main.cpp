#include "Worker.hpp"

int main() {
    Worker worker("Brice", (Position){0, 0, 0}, (Statistic){1, 0});
    Shovel shovel(5);
    Worker worker2("Antoine", (Position){0, 0, 0}, (Statistic){1, 0});

    cout << endl << Gray << "Equiping tools :" << ResetColor << endl;

    worker.equip(shovel);
    Shovel *equipedShovel = worker.getTool<Shovel>();
    cout << Gray << "> Shovel have " << equipedShovel->getNumberOfUses() << " uses left" << ResetColor << endl;

    cout << endl;

    worker2.equip(*equipedShovel); // Should not equip the shovel
    Shovel *equipedShovel2 = worker2.getTool<Shovel>(); // Should return NULL
    if (equipedShovel2 == NULL)
        cout << Gray << "> Shovel hasn't been equipped" << ResetColor << endl;
    
    cout << endl << Gray << "Working with tools :" << ResetColor << endl;
    
    for (int i = 0; i < 6; i++) {
        worker.work<Shovel>(); // Should work 5 times and fail the last time
    }
    worker2.work<Shovel>(); // Should not work

    cout << endl << Gray << "Unequiping tools :" << ResetColor << endl;

    worker.unequip<Shovel>(); // Should unequip the shovel
    worker.unequip<Shovel>(); // Should not unequip any tool
    worker2.unequip<Shovel>(); // Should not unequip any tool

    cout << endl;
}