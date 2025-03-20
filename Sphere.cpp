#include "Sphere.h"
#include <sstream>
#include <iomanip>
#include <string>

// Constructor
Sphere::Sphere(const std::string& name, double radius)
    : Shape(name), radius(radius) {}

// Surface Area = 4 * PI * r^2
double Sphere::getArea() const {
    return 4 * PI * radius * radius;
}

// Volume = (4/3) * PI * r^3
double Sphere::getVolume() const {
    return (4.0/3.0) * PI * radius * radius * radius;
}

// The test function goes through the condition vector three strings at a time.
// For "type" it compares the constant string "sphere" with the provided value.
// For "area" and "volume" it compares the computed values.
bool Sphere::test(const std::vector<std::string>& cond) const {
    std::string myType = "sphere";
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

std::string Sphere::getInfo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "Sphere: " << getName() << ", Radius=" << radius << "\n";
    oss << " Surface Area: " << getArea() << ", Volume: " << getVolume();
    return oss.str();
}
