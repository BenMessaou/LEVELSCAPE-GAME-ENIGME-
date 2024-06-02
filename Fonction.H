#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_keysym.h> // biblioteque qui donne l'adresse des touches de clavier
#define SCREEN_H 640
#define SCREEN_W 1000
typedef struct
{
	char *url;
	SDL_Rect pos_img_affiche; //partie de l'image qui doiet etre afficher
	SDL_Rect pos_img_ecran; //position del 'image par rapport a l'ecran
	SDL_Surface *img;
}image;

typedef struct
{
    SDL_Surface *img,*timer[10];
    SDL_Rect p,pos_timer;
    int reponsevrai; // numero de reponse
    int reponsejoueur;
    int num_enigme;

}enigme;



typedef struct
{
SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
}text;



void init_enigme(enigme * e, char *nomfichier); // Declaration et initiliasation enigme //
void generate_afficher (int *alea) ; // Generer aleatoirement le numero
void afficherEnigme(enigme e, SDL_Surface * screen);
void initialiser_intro(image *imge);
void initialiser_audio(Mix_Music *music);
int resolution (int * running,int *run); // Comparer les reponses
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en);
void initexte(text *t);
//void AfficherText(text t,SDL_Surface *screen,char cc[30]);// Cette fonction affiche la chaîne de caractères cc sur l'écran en utilisant les paramètres spécifiés dans la structure tt.
void afficher_image(SDL_Surface *screen,image imge);


#endif
