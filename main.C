#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_keysym.h> // biblioteque qui donne l'adresse des touches de clavier
#include "fonction.h"

int main ()
{
	//declaration
	
	SDL_Surface *screen ;
	image intro;
	enigme  e;
	Mix_Music *music ;
        e.num_enigme=-1;
	int s,r=0;
	int running=0;
	int alea;
	int boucle=1;
	char image[30]="";
	SDL_Event event;

	int t=0;
	time_t start,end;
    	start=clock();
    	char cc[20];
    	text tt;
	//initialisation

	SDL_Init (SDL_INIT_EVERYTHING) ;

	SDL_WM_SetCaption("ENIGME",NULL);
	screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H ,32 ,SDL_HWSURFACE  |  SDL_DOUBLEBUF  );
 	initialiser_audio(music);
	initialiser_intro(&intro);
	TTF_Init();
	init_enigme(&e,"enigme.txt");
	initexte(&tt);
        afficher_image(screen,intro);
	SDL_Flip(screen);
	SDL_Delay(7000);
	
           
while(boucle)
	{
	   
	   
	   afficherEnigme(e,screen);
	  // AfficherText(tt,screen,cc);

            sprintf(cc, ":0%d", t);
            SDL_BlitSurface (e.timer[t],NULL,screen,&e.pos_timer);
	    SDL_Flip(screen);

        	end=clock();
        	t=(end-start)/CLOCKS_PER_SEC; // Cette ligne de code met à jour la valeur de la variable                            t pour qu'elle corresponde au temps écoulé depuis le début de l'énigme.

        	if(t==10)
        	{
         	   running=1; // Cette condition vérifie si 10 secondes se sont écoulées depuis le début de l'énigme,
                        // et met à jour la variable running pour qu'elle indique que le temps est écoulé.
        	}

	     	SDL_PollEvent(&event);
        	switch(event.type)
        	{
            		case SDL_QUIT:
                		boucle = 0;
	        		break ;
        	}



    		SDL_PollEvent(&event);
		//son= Mix_LoadWAV( "click_effect.wav" );
		switch(event.type)
		{
			case SDL_QUIT:
				running= 0 ;
                		boucle = 0;
				break ;

       		case SDL_KEYDOWN :
            			switch( event.key.keysym.sym )
                		{
					case  SDLK_F1:

			   			r= 1;
			   			running= 1 ;
			   			break ;
			   		case  SDLK_F2:
			   			r= 2;
			   			running= 1 ;
			   			break;
			   		case SDLK_F3:

			   			r=3 ;
			   			running= 1 ;
			   			break;

				}
       			break ;
       	}


      		while(running)
      		{
          		afficher_resultat(screen,e.reponsevrai,r,&e);

			SDL_WaitEvent(&event);
        		switch(event.type)
            		{
				case SDL_QUIT :
                    			running =0 ;
					boucle=0 ;
					break ;

            			case SDL_KEYDOWN :
					switch( event.key.keysym.sym )
                			{
	             				case  SDLK_ESCAPE:
		        				running= 0;
		        				boucle=0;
			            			break;
			    		}
            		}

		}
 }

      SDL_FreeSurface(screen);
      SDL_Quit();
      return 0;
}
