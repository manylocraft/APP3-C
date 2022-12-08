#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"

void analyse_arbre (arbre racine, int* nb_esp, int* nb_carac)
{

   if(racine==NULL){
      (*nb_esp) = 0;
      (*nb_carac) =0;
   }
   else if ( (racine->gauche==NULL) && (racine->droit==NULL) ){
      (*nb_esp) = 1;
      (*nb_carac) = 0;
   }
   else {
      int nb_esp_d = 0;
      int nb_esp_g = 0;
      int nb_carac_d = 0;
      int nb_carac_g = 0;
      analyse_arbre((racine->gauche), (&nb_esp_g), (&nb_carac_g));
      analyse_arbre((racine->droit), (&nb_esp_d), (&nb_carac_d));
      (*nb_carac) = nb_carac_g + nb_carac_d+1;
      (*nb_esp) = nb_esp_g + nb_esp_d;
   }
}
// }

/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y mettre les
 * caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece (arbre racine, char *espece, liste_t* seq)
{

   /* à compléter */
   if (racine == NULL){
      return 1;
   }

   else if (racine->valeur == espece){
      return 0;
   }

   else {
      if ( rechercher_espece((racine->gauche), espece, seq) == 0 ){
         return 0;
      }
      else if ( rechercher_espece((racine->droit), espece, seq) == 0 ){
         ajouter_tete(seq, racine->valeur);
         return 0;
      }
      else{
         return 1;
      }
   }
   
   return 1;
}



/* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un 
 * message d'erreur.
 */
int ajouter_espece (arbre* a, char *espece, cellule_t* seq) {

    return 1;
}

/* Doit afficher la liste des caractéristiques niveau par niveau, de gauche
 * à droite, dans le fichier fout.
 * Appeler la fonction avec fout=stdin pour afficher sur la sortie standard.
 */
void afficher_par_niveau (arbre racine, FILE* fout) {
   printf ("<<<<< À faire: fonction afficher_par_niveau fichier " __FILE__ "\n >>>>>");
}

// Acte 4


int ajouter_carac(arbre* a, char* carac, cellule_t* seq) {
   printf ("<<<<< À faire: fonction ajouter_carac fichier " __FILE__ "\n >>>>>");
   return 0;
}
