#include "Graph.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

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

// Save in PNG format
void    Graph::saveAsImage(const string &output) const {
    int width = MAX_SIZE * 4;
    int height = MAX_SIZE * 4;
    int channels = 1;

    vector<unsigned char>image(width * height * channels);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * channels;
            Vector2 pos(x / 4, y / 4);

            if (find(points.begin(), points.end(), pos) != points.end())
                image[index] = 255;
            else
                image[index] = 0;
        }
    }

    vector<unsigned char>flipped_image(width * height * channels);

    // Flip the rows: copy from bottom to top
    for (int y = 0; y < height; ++y) {
        const unsigned char* src_row = &image[(height - 1 - y) * width * channels];
        unsigned char* dst_row = &flipped_image[y * width * channels];
        copy(src_row, src_row + width * channels, dst_row);
    }

    // Save the image as a PNG
    if (!stbi_write_png(output.c_str(), width, height, channels, flipped_image.data(), width * channels))
        throw runtime_error("Failed to save the image");
}
/// ---