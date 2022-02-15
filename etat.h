#pragma once

#include "symbole.h"
#include <string>
using namespace std;

typedef struct Automate {} Automate;

class Etat {

   public:
      virtual ~Etat() { }
      virtual Etat * transition(Automate & d, Symbole s) = 0;
};

class Etat1 : public Etat{
    public:
      Etat1() { }
      virtual ~Etat1() { }
      virtual Etat * transition(Automate & d, Symbole s);
};