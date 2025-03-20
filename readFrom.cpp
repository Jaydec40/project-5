#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "reading.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Box.h"

std::vector<Shape*> *readFrom(std::string filename) {
    std::vector<Shape*> *shapes = new std::vector<Shape*>;
    std::ifstream file(filename);
    if (!file.is_open()) {
        // If file cannot be opened, return an empty vector.
        return shapes;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if(line.empty()) continue;
        std::istringstream iss(line);
        std::string name, type;
        iss >> name >> type;
        
        if (type == "sphere") {
            double radius;
            iss >> radius;
            shapes->push_back(new Sphere(name, radius));
        }
        else if (type == "cylinder") {
            double radius, height;
            iss >> radius >> height;
            shapes->push_back(new Cylinder(name, radius, height));
        }
        else if (type == "torus") {
            double smallRadius, bigRadius;
            iss >> smallRadius >> bigRadius;
            shapes->push_back(new Torus(name, smallRadius, bigRadius));
        }
        else if (type == "box") {
            double length, width, height;
            iss >> length >> width >> height;
            shapes->push_back(new Box(name, length, width, height));
        }
        // If an unknown type is encountered, you could skip or handle it.
    }
    return shapes;
}
