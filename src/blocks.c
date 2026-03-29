#include "../include/blocks.h"

/* TAILLE DE REFERENCE POUR LES LASERS: 20x250x20 */

//Tableau de blocks de chaque difficulte
//Chaque blocks est aligne avec les axes et contient: xmin/ymin/zmin/xmax/ymax/zmax
double blocks_easy[NB_BLOCKS_MAX][6];
double blocks_medium[NB_BLOCKS_MAX][6];
double blocks_hard[NB_BLOCKS_MAX][6];
double blocks_extreme[NB_BLOCKS_MAX][6];

//Nombre de blocks
int nb_blocks_easy = 0;
int nb_blocks_medium = 0;
int nb_blocks_hard = 0;
int nb_blocks_extreme = 0;

//Vitesse des blocks
double vitesse_blocks_easy = 6.0;
double vitesse_blocks_medium = 12.0;
double vitesse_blocks_hard = 18.0;
double vitesse_blocks_extreme = 24.0;

//Fonction qui init le tableau des blocks easy
void spawn_blocks_easy(){
    blocks_easy[0][0] = 490; //xmin
    blocks_easy[0][1] = 3075; //ymin
    blocks_easy[0][2] = 490; //zmin
    blocks_easy[0][3] = 510; //xmax
    blocks_easy[0][4] = 3325; //ymax
    blocks_easy[0][5] = 510; //zmax
    nb_blocks_easy += 1;
}

//Fonction qui init le tableau des blocks medium
void spawn_blocks_medium(){
    blocks_medium[0][0] = 490; //xmin
    blocks_medium[0][1] = 3075; //ymin
    blocks_medium[0][2] = 490; //zmin
    blocks_medium[0][3] = 510; //xmax
    blocks_medium[0][4] = 3325; //ymax
    blocks_medium[0][5] = 510; //zmax
    nb_blocks_medium += 1;
}

//Fonction qui init le tableau des blocks hard
void spawn_blocks_hard(){
    blocks_hard[0][0] = 490; //xmin
    blocks_hard[0][1] = 3075; //ymin
    blocks_hard[0][2] = 490; //zmin
    blocks_hard[0][3] = 510; //xmax
    blocks_hard[0][4] = 3325; //ymax
    blocks_hard[0][5] = 510; //zmax
    nb_blocks_hard += 1;
}

//Fonction qui init le tableau des blocks extreme
void spawn_blocks_extreme(){
    blocks_extreme[0][0] = 490; //xmin
    blocks_extreme[0][1] = 3075; //ymin
    blocks_extreme[0][2] = 490; //zmin
    blocks_extreme[0][3] = 510; //xmax
    blocks_extreme[0][4] = 3325; //ymax
    blocks_extreme[0][5] = 510; //zmax
    nb_blocks_extreme += 1;
}