#include "etat.h"
#include <iostream>

int Etat::getNumEtat(){
    return numEtat;
}

int Etat0::transition(Automate &d, Symbole *s)
{
    int valid = 0;
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
        d.decalage(s, new Etat1());
    }
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat1::transition(Automate &d, Symbole *s)
{
    int valid = 0;
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
        return 1;
    }
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat2::transition(Automate &d, Symbole *s)
{
    int valid = 0;
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
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat3::transition(Automate &d, Symbole *s)
{
    int valid = 0;
    if (*s == PLUS)
    {
        valid = regle5(d, s);
    }
    else if (*s == MULT)
    {
        valid = regle5(d, s);
    }
    else if (*s == CLOSEPAR)
    {
        valid = regle5(d, s);
    }
    else if (*s == FIN)
    {
        valid = regle5(d, s);
    }
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat4::transition(Automate &d, Symbole *s)
{
    int valid = 0;
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
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat5::transition(Automate &d, Symbole *s)
{
    int valid = 0;
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
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat6::transition(Automate &d, Symbole *s)
{
    int valid = 0;
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
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat7::transition(Automate &d, Symbole *s)
{
    int valid = 0;
    if (*s == PLUS)
    {
        valid = regle2(d, s);
    }
    else if (*s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (*s == CLOSEPAR)
    {
        valid = regle2(d, s);
    }
    else if (*s == FIN)
    {
        valid = regle2(d, s);
    }
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat8::transition(Automate &d, Symbole *s)
{
    int valid = 0;
    if (*s == PLUS)
    {
        valid = regle3(d, s);
    }
    else if (*s == MULT)
    {
        valid = regle3(d, s);
    }
    else if (*s == CLOSEPAR)
    {
        valid = regle3(d, s);
    }
    else if (*s == FIN)
    {
        valid = regle3(d, s);
    }
    else
    {
        valid = 2;
    }
    return valid;
}

int Etat9::transition(Automate &d, Symbole *s)
{
    int valid = 0;
    if (*s == PLUS)
    {
        valid = regle4(d, s);
    }
    else if (*s == MULT)
    {
        valid = regle4(d, s);
    }
    else if (*s == CLOSEPAR)
    {
        valid = regle4(d, s);
    }
    else if (*s == FIN)
    {
        valid = regle4(d, s);
    }
    else
    {
        valid = 2;
    }
    return valid;
}

// regles : Il faut peut-etre penser a delete les pointeurs sur les symboles poped?

int Etat::regle1(Automate &d, Symbole *s)
{
    cerr<<"Not implemented because not necessary"<<endl;
    exit(1);
}

int Etat::regle2(Automate &d, Symbole *s)
{
    Symbole *E1 = d.popSymbole();
    Symbole *plus = d.popSymbole();
    Symbole *E2 = d.popSymbole();
    int exprValeur;
    if (*E1 == EXPR && *plus == PLUS && *E2 == EXPR)
    {
        exprValeur = E1->getValeur() + E2->getValeur();
    }
    else
    {
        cout << "ERREUR lors de la reduction de la regle 2" << endl;
        exit(1);
    }
    delete(E1); delete(plus); delete(E2);
    return d.reduction(3, new Expr(exprValeur), s);
}

int Etat::regle3(Automate &d, Symbole *s)
{
    Symbole *E1 = d.popSymbole();
    Symbole *mult = d.popSymbole();
    Symbole *E2 = d.popSymbole();
    int exprValeur;
    if (*E1 == EXPR && *mult == MULT && *E2 == EXPR)
    {
        exprValeur = E1->getValeur() * E2->getValeur();
    }
    else
    {
        cout << "ERREUR lors de la reduction de la regle 3" << endl;
        exit(1);
    }
    delete(E1); delete(mult); delete(E2);
    return d.reduction(3, new Expr(exprValeur), s);
}

int Etat::regle4(Automate &d, Symbole *s)
{
    Symbole *paren2 = d.popSymbole();
    Symbole *E = d.popSymbole();
    Symbole *paren1 = d.popSymbole();
    int exprValeur;
    if (*paren1 == OPENPAR && *E == EXPR && *paren2 == CLOSEPAR)
    {
        exprValeur = E->getValeur();
    }
    else
    {
        cout << "ERREUR lors de la reduction de la regle 4" << endl;
        paren1->Affiche(); E->Affiche(); paren2->Affiche();
        cout << endl;
        exit(1);
    }
    delete(paren1); delete(E); delete(paren2);
    return d.reduction(3, new Expr(exprValeur), s);
}

int Etat::regle5(Automate &d, Symbole *s)
{
    Symbole *s1 = d.popSymbole();
    int exprValeur;
    if (*s1 == INT)
    {
        exprValeur = s1->getValeur();
    }
    else
    {
        cout << "ERREUR lors de la reduction de la regle 5, le symbole n'est pas val" << endl;
        exit(1);
    }
    delete(s1);
    return d.reduction(1, new Expr(exprValeur), s);
}