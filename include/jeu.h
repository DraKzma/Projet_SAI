#ifndef _JEU_H_
#define _JEU_H_

#include "GL/gl.h"
#include "GL/glut.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

//coordonnee x: droite/gauche (augmente a droite/diminue a gauche)
//coordonnee y: avant/arriere (augmente en avant/diminue en arriere)
//coordonnee z: haut/bas (augmente en haut/diminue en bas)
struct joueur{
    double eyeX;
    double eyeY;
    double eyeZ;
    double xO;
    double yO;
    double zO;
    double rightX;
    double rightY;
    double rightZ;
    double frontX;
    double frontY;
    double frontZ;
    double upX;
    double upY;
    double upZ;
};
typedef struct joueur joueur;

struct cube{
    double xmin;
    double ymin;
    double zmin;
    double xmax;
    double ymax;
    double zmax;
};
typedef struct cube cube;

//Declaration du joueur
joueur j;

//Cube dans lequel le joueur se trouve
cube main_cube;

//Tableau des touches (pour gerer le multi-input)
int touches[256];

//Taille de la fenetre
int screen_width;
int screen_height;

//Gestion de la camera
int put_mouse_in_the_middle = 1;

//Variables pour le Frustum
int left = -16;
int right = 16;
int bottom = -9;
int top = 9;
int near = 16;
int front = 3016; //Distance de vision

//Vitesse de deplacement
double vitesse = 4.0;

//Hitbox du joueur 40x40x40
double hitboxXmin = 480;
double hitboxYmin = 480;
double hitboxZmin = 480;
double hitboxXmax = 520;
double hitboxYmax = 520;
double hitboxZmax = 520;

//Booleen qui indique le niveau actuel
int onEasyMode = 1;
int onMediumMode = 0;
int onHardMode = 0;
int onExtremeMode = 0;

//Dimensions du rectangle d'affichage en haut a gauche
double panelXmin;
double panelYmin;
double panelXmax;
double panelYmax;

#endif /* _JEU_H_ */