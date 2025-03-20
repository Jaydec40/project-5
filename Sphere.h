#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include <string>
#include <vector>

class Sphere : public Shape {
public:
    Sphere(const std::string& name, double radius);
    virtual ~Sphere() = default;
    
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual bool test(const std::vector<std::string>& cond) const;
    virtual std::string getInfo() const;
    
private:
    double radius;
};

#endif
