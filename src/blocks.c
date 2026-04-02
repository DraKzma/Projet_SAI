#include "../include/blocks.h"

/* TAILLE DE REFERENCE POUR LES LASERS: 20x250x20 */

//Tableau de blocks de chaque difficulte
//Chaque blocks est aligne avec les axes et contient: xmin/ymin/zmin/xmax/ymax/zmax
double blocks_easy[NB_BLOCKS_EASY_MAX][6];
double blocks_medium[NB_BLOCKS_MEDIUM_MAX][6];
double blocks_hard[NB_BLOCKS_HARD_MAX][6];
double blocks_extreme[NB_BLOCKS_EXTREME_MAX][6];

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

//Renvoie 1 si au moins une collision avec un blocks easy, 0 sinon
int verif_collisions_spawn_easy(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_easy){

        if((xmin <= blocks_easy[i][3]) &&
            (xmax >= blocks_easy[i][0]) &&
            (ymin <= blocks_easy[i][4]) &&
            (ymax >= blocks_easy[i][1]) &&
            (zmin <= blocks_easy[i][5]) &&
            (zmax >= blocks_easy[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Fonction qui init le tableau des blocks easy
void spawn_blocks_easy(){
    /*
    blocks_easy[0][0] = 490; //xmin
    blocks_easy[0][1] = 3075; //ymin
    blocks_easy[0][2] = 490; //zmin
    blocks_easy[0][3] = 510; //xmax
    blocks_easy[0][4] = 3325; //ymax
    blocks_easy[0][5] = 510; //zmax
    nb_blocks_easy += 1;
    */

    //Variables
    double coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax;
    int i;

    //Initialisation de la graine pour faire de l'aleatoire
    srand(time(NULL));

    for(i=0; i<NB_BLOCKS_EASY_MAX; i++){
        do{
            //Block de 20x250x20
            coord_xmin = rand()%981; //entre 0 et 981
            coord_ymin = (rand()%5001)+3000; //entre 3000 et 8000
            coord_zmin = rand()%981; //entre 0 et 981
            coord_xmax = coord_xmin+20;
            coord_ymax = coord_ymin+250;
            coord_zmax = coord_zmin+20;
        }
        while(verif_collisions_spawn_easy(coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax));
        blocks_easy[i][0] = coord_xmin;
        blocks_easy[i][1] = coord_ymin;
        blocks_easy[i][2] = coord_zmin;
        blocks_easy[i][3] = coord_xmax;
        blocks_easy[i][4] = coord_ymax;
        blocks_easy[i][5] = coord_zmax;
        nb_blocks_easy++;
    }
}

//Renvoie 1 si au moins une collision avec un blocks medium, 0 sinon
int verif_collisions_spawn_medium(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_medium){

        if((xmin <= blocks_medium[i][3]) &&
            (xmax >= blocks_medium[i][0]) &&
            (ymin <= blocks_medium[i][4]) &&
            (ymax >= blocks_medium[i][1]) &&
            (zmin <= blocks_medium[i][5]) &&
            (zmax >= blocks_medium[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Fonction qui init le tableau des blocks medium
void spawn_blocks_medium(){
    /*
    blocks_medium[0][0] = 490; //xmin
    blocks_medium[0][1] = 3075; //ymin
    blocks_medium[0][2] = 490; //zmin
    blocks_medium[0][3] = 510; //xmax
    blocks_medium[0][4] = 3325; //ymax
    blocks_medium[0][5] = 510; //zmax
    nb_blocks_medium += 1;
    */

    //Variables
    double coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax;
    int i;

    //Initialisation de la graine pour faire de l'aleatoire
    srand(time(NULL));

    for(i=0; i<NB_BLOCKS_MEDIUM_MAX; i++){
        do{
            //Block de 20x250x20
            coord_xmin = rand()%981; //entre 0 et 981
            coord_ymin = (rand()%5001)+3000; //entre 3000 et 8000
            coord_zmin = rand()%981; //entre 0 et 981
            coord_xmax = coord_xmin+20;
            coord_ymax = coord_ymin+250;
            coord_zmax = coord_zmin+20;
        }
        while(verif_collisions_spawn_medium(coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax));
        blocks_medium[i][0] = coord_xmin;
        blocks_medium[i][1] = coord_ymin;
        blocks_medium[i][2] = coord_zmin;
        blocks_medium[i][3] = coord_xmax;
        blocks_medium[i][4] = coord_ymax;
        blocks_medium[i][5] = coord_zmax;
        nb_blocks_medium++;
    }
}

//Renvoie 1 si au moins une collision avec un blocks hard, 0 sinon
int verif_collisions_spawn_hard(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_hard){

        if((xmin <= blocks_hard[i][3]) &&
            (xmax >= blocks_hard[i][0]) &&
            (ymin <= blocks_hard[i][4]) &&
            (ymax >= blocks_hard[i][1]) &&
            (zmin <= blocks_hard[i][5]) &&
            (zmax >= blocks_hard[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Fonction qui init le tableau des blocks hard
void spawn_blocks_hard(){
    /*
    blocks_hard[0][0] = 490; //xmin
    blocks_hard[0][1] = 3075; //ymin
    blocks_hard[0][2] = 490; //zmin
    blocks_hard[0][3] = 510; //xmax
    blocks_hard[0][4] = 3325; //ymax
    blocks_hard[0][5] = 510; //zmax
    nb_blocks_hard += 1;
    */

    //Variables
    double coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax;
    int i;

    //Initialisation de la graine pour faire de l'aleatoire
    srand(time(NULL));

    for(i=0; i<NB_BLOCKS_HARD_MAX; i++){
        do{
            //Block de 20x250x20
            coord_xmin = rand()%981; //entre 0 et 981
            coord_ymin = (rand()%5001)+3000; //entre 3000 et 8000
            coord_zmin = rand()%981; //entre 0 et 981
            coord_xmax = coord_xmin+20;
            coord_ymax = coord_ymin+250;
            coord_zmax = coord_zmin+20;
        }
        while(verif_collisions_spawn_hard(coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax));
        blocks_hard[i][0] = coord_xmin;
        blocks_hard[i][1] = coord_ymin;
        blocks_hard[i][2] = coord_zmin;
        blocks_hard[i][3] = coord_xmax;
        blocks_hard[i][4] = coord_ymax;
        blocks_hard[i][5] = coord_zmax;
        nb_blocks_hard++;
    }
}

//Renvoie 1 si au moins une collision avec un blocks hard, 0 sinon
int verif_collisions_spawn_extreme(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_extreme){

        if((xmin <= blocks_extreme[i][3]) &&
            (xmax >= blocks_extreme[i][0]) &&
            (ymin <= blocks_extreme[i][4]) &&
            (ymax >= blocks_extreme[i][1]) &&
            (zmin <= blocks_extreme[i][5]) &&
            (zmax >= blocks_extreme[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Fonction qui init le tableau des blocks extreme
void spawn_blocks_extreme(){
    /*
    blocks_extreme[0][0] = 490; //xmin
    blocks_extreme[0][1] = 3075; //ymin
    blocks_extreme[0][2] = 490; //zmin
    blocks_extreme[0][3] = 510; //xmax
    blocks_extreme[0][4] = 3325; //ymax
    blocks_extreme[0][5] = 510; //zmax
    nb_blocks_extreme += 1;
    */

    //Variables
    double coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax;
    int i;

    //Initialisation de la graine pour faire de l'aleatoire
    srand(time(NULL));

    for(i=0; i<NB_BLOCKS_EXTREME_MAX; i++){
        do{
            //Block de 20x250x20
            coord_xmin = rand()%981; //entre 0 et 981
            coord_ymin = (rand()%5001)+8000; //entre 3000 et 8000
            coord_zmin = rand()%981; //entre 0 et 981
            coord_xmax = coord_xmin+20;
            coord_ymax = coord_ymin+250;
            coord_zmax = coord_zmin+20;
        }
        while(verif_collisions_spawn_extreme(coord_xmin, coord_ymin, coord_zmin, coord_xmax, coord_ymax, coord_zmax));
        blocks_extreme[i][0] = coord_xmin;
        blocks_extreme[i][1] = coord_ymin;
        blocks_extreme[i][2] = coord_zmin;
        blocks_extreme[i][3] = coord_xmax;
        blocks_extreme[i][4] = coord_ymax;
        blocks_extreme[i][5] = coord_zmax;
        nb_blocks_extreme++;
    }
}