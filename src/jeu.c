#include "../include/jeu.h"
#include "../include/blocks.h"
#include "../include/scores.h"

//Initialise le joueur
void init_joueur(){
    j.eyeX = 500.0;
    j.eyeY = 500.0;
    j.eyeZ = 500.0;
    j.xO = 500.0;
    j.yO = 2000.0;
    j.zO = 500.0;
    j.rightX = 1.0;
    j.rightY = 0.0;
    j.rightZ = 0.0;
    j.frontX = 0.0;
    j.frontY = 1.0;
    j.frontZ = 0.0;
    j.upX = 0.0;
    j.upY = 0.0;
    j.upZ = 1.0;
}

//Initialise le cube principale
void init_main_cube(){
    main_cube.xmin = 0.0;
    main_cube.ymin = 0.0;
    main_cube.zmin = 0.0;
    main_cube.xmax = 1000.0;
    main_cube.ymax = 1000.0;
    main_cube.zmax = 1000.0;
}

//Initialise Le tableau de touches du clavier
void init_touches(){
    int i;
    for(i = 0; i<256; i++){
        touches[i] = 0;
    }
}

//Initialise l'ecran et son ratio pour le frustum
void init_taille_ecran(){

    double ratio;
    int ratioOne;
    int ratioTwo;

    screen_width = glutGet(GLUT_SCREEN_WIDTH);
    screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    ratio = (double)screen_width/(double)screen_height;
    //Ratio de 16:9 par defaut
    ratioOne = 16;
    ratioTwo = 9;

    //Si le ratio est 16:10 on change les coordonnes du frustum
    if(ratio == 16.0/10.0){
        left = -16;
        right = 16;
        bottom = -10;
        top = 10;
        near = 16;
        front = 3016;

        ratioOne = 16;
        ratioTwo = 10;
    }
    printf("Taille de l'ecran: %d x %d (Ratio: %d:%d)\n", screen_width, screen_height, ratioOne, ratioTwo);

    //Initialisation de la taille du panel (flemme de le faire dans une autre fonction)
    panelXmin = 0;
    panelYmin = screen_height/2;
    panelXmax = screen_width/4;
    panelYmax = screen_height;
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

//Fonction qui affiche un cube en 2D
void afficherCubeFaces2D(double xmin, double ymin, double xmax, double ymax){
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
}

//Fonction qui affiche un cube en 2D (seulement le contour)
void afficherCubeLignes2D(double xmin, double ymin, double xmax, double ymax){
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);

    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);

    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);

    glVertex2f(xmin, ymax);
    glVertex2f(xmin, ymin);
}

/*  valeurs de exit_code
*   0: appuie sur le bouton de fin de partie detectee
*   1: collision avec un block easy
*   2: collision avec un block medium
*   3: collision avec un block hard
*   4: collision avec un block extreme
*   5: le joueur gagne
*/
int finPartie(int exit_code){

    sleep(1);
    glutLeaveMainLoop();

}

/*  Fonction qui gere le changement de difficulte
*   On change de difficulte si tous les blocks sont à -500
*/
void gestion_changement_dfficulte(){
    int i;
    int blocks_encore_a_portee = 0;
    if(onEasyMode){
        for(i = 0; i<nb_blocks_easy; i++){
            //On teste le ymax
            if(blocks_easy[i][4] > -500){
                blocks_encore_a_portee = 1;
            }
        }
        if(!blocks_encore_a_portee){
            onEasyMode = 0;
            onMediumMode = 1;
        }
    }
    else if(onMediumMode){
        for(i=0; i<nb_blocks_medium; i++){
            //on teste le ymax
            if(blocks_medium[i][4] > -500){
                blocks_encore_a_portee = 1;
            }
        }
        if(!blocks_encore_a_portee){
            onMediumMode = 0;
            onHardMode = 1;
        }
    }
    else if(onHardMode){
        for(i=0; i<nb_blocks_hard; i++){
            //on teste le ymax
            if(blocks_hard[i][4] > -500){
                blocks_encore_a_portee = 1;
            }
        }
        if(!blocks_encore_a_portee){
            onHardMode = 0;
            onExtremeMode = 1;
        }
    }
    else{
        for(i=0; i<nb_blocks_extreme; i++){
            //On teste le ymax
            if(blocks_extreme[i][4] > -500){
                blocks_encore_a_portee = 1;
            }
        }
        if(!blocks_encore_a_portee){
            finPartie(5);
        }
    }
}

