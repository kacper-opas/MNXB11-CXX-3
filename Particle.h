#pragma once
#include <TObject.h>
#include <cmath>

class Particle : public TObject
{
public:
    Particle();                                      // default constructor
    Particle(Double_t px, Double_t py, Double_t pz); // constructor
    virtual ~Particle();                             // destructor

    Double_t Magnitude() const; // calculate |p|

    Double_t px, py, pz; // momentum
private:
    ClassDef(Particle, 1); // my class
};
