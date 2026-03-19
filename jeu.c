#include "GL/gl.h"
#include "GL/glut.h"
#include "stdlib.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MIN_ORTHO_X -20
#define MAX_ORTHO_X 20
#define MIN_ORTHO_Y -20
#define MAX_ORTHO_Y 20
#define TAILLE_FENETRE_X 1000
#define TAILLE_FENETRE_Y 1000

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

//Declaration du joueur
joueur j;

//Variables pour le Frustum
int left = -5;
int right = 5;
int bottom = -5;
int top = 5;
int near = 5;
int front = 3005; //Distance de vision, les blocs spawn vers 5000 (invisible au debut jusqu'a ce qu'ils atteignent le champ de vision)

void init_joueur(){
    j.eyeX = 250.0;
    j.eyeY = 250.0;
    j.eyeZ = 250.0;
    j.xO = 250.0;
    j.yO = 1000.0;
    j.zO = 250.0;
    j.rightX = 5.0; //SET LA VITESSE DE DEPLACEMENT SUR LES X
    j.rightY = 0.0;
    j.rightZ = 0.0;
    j.frontX = 0.0;
    j.frontY = 5.0; //SET LA VITESSE DE DEPLACEMENT SUR LES Y
    j.frontZ = 0.0;
    j.upX = 0.0;
    j.upY = 0.0;
    j.upZ = 5.0; //SET LA VITESSE DE DEPLACEMENT SUR LES Z
}

//Fonction afficher cube avec faces
void afficherCubeFaces(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){

    double p1x = xmin;
    double p1y = ymin;
    double p1z = zmin;

    double p2x = xmax;
    double p2y = ymin;
    double p2z = zmin;

    double p3x = xmax;
    double p3y = ymax;
    double p3z = zmin;

    double p4x = xmin;
    double p4y = ymax;
    double p4z = zmin;

    double p5x = xmin;
    double p5y = ymin;
    double p5z = zmax;

    double p6x = xmax;
    double p6y = ymin;
    double p6z = zmax;

    double p7x = xmax;
    double p7y = ymax;
    double p7z = zmax;

    double p8x = xmin;
    double p8y = ymax;
    double p8z = zmax;

    glVertex3f(p1x, p1y, p1z);
    glVertex3f(p2x, p2y, p2z);
    glVertex3f(p3x, p3y, p3z);
    glVertex3f(p4x, p4y, p4z);

    glVertex3f(p1x, p1y, p1z);
    glVertex3f(p5x, p5y, p5z);
    glVertex3f(p8x, p8y, p8z);
    glVertex3f(p4x, p4y, p4z);

    glVertex3f(p5x, p5y, p5z);
    glVertex3f(p6x, p6y, p6z);
    glVertex3f(p7x, p7y, p7z);
    glVertex3f(p8x, p8y, p8z);

    glVertex3f(p7x, p7y, p7z);
    glVertex3f(p6x, p6y, p6z);
    glVertex3f(p2x, p2y, p2z);
    glVertex3f(p3x, p3y, p3z);

    glVertex3f(p1x, p1y, p1z);
    glVertex3f(p2x, p2y, p2z);
    glVertex3f(p6x, p6y, p6z);
    glVertex3f(p5x, p5y, p5z);

    glVertex3f(p3x, p3y, p3z);
    glVertex3f(p4x, p4y, p4z);
    glVertex3f(p8x, p8y, p8z);
    glVertex3f(p7x, p7y, p7z);
}

void afficheLigne(double x1, double y1, double z1, double x2, double y2, double z2){
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
}

//Fonction afficher cube avec lignes
void  afficherCubeLignes(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){
    double p1x = xmin;
    double p1y = ymin;
    double p1z = zmin;

    double p2x = xmax;
    double p2y = ymin;
    double p2z = zmin;

    double p3x = xmax;
    double p3y = ymax;
    double p3z = zmin;

    double p4x = xmin;
    double p4y = ymax;
    double p4z = zmin;

    double p5x = xmin;
    double p5y = ymin;
    double p5z = zmax;

    double p6x = xmax;
    double p6y = ymin;
    double p6z = zmax;

    double p7x = xmax;
    double p7y = ymax;
    double p7z = zmax;

    double p8x = xmin;
    double p8y = ymax;
    double p8z = zmax;

    //Affichage des 12 cotes
    afficheLigne(p1x, p1y, p1z, p2x, p2y, p2z);
    afficheLigne(p2x, p2y, p2z, p3x, p3y, p3z);
    afficheLigne(p3x, p3y, p3z, p4x, p4y, p4z);
    afficheLigne(p4x, p4y, p4z, p1x, p1y, p1z);

    afficheLigne(p1x, p1y, p1z, p5x, p5y, p5z);
    afficheLigne(p2x, p2y, p2z, p6x, p6y, p6z);
    afficheLigne(p3x, p3y, p3z, p7x, p7y, p7z);
    afficheLigne(p4x, p4y, p4z, p8x, p8y, p8z);

    afficheLigne(p5x, p5y, p5z, p6x, p6y, p6z);
    afficheLigne(p6x, p6y, p6z, p7x, p7y, p7z);
    afficheLigne(p7x, p7y, p7z, p8x, p8y, p8z);
    afficheLigne(p8x, p8y, p8z, p5x, p5y, p5z);
}