//Renvoie 1 si au moins une collision avec un blocks easy, 0 sinon
int verif_collisions_blocks_easy(){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_easy){

        if((hitboxXmin <= blocks_easy[i][3]) &&
            (hitboxXmax >= blocks_easy[i][0]) &&
            (hitboxYmin <= blocks_easy[i][4]) &&
            (hitboxYmax >= blocks_easy[i][1]) &&
            (hitboxZmin <= blocks_easy[i][5]) &&
            (hitboxZmax >= blocks_easy[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Renvoie 1 si au moins une collision avec un blocks medium, 0 sinon
int verif_collisions_blocks_medium(){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_medium){

        if((hitboxXmin <= blocks_medium[i][3]) &&
            (hitboxXmax >= blocks_medium[i][0]) &&
            (hitboxYmin <= blocks_medium[i][4]) &&
            (hitboxYmax >= blocks_medium[i][1]) &&
            (hitboxZmin <= blocks_medium[i][5]) &&
            (hitboxZmax >= blocks_medium[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Renvoie 1 si au moins une collision avec un blocks hard, 0 sinon
int verif_collisions_blocks_hard(){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_hard){

        if((hitboxXmin <= blocks_hard[i][3]) &&
            (hitboxXmax >= blocks_hard[i][0]) &&
            (hitboxYmin <= blocks_hard[i][4]) &&
            (hitboxYmax >= blocks_hard[i][1]) &&
            (hitboxZmin <= blocks_hard[i][5]) &&
            (hitboxZmax >= blocks_hard[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

//Renvoie 1 si au moins une collision avec un blocks extreme, 0 sinon
int verif_collisions_blocks_extreme(){
    int collision = 0;
    int i = 0;
    while(!collision && i<nb_blocks_extreme){

        if((hitboxXmin <= blocks_extreme[i][3]) &&
            (hitboxXmax >= blocks_extreme[i][0]) &&
            (hitboxYmin <= blocks_extreme[i][4]) &&
            (hitboxYmax >= blocks_extreme[i][1]) &&
            (hitboxZmin <= blocks_extreme[i][5]) &&
            (hitboxZmax >= blocks_extreme[i][2])){
                collision = 1;
            }
        i++;

    }
    return collision;
}

// renv 1 si le joueur sort du cube principal et 0 sinon
int verif_sortie_main_cube(){
    // On vérifie si n'importe quel bord de la hitbox dépasse les bords du main_cube
    if(hitboxXmin < main_cube.xmin || hitboxXmax > main_cube.xmax ||
       hitboxYmin < main_cube.ymin || hitboxYmax > main_cube.ymax ||
       hitboxZmin < main_cube.zmin || hitboxZmax > main_cube.zmax){
        return 1; // Le joueur est sorti
    }
    return 0; // Le joueur est toujours à l'intérieur
}

void printText2DBitmap(int x, int y, char *string, void *font){
    //Variables
	int len, i;

	glRasterPos2f(x,y); // Positionne le premier caractère de la chaîne
	len = (int) strlen(string);
	for(i = 0; i < len; i++){
        glutBitmapCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
    }
}

void printText2DStroke(float x, float y, char *string, void *font){
	char *p;
	glPushMatrix();
	glTranslatef(x, y, 0); // Positionne le premier caractère de la chaîne
	for (p = string; *p; p++){
        glutStrokeCharacter(font, *p); // Affiche chaque caractère de la chaîne
    }
	glPopMatrix();
}

//Fonction d'affichage
void Affichage(){

    //Variables
    int i;
    char posX[20];
    char posY[20];
    char posZ[20];

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
    gluLookAt(j.eyeX+(250*(-j.frontX))+(75*(j.upX)),j.eyeY+(250*(-j.frontY))+(75*(j.upY)),j.eyeZ+(250*(-j.frontZ))+(75*(j.upZ)),j.xO+(250*(-j.frontX))+(75*(j.upX)),j.yO+(250*(-j.frontY))+(75*(j.upY)),j.zO+(250*(-j.frontZ))+(75*(j.upZ)),j.upX,j.upY,j.upZ);

    //GL_QUADS affiche faces par faces les cubes
    glBegin(GL_QUADS);

    //Zone d'affichage

    //Gros cube ou le joueur se situe, 1000x1000x1000 sur l'origine avec 0.2 d'opacite
    //glColor4f(0, 0, 1.0, 0.2);
    //afficherCubeFaces(main_cube.xmin, main_cube.ymin, main_cube.zmin, main_cube.xmax, main_cube.ymax, main_cube.zmax);

    //Cube du joueur
    glColor3f(0.0,0.0,1.0);
    afficherCubeFaces(hitboxXmin, hitboxYmin, hitboxZmin, hitboxXmax, hitboxYmax, hitboxZmax);

    if(onEasyMode){
        glColor3f(0.0,1.0,0.0);
        for(i = 0; i<nb_blocks_easy; i++){
            afficherCubeFaces(blocks_easy[i][0], blocks_easy[i][1], blocks_easy[i][2], blocks_easy[i][3], blocks_easy[i][4], blocks_easy[i][5]);
        }
    }
    else if(onMediumMode){
        glColor3f(1.0,0.5,0.0);
        for(i = 0; i<nb_blocks_medium; i++){
            afficherCubeFaces(blocks_medium[i][0], blocks_medium[i][1], blocks_medium[i][2], blocks_medium[i][3], blocks_medium[i][4], blocks_medium[i][5]);
        }
    }
    else if(onHardMode){
        glColor3f(1.0,0.0,0.0);
        for(i = 0; i<nb_blocks_hard; i++){
            afficherCubeFaces(blocks_hard[i][0], blocks_hard[i][1], blocks_hard[i][2], blocks_hard[i][3], blocks_hard[i][4], blocks_hard[i][5]);
        }
    }
    else{
        glColor3f(0.5, 0.1, 0.8);
        for(i = 0; i<nb_blocks_extreme; i++){
            afficherCubeFaces(blocks_extreme[i][0], blocks_extreme[i][1], blocks_extreme[i][2], blocks_extreme[i][3], blocks_extreme[i][4], blocks_extreme[i][5]);
        }
    }

    glEnd();

    //Disable du depth test et epaisseur de la ligne a 5 pixels
    glDisable(GL_DEPTH_TEST);
    glLineWidth(5.0);

    glBegin(GL_LINES);

    //Cube de 1000x1000x1000 sur l'origine, le joueur ne peut pas sortir de ce cube
    glColor3f(1.0,1.0,1.0);
    afficherCubeLignes(main_cube.xmin, main_cube.ymin, main_cube.zmin, main_cube.xmax, main_cube.ymax, main_cube.zmax);

    //Cube du joueur
    afficherCubeLignes(hitboxXmin, hitboxYmin, hitboxZmin, hitboxXmax, hitboxYmax, hitboxZmax);

    // Right (rose)
    //glColor3f(1,0,1);
    //afficheLigne(j.eyeX, j.eyeY+20.0, j.eyeZ+5.0, j.eyeX+(100.0*j.rightX), j.eyeY+(100.0*j.rightY), j.eyeZ+(100.0*j.rightZ));

    // Front (jaune)
    //glColor3f(1,1,0);
    //afficheLigne(j.eyeX, j.eyeY+20.0, j.eyeZ+5.0, j.eyeX+(100.0*j.frontX), j.eyeY+(100.0*j.frontY), j.eyeZ+(100.0*j.frontZ));

    // Up (bleu-ciel)
    //glColor3f(0,1,1);
    //afficheLigne(j.eyeX, j.eyeY+20.0, j.eyeZ+5.0, j.eyeX+(100.0*j.upX), j.eyeY+(100.0*j.upY), j.eyeZ+(100.0*j.upZ));

    glEnd();

    //Partie 2D pour le texte
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    //GlOrtho
    glOrtho(0, screen_width, 0, screen_height, -1, 1);

    //Matrices de visualisation
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    //FAIRE L'AFFICHAGE DU TEXTE ICI

    /*
    glColor3f(1.0, 1.0, 1.0);
    printText2DBitmap(10, screen_height-20, "Yooooo", GLUT_BITMAP_TIMES_ROMAN_24);
    printText2DStroke(screen_width/2, screen_height/2, "Yooooo", GLUT_STROKE_ROMAN);
    */

    //Affichage en faces
    glBegin(GL_QUADS);

    //Rectangle d'affichage en haut a gauche de l'ecran
    glColor4f(0.5,0.5,0.5,0.5);
    afficherCubeFaces2D(panelXmin, panelYmin, panelXmax, panelYmax);

    glEnd();

    //Affichage en ligne
    glBegin(GL_LINES);

    glColor3f(0.5,0.5,0.5);
    afficherCubeLignes2D(panelXmin, panelYmin, panelXmax, panelYmax);

    glEnd();

    //Affichage de la difficulte
    if(onEasyMode){
        glColor3f(0.0,1.0,0.0);
        printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.8), "EasyMode", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(onMediumMode){
        glColor3f(1.0,0.5,0.0);
        printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.8), "MediumMode", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(onHardMode){
        glColor3f(1.0,0.0,0.0);
        printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.8), "HardMode", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(onExtremeMode){
        glColor3f(0.5, 0.1, 0.8);
        printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.8), "ExtremeMode", GLUT_BITMAP_TIMES_ROMAN_24);
    }

    //Affichage du timer
    glColor3f(1.0,1.0,1.0);
    printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.6), "Timer: mm.ss.dd", GLUT_BITMAP_TIMES_ROMAN_24);

    //Affichage de la position du joueur
    sprintf(posX, "PlayerPosX: %.2f", j.eyeX);
    sprintf(posY, "PlayerPosY: %.2f", j.eyeY);
    sprintf(posZ, "PlayerPosZ: %.2f", j.eyeZ);
    printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.4), posX, GLUT_BITMAP_TIMES_ROMAN_24);
    printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.3), posY, GLUT_BITMAP_TIMES_ROMAN_24);
    printText2DBitmap(panelXmin+((panelXmax-panelXmin)*0.2), panelYmin+((panelYmax-panelYmin)*0.2), posZ, GLUT_BITMAP_TIMES_ROMAN_24);

    //Restaurer les matrices
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    //Fin
    glutSwapBuffers();


    //on met la souris au milieu de l'ecran au tout debut
    if(put_mouse_in_the_middle){
        glutWarpPointer(screen_width/2, screen_height/2);
        put_mouse_in_the_middle = 0;
    }

    //Gestion des collisions avec les blocks
    if(onEasyMode){
        if(verif_collisions_blocks_easy()){
            finPartie(1);
        }
    }
    else if(onMediumMode){
        if(verif_collisions_blocks_medium()){
            finPartie(2);
        }
    }
    else if(onHardMode){
        if(verif_collisions_blocks_hard()){
            finPartie(3);
        }
    }
    else{
        if(verif_collisions_blocks_extreme()){
            finPartie(4);
        }
    }


    gestion_changement_dfficulte();

}

//Fonction qui gere lorsqu'on appuie sur une touche du clavier
void ToucheAppuyee(unsigned char touche, int x, int y){
    touches[touche] = 1;

    //Si on appuie sur '&' la partie s'arrete et la fenetre se ferme
    if(touche == '&'){
        finPartie(0);
    }
}

//Fonction qui gere lorsqu'on relache une touche du clavier
void ToucheLachee(unsigned char touche, int x, int y){
    touches[touche] = 0;
}
/*
//Fonction appelee par les deux autres fonctions de gestion de la souris
void MouvementSourisGenerique(int x, int y){

    //Redefinition des vecteurs de base
    double BaseRightX = 1.0;
    double BaseRightY = 0.0;
    double BaseRightZ = 0.0;

    double BaseFrontX = 0.0;
    double BaseFrontY = 1.0;
    double BaseFrontZ = 0.0;

    double BaseUpX = 0.0;
    double BaseUpY = 0.0;
    double BaseUpZ = 1.0;

    //Variable de l'angle
    double angle;

    //Rotation sur les y
    /*
    angle = ((y*(M_PI/screen_height)) - (M_PI/2)) * -1;
    j.frontX = BaseFrontX;
    j.frontY = BaseFrontY * cos(angle) + BaseFrontZ * (-sin(angle));
    j.frontZ = BaseFrontY * sin(angle) + BaseFrontZ * cos(angle);

    j.upX = BaseUpX;
    j.upY = BaseUpY * cos(angle) + BaseUpZ * (-sin(angle));
    j.upZ = BaseUpY * sin(angle) + BaseUpZ * cos(angle);

    j.xO = j.eyeX + j.frontX * 1500;
    j.yO = j.eyeY + j.frontY * 1500;
    j.zO = j.eyeZ + j.frontZ * 1500;
    

    //Rotation sur les x
    angle = ((x*(M_PI/screen_width)) - (M_PI/2)) * -1;
    j.rightX = (BaseRightX * cos(angle)) + (BaseRightY * (-sin(angle)));
    j.rightY = (BaseRightX * sin(angle)) + (BaseRightY * cos(angle));
    j.rightZ = BaseRightZ;

    j.frontX = (BaseFrontX * cos(angle)) + (BaseFrontY * (-sin(angle)));
    j.frontY = (BaseFrontX * sin(angle)) + (BaseFrontY * cos(angle));
    j.frontZ = BaseFrontZ;

    j.xO = j.eyeX + j.frontX * 1500;
    j.yO = j.eyeY + j.frontY * 1500;
    j.zO = j.eyeZ + j.frontZ * 1500;
} */

//Fonction appelee par les deux autres fonctions de gestion de la souris
void MouvementSourisGenerique(int x, int y){

    // Calcul de l'angle horizontal (Yaw / Lacet) avec x
    double horizontal = ((x*(M_PI/screen_width)) - (M_PI/2)) * -1;
    
    // Calcul de l'angle vertical (Pitch / Tangage) avec y
    double vertical = ((y*(M_PI/screen_height)) - (M_PI/2)) * -1;

    

    // Vecteur Right (La droite du joueur, uniquement affectée par la rotation horizontale)
    j.rightX = cos(horizontal);
    j.rightY = sin(horizontal);
    j.rightZ = 0.0;

    // Vecteur Front (La direction du regard, combine la rotation horizontale et verticale)
    j.frontX = -sin(horizontal) * cos(vertical);
    j.frontY = cos(horizontal) * cos(vertical);
    j.frontZ = sin(vertical);

    // Vecteur Up (Le haut de la caméra, pour suivre l'inclinaison)
    j.upX = -sin(horizontal) * -sin(vertical);
    j.upY = cos(horizontal) * -sin(vertical);
    j.upZ = cos(vertical);

    // Mise a jour des coordonnees du point regarde (Point O)
    j.xO = j.eyeX + j.frontX * 1500;
    j.yO = j.eyeY + j.frontY * 1500;
    j.zO = j.eyeZ + j.frontZ * 1500;
}

//Fonction qui gere le mouvement de la souris lorsqu'un bouton de celle-ci est appuyee
void MouvementSourisAppuyee(int x, int y){
    MouvementSourisGenerique(x, y);
}

//Fonction qui gere le mouvement de la souris lorsque aucun bouton de celle-ci est appuyee
void MouvementSourisRelachee(int x, int y){
    MouvementSourisGenerique(x, y);
}

//Fonction d'animation
void Animer(){

    //Variables
    int i;
    //Variables pour gérer les colisions entre le petit cube (le joueur) et le gros cube
    // 3 variables de la caméra
    double oldEyeX= j.eyeX; 
    double oldEyeY = j.eyeY; 
    double oldEyeZ = j.eyeZ;
    // 3 variables du point ou on regarde
    double oldxO = j.xO; 
    double oldyO = j.yO; 
    double oldzO = j.zO;
    // les variables de la hitbox
    double oldHxmin= hitboxXmin; 
    double oldHymin = hitboxYmin; 
    double oldHzmin = hitboxZmin;
    double oldHxmax = hitboxXmax; 
    double oldHymax = hitboxYmax; 
    double oldHzmax = hitboxZmax;


    //On bouge en avant
    if(touches['z']){
        j.eyeX += j.frontX*vitesse;
        j.eyeY += j.frontY*vitesse;
        j.eyeZ += j.frontZ*vitesse;
        j.xO += j.frontX*vitesse;
        j.yO += j.frontY*vitesse;
        j.zO += j.frontZ*vitesse;
        hitboxXmin += j.frontX*vitesse;
        hitboxYmin += j.frontY*vitesse;
        hitboxZmin += j.frontZ*vitesse;
        hitboxXmax += j.frontX*vitesse;
        hitboxYmax += j.frontY*vitesse;
        hitboxZmax += j.frontZ*vitesse;
    }
    //On bouge en arriere
    if(touches['s']){
        j.eyeX -= j.frontX*vitesse;
        j.eyeY -= j.frontY*vitesse;
        j.eyeZ -= j.frontZ*vitesse;
        j.xO -= j.frontX*vitesse;
        j.yO -= j.frontY*vitesse;
        j.zO -= j.frontZ*vitesse;
        hitboxXmin -= j.frontX*vitesse;
        hitboxYmin -= j.frontY*vitesse;
        hitboxZmin -= j.frontZ*vitesse;
        hitboxXmax -= j.frontX*vitesse;
        hitboxYmax -= j.frontY*vitesse;
        hitboxZmax -= j.frontZ*vitesse;
    }
    //On bouge a droite
    if(touches['d']){
        j.eyeX += j.rightX*vitesse;
        j.eyeY += j.rightY*vitesse;
        j.eyeZ += j.rightZ*vitesse;
        j.xO += j.rightX*vitesse;
        j.yO += j.rightY*vitesse;
        j.zO += j.rightZ*vitesse;
        hitboxXmin += j.rightX*vitesse;
        hitboxYmin += j.rightY*vitesse;
        hitboxZmin += j.rightZ*vitesse;
        hitboxXmax += j.rightX*vitesse;
        hitboxYmax += j.rightY*vitesse;
        hitboxZmax += j.rightZ*vitesse;
    }
    //On bouge a gauche
    if(touches['q']){
        j.eyeX -= j.rightX*vitesse;
        j.eyeY -= j.rightY*vitesse;
        j.eyeZ -= j.rightZ*vitesse;
        j.xO -= j.rightX*vitesse;
        j.yO -= j.rightY*vitesse;
        j.zO -= j.rightZ*vitesse;
        hitboxXmin -= j.rightX*vitesse;
        hitboxYmin -= j.rightY*vitesse;
        hitboxZmin -= j.rightZ*vitesse;
        hitboxXmax -= j.rightX*vitesse;
        hitboxYmax -= j.rightY*vitesse;
        hitboxZmax -= j.rightZ*vitesse;
    }
    //On bouge en haut
    if(touches[' ']){
        j.eyeX += j.upX*vitesse;
        j.eyeY += j.upY*vitesse;
        j.eyeZ += j.upZ*vitesse;
        j.xO += j.upX*vitesse;
        j.yO += j.upY*vitesse;
        j.zO += j.upZ*vitesse;
        hitboxXmin += j.upX*vitesse;
        hitboxYmin += j.upY*vitesse;
        hitboxZmin += j.upZ*vitesse;
        hitboxXmax += j.upX*vitesse;
        hitboxYmax += j.upY*vitesse;
        hitboxZmax += j.upZ*vitesse;
    }
    //On bouge en bas
    if(touches['c']){
        j.eyeX -= j.upX*vitesse;
        j.eyeY -= j.upY*vitesse;
        j.eyeZ -= j.upZ*vitesse;
        j.xO -= j.upX*vitesse;
        j.yO -= j.upY*vitesse;
        j.zO -= j.upZ*vitesse;
        hitboxXmin -= j.upX*vitesse;
        hitboxYmin -= j.upY*vitesse;
        hitboxZmin -= j.upZ*vitesse;
        hitboxXmax -= j.upX*vitesse;
        hitboxYmax -= j.upY*vitesse;
        hitboxZmax -= j.upZ*vitesse;
    }
    // si on tente de sortir du cube alors on remet aux anciennes coordonnées
    
    if(verif_sortie_main_cube() == 1){
        j.eyeX = oldEyeX; 
        j.eyeY = oldEyeY; 
        j.eyeZ=oldEyeZ;
        j.xO = oldxO; 
        j.yO= oldyO; 
        j.zO = oldzO;
        hitboxXmin = oldHxmin; 
        hitboxYmin = oldHymin; 
        hitboxZmin = oldHzmin;
        hitboxXmax = oldHxmax; 
        hitboxYmax= oldHymax; 
        hitboxZmax = oldHzmax;
    }
    
    //Gestion des blocks
    if(onEasyMode){
        for(i=0; i<nb_blocks_easy; i++){
            //On modif le ymin et ymax
            blocks_easy[i][1] -= vitesse_blocks_easy;
            blocks_easy[i][4] -= vitesse_blocks_easy;
        }
    }
    else if(onMediumMode){
        for(i=0; i<nb_blocks_medium; i++){
            //On modif le ymin et ymax
            blocks_medium[i][1] -= vitesse_blocks_medium;
            blocks_medium[i][4] -= vitesse_blocks_medium;
        }
    }
    else if(onHardMode){
        for(i = 0; i<nb_blocks_hard; i++){
            //On modif le ymin et ymax
            blocks_hard[i][1] -= vitesse_blocks_hard;
            blocks_hard[i][4] -= vitesse_blocks_hard; 
        }
    }
    else{
        for(i = 0; i<nb_blocks_extreme; i++){
            //On modif le ymin et ymax
            blocks_extreme[i][1] -= vitesse_blocks_extreme;
            blocks_extreme[i][4] -= vitesse_blocks_extreme;
        }
    }

    //Reaffichage
    glutPostRedisplay();
}

int main(int argc, char* argv[]){

    //Variables
    char c;
    char nom[20] = "";

    //Debut
    glutInit(&argc, argv);                
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    //Initialisation du joueur
    init_joueur();

    //Initialisation du main cube
    init_main_cube();

    //Initialisation du tableau des touches appuyees
    init_touches();

    //Initialisation de la taille de l'ecran
    init_taille_ecran();

    //Intit des blocks
    spawn_blocks_easy();
    spawn_blocks_medium();
    spawn_blocks_hard();
    spawn_blocks_extreme();

    //Attente d'un appuie sur entree pour commencer
    printf("Pour quitter la fenetre, appuyez sur \'&\'.\n");

    read_scores();
    print_scores();

    printf("Pour commencer le jeu, appuyez sur entree:\n");
    while((c = getchar()) != '\n'){
    }

    //Creation de la fenetre
    glutCreateWindow("Game");
    glEnable(GL_DEPTH_TEST);

    //Mettre en plein ecran
    glutFullScreen();

    //Activation du blend pour l'opacite
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Gestion du clavier
    glutKeyboardFunc(ToucheAppuyee);
    glutKeyboardUpFunc(ToucheLachee);

    //Gestion de la souris
    glutMotionFunc(MouvementSourisAppuyee);
    glutPassiveMotionFunc(MouvementSourisRelachee);

    //Forme du curseur de la souris
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);

    //Gestion de l'affichage
    glutDisplayFunc(Affichage);

    //Gestion de l'animation
    glutIdleFunc(Animer);

    //Tests pour les scores
    /*
    read_scores();
    print_scores();
    update_scores(test, 1, 30, 89);
    print_scores();
    save_scores();
    */

    //Boucle
    glutMainLoop();

    printf("Fin de la partie:\n");
    if(game_result == 0){
        printf("Le bouton de fin de partie a ete appuyee.\n");
    }
    else if(game_result == 1){
        printf("Un block easy a touche le joueur.\n");
    }
    else if(game_result == 2){
        printf("Un block medium a touche le joueur.\n");
    }
    else if(game_result == 3){
        printf("Un block hard a touche le joueur.\n");
    }
    else if(game_result == 4){
        printf("Un block extreme a touche le joueur.\n");
    }
    else{
        printf("Vous avez gagne!\n");
    }

    //CHANGER LES ARGUMENTS PAR LES VALEURS REELLES DU TEMPS, LAISSER LE NOM VIDE TEL QUEL
    update_scores(nom, 0, 0, 0);
    save_scores();
    
    //Fin
    exit(EXIT_SUCCESS);
}