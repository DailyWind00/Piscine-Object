#include "Graph.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: ./graph filename" << endl;
        return 1;
    }

    try {
        Graph graph(argv[1]);

        graph.printOnTerminal();
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }

    return 0;
}
