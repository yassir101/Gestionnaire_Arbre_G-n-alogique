#ifndef GESTION_H
#define GESTION_H

#include "modif_pers.h"

Pers* creerPers();
ListePers* ajouterPersonne(ListePers* arbre);
void supprimerFiliationPers(Pers* pers);
ListePers* supprimerPers(ListePers* arbre);
ListePers* viderArbre(ListePers* arbre);

#endif  // GESTION_H
