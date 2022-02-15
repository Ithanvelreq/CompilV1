#pragma once

#include "symbole.h"
#include "automate.h"
#include <string>
using namespace std;

class Etat
{

public:
      virtual ~Etat() {}
      virtual bool *transition(Automate &d, Symbole *s) = 0;

protected:
      void regleCinq(Automate &d, Symbole *s);
};

class Etat0 : public Etat
{
public:
      Etat0() {}
      ~Etat0() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat1 : public Etat
{
public:
      Etat1() {}
      ~Etat1() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat2 : public Etat
{
public:
      Etat2() {}
      ~Etat2() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat3 : public Etat
{
public:
      Etat3() {}
      ~Etat3() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat4 : public Etat
{
public:
      Etat4() {}
      ~Etat4() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat5 : public Etat
{
public:
      Etat5() {}
      ~Etat5() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat6 : public Etat
{
public:
      Etat6() {}
      ~Etat6() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat7 : public Etat
{
public:
      Etat7() {}
      ~Etat7() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat8 : public Etat
{
public:
      Etat8() {}
      ~Etat8() {}
      virtual bool *transition(Automate &d, Symbole *s);
};

class Etat9 : public Etat
{
public:
      Etat9() {}
      ~Etat9() {}
      virtual bool *transition(Automate &d, Symbole *s);
};