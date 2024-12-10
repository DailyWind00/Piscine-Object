#pragma once

# include <iostream>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <vector>

# define MAX_SIZE 16

using namespace std;

typedef pair<float, float> Vector2; // x, y

class Graph {
    private:
        vector<Vector2> points;

    public:
        Graph(const string &filename);
        ~Graph();

        // Output methods

        void printOnTerminal() const;
        void saveAsImage(const string &output) const;
};