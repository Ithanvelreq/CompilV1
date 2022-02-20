#include "Automate.h"
#include "etat.h"
#include <iostream>
#include <assert.h>

Automate::Automate(Etat *etat, string expression)
{
    stackEtats.push(etat);
    lexer = new Lexer(expression);
    // cout << "constr automate" << endl;
}
Automate::~Automate()
{
    while (!stackEtats.empty())
    {
        delete (stackEtats.top());
        stackEtats.pop();
    }
    while (!stackSymbole.empty())
    {
        delete (stackSymbole.top());
        stackSymbole.pop();
    }
    delete (lexer);
    // cout << "destr automate" << endl;
}

bool Automate::analyser()
{
    int accepted = 0;
    bool init = true;
    Symbole *suivant;
    while (accepted == 0 && (!stackSymbole.empty() || init))
    {
        suivant = lexer->Consulter();
        cout << "etat actuel: Etat" << stackEtats.top()->getNumEtat() << " ||| dernier symbole sur le stack ";
        if (!stackSymbole.empty())
        {
            stackSymbole.top()->Affiche();
        }
        cout << " |||| symbole sous la tete: ";
        suivant->Affiche();
        cout << endl;
        accepted = stackEtats.top()->transition(*this, suivant);
        lexer->Avancer();
        assert(stackEtats.size() == (stackSymbole.size() + 1));
        init = false;
    }
    delete (suivant);
    if (accepted == 1)
    {
        resultat = stackSymbole.top()->getValeur();
    }
    else
    {
        accepted = 0;
    }
    return accepted;
}

Symbole *Automate::popSymbole()
{
    Symbole *s = stackSymbole.top();
    stackSymbole.pop();
    return s;
}

void Automate::decalage(Symbole *s, Etat *etat)
{
    stackEtats.push(etat);
    stackSymbole.push(s);
}

int Automate::reduction(int n, Symbole *expr, Symbole *teteLecture)
{
    for (int i = 0; i < n; i++)
    {
        delete (stackEtats.top());
        stackEtats.pop();
    }
    cout << "reduction a l'etat " << stackEtats.top()->getNumEtat() << " avec symbole de trans: ";
    expr->Affiche();
    cout << endl;
    stackEtats.top()->transition(*this, expr);
    return stackEtats.top()->transition(*this, teteLecture);
}

int Automate::getResultat()
{
    return resultat;
}