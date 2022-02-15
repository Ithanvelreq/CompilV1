#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs
{
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   FIN,
   EXPR,
   ERREUR
};

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "EXPR", "ERREUR"};

class Symbole
{
public:
   Symbole(int i, bool t) : ident(i), terminal(t) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   bool isTerminal() { return terminal; }
   virtual void Affiche();

protected:
   int ident;
   bool terminal;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT, true), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();

protected:
   int valeur;
};

class Expr : public Symbole
{
public:
   Expr() : Symbole(EXPR, false) {}
   ~Expr() {}
};
