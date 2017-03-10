#include <stdio.h>
#include <stdlib.h>

#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste.h>


int
main(int argc,char *argv[] ) 
{
  err_t noerr = OK; 

  individu_t ** individus = NULL  ; 
  fraction_t ** fractions = NULL  ;
  string_t ** strings = NULL  ; 

  liste_t * liste = NULL ; 
  int i = 0 ; 
  int N;
  int verbose;
  if(argc>3||argc<2){
  	printf("Nombre de argument faut\n");
  	return 0;
  }
  for(i=1;i<argc;i++){
  	if(strcmp(argv[i],"verbose")==0)verbose=1;
  	else N=atoi(argv[i]);
  }
  int stock;




  individus = malloc( sizeof(individu_t *) * N )  ; 
  fractions = malloc( sizeof(fraction_t *) * N )  ;
  strings = malloc( sizeof(string_t *) * N )   ; 

  printf( "Debut du programme des test sur les listes de %d objets homogenes\n" , N ) ; 


  if(verbose==1)
  printf( "\nTest creation d'une liste de %d individus \n" , N ) ;
  char prenom[128] ;
  char nom[128] ; 
  printf("Stocké par 1-référencement 2-copie : ");
  scanf("%i",&stock);
  if(stock==1)
 	 liste = liste_creer(N,individu_effacer,individu_referencer) ;
  else
  	 liste = liste_creer(N,individu_detruire,individu_copier) ;
  for( i=0 ; i<N ; i++ ) 
    {
      sprintf( nom , "nom_%d" , N-i ) ;
      sprintf( prenom , "prenom_%d" , N-i ) ;
      individus[i] = individu_creer( prenom , nom ) ;
      liste_elem_ecrire( liste , individus[i] , i ) ;
    }
  if(verbose==1)
  printf( "Test affichage liste d'individus AVANT tri \n" ) ;
  liste_afficher( liste ,N,1,individu_afficher, ' ' ) ; 
  printf( "\n");
  if(verbose==1)
  printf( "Test Tri de la liste des individus\n" );
    liste_trier(liste , N,1,individu_comparer);
  if(verbose==1)
  printf( "Test affichage liste d'individus APRES tri\n" ) ;
  liste_afficher( liste ,N,1,individu_afficher, ' ' ) ; 
  printf( "\n");
  if(verbose==1)
  printf( "Test destruction liste d'individus\n" ) ;
  if( ( noerr = liste_detruire(&liste , N,1 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  if(verbose==1)
  printf( "\nTest creation d'une liste de %d fractions \n" , N ) ;
  printf("Stocké par 1-référencement 2-copie : ");
  scanf("%i",&stock);
  if(stock==1)
 	 liste = liste_creer(N,fraction_effacer,fraction_referencer) ;
  else
  	 liste = liste_creer(N,fraction_detruire,fraction_copier) ;

  for( i=0 ; i<N ; i++ ) 
    {
      fractions[i] = fraction_creer( N-i , N-i+1 ) ; 
      liste_elem_ecrire( liste , fractions[i] , i ) ;
    }
  if(verbose==1)
  printf( "Test affichage liste de fractions AVANT tri\n" ) ;
  liste_afficher( liste ,N,1,fraction_afficher, ' ' ) ;  
  printf( "\n");
  if(verbose==1)
  printf( "Test Tri de la liste des fractions\n" );
   liste_trier(liste , N,1,fraction_comparer);
  if(verbose==1)
  printf( "Test affichage liste des fractions APRES tri\n" ) ;
  liste_afficher( liste ,N,1,fraction_afficher, ' ' ) ; 
  printf( "\n");
  if(verbose==1)
  printf( "Test destruction liste de fractions\n" ) ;
  if( ( noerr = liste_detruire(&liste , N,1) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  if(verbose==1)
  printf( "\nTest creation d'une liste de %d strings \n" , N ) ;
  char string[128] ;
    printf("Stocké par 1-référencement 2-copie : ");
  scanf("%i",&stock);
  if(stock==1)
 	 liste = liste_creer(N,string_effacer,string_referencer) ;
  else
  	 liste = liste_creer(N,string_detruire,string_copier) ;
  for( i=0 ; i<N ; i++ ) 
    {
      sprintf( string , "string_%d" , N-i ) ; 
      strings[i] = string_creer( string ) ; 
      liste_elem_ecrire( liste , strings[i] , i ) ;
    }
  if(verbose==1)
  printf( "Test affichage liste de strings AVANT tri\n" ) ;
  liste_afficher( liste ,N,1,string_afficher, ' ' ) ; 
  printf( "\n");
  if(verbose==1)
  printf( "Test Tri de la liste des strings\n" );
   liste_trier(liste , N,1,string_comparer);
  if(verbose==1)
  printf( "Test affichage liste des strings APRES tri\n" ) ;
  liste_afficher( liste ,N,1,string_afficher, ' ' ) ; 
  printf( "\n");
  if(verbose==1)
  printf( "Test destruction liste de strings\n" ) ;
  if( ( noerr = liste_detruire(&liste , N,1 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

/* ---------- */

  printf( "\nDestructions des variables de travail\n" ) ;

  printf( "\tindividus..." ) ; fflush(stdout) ; 

  for( i=0 ; i<N ; i++ ) 
    {
      if( ( noerr = individu_detruire( &individus[i] ) ) )
	{ 
	  printf("Sortie avec code erreur = %d\n" , noerr ) ;
	  exit(-1) ; 
	}
    }

  free( individus ) ;
  printf("OK\n"); 


  printf( "\tfractions..." ) ; fflush(stdout) ; 

  for( i=0 ; i<N ; i++ ) 
    {
      if( ( noerr = fraction_detruire( &fractions[i] ) ) )
	{ 
	  printf("Sortie avec code erreur = %d\n" , noerr ) ;
	  exit(-1) ; 
	}
    }

  free( fractions ) ;
  printf("OK\n"); 

  
  printf( "\tstrings..." ) ; fflush(stdout) ; 

  for( i=0 ; i<N ; i++ ) 
    {
      if( ( noerr =string_detruire( &strings[i] ) ) )
	{ 
	  printf("Sortie avec code erreur = %d\n" , noerr ) ;
	  exit(-1) ; 
	}
    }

  free( strings ) ; 
  printf("OK\n"); 

  
  /* ---------- */

  printf( "\nFin du programme des test sur la lste d'objets homogenes\n" ) ; 
  
  printf( "Nombre de liste_t  = %lu\n" , liste_cpt ) ;

  return(0) ; 
}
