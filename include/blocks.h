#ifndef _BLOCKS_H_
#define _BLOCKS_H_

#include "GL/gl.h"
#include "GL/glut.h"
#include <stdlib.h>
#include <stdio.h>

#define NB_BLOCKS_MAX 100

//Tableau de blocks de chaque difficulte
//Chaque blocks est aligne avec les axes et contient: xmin/ymin/zmin/xmax/ymax/zmax
extern double blocks_easy[NB_BLOCKS_MAX][6];
extern double blocks_medium[NB_BLOCKS_MAX][6];
extern double blocks_hard[NB_BLOCKS_MAX][6];

//Nombre de blocks
extern int nb_blocks_easy;
extern int nb_blocks_medium;
extern int nb_blocks_hard;

//Vitesse des blocks
extern double vitesse_blocks_easy;
extern double vitesse_blocks_medium;
extern double vitesse_blocks_hard;

void spawn_blocks_easy();

void spawn_blocks_medium();

void spawn_blocks_hard();

#endif /* _BLOCKS_H_ */