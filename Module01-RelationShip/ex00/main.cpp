#include "Workshop.hpp"

// Do every unit test here
int main() {
    Workshop<Shovel> childLabor("Child labor workshop");
    Workshop<Hammer> bob("Bob the builder's workshop");
    Worker Brice("Brice", (Position){0, 0, 0}, (Statistic){1, 0});
    Shovel shovel(5);
    Worker Antoine("Antoine", (Position){0, 0, 0}, (Statistic){1, 0});
    Hammer hammer(2);

    cout << endl << LightGray << "Equiping tools :" << ResetColor << endl;

    Brice.equip(shovel);
    Brice.equip(hammer);
    Shovel *equipedShovel = Brice.getTool<Shovel>();
    cout << LightGray << "> Shovel have " << equipedShovel->getNumberOfUses() << " uses left" << ResetColor << endl;
    Hammer *equipedHammer = Brice.getTool<Hammer>();
    cout << LightGray << "> Hammer have " << equipedHammer->getNumberOfUses() << " uses left" << ResetColor << endl;

    Antoine.equip(*equipedShovel); // Should not equip the shovel
    Shovel *equipedShovel2 = Antoine.getTool<Shovel>(); // Should return NULL
    if (equipedShovel2 == NULL)
        cout << LightGray << "> Shovel hasn't been equipped" << ResetColor << endl;
    
    cout << endl << LightGray << "Registering workers :" << ResetColor << endl;

    bob.registerWorker(Brice);
    childLabor.registerWorker(Brice);
    childLabor.registerWorker(Antoine); // Should not register Antoine because he doesn't have the right tool
    childLabor.registerWorker(Brice); // Should not register Brice again

    cout << endl;

    Brice.listWorkshops();
    Antoine.listWorkshops();

    cout << endl << LightGray << "Working with tools :" << ResetColor << endl;
    
    for (int i = 0; i < 6; i++) {
        Brice.work<Shovel>(); // Should work 5 times and fail the last time
    }

	cout << endl;

	for (int i = 0; i < 3; i++)
		bob.executeWorkDay(); // Should work 2 times and fail the last time

    cout << endl;

    Antoine.work<Shovel>(); // Should not work

    Antoine.equip(shovel); // Shovel has been removed but not deleted

    cout << endl << LightGray << "Unequiping tools :" << ResetColor << endl;

    Antoine.unequip<Shovel>(); // Should unequip the shovel
    Antoine.unequip<Shovel>(); // Should not unequip any tool
    Brice.unequip<Shovel>(); // Should not unequip any tool

    cout << endl << LightGray << "Unregistering workers :" << ResetColor << endl;

    childLabor.unregisterWorker(Brice);
    childLabor.unregisterWorker(Antoine);
    childLabor.unregisterWorker(Brice); // Should not unregister Brice again

    cout << endl;

    Brice.listWorkshops();

    cout << endl;
}