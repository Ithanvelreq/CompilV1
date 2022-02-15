#include "etat.h"
#include <iostream>

bool *Etat0::transition(Automate &d, Symbole *s)
{
    if (*s == INT)
    {
        cout << "INT" << endl;
        d.decalage(s, new Etat3());
    }
    else if (*s == OPENPAR)
    {
        cout << "OPENPAR" << endl;
        d.decalage(s, new Etat2());
    }
    else if (*s == EXPR)
    {
        cout << "EXPR" << endl;
        d.decalage(s, new Etat1());
    }
    return false;
}

bool *Etat1::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        d.decalage(s, new Etat4());
    }
    else if (*s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (*s == FIN)
    {
        return true;
    }
    return false;
}

bool *Etat2::transition(Automate &d, Symbole *s)
{
    if (*s == INT)
    {
        d.decalage(s, new Etat3());
    }
    else if (*s == OPENPAR)
    {
        d.decalage(s, new Etat2());
    }
    else if (*s == EXPR)
    {
        d.decalage(s, new Etat6());
    }
    return false;
}

bool *Etat3::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        regleCinq(d, s);
    }
    else if (*s == MULT)
    {
        // regle 5
        return new Etat2();
    }
    else if (*s == CLOSEPAR)
    {
        // regle 5
        return new Etat1();
    }
    else if (*s == FIN)
    {
        // regle 5
        return new Etat0();
    }
    return false;
}

bool *Etat4::transition(Automate &d, Symbole *s)
{
    if (*s == INT)
    {
        d.decalage(s, new Etat3());
    }
    else if (*s == OPENPAR)
    {
        d.decalage(s, new Etat2());
    }
    else if (*s == EXPR)
    {
        d.decalage(s, new Etat7());
    }
    return false;
}

bool *Etat5::transition(Automate &d, Symbole *s)
{
    if (*s == INT)
    {
        d.decalage(s, new Etat3());
    }
    else if (*s == OPENPAR)
    {
        d.decalage(s, new Etat2());
    }
    else if (*s == EXPR)
    {
        d.decalage(s, new Etat8());
    }
    return false;
}

bool *Etat6::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        d.decalage(s, new Etat4());
    }
    else if (*s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (*s == CLOSEPAR)
    {
        d.decalage(s, new Etat9());
    }
    return false;
}

bool *Etat7::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        // regle 2
        return new Etat0();
    }
    else if (*s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (*s == CLOSEPAR)
    {
        // regle 2
        return new Etat1();
    }
    else if (*s == FIN)
    {
        // regle 2
        return new Etat0();
    }
    return false;
}

bool *Etat8::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        // regle 3
        return new Etat0();
    }
    else if (*s == MULT)
    {
        // regle 3
        return new Etat2();
    }
    else if (*s == CLOSEPAR)
    {
        // regle 3
        return new Etat1();
    }
    else if (*s == FIN)
    {
        // regle 3
        return new Etat0();
    }
    return false;
}

bool *Etat9::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        // regle 4
        return new Etat0();
    }
    else if (*s == MULT)
    {
        // regle 4
        return new Etat2();
    }
    else if (*s == CLOSEPAR)
    {
        // regle 4
        return new Etat1();
    }
    else if (*s == FIN)
    {
        // regle 4
        return new Etat0();
    }
    return false;
}

// regles :

void Etat::regleCinq(Automate &d, Symbole *s)
{
    Symbole *s1 = d.popSymbole();
    int exprValeur;
    if (*s1 == INT)
    {
        exprValeur = *s1->getValeur();
    }
    else
    {
        cout << "ERREUR" << endl;
    }
    d.reduction(1, new Expr(exprValeur));
}