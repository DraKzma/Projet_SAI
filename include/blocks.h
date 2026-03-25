#include "GL/gl.h"
#include "GL/glut.h"
#include <stdlib.h>
#include <stdio.h>

#define NB_BLOCKS_MAX 100

//Tableau de blocks de chaque difficulte
//Chaque blocks est aligne avec les axes et contient: xmin/ymin/zmin/xmax/ymax/zmax
double blocks_easy[NB_BLOCKS_MAX][6];
double blocks_medium[NB_BLOCKS_MAX][6];
double blocks_hard[NB_BLOCKS_MAX][6];

int nb_blocks_easy = 0;
int nb_blocks_medium = 0;
int nb_blocks_hard = 0;