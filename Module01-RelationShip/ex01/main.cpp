#include "Worker.hpp"
#include "Tools.hpp"

int main() {
    Worker worker("Brice", (Position){0, 0, 0}, (Statistic){1, 0});
    Shovel shovel(5);
    Worker worker2("Antoine", (Position){0, 0, 0}, (Statistic){1, 0});

    cout << endl << Gray << "Equiping tools :" << ResetColor << endl;

    worker.equip(&shovel);

    cout << endl;
}