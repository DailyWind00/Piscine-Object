#include "Graph.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: ./graph filename" << endl;
        return 1;
    }

    try {
        Graph graph = Graph(argv[1]);
    }
    catch(const std::exception& e) {
        cerr << e.what() << '\n';
    }

    return 0;
}
