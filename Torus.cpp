#include "Torus.h"
#include <sstream>
#include <iomanip>

// Constructor
Torus::Torus(const std::string& name, double smallRadius, double bigRadius)
    : Shape(name), smallRadius(smallRadius), bigRadius(bigRadius) {}

// Surface Area = 4 * PI^2 * bigRadius * smallRadius
double Torus::getArea() const {
    return 4 * PI * PI * bigRadius * smallRadius;
}

// Volume = 2 * PI^2 * bigRadius * (smallRadius)^2
double Torus::getVolume() const {
    return 2 * PI * PI * bigRadius * smallRadius * smallRadius;
}

bool Torus::test(const std::vector<std::string>& cond) const {
    std::string myType = "torus";
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

std::string Torus::getInfo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "Torus: " << getName() << ", Small Radius=" << smallRadius << ", Big Radius=" << bigRadius << "\n";
    oss << " Surface Area: " << getArea() << ", Volume: " << getVolume();
    return oss.str();
}
