#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listes.h"

/* fichier à compléter au besoin */

void init_liste_vide(liste_t* L) {
   // printf ("<<<<< À faire: fonction init_liste_vide fichier " __FILE__ "\n >>>>>");
    /* a completer */
   L = (liste_t *) malloc(sizeof(liste_t)) ;
}

void liberer_liste(liste_t* L) {
   // printf ("<<<<< À faire: fonction liberer_liste fichier " __FILE__ "\n >>>>>");
    /* a completer */
   free(L);
}

int ajouter_tete(liste_t* L, string c) { /* retourne 0 si OK, 1 sinon  */
   // printf ("<<<<< À faire: fonction ajouter_tete fichier " __FILE__ " >>>>>\n");
    /* a completer: FAIT */

   cellule_t * newCel = (cellule_t *) malloc(sizeof(cellule_t)) ;
   newCel->val = c;
   newCel->suivant = L->tete;
   L->tete = newCel;

   return 1;
}

