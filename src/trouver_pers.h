#ifndef TROUVER_PERS_H
#define TROUVER_PERS_H

#include "types.h"
#include "getset.h"

int get_nbJours_mois(int m);
int estBisextile(int a);
int estUneDate(Date date);
Date demanderDate();
Pers* trouverPers(ListePers* arbre);

#endif  // TROUVER_PERS_H
