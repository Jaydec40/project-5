#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include <string>
#include <vector>

class Cylinder : public Shape {
public:
    Cylinder(const std::string& name, double radius, double height);
    virtual ~Cylinder() = default;
    
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual bool test(const std::vector<std::string>& cond) const;
    virtual std::string getInfo() const;
    
private:
    double radius;
    double height;
};

#endif
