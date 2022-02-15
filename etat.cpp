#include "etat.h"
#include <iostream>

bool *Etat0::transition(Automate &d, Symbole s)
{
    if (s == INT)
    {
        cout << "INT" << endl;
        d.decalage(s, new Etat3());
    }
    else if (s == OPENPAR)
    {
        cout << "OPENPAR" << endl;
        d.decalage(s, new Etat2());
    }
    else if (s == EXPR)
    {
        cout << "EXPR" << endl;
        d.decalage(s, new Etat1());
    }
    return false;
}

Etat *Etat1::transition(Automate &d, Symbole s)
{
    if (s == PLUS)
    {
        d.decalage(s, new Etat4());
    }
    else if (s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (s == FIN)
    {
        return true;
    }
    return false;
}

Etat *Etat2::transition(Automate &d, Symbole s)
{
    if (s == INT)
    {
        d.decalage(s, new Etat3());
    }
    else if (s == OPENPAR)
    {
        d.decalage(s, new Etat2());
    }
    else if (s == EXPR)
    {
        d.decalage(s, new Etat6());
    }
    return false;
}

Etat *Etat3::transition(Automate &d, Symbole s)
{
    if (s == PLUS)
    {
        // regle 5
        return new Etat0();
    }
    else if (s == MULT)
    {
        // regle 5
        return new Etat2();
    }
    else if (s == CLOSEPAR)
    {
        // regle 5
        return new Etat1();
    }
    else if (s == FIN)
    {
        // regle 5
        return new Etat0();
    }
    return false;
}

Etat *Etat4::transition(Automate &d, Symbole s)
{
    if (s == INT)
    {
        d.decalage(s, new Etat3());
    }
    else if (s == OPENPAR)
    {
        d.decalage(s, new Etat2());
    }
    else if (s == EXPR)
    {
        d.decalage(s, new Etat7());
    }
    return false;
}

Etat *Etat5::transition(Automate &d, Symbole s)
{
    if (s == INT)
    {
        d.decalage(s, new Etat3());
    }
    else if (s == OPENPAR)
    {
        d.decalage(s, new Etat2());
    }
    else if (s == EXPR)
    {
        d.decalage(s, new Etat8());
    }
    return false;
}

Etat *Etat6::transition(Automate &d, Symbole s)
{
    if (s == PLUS)
    {
        d.decalage(s, new Etat4());
    }
    else if (s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (s == CLOSEPAR)
    {
        d.decalage(s, new Etat9());
    }
    return false;
}

Etat *Etat7::transition(Automate &d, Symbole s)
{
    if (s == PLUS)
    {
        // regle 2
        return new Etat0();
    }
    else if (s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (s == CLOSEPAR)
    {
        // regle 2
        return new Etat1();
    }
    else if (s == FIN)
    {
        // regle 2
        return new Etat0();
    }
    return false;
}

Etat *Etat8::transition(Automate &d, Symbole s)
{
    if (s == PLUS)
    {
        // regle 3
        return new Etat0();
    }
    else if (s == MULT)
    {
        // regle 3
        return new Etat2();
    }
    else if (s == CLOSEPAR)
    {
        // regle 3
        return new Etat1();
    }
    else if (s == FIN)
    {
        // regle 3
        return new Etat0();
    }
    return false;
}

Etat *Etat9::transition(Automate &d, Symbole s)
{
    if (s == PLUS)
    {
        // regle 4
        return new Etat0();
    }
    else if (s == MULT)
    {
        // regle 4
        return new Etat2();
    }
    else if (s == CLOSEPAR)
    {
        // regle 4
        return new Etat1();
    }
    else if (s == FIN)
    {
        // regle 4
        return new Etat0();
    }
    return false;
}