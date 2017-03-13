#ifndef _LISTE_H_
#define _LISTE_H_

#include <commun.h>

#define LISTE_NULL NULL
#define LISTE_ID_NULL -1

typedef enum type_tri_s{QUICK,PERSO} type_tri_t;



typedef struct liste_s
{
    void(*det)(void *);
    void(*ajout)(void *,void *);
  int nb ;		/* Nombre d'objets dans la liste  */
  void ** liste ;	/* liste  des objets */
} liste_t ;

extern unsigned long int liste_cpt  ;

/*
 * FONCTIONS
 */

/*!
 * \name Methodes d'acces 
 * @{
 */

/*! Acces au nombre d'objets */
extern int liste_nb_lire( liste_t * const liste );

/*! Acces a un objets de la liste */
extern void * liste_elem_lire( liste_t * const liste , const int ind );

/*!
 * @}
 * \name Tests 
 * @{
 */

/*! Teste si la liste existe */
extern booleen_t liste_existe( liste_t * const liste) ; 

/*! Teste si la liste est vide (aucun &eacute;l&eacute;ment dedans) */
extern booleen_t liste_vide( liste_t * const liste) ; 

/*!
 * @}
 * \name Methodes d'affectations 
 * @{
 */

/*! Affectation d'un objet */
extern err_t liste_elem_ecrire( liste_t * liste, 
				void * const elem ,
				const int ind ) ;

/*!
 * @}
 * \name Primitives
 * @{
 */

/*!
 * Creation d'une liste 
 */
extern liste_t * liste_creer( const int nb ,void(*det)(void *),void(*affect)(void *,void *));

/*!
 * Destruction d'une liste 
 */

err_t liste_detruire( liste_t ** liste , int nb,int taille ) ; 


/*! 
 * \name Affichage
 * @{
 */

/*!
 * Affichage d'une liste sur la sortie standard
 */

extern void liste_afficher( liste_t * const liste ,int nb,int taille,void(*aff)(void *),char sep);

/*!
 * @}
 */


/*!
 * tri d'une liste 
 */

extern err_t liste_trier_bulle( liste_t * liste , int nb,int taille,int(*compare)(void*,void*) );
extern err_t liste_trier_qsort( liste_t * liste , int nb,int taille,int(*compare)(void*,void*) );
extern err_t liste_trier( liste_t * liste , int nb,int taille,int(*comparep)(void*,void*),int(*compareq)(void*,void*),type_tri_t type);

/*! @} */
#endif
