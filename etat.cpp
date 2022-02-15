#include "etat.h"
#include <iostream>

Etat * Etat0::transition(Automate & d, Symbole s){
    if(s == INT){
        return new Etat3();
    }else if(s == OPENPAR){
        return new Etat2();
    }else if(s == EXPR){
        return new Etat1();
    }
    return nullptr;
}
