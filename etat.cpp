#include "etat.h"
#include <iostream>

int Etat::getNumEtat(){
    return numEtat;
}

bool Etat0::transition(Automate &d, Symbole *s)
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
        d.decalage(s, new Etat1());
    }
    return false;
}

bool Etat1::transition(Automate &d, Symbole *s)
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

bool Etat2::transition(Automate &d, Symbole *s)
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

bool Etat3::transition(Automate &d, Symbole *s)
{
    
    if (*s == PLUS)
    {
        regle5(d, s);
    }
    else if (*s == MULT)
    {
        regle5(d, s);
    }
    else if (*s == CLOSEPAR)
    {
        regle5(d, s);
    }
    else if (*s == FIN)
    {
        regle5(d, s);
    }
    return false;
}

bool Etat4::transition(Automate &d, Symbole *s)
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

bool Etat5::transition(Automate &d, Symbole *s)
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

bool Etat6::transition(Automate &d, Symbole *s)
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

bool Etat7::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        regle2(d, s);
    }
    else if (*s == MULT)
    {
        d.decalage(s, new Etat5());
    }
    else if (*s == CLOSEPAR)
    {
        regle2(d, s);
    }
    else if (*s == FIN)
    {
        regle2(d, s);
    }
    return false;
}

bool Etat8::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        regle3(d, s);
    }
    else if (*s == MULT)
    {
        regle3(d, s);
    }
    else if (*s == CLOSEPAR)
    {
        regle3(d, s);
    }
    else if (*s == FIN)
    {
        regle3(d, s);
    }
    return false;
}

bool Etat9::transition(Automate &d, Symbole *s)
{
    if (*s == PLUS)
    {
        regle4(d, s);
    }
    else if (*s == MULT)
    {
        regle4(d, s);
    }
    else if (*s == CLOSEPAR)
    {
        regle4(d, s);
    }
    else if (*s == FIN)
    {
        regle4(d, s);
    }
    return false;
}

// regles : Il faut peut-etre penser a delete les pointeurs sur les symboles poped?

void Etat::regle1(Automate &d, Symbole *s)
{
    cerr<<"Not implemented because not necessary"<<endl;
    exit(1);
}

void Etat::regle2(Automate &d, Symbole *s)
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
    d.reduction(3, new Expr(exprValeur), s);
}

void Etat::regle3(Automate &d, Symbole *s)
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
    d.reduction(3, new Expr(exprValeur), s);
}

void Etat::regle4(Automate &d, Symbole *s)
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
    d.reduction(3, new Expr(exprValeur), s);
}

void Etat::regle5(Automate &d, Symbole *s)
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
    d.reduction(1, new Expr(exprValeur), s);
}