#include "Automate.h"
#include "etat.h"
#include <iostream>
#include <assert.h>

Automate::Automate(Etat *etat, string expression){
    stackEtats.push(etat);
    lexer = new Lexer(expression);
}
Automate::~Automate(){
    delete(lexer);
}

int Automate::analyser(){
    bool accepted = false;
    while(!accepted || !stackSymbole.empty()){
        Symbole * suivant = lexer->Consulter();
        accepted = stackEtats.top()->transition(*this, *suivant);
        lexer->Avancer();
        assert(stackEtats.size() == (stackSymbole.size()+1));
    }
    return accepted;
}

Symbole * Automate::popSymbole(){
    Symbole * s = stackSymbole.top();
    stackSymbole.pop();
    return s;
}

void Automate::decalage (Symbole s, Etat * etat){
    stackEtats.push(etat);
    stackSymbole.push(s);
}
/**
void Automate::reduction (int n, Symbole s);*/