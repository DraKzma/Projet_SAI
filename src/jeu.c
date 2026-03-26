#include "../include/jeu.h"

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

    //Gros cube ou le joueur se situe, 1000x1000x1000 sur l'origine avec 0.2 d'opacite
    glColor4f(0, 0, 1.0, 0.2);
    afficherCubeFaces(main_cube.xmin, main_cube.ymin, main_cube.zmin, main_cube.xmax, main_cube.ymax, main_cube.zmax);

    glEnd();

    //Disable du depth test et epaisseur de la ligne a 5 pixels
    glDisable(GL_DEPTH_TEST);
    glLineWidth(5.0);

    glBegin(GL_LINES);

    //Cube de 1000x1000x1000 sur l'origine, le joueur ne peut pas sortir de ce cube
    glColor3f(1,1,1);
    afficherCubeLignes(main_cube.xmin, main_cube.ymin, main_cube.zmin, main_cube.xmax, main_cube.ymax, main_cube.zmax);

    // Right (rouge)
    glColor3f(1,0,0);
    afficheLigne(j.eyeX, j.eyeY+20.0, j.eyeZ+5.0, j.eyeX+(100.0*j.rightX), j.eyeY+(100.0*j.rightY), j.eyeZ+(100.0*j.rightZ));

    // Front (vert)
    glColor3f(0,1,0);
    afficheLigne(j.eyeX, j.eyeY+20.0, j.eyeZ+5.0, j.eyeX+(100.0*j.frontX), j.eyeY+(100.0*j.frontY), j.eyeZ+(100.0*j.frontZ));

    // Up (bleu)
    glColor3f(0,0,1);
    afficheLigne(j.eyeX, j.eyeY+20.0, j.eyeZ+5.0, j.eyeX+(100.0*j.upX), j.eyeY+(100.0*j.upY), j.eyeZ+(100.0*j.upZ));

    glEnd();
    glEnable(GL_DEPTH_TEST);

    //Fin
    glutSwapBuffers();


    //on met la souris au milieu de l'ecran au tout debut
    if(put_mouse_in_the_middle){
        glutWarpPointer(screen_width/2, screen_height/2);
        put_mouse_in_the_middle = 0;
    }
}

int finPartie(){
    exit(EXIT_SUCCESS);
}

//Fonction qui gere lorsqu'on appuie sur une touche du clavier
void ToucheAppuyee(unsigned char touche, int x, int y){
    touches[touche] = 1;

    //Si on appuie sur '&' la partie s'arrete et la fenetre se ferme
    if(touche == '&'){
        finPartie();
    }
}

//Fonction qui gere lorsqu'on relache une touche du clavier
void ToucheLachee(unsigned char touche, int x, int y){
    touches[touche] = 0;
}

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

    angle = (x*(M_PI/screen_width)) - (M_PI/2);
    printf("%f\n", angle);
    j.rightX = (BaseRightX * cos(angle)) + (BaseRightY * (-sin(angle)));
    j.rightY = (BaseRightX * sin(angle)) + (BaseRightY * cos(angle));
    j.rightZ = BaseRightZ;

    j.frontX = (BaseFrontX * cos(angle)) + (BaseFrontY * (-sin(angle)));
    j.frontY = (BaseFrontX * sin(angle)) + (BaseFrontY * cos(angle));
    j.frontZ = BaseRightZ;

    j.xO = (j.frontX) + j.eyeX; 
    j.yO = (j.frontY * 1500) + j.eyeY; 
    j.zO = (j.frontZ) + j.eyeZ;

    printf("%f %f %f\n", j.xO, j.yO, j.zO);
    printf("%f %f %f\n", j.frontX, j.frontY, j.frontZ);
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

    double vitesse = 2.25; //Vitesse de deplacement de 0.75

    //On bouge en avant
    if(touches['z']){
        j.eyeX += j.frontX*vitesse;
        j.eyeY += j.frontY*vitesse;
        j.eyeZ += j.frontZ*vitesse;
        j.xO += j.frontX*vitesse;
        j.yO += j.frontY*vitesse;
        j.zO += j.frontZ*vitesse;
    }
    //On bouge en arriere
    if(touches['s']){
        j.eyeX -= j.frontX*vitesse;
        j.eyeY -= j.frontY*vitesse;
        j.eyeZ -= j.frontZ*vitesse;
        j.xO -= j.frontX*vitesse;
        j.yO -= j.frontY*vitesse;
        j.zO -= j.frontZ*vitesse;
    }
    //On bouge a droite
    if(touches['d']){
        j.eyeX += j.rightX*vitesse;
        j.eyeY += j.rightY*vitesse;
        j.eyeZ += j.rightZ*vitesse;
        j.xO += j.rightX*vitesse;
        j.yO += j.rightY*vitesse;
        j.zO += j.rightZ*vitesse;
    }
    //On bouge a gauche
    if(touches['q']){
        j.eyeX -= j.rightX*vitesse;
        j.eyeY -= j.rightY*vitesse;
        j.eyeZ -= j.rightZ*vitesse;
        j.xO -= j.rightX*vitesse;
        j.yO -= j.rightY*vitesse;
        j.zO -= j.rightZ*vitesse;
    }
    //On bouge en haut
    if(touches[' ']){
        j.eyeX += j.upX*vitesse;
        j.eyeY += j.upY*vitesse;
        j.eyeZ += j.upZ*vitesse;
        j.xO += j.upX*vitesse;
        j.yO += j.upY*vitesse;
        j.zO += j.upZ*vitesse;
    }
    //On bouge a gauche
    if(touches['c']){
        j.eyeX -= j.upX*vitesse;
        j.eyeY -= j.upY*vitesse;
        j.eyeZ -= j.upZ*vitesse;
        j.xO -= j.upX*vitesse;
        j.yO -= j.upY*vitesse;
        j.zO -= j.upZ*vitesse;
    }

    //Reaffichage
    glutPostRedisplay();
}

int main(int argc, char* argv[]){

    //Variables
    char c;

    //Debut
    glutInit(&argc, argv);                
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    //Initialisation du joueur
    init_joueur();

    //Initialisation du main cube
    init_main_cube();

    //Initialisation du tableau des touches appuyees
    init_touches();

    //Initialisation de la taille de l'ecran
    init_taille_ecran();

    //Attente d'un appuie sur entree pour commencer
    printf("Pour quitter la fenetre, appuyez sur \'&\'.\n");
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

    //Boucle
    glutMainLoop();
    
    //Fin
    exit(EXIT_SUCCESS);
}