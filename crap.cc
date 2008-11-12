#include <cstdlib>
#include <iostream>
#include "trm_subs.h"
#include "trm_binary.h"
#include "trm_constants.h"

int main(){
  double m1 = 0.6;
  double m2 = 0.1;
  double period = 1.14*3600;
  double a = Binary::orbital_separation(m1, m2, period);
  double jdot = Binary::jdotgr(m1, m2, a)*Binary::orbital_ang_mom(m1, m2, a);
  cout << Constants::MSUN*Subs::sqr(Constants::RSUN)*jdot << endl;
}
