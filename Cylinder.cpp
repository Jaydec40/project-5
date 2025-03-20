#include "Cylinder.h"
#include <sstream>
#include <iomanip>

// Constructor
Cylinder::Cylinder(const std::string& name, double radius, double height)
    : Shape(name), radius(radius), height(height) {}

// Surface Area = 2 * PI * r * h + 2 * PI * r^2
double Cylinder::getArea() const {
    return 2 * PI * radius * height + 2 * PI * radius * radius;
}

// Volume = PI * r^2 * h
double Cylinder::getVolume() const {
    return PI * radius * radius * height;
}

bool Cylinder::test(const std::vector<std::string>& cond) const {
    std::string myType = "cylinder";
    for (size_t i = 0; i < cond.size(); i += 3) {
        std::string field = cond[i];
        std::string op = cond[i+1];
        std::string value = cond[i+2];

        if (field == "type") {
            if (op == "==") {
                if (myType != value) return false;
            } else if (op == "!=") {
                if (myType == value) return false;
            } else if (op == ">") {
                if (!(myType > value)) return false;
            } else if (op == "<") {
                if (!(myType < value)) return false;
            } else if (op == ">=") {
                if (!(myType >= value)) return false;
            } else if (op == "<=") {
                if (!(myType <= value)) return false;
            }
        } else if (field == "area") {
            double cmp = std::stod(value);
            double area = getArea();
            if (op == "==") {
                if (!(area == cmp)) return false;
            } else if (op == "!=") {
                if (!(area != cmp)) return false;
            } else if (op == ">") {
                if (!(area > cmp)) return false;
            } else if (op == "<") {
                if (!(area < cmp)) return false;
            } else if (op == ">=") {
                if (!(area >= cmp)) return false;
            } else if (op == "<=") {
                if (!(area <= cmp)) return false;
            }
        } else if (field == "volume") {
            double cmp = std::stod(value);
            double vol = getVolume();
            if (op == "==") {
                if (!(vol == cmp)) return false;
            } else if (op == "!=") {
                if (!(vol != cmp)) return false;
            } else if (op == ">") {
                if (!(vol > cmp)) return false;
            } else if (op == "<") {
                if (!(vol < cmp)) return false;
            } else if (op == ">=") {
                if (!(vol >= cmp)) return false;
            } else if (op == "<=") {
                if (!(vol <= cmp)) return false;
            }
        }
    }
    return true;
}

std::string Cylinder::getInfo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "Cylinder: " << getName() << ", Radius=" << radius << ", Height=" << height << "\n";
    oss << " Surface Area: " << getArea() << ", Volume: " << getVolume();
    return oss.str();
}

