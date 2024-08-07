#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include "enigmestat.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<time.h>

void init_enigme(enigme *enig)
{
     
    SDL_Color couleur={0,0,0};
    SDL_Color couleur2={255,255,255};
    enig->police=NULL;	
    enig->image=NULL;
    enig->dev=NULL;
    enig->texte1=NULL;
    enig->texte2=NULL;
    enig->texte3=NULL;
    enig->police=NULL;
    enig->posim.x=538;
    enig->posim.y=79;
    enig->posdev.x=259;
    enig->posdev.y=180;
    
    enig->post1.x=1060;
    enig->post1.y=660;
    
    enig->post2.x=270;
    enig->post2.y=660;
    
    enig->post3.x=630;
    enig->post3.y=520;
    
    enig->posrep.x=440;
    enig->posrep.y=120;



    enig->image=IMG_Load("enigme.png");
    enig->dev=IMG_Load("devinette.png");

    enig->police=TTF_OpenFont("texxte.ttf",63);
    enig->texte1=TTF_RenderText_Blended(enig->police,"B)",couleur2);
    enig->texte2=TTF_RenderText_Blended(enig->police,"A)",couleur2);
    //enig->texte3=TTF_RenderText_Blended(enig->police,"c) 252",couleur);

    enig->repvrai=TTF_RenderText_Blended(enig->police,"Correct Answer ",couleur2);
    enig->repfausse=TTF_RenderText_Blended(enig->police,"Wrong Answer",couleur2);
    
}
void afficher_enigme(SDL_Surface *ecran,enigme enig)
{
          
          
          
          // blit img enigme
	   SDL_BlitSurface(enig.image,NULL,ecran,&(enig.posim)); 
          // blit img devinette
           SDL_BlitSurface(enig.dev,NULL,ecran,&(enig.posdev));
          // blit des reponses
	        SDL_BlitSurface(enig.texte1,NULL,ecran,&(enig.post1));
           SDL_BlitSurface(enig.texte2,NULL,ecran,&(enig.post2));
           SDL_BlitSurface(enig.texte3,NULL,ecran,&(enig.post3));
           
	   
}
void rep_vrai(SDL_Surface *ecran, enigme enig)
{
  // Blit : bonne reponse
  SDL_BlitSurface(enig.repvrai,NULL,ecran,&(enig.posrep)); 
 
}

void rep_fausse(SDL_Surface *ecran, enigme enig)
{
   // Blit : fausse reponse
  SDL_BlitSurface(enig.repfausse,NULL,ecran,&(enig.posrep)); 
  
}
void free_enigmestat(enigme *enig)
{
    SDL_FreeSurface(enig->image);
    SDL_FreeSurface(enig->dev);
    SDL_FreeSurface(enig->texte1);
    SDL_FreeSurface(enig->texte2);
     SDL_FreeSurface(enig->texte3);
     SDL_FreeSurface(enig->repvrai);
    SDL_FreeSurface(enig->repfausse);
    TTF_CloseFont(enig->police);
}


