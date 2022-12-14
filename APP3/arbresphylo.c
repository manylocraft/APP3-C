#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"

/* ACTE 1-a */
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


/* ACTE II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y mettre les
 * caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece (arbre racine, char *espece, liste_t* seq)
{

   /* à compléter */

   // printf("\n ESPECE / CARACTERISTIQUE: %s \n", racine->valeur);

   if (racine == NULL){
      return 1;
   }

   else if ( strcmp(racine->valeur, espece) == 0 ){
      return 0;
   }

   else {

      int dans_g = rechercher_espece((racine->gauche), espece, seq);

      if ( dans_g == 0 ){
         return 0;
      }
      else {
         int dans_d = rechercher_espece((racine->droit), espece, seq);
         if ( dans_d == 0 ){
            ajouter_tete(seq, racine->valeur);
            return 0;
         }
         else {
            return 1;
         }
      }
   }

   return 1;
}

// // ALI
// int rechercher_espece (arbre racine, char *espece, liste_t* seq)
// {
//    if (racine == NULL){
//       return 1;
//    }
   
//    else if (strcmp(espece,racine->valeur)==0){
//       return 0;
    
//    } else {

//       int est_dans_g = rechercher_espece(racine->gauche,espece,seq);
      

//       if (est_dans_g == 0){

//          return 0;
//       } else {
//          int est_dans_d = rechercher_espece(racine->droit,espece,seq);
//          if (est_dans_d == 0){
//          ajouter_tete(seq,racine->valeur);

//          return 0;
//       } else {
//          return 1;
//       }

//     }
//     return 1;
// }
// }


/* ACTE III-a */

bool est_feuille(noeud* n){
   return ( (n->droit == NULL) && (n->gauche == NULL) );
}

int ajouter_espece_rec (noeud* a, char *espece, cellule_t* seq){

   // cas ou l'on tombe sur une feuille
   if ( est_feuille(a->droit) &&  est_feuille(a->gauche) ){

      noeud * nv_carac = nouveau_noeud();    // Créer pour ajouter une nouvelle caractéristique
      noeud * nv_espece = nouveau_noeud();   // Créer pour ajouter la nouvelle espèce
      nv_carac->valeur = seq->val;           // nv_carac = la caractéristique en tete de sequence
      nv_espece->valeur = espece;

      // plus de caractéristique à ajouter
      if ( seq->suivant == NULL ) {
         if ( seq->val == a->valeur ) {        // cas ou le caractère existe dans l'arbre
            noeud *espece_a_sauver_d = nouveau_noeud();    // espece deja existante n'ayant pas les nouvelles caracs
            espece_a_sauver_d = a->droit;                  // récupération de l'espece deja existante a droite du noeud courant
            a->droit = nv_carac;                           // on l'écrase par le nouveau caractère
            nv_carac->gauche = espece_a_sauver_d;          // on remet en place "l'espèce sauvée" (youhouu)
            nv_carac->droit = nv_espece;                   // on ajoute la nouvelle espèce à droite de sa nouvelle caractéristique
            return 0;
         }
         else{
            noeud *espece_a_sauver_g = nouveau_noeud();    // espece deja existante n'ayant pas les nouvelles caracs
            espece_a_sauver_g = a->gauche;                  // récupération de l'espece deja existante a droite du noeud courant
            a->gauche = nv_carac;                           // on l'écrase par le nouveau caractère
            nv_carac->gauche = espece_a_sauver_g;          // on remet en place "l'espèce sauvée" (youhouu)
            nv_carac->droit = nv_espece;                   // on ajoute la nouvelle espèce à droite de sa nouvelle caractéristique
            return 0;
         }
      }
      
      // cas ou il reste des caractérisques de la séquence 
      else{
         if ( a->valeur == seq->val ){    // cas ou la caractéristique existe
            noeud *espece_a_sauver_d = nouveau_noeud();     // espece deja existante n'ayant pas les nouvelles caracs
            espece_a_sauver_d = a->droit;                   // car l'espece deja existante possède la caractéristique
            noeud *carac_suiv = nouveau_noeud();            // caractere suivant de la séquence
            carac_suiv->valeur = seq->suivant->val;         // la valeur du caractère = seq->suivant 
            a->droit = carac_suiv;                          // mise en place du "caractère suivant" a droite(oui) de l'arbre
            carac_suiv->gauche = espece_a_sauver_d;         // remise en place de l'espèce existante
            ajouter_espece_rec(a->droit, espece, seq->suivant);
         }
         else {   // cas ou la caractéristique n'existe pas
            noeud *espece_a_sauver_g = nouveau_noeud();        // espece deja existante n'ayant pas les nouvelles caracs
            espece_a_sauver_g = a->gauche;                     // car l'espece deja existante possède la caractéristique
            noeud *carac_suiv = nouveau_noeud();               // caractere suivant de la séquence
            carac_suiv->valeur = seq->val;                     // la valeur du caractère = seq->suivant
            a->gauche = carac_suiv;                            // mise en place du "caractère suivant" a gauche(non) de l'arbre
            carac_suiv->gauche = espece_a_sauver_g;            // remise en place de l'espèce existante
            ajouter_espece_rec(a->gauche, espece, seq->suivant);
         }
      }
   }
   else{
      if(a->valeur==seq->val){
         ajouter_espece_rec(a->droit, espece, seq->suivant);
      }
      else{
         ajouter_espece_rec(a->gauche, espece, seq);
      }
   }
   return 1;
}

/* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un 
 * message d'erreur.
 */
int ajouter_espece (arbre* a, char *espece, cellule_t* seq) {

   if (a == NULL){
      return 1;
   }
   
   else {
      return ajouter_espece_rec(*a, espece, seq);
   }

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
