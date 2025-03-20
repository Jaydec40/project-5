#ifndef TORUS_H
#define TORUS_H

#include "Shape.h"
#include <string>
#include <vector>

class Torus : public Shape {
public:
    Torus(const std::string& name, double smallRadius, double bigRadius);
    virtual ~Torus() = default;
    
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual bool test(const std::vector<std::string>& cond) const;
    virtual std::string getInfo() const;
    
private:
    double smallRadius;
    double bigRadius;
};

#endif
