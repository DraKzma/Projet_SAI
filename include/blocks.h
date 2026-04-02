#ifndef _BLOCKS_H_
#define _BLOCKS_H_

#include "GL/gl.h"
#include "GL/glut.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NB_BLOCKS_EASY_MAX 25
#define NB_BLOCKS_MEDIUM_MAX 40
#define NB_BLOCKS_HARD_MAX 55
#define NB_BLOCKS_EXTREME_MAX 70

//Tableau de blocks de chaque difficulte
//Chaque blocks est aligne avec les axes et contient: xmin/ymin/zmin/xmax/ymax/zmax
extern double blocks_easy[NB_BLOCKS_EASY_MAX][6];
extern double blocks_medium[NB_BLOCKS_MEDIUM_MAX][6];
extern double blocks_hard[NB_BLOCKS_HARD_MAX][6];
extern double blocks_extreme[NB_BLOCKS_EXTREME_MAX][6];

//Nombre de blocks
extern int nb_blocks_easy;
extern int nb_blocks_medium;
extern int nb_blocks_hard;
extern int nb_blocks_extreme;

//Vitesse des blocks
extern double vitesse_blocks_easy;
extern double vitesse_blocks_medium;
extern double vitesse_blocks_hard;
extern double vitesse_blocks_extreme;

void spawn_blocks_easy();

void spawn_blocks_medium();

void spawn_blocks_hard();

void spawn_blocks_extreme();

#endif /* _BLOCKS_H_ */