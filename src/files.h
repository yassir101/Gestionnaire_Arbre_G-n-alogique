#ifndef FILES_H
#define FILES_H

#include "types.h"
#include "getset.h"

char* saisirNomFichier();
ListePers* numero(ListePers* arbre);
void sauvegarderArbreFichier(ListePers* arbre, char* nomFich);
Pers* retrouverPersavecNumero(ListePers* arbre, int n);
ListePers* retrouverLiens(ListePers* arbre);
ListePers* chargerArbre(char* nomFich);

#endif  // FILES_H
