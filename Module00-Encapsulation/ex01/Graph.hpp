#pragma once

# include "stb_image_write.h"
# include <iostream>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <vector>

using namespace std;

typedef pair<float, float> Vector2; // x, y

class Graph {
    private:
        vector<Vector2> points;

    public:
        Graph();
        Graph(const string &filename);
        ~Graph();
};