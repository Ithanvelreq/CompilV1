#include <iostream>
#include <stack>
#include "Etat.h"
#include "Automate.h"

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      cout << "Usage: ./Main E    avec E l'expression a analyser sans espaces" << endl;
      cout << "Exemple: ./Main 1+2+3+4+5"<<endl;
      exit(1);
   }
   string chaine = argv[1];
   
   Automate a(new Etat0(), chaine);
   bool accepted = a.analyser();
   cout << "---------------------------------------------------------------------------------------------------------" << endl;
   cout << "---------------------------------------------------------------------------------------------------------" << endl;
   if (accepted == 1)
   {
      cout << "Expression reconue :)" << endl;
      cout << "Le resultat est :" << a.getResultat() << endl;
   }
   else
   {
      cout << "L'expression n'est pas syntaxiquement correcte :(" << endl;
   }
   return 0;
}
