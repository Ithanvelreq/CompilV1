#pragma once

#include <string>
#include <stack>
#include <string>
#include "symbole.h"
#include "lexer.h"
class Etat;
class Automate{
    public:
        Automate(Etat * etat, string expression);
        ~Automate();
        int analyser();
        void decalage (Symbole * s, Etat * etat);
        void reduction (int n, Symbole * s);
        Symbole * popSymbole();

    protected:
        stack<Etat *> stackEtats;
        stack<Symbole *> stackSymbole;
        Lexer * lexer;
};