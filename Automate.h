#pragma once

#include <string>
#include <stack>
#include <string>
#include "symbole.h"
#include "lexer.h"
class Etat;
class Automate
{
public:
    Automate(Etat *etat, string expression);
    ~Automate();
    bool analyser();
    void decalage(Symbole *s, Etat *etat);
    int reduction(int n, Symbole *s, Symbole *teteLecture);
    int getResultat();
    Symbole *popSymbole();

protected:
    stack<Etat *> stackEtats;
    stack<Symbole *> stackSymbole;
    Lexer *lexer;
    int resultat = 0;
};