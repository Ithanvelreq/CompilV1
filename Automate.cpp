#include "Automate.h"
#include <iostream>


Automate::Automate(Etat *etat, string expression){
    stackEtats.push(etat);
    lexer = new Lexer(expression);
}
Automate::~Automate(){
    delete(lexer);
}
/**
int Automate::analyser();

void Automate::decalage (Symbole s, Etat * etat);
void Automate::reduction (int n, Symbole s);*/