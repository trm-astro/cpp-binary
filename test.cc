
#include <iostream>
#include "trm_binary.h"

int main(){

  double q  = 0.6;
  double dq = 0.0001;

  cout << Binary::rcirc(q) << ": derivs " 
       << (Binary::rcirc(q+dq) - Binary::rcirc(q-dq))/(2.*dq) << " vs " 
       << Binary::drcircdq(q) << endl;
}
