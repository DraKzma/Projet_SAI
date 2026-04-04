#ifndef _SCORES_H_
#define _SCORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char tab_names[10][20]; //Tableau des noms des joueurs
extern int tab_times[10][3]; //Tableau des scores des joueurs

extern int taille_tab; //Taile des deux tableaux

void viderBuffer();

void read_scores();

void print_scores();

void update_scores(char nom[20], int minutes, int secondes, int dixiemes);

void save_scores();

#endif /* _SCORES_H_ */