#ifndef MENUS_H
#define MENUS_H

#include "types.h"

void chargement();
ListePers* quitterSauvegarder(ListePers* arbre);
void sauvegarder(ListePers* arbre);
ListePers* menuPrincipal(ListePers* arbre);
ListePers* gerer(ListePers* arbre);
void modifierPers(ListePers* arbre);
void consulter(ListePers* arbre);

#endif // MENUS_H
