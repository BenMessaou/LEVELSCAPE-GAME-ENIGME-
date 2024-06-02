#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_keysym.h> // biblioteque qui donne l'adresse des touches de clavier
#include "fonction.h"

void initialiser_intro(image *imge)
{
//chargemenet de l'image
(*imge).url="Intro.png";
(*imge).img=IMG_Load((*imge).url);
if ((*imge).img==NULL)
{ printf("unable to load background image %s\n",SDL_GetError());

   return ;}


(*imge).pos_img_ecran.x=0;
(*imge).pos_img_ecran.y=0;
(*imge).pos_img_affiche.x=0;
(*imge).pos_img_affiche.y=0;
(*imge).pos_img_affiche.h=SCREEN_H;
(*imge).pos_img_affiche.w=SCREEN_W;
}


int aleatoire_entre_1_et_3()
{
    int a;
    srand(time(NULL)); // initialisation du générateur de nombres aléatoires avec l'horloge du système
    a=(rand() % 3) + 1;
    return a; // retourne un nombre aléatoire entre 1 et 3
}



void init_enigme(enigme *e, char *nomfichier)
{
	int j,y;
	int i=1;
	char nomimage[20];


	e->p.x=0;
	e->p.y=0;
	e->img=NULL;

	e->num_enigme=aleatoire_entre_1_et_3();

	FILE *f=fopen("enigme.txt","r"); // ouvre le fichier enigme.txt
	if(f!=NULL)
	{

		while(fscanf(f,"%s %d\n",nomimage,&e->reponsevrai)!=EOF && i!=e->num_enigme) //stock le nom de limage qui contient lenigme dans une variable nomimage et la reponse vrai dans la variable reponsevrai
		{
			i++;                                                 // Remarque: yekef ki yekhou l'enigme li khtarna el nombre mteha aleatoirement
		}
		e->img=IMG_Load(nomimage);
		fclose(f);
	}
	else printf("ERROR !\n");


}




void afficherEnigme(enigme e, SDL_Surface * screen)
{
	SDL_BlitSurface(e.img,NULL,screen,&e.p);
}

void afficher_image(SDL_Surface *screen,image imge)
{
//coller et afficher l'image du background dans screen
	SDL_BlitSurface(imge.img, &imge.pos_img_affiche,screen, &imge.pos_img_ecran);
}


void initialiser_audio(Mix_Music *music)
{
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
	printf("%s",SDL_GetError());
}

music=Mix_LoadMUS("harry.mp3"); //chargement de la musique
Mix_PlayMusic(music,-1);//jouer la musique
Mix_VolumeMusic (MIX_MAX_VOLUME/3.5);
}

void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {

 	if (r==s)
 	{
 		en->img=IMG_Load("win.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
        SDL_FreeSurface(en->img);
 	}
 	else
 	{
 		en->img=IMG_Load("lose.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
        SDL_FreeSurface(en->img);
 	}
 }

void initexte(text *A)
{
    A->position.x=0;
    A->position.y=0;
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont( "police.ttf", 20 );
}


//void AfficherText(text t,SDL_Surface *screen,char cc[30])
//{
 //   t.surfaceTexte = TTF_RenderText_Solid(t.font, cc, t.textColor );
   // SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
//}


void liberer_texte(text txte)
{

  TTF_CloseFont(txte.font);// fermer la police
  TTF_Quit(); // arreter la SDL_ttf

}
















