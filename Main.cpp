#include <iostream>
#include <stack>
#include "Etat.h"
#include "symbole.h"
#include "Automate.h"


int main(void) {
   string chaine("(12+12)*35+5");
   Automate a(new Etat0(), chaine);
   bool accepted = a.analyser();
   if(accepted==1){
      cout<<"Le resultat est :" << a.getResultat() << endl;
   }else{
      cout << "L'expression n'est pas syntaxiquement correcte :(" << endl;
   }
   return 0;
   
}
