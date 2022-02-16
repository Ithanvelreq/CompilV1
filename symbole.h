#pragma once
#include <iostream>
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
   Symbole(int i) : ident(i) {cout << "constr symbole" << endl;}
   virtual ~Symbole() {cout << "destr symbole" << endl;}
   operator int() const { return ident; }
   virtual void Affiche();
   virtual int getValeur() { return 0; }

protected:
   int ident;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();
   virtual int getValeur() { return valeur; }

protected:
   int valeur;
};

class Expr : public Symbole
{
public:
   Expr(int v) : Symbole(EXPR), valeur(v) {}
   ~Expr() {}
   virtual void Affiche();
   virtual int getValeur() { return valeur; }

protected:
   int valeur;
};
