#ifndef GETSET_H
#define GETSET_H
#include "types.h"

// Déclarations des fonctions de getters
char* get_nom_pers(Pers *pers);
char* get_prenom_pers(Pers *pers);
int get_jNaissance_pers(Pers *pers);
int get_mNaissance_pers(Pers *pers);
int get_aNaissance_pers(Pers *pers);
Date get_dateNaissance_pers(Pers *pers);
int get_jDeces_pers(Pers *pers);
int get_mDeces_pers(Pers *pers);
int get_aDeces_pers(Pers *pers);
int get_jour_date(Date date);
int get_mois_date(Date date);
int get_annee_date(Date date);
Pers* get_pere_pers(Pers *pers);
Pers* get_mere_pers(Pers *pers);
int get_nbEnfants_pers(Pers *pers);
Pers* get_iemeEnfant_pers(Pers *pers, int i);
ListePers* get_enfants_pers(Pers *pers);
int get_vivant_pers(Pers *pers);
Pers* get_pers_liste(ListePers *arbre);
ListePers* get_suiv_liste(ListePers *arbre);
int get_n_pers(Pers *pers);
int get_np_pers(Pers *pers);
int get_nm_pers(Pers *pers);
int get_nc_pers(Pers *pers);

// Déclarations des fonctions de setters
void set_nom_pers(Pers *pers, const char *nom);
void set_prenom_pers(Pers *pers, const char *prenom);
void set_jNaissance_pers(Pers *pers, int jour);
void set_mNaissance_pers(Pers *pers, int mois);
void set_aNaissance_pers(Pers *pers, int annee);
void set_dateNaissance_pers(Pers *pers, Date date);
void set_jDeces_pers(Pers *pers, int jour);
void set_mDeces_pers(Pers *pers, int mois);
void set_aDeces_pers(Pers *pers, int annee);
void set_pere_pers(Pers *pers, Pers *pere);
void set_mere_pers(Pers *pers, Pers *mere);
void set_nbEnfants_pers(Pers *pers, int nbEnfants);
void set_iemeEnfant_pers(Pers *pers, int i, Pers *enfant);
void set_enfants_pers(Pers *pers, ListePers *enfants);
void set_vivant_pers(Pers *pers, int vivant);
void set_pers_liste(ListePers *arbre, Pers *pers);
void set_suiv_liste(ListePers *arbre, ListePers *suivant);
void set_n_pers(Pers *pers, int n);
void set_np_pers(Pers *pers, int np);
void set_nm_pers(Pers *pers, int nm);
void set_nc_pers(Pers *pers, int nc);

ListePers* fix_maillon_liste(ListePers* arbre);
ListePers* fix_pers_liste_creer(ListePers* arbre, Pers* pers);
ListePers* sup_maillon_liste(ListePers* arbre, Pers* intru);
ListePers* fusion_listes_sansDouble(ListePers* l1, ListePers* l2);

Pers* personneVide();
ListePers* listeVide();

#endif  // GETSET_H
