#include "Graph.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION

/// Constructor & Destructor
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
        // cout << pos.first << " " << pos.second << endl; // To remove
        if (ss.fail())
            throw invalid_argument("Invalid file format");
        if (pos.first < 0 || pos.second < 0 || pos.first >= MAX_SIZE || pos.second >= MAX_SIZE)
            throw invalid_argument((string)"Invalid point, must be between 0 and 15");
        points.push_back(pos);
        ss.clear();
    }

    file.close();
}

Graph::~Graph() {
}
// ---



/// Output methods

void    Graph::printOnTerminal() const {
    int y = MAX_SIZE - 1;

    while (y >= 0) {
        if (y < 10)
            cout << " ";
        cout << y;
        for (int x = 0; x < MAX_SIZE; x++) {
            Vector2 pos(x, y);
            if (find(points.begin(), points.end(), pos) != points.end())
                cout << " X ";
            else
                cout << " . ";
        }
        cout << endl;
        y--;
    }
    cout << "  ";
    for (int x = 0; x < MAX_SIZE; x++) {
        if (x < 10)
            cout << " ";
        cout << x << " ";
    }
    cout << endl;   
}

void    Graph::saveAsImage(const string &output) const {
    (void)output;
}
/// ---