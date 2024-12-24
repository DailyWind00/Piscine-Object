#include "Workshop.hpp"

int main() {
    Workshop workshop("Child labor workshop");
    Worker Brice("Brice", (Position){0, 0, 0}, (Statistic){1, 0});
    Shovel shovel(5);
    Worker Antoine("Antoine", (Position){0, 0, 0}, (Statistic){1, 0});
    Hammer hammer(2);

    cout << endl << Gray << "Registering workers :" << ResetColor << endl;

    workshop.registerWorker(Brice);
    workshop.registerWorker(Antoine);
    workshop.registerWorker(Brice); // Should not register Brice again

    cout << endl << Gray << "Equiping tools :" << ResetColor << endl;

    Brice.equip(shovel);
    Brice.equip(hammer);
    Shovel *equipedShovel = Brice.getTool<Shovel>();
    cout << Gray << "> Shovel have " << equipedShovel->getNumberOfUses() << " uses left" << ResetColor << endl;
    Hammer *equipedHammer = Brice.getTool<Hammer>();
    cout << Gray << "> Hammer have " << equipedHammer->getNumberOfUses() << " uses left" << ResetColor << endl;

    cout << endl;

    Antoine.equip(*equipedShovel); // Should not equip the shovel
    Shovel *equipedShovel2 = Antoine.getTool<Shovel>(); // Should return NULL
    if (equipedShovel2 == NULL)
        cout << Gray << "> Shovel hasn't been equipped" << ResetColor << endl;
    
    cout << endl << Gray << "Working with tools :" << ResetColor << endl;
    
    for (int i = 0; i < 6; i++) {
        Brice.work<Shovel>(); // Should work 5 times and fail the last time
    }
    cout << endl;

    Antoine.work<Shovel>(); // Should not work

    Antoine.equip(shovel); // Shovel has been removed but not deleted

    cout << endl << Gray << "Unequiping tools :" << ResetColor << endl;

    Antoine.unequip<Shovel>(); // Should unequip the shovel
    Antoine.unequip<Shovel>(); // Should not unequip any tool
    Brice.unequip<Shovel>(); // Should not unequip any tool

    cout << endl << Gray << "Unregistering workers :" << ResetColor << endl;

    workshop.unregisterWorker(Brice);
    workshop.unregisterWorker(Antoine);
    workshop.unregisterWorker(Brice); // Should not unregister Brice again

    cout << endl;
}