//Fonction d'affichage
void Affichage(){
    //Debut
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Modif de la visualisation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //left,right,bottom,top: taille de la face avant
    //near: distance de la face avant (near)
    //front: distance de vision (far)
    glFrustum(left,right,bottom,top,near,front);

    //Init de la matrice de visualisation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //eye: position de l'oeil
    //pointO: point ou l'on regarde
    //up: Vecteur qui represente le haut pour nous 
    gluLookAt(j.eyeX,j.eyeY,j.eyeZ,j.xO,j.yO,j.zO,j.upX,j.upY,j.upZ);

    //GL_QUADS affiche faces par faces les cubes
    glBegin(GL_QUADS);

    //Zone d'affichage

    //Gros cube ou le joueur se situe, 500x500x500 sur l'origine avec 0.2 d'opacite
    //glColor4f(0, 0, 1.0, 0.2);
    //afficherCubeFaces(0.0,0.0,0.0,500.0,500.0,500.0);

    glEnd();

    //Disable du depth test et epaisseur de la ligne a 5 pixels
    glDisable(GL_DEPTH_TEST);
    glLineWidth(5.0);

    glBegin(GL_LINES);

    //Cube de 500x500x500 sur l'origine, le joueur ne peut pas sortir de ce cube
    glColor3f(1,1,1);
    afficherCubeLignes(0.0,0.0,0.0,500.0,500.0,500.0);

    // Right (rouge)
    glColor3f(1,0,0);
    afficheLigne(j.eyeX, j.eyeY+10.0, j.eyeZ+5.0, j.eyeX+(100.0*j.rightX), j.eyeY, j.eyeZ);

    // Front (vert)
    glColor3f(0,1,0);
    afficheLigne(j.eyeX, j.eyeY+10.0, j.eyeZ+5.0, j.eyeX, j.eyeY+(100.0*j.frontY), j.eyeZ);

    // Up (bleu)
    glColor3f(0,0,1);
    afficheLigne(j.eyeX, j.eyeY+10.0, j.eyeZ+5.0, j.eyeX, j.eyeY, j.eyeZ+(100.0*j.upZ));

    glEnd();
    glEnable(GL_DEPTH_TEST);

    //Fin
    glutSwapBuffers();
}

//Fonction qui gere le clavier
void GererClavier(unsigned char touche, int x, int y){
    //On bouge en avant
    if(touche == 'z'){
        j.eyeX += j.frontX;
        j.eyeY += j.frontY;
        j.eyeZ += j.frontZ;
        j.xO += j.frontX;
        j.yO += j.frontY;
        j.zO += j.frontZ;
    }
    //On bouge en arriere
    if(touche == 's'){
        j.eyeX -= j.frontX;
        j.eyeY -= j.frontY;
        j.eyeZ -= j.frontZ;
        j.xO -= j.frontX;
        j.yO -= j.frontY;
        j.zO -= j.frontZ;
    }
    //On bouge a droite
    if(touche == 'd'){
        j.eyeX += j.rightX;
        j.eyeY += j.rightY;
        j.eyeZ += j.rightZ;
        j.xO += j.rightX;
        j.yO += j.rightY;
        j.zO += j.rightZ;
    }
    //On bouge a gauche
    if(touche == 'q'){
        j.eyeX -= j.rightX;
        j.eyeY -= j.rightY;
        j.eyeZ -= j.rightZ;
        j.xO -= j.rightX;
        j.yO -= j.rightY;
        j.zO -= j.rightZ;
    }
    //On bouge en haut
    if(touche == ' '){
        j.eyeX += j.upX;
        j.eyeY += j.upY;
        j.eyeZ += j.upZ;
        j.xO += j.upX;
        j.yO += j.upY;
        j.zO += j.upZ;
    }
    //On bouge a gauche
    if(touche == 'c'){
        j.eyeX -= j.upX;
        j.eyeY -= j.upY;
        j.eyeZ -= j.upZ;
        j.xO -= j.upX;
        j.yO -= j.upY;
        j.zO -= j.upZ;
    }
}

//Fonction qui convertit les coodronnees de l'ecran en coordonnees qu'on a besoin
void conversionCoordonnees(int *x, int *y){
    //Conversion des coordonnees
    *x = (*x * (MAX_ORTHO_X - MIN_ORTHO_Y))/(TAILLE_FENETRE_X+1) + MIN_ORTHO_X;
    *y = -((*y * (MAX_ORTHO_Y - MIN_ORTHO_Y))/(TAILLE_FENETRE_Y+1) + MIN_ORTHO_Y);
}

//Fonction qui gere la souris
void GererSouris(int bouton, int etat, int x, int y){
    //Conversion des coordonnees
    conversionCoordonnees(&x, &y);
}

//Fonction d'animation
void Animer(){

    //Reaffichage
    glutPostRedisplay();
}

int main(int argc, char* argv[]){

    //Variables

    //Initialisation du joueur
    init_joueur();

    //Debut
    glutInit(&argc, argv);                
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    //Position de la fenetre
    glutInitWindowSize(TAILLE_FENETRE_X, TAILLE_FENETRE_Y);
    glutInitWindowPosition(50, 50);

    //Creation de la fenetre
    glutCreateWindow("Game");
    glEnable(GL_DEPTH_TEST);

    //Si on veut mettre en plein ecran par la suite
    //glutFullScreen();

    //Activation du blend pour l'opacite
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Gestion du clavier
    glutKeyboardFunc(GererClavier);

    //Gestion de la souris
    glutMouseFunc(GererSouris);

    //Gestion du curseur de la souris
    glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);

    //Gestion de l'affichage
    glutDisplayFunc(Affichage);

    //Gestion de l'animation
    glutIdleFunc(Animer);

    //Boucle
    glutMainLoop();
    
    //Fin
    exit(EXIT_SUCCESS);
}