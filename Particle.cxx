#include "Particle.h"
#include "TMath.h"

ClassImp(Particle)

    // default constructor
    Particle::Particle() : px(0), py(0), pz(0)
{
}

// another constructor
Particle::Particle(Double_t px_, Double_t py_, Double_t pz_) : px(px_), py(py_), pz(pz_) {}

// destructor
Particle::~Particle() {}

// magnitude calculation
Double_t Particle::Magnitude() const
{
    return std::sqrt(px * px + py * py + pz * pz);
}
