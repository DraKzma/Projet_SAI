#include "../include/blocks.h"

//Tableau de blocks de chaque difficulte
//Chaque blocks est aligne avec les axes et contient: xmin/ymin/zmin/xmax/ymax/zmax
double blocks_easy[NB_BLOCKS_MAX][6];
double blocks_medium[NB_BLOCKS_MAX][6];
double blocks_hard[NB_BLOCKS_MAX][6];

//Nombre de blocks
int nb_blocks_easy = 0;
int nb_blocks_medium = 0;
int nb_blocks_hard = 0;

//Vitesse des blocks
double vitesse_blocks_easy = 5.0;
double vitesse_blocks_medium = 10.0;
double vitesse_blocks_hard = 15.0;

//Fonction qui init le tableau des blocks easy
void spawn_blocks_easy(){
    blocks_easy[0][0] = 475; //xmin
    blocks_easy[0][1] = 3175; //ymin
    blocks_easy[0][2] = 475; //zmin
    blocks_easy[0][3] = 525; //xmax
    blocks_easy[0][4] = 3225; //ymax
    blocks_easy[0][5] = 525; //zmax
    nb_blocks_easy += 1;
}

//Fonction qui init le tableau des blocks medium
void spawn_blocks_medium(){

}

//Fonction qui init le tableau des blocks hard
void spawn_blocks_hard(){

}