#include <cstdlib>
#include <cmath>
#include "trm_subs.h"
#include "trm_constants.h"
#include "trm_binary.h"

/**
 * kepler_omega computes the Keplerian angular velocity a distance \b r
 * from a point mass of mass \b m.
 * \param m mass of object (solar masses)
 * \param r distance from object (solar radii)
 * \return Angular velocity in radians per second.
 */

double Binary::kepler_omega(double m, double r){
  return(sqrt(Constants::G*Constants::MSUN*m/(Constants::RSUN*r))/(Constants::RSUN*r));
}

