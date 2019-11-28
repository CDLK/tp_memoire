#include "vecteur_dynamique.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
  if(taille > 0){
    vecteur v = malloc(sizeof(int)+sizeof(double*));
    v->taille=taille;
    v->donnees = malloc(taille * sizeof(double));
    return v;
  } else {
    return NULL;
  }
}

void liberer_vecteur(vecteur v) {
  free(v->donnees);
  free(v);
}

int est_vecteur_invalide(vecteur v) {
    return v == NULL;
}

double *acces_vecteur(vecteur v, int i) {
  if(est_vecteur_invalide(v) == 0 && i >= 0){
    while(i >= v->taille){
      double* saveOld = v->donnees;
      v->donnees = realloc(v->donnees, sizeof(double)*v->taille*2);
      if(v->donnees == NULL){
        v->donnees = saveOld;
        return NULL;
      } else {
        v->taille = v->taille*2;
      }
    }
      return &(v->donnees[i]);
  } else {
    return NULL;
  }
}

int taille_vecteur(vecteur v) {
    return v->taille;
}
