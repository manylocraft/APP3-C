#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"

bool est_feuille(noeud* n){
   return ( (n->droit == NULL) && (n->gauche == NULL) );
}

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

   if (racine == NULL){
      return 1;
   }

   else if ( est_feuille(racine) ){
      return strcmp(racine->valeur, espece);
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
      return 1;
   }
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


// int ajouter_espece_rec (noeud* a, char *espece, cellule_t* seq){
//    noeud *esp_a_ajouter = nouveau_noeud();
//    esp_a_ajouter->valeur = espece;
//    noeud *seq_copie = nouvelle_noeud();
//    seq_copie->valeur = seq->val;

//    if(a->gauche==NULL){
//       if(est_feuille(a->droit)){ //si a->droit est une espece
//          //a completer
//       }else{//si a droit est une carac
//          if(strcmp(a->valeur, seq->val)){ 
//             if(seq->suivant!=NULL){
//                ajouter_espece_rec(a->droit, espece, seq->suivant);
//             }else{
//                ajouter_espece_rec(a->droit, espece, seq);
//             }
//          }else{
//             if(seq->suivant==NULL){ //si seq est le dernier elem de la séquence
//                seq_copie->droit = esp_a_ajouter;
//                a->gauche = seq_copie; 
//                return 0;
//             }
//             else
//             {
//                a->gauche == seq_copie;
//                ajouter_espece_rec(a->gauche, espece, seq); 
//             }
//          }
//       }
//    }else if(a->droit==NULL){
//       if(est_feuille(a->gauche)){//si a->gauche est une espece
//          //a completer
//       }else{ //si a->gauche est une carac
//          if(strcmp(seq->val, a->valeur)){
//             if(seq->suivant==NULL){
//                a->droit = esp_a_ajouter;
//                return 0;
//             }else{
//                a->droit = seq_copie;
//                ajouter_espece_rec(a->droit, espece, seq->suivant);
//             }
//          }else{
//             ajouter_espece_rec(a->gauche, espece, seq);
//          }
//       }
//    }

// }

// /* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un 
//  * message d'erreur.
//  */
int ajouter_espece (arbre* a, char *espece, cellule_t* seq) {

//    if (a == NULL){
//       printf("L'arbre est vide");
//       return 1;
//    }else if(seq==NULL){
//       printf("La séquence est vide");
//       return 1;
//    }

//    else {
//       return ajouter_espece_rec(*a, espece, seq);
//    }
   return 0;
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
