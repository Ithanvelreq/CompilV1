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

class Etat0 : public Etat{
    public:
      Etat0() { }
      virtual ~Etat0() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat1 : public Etat{
    public:
      Etat1() { }
      virtual ~Etat1() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat2 : public Etat{
    public:
      Etat2() { }
      virtual ~Etat2() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat3 : public Etat{
    public:
      Etat3() { }
      virtual ~Etat3() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat4 : public Etat{
    public:
      Etat4() { }
      virtual ~Etat4() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat5 : public Etat{
    public:
      Etat5() { }
      virtual ~Etat5() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat6 : public Etat{
    public:
      Etat6() { }
      virtual ~Etat6() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat7 : public Etat{
    public:
      Etat7() { }
      virtual ~Etat7() { }
      virtual Etat * transition(Automate & d, Symbole s);
};

class Etat8 : public Etat{
    public:
      Etat8() { }
      virtual ~Etat8() { }
      virtual Etat * transition(Automate & d, Symbole s);
};