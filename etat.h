#pragma once

#include "symbole.h"
#include "automate.h"
#include <string>
using namespace std;

class Etat
{

public:
      Etat(int i) : numEtat(i) {}
      virtual ~Etat() {}
      virtual int getNumEtat();
      virtual int transition(Automate &d, Symbole *s) = 0; // 0 pas encore fini mais valide pour l'instant
                                                           // 1 fini et valide
                                                           // 2 Pas valide

protected:
      int regle1(Automate &d, Symbole *s);
      int regle2(Automate &d, Symbole *s);
      int regle3(Automate &d, Symbole *s);
      int regle4(Automate &d, Symbole *s);
      int regle5(Automate &d, Symbole *s);
      int numEtat = 88;
};

class Etat0 : public Etat
{
public:
      Etat0() : Etat(0) {}
      ~Etat0() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat1 : public Etat
{
public:
      Etat1() : Etat(1) {}
      ~Etat1() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat2 : public Etat
{
public:
      Etat2() : Etat(2) {}
      ~Etat2() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat3 : public Etat
{
public:
      Etat3() : Etat(3) {}
      ~Etat3() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat4 : public Etat
{
public:
      Etat4() : Etat(4) {}
      ~Etat4() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat5 : public Etat
{
public:
      Etat5() : Etat(5) {}
      ~Etat5() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat6 : public Etat
{
public:
      Etat6() : Etat(6) {}
      ~Etat6() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat7 : public Etat
{
public:
      Etat7() : Etat(7) {}
      ~Etat7() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat8 : public Etat
{
public:
      Etat8() : Etat(8) {}
      ~Etat8() {}
      virtual int transition(Automate &d, Symbole *s);
};

class Etat9 : public Etat
{
public:
      Etat9() : Etat(9) {}
      ~Etat9() {}
      virtual int transition(Automate &d, Symbole *s);
};