#include "Graph.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION

/// Constructor & Destructor
Graph::Graph() {
}

Graph::Graph(const string &filename) {
    ifstream file(filename.c_str());
    if (!file.is_open())
        throw invalid_argument("File does not exist");

    string line;
    stringstream ss;
    Vector2 pos;

    while (getline(file, line)) {
        replace(line.begin(), line.end(), ',', ' ');
        ss << line;
        ss >> pos.first >> pos.second;
        cout << pos.first << " " << pos.second << endl;
        if (ss.fail())
            throw invalid_argument("Invalid file format");
        points.push_back(pos);
        ss.clear();
    }

    file.close();
}

Graph::~Graph() {
}
// ---



///