#ifndef BOX_H
#define BOX_H

#include "Shape.h"
#include <string>
#include <vector>

class Box : public Shape {
public:
    Box(const std::string& name, double length, double width, double height);
    virtual ~Box() = default;
    
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual bool test(const std::vector<std::string>& cond) const;
    virtual std::string getInfo() const;
    
private:
    double length;
    double width;
    double height;
};

#endif
