#pragma once
#include <iostream>
#include <string>
#include "symbole.h"
using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { cout << "constr lexer" << endl;}
      ~Lexer() { delete(tampon);cout << "destr lexer" << endl;}

      Symbole * Consulter();
      void Avancer();

   protected:
      string flux;
      int tete;
      Symbole * tampon;
};
