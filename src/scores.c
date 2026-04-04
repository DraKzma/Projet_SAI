#include "../include/scores.h"

char tab_names[10][20]; //Tableau des noms des joueurs
int tab_times[10][3]; //Tableau des scores des joueurs

int taille_tab = 0;

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

//Fonction qui lit le fichier des scores
void read_scores(){
    //Variables
    FILE* file = NULL;
    int i = 0;

    file = fopen("file/scores.txt", "r");
    if(file == NULL){
        fprintf(stderr, "ERROR, could not open scores.txt file.\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(file, "%s %d %d %d", tab_names[i], &tab_times[i][0], &tab_times[i][1], &tab_times[i][2]) == 4){
        i++;
    }

    taille_tab = i;
    fclose(file);
}

//Fonction qui affiche les meilleurs scores
void print_scores(){
    int i = 0;

    printf("------- MEILLEURS SCORES -------\n");
    for(i=0; i<taille_tab; i++){
        printf("%d. %s (", i+1, tab_names[i]);
        if(tab_times[i][0] < 10){
            printf("0%d:", tab_times[i][0]);
        }
        else{
            printf("%d:", tab_times[i][0]);
        }
        if(tab_times[i][1] < 10){
            printf("0%d:", tab_times[i][1]);
        }
        else{
            printf("%d:", tab_times[i][1]);
        }
        if(tab_times[i][2] < 10){
            printf("0%d)\n", tab_times[i][2]);
        }
        else{
            printf("%d)\n", tab_times[i][2]);
        }
    }
    printf("--------------------------------\n");
}

//Fonction qui insère le score du joueur dans la tableau des scores
//IMPORTANT: On suppose que le tableau des scores est deja triee
void update_scores(char nom[20], int minutes, int secondes, int dixiemes){
    //Variables
    int i = 0;
    int score_placee = 0; //Indique si le nouveau score a ete placee dans le tableau
    int est_plus_grand = 0; //Indique si le score a placer est plus grand que le score au rang i

    char name_tmp[20];
    int minutes_tmp;
    int secondes_tmp;
    int dixiemes_tmp;

    char name_tmp2[20];
    int minutes_tmp2;
    int secondes_tmp2;
    int dixiemes_tmp2;

    char new_nom[20];
    int indice_new_nom;
    
    for(i=0; i<taille_tab; i++){

        if(!score_placee){
            //Si le score n'est pas place on compare avec le score actuel pour voir si il est meilleur
            if(minutes > tab_times[i][0]){
                est_plus_grand = 1;
            }
            else if(minutes == tab_times[i][0] && secondes > tab_times[i][1]){
                est_plus_grand = 1;
            }
            else if(minutes == tab_times[i][0] && secondes == tab_times[i][1] && dixiemes > tab_times[i][2]){
                est_plus_grand = 1;
            }

            if(est_plus_grand){
                strcpy(name_tmp, tab_names[i]);
                minutes_tmp = tab_times[i][0];
                secondes_tmp = tab_times[i][1];
                dixiemes_tmp = tab_times[i][2];

                strcpy(tab_names[i], nom);
                tab_times[i][0] = minutes;
                tab_times[i][1] = secondes;
                tab_times[i][2] = dixiemes;

                score_placee = 1;
                indice_new_nom = i;
            }
        }

        else{
            //Sinon on deplace tout le tableau
            strcpy(name_tmp2, tab_names[i]);
            minutes_tmp2 = tab_times[i][0];
            secondes_tmp2 = tab_times[i][1];
            dixiemes_tmp2 = tab_times[i][2];

            strcpy(tab_names[i], name_tmp);
            tab_times[i][0] = minutes_tmp;
            tab_times[i][1] = secondes_tmp;
            tab_times[i][2] = dixiemes_tmp;

            strcpy(name_tmp, name_tmp2);
            minutes_tmp = minutes_tmp2;
            secondes_tmp = secondes_tmp2;
            dixiemes_tmp = dixiemes_tmp2;
        }

    }

    //Si le tableau ne contient pas encore 10 scores, on peut ajouter à la fin
    if(taille_tab < 10){
        if(!score_placee){
            strcpy(tab_names[i], nom);
            tab_times[i][0] = minutes;
            tab_times[i][1] = secondes;
            tab_times[i][2] = dixiemes;

            score_placee = 1;
            taille_tab++;
            indice_new_nom = i;
        }
        else{
            strcpy(tab_names[i], name_tmp);
            tab_times[i][0] = minutes_tmp;
            tab_times[i][1] = secondes_tmp;
            tab_times[i][2] = dixiemes_tmp;

            taille_tab++;
        }
    }

    //Affichage d'un message de confirmation et demande du nom
    if(score_placee){
        printf("Bravo! Votre score fait maintenant partie du top 10.\n");
        printf("Veuillez entrer votre nom (Sans espaces!!): ");
        while(scanf("%19s", new_nom) != 1){
            viderBuffer();
        }
        strcpy(tab_names[indice_new_nom], new_nom);
    }
}

void save_scores(){
    //Variables
    FILE* file = NULL;
    int i;

    file = fopen("file/scores.txt", "w");
    for(i = 0; i<taille_tab; i++){
        fprintf(file, "%s %d %d %d\n", tab_names[i], tab_times[i][0], tab_times[i][1], tab_times[i][2]);
    }

    fclose(file);
}