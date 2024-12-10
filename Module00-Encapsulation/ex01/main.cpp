#include "Graph.hpp"

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Usage: ./graph filename png_output" << endl;
        return 1;
    }

    try {
        Graph graph(argv[1]);

        graph.printOnTerminal();
        graph.saveAsImage(argv[2]);
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }

    return 0;
}
