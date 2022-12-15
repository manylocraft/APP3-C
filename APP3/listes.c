#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listes.h"

/* fichier à compléter au besoin */

void init_liste_vide(liste_t* L) {
   // printf ("<<<<< À faire: fonction init_liste_vide fichier " __FILE__ "\n >>>>>");
    /* a completer */
   L->tete = NULL;
}

void liberer_liste(liste_t* L) {
   // printf ("<<<<< À faire: fonction liberer_liste fichier " __FILE__ "\n >>>>>");
    /* a completer */
   if (L == NULL){
      return;
   }

   cellule_t *tmp;
   while (L->tete != NULL){
      tmp = L->tete;
      L->tete = L->tete->suivant;
      free(tmp);
   }
}

int ajouter_tete(liste_t* L, string c) { /* retourne 0 si OK, 1 sinon  */
   // printf ("<<<<< À faire: fonction ajouter_tete fichier " __FILE__ " >>>>>\n");
    /* a comple  ter: FAIT */

   if (L == NULL){
      return 1;
   }
   else {
      
      cellule_t * newCel = (cellule_t *) malloc(sizeof(cellule_t)) ;
      newCel->val = c;
      newCel->suivant = L->tete;
      L->tete = newCel;

      return 0;
   }

}

