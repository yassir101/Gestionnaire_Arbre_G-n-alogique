#ifndef FAMILLE_H
#define FAMILLE_H

#define MAX_NAME_LENGTH 50

typedef struct Personne {
  char nom[MAX_NAME_LENGTH];
  char prenom[MAX_NAME_LENGTH];
  int age;
  struct Personne *conjoint;
  struct Personne *enfant;
  struct Personne *parent;
} Personne;

void ajouterPersonne(Personne **famille);
void marier(Personne **famille);
void ajouterEnfant(Personne **famille);
void afficherFamille(Personne **famille);
void sauvegarderGeneralogie(Personne **famille, const char *nomFichier);
void chargerGeneralogie(Personne **famille, const char *nomFichier);
void libererMemoire(Personne **famille);

#endif /* FAMILLE_H */
