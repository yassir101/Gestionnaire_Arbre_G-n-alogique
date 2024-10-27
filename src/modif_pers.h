#ifndef MODIF_PERS_H
#define MODIF_PERS_H

#include "types.h"
#include "files.h"
#include "getset.h"

void modifierNom(Pers *pers);
void modifierPrenom(Pers *pers);
void modifierNaissance(Pers *pers);
void modifierDeces(Pers *pers);
void modifierVivant(Pers *pers);
void ajouterLienParentReci(Pers *parent, Pers *enfant, char *mpt);
void supprimerLienParentReci(Pers *parent, Pers *enfant);
void ajouterEnfant(ListePers *arbre, Pers *pers);
void ajouterPere(ListePers *arbre, Pers *pers);
void ajouterMere(ListePers *arbre, Pers *pers);
void ajouterConj(ListePers *arbre, Pers *pers);
void supprimerEnfant(Pers *pers);
void supprimerPere(Pers *pers);
void supprimerMere(Pers *pers);
void supprimerConj(Pers *pers);
void modifierPere(ListePers *arbre, Pers *pers);
void modifierMere(ListePers *arbre, Pers *pers);
void modifierEnfants(ListePers *arbre, Pers *pers);
void modifierConj(ListePers *arbre, Pers *pers);
int coherenceDates(Pers *parent, Pers *enfant, char *mpt);

#endif  // MODIF_PERS_H
