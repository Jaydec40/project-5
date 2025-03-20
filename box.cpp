#include "Box.h"
#include <sstream>
#include <iomanip>

// Constructor
Box::Box(const std::string& name, double length, double width, double height)
    : Shape(name), length(length), width(width), height(height) {}

// Surface Area = 2*(lw + lh + wh)
double Box::getArea() const {
    return 2 * (length * width + length * height + width * height);
}

// Volume = l * w * h
double Box::getVolume() const {
    return length * width * height;
}

bool Box::test(const std::vector<std::string>& cond) const {
    std::string myType = "box";
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

std::string Box::getInfo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "Box: " << getName() << ", Length=" << length << ", Width=" << width << ", Height=" << height << "\n";
    oss << " Surface Area: " << getArea() << ", Volume: " << getVolume();
    return oss.str();
}


