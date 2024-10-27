#include "types.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char* get_nom_pers(Pers *pers) {
    return pers->nom;
}

char* get_prenom_pers(Pers *pers) {
    return pers->prenom;
}

int get_jNaissance_pers(Pers *pers) {
    return pers->naissance.jour;
}

int get_mNaissance_pers(Pers *pers) {
    return pers->naissance.mois;
}

int get_aNaissance_pers(Pers *pers) {
    return pers->naissance.annee;
}

Date get_dateNaissance_pers(Pers *pers) {
    return pers->naissance;
}

int get_jDeces_pers(Pers *pers) {
    return pers->deces.jour;
}

int get_mDeces_pers(Pers *pers) {
    return pers->deces.mois;
}

int get_aDeces_pers(Pers *pers) {
    return pers->deces.annee;
}

int get_jour_date(Date date) {
    return date.jour;
}

int get_mois_date(Date date) {
    return date.mois;
}

int get_annee_date(Date date) {
    return date.annee;
}

Pers* get_pere_pers(Pers *pers) {
    return pers->pere;
}

Pers* get_mere_pers(Pers *pers) {
    return pers->mere;
}

int get_nbEnfants_pers(Pers *pers) {
    return pers->n;
}

Pers* get_iemeEnfant_pers(Pers *pers, int i) {
    if (i >= 0 && i < pers->n) {
        return pers->enfants[i];
    }
    return NULL;  // Indiquer un dépassement de tableau
}

ListePers* get_enfants_pers(Pers *pers) {
    return pers->enfants;
}

int get_vivant_pers(Pers *pers) {
    return pers->vivant;
}

Pers* get_pers_liste(ListePers *arbre) {
    return arbre->pers;
}

ListePers* get_suiv_liste(ListePers *arbre) {
    return arbre->suivant;
}

int get_n_pers(Pers *pers) {
    return pers->n;
}

int get_np_pers(Pers *pers) {
    return pers->np;
}

int get_nm_pers(Pers *pers) {
    return pers->nm;
}

int get_nc_pers(Pers *pers) {
    return pers->nc;
}

void set_nom_pers(Pers *pers, const char *nom) {
    strncpy(pers->nom, nom, sizeof(pers->nom) - 1);
    pers->nom[sizeof(pers->nom) - 1] = '\0';
}

void set_prenom_pers(Pers *pers, const char *prenom) {
    strncpy(pers->prenom, prenom, sizeof(pers->prenom) - 1);
    pers->prenom[sizeof(pers->prenom) - 1] = '\0';
}

void set_jNaissance_pers(Pers *pers, int jour) {
    pers->naissance.jour = jour;
}

void set_mNaissance_pers(Pers *pers, int mois) {
    pers->naissance.mois = mois;
}

void set_aNaissance_pers(Pers *pers, int annee) {
    pers->naissance.annee = annee;
}

void set_dateNaissance_pers(Pers *pers, Date date) {
    pers->naissance = date;
}

void set_jDeces_pers(Pers *pers, int jour) {
    pers->deces.jour = jour;
}

void set_mDeces_pers(Pers *pers, int mois) {
    pers->deces.mois = mois;
}

void set_aDeces_pers(Pers *pers, int annee) {
    pers->deces.annee = annee;
}

void set_pere_pers(Pers *pers, Pers *pere) {
    pers->pere = pere;
}

void set_mere_pers(Pers *pers, Pers *mere) {
    pers->mere = mere;
}

void set_nbEnfants_pers(Pers *pers, int nbEnfants) {
    pers->n = nbEnfants;
}

void set_iemeEnfant_pers(Pers *pers, int i, Pers *enfant) {
    if (i >= 0 && i < pers->n) {
        pers->enfants[i] = enfant;
    }
}

void set_enfants_pers(Pers *pers, ListePers *enfants) {
    pers->enfants = enfants;
}

void set_vivant_pers(Pers *pers, int vivant) {
    pers->vivant = vivant;
}

void set_pers_liste(ListePers *arbre, Pers *pers) {
    arbre->pers = pers;
}

void set_suiv_liste(ListePers *arbre, ListePers *suivant) {
    arbre->suivant = suivant;
}

void set_n_pers(Pers *pers, int n) {
    pers->n = n;
}

void set_np_pers(Pers *pers, int np) {
    pers->np = np;
}

void set_nm_pers(Pers *pers, int nm) {
    pers->nm = nm;
}

void set_nc_pers(Pers *pers, int nc) {
    pers->nc = nc;
}



