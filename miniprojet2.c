#include <stdio.h>
#include <string.h>

int chois;
int nbr_contact = 0;

struct contact {
    char nom[100];
    char tele[30];
    char email[50];
};

struct contact personne[100]; 


void ajouter() {
    printf("Entrer le nom: ");
    scanf("%s", personne[nbr_contact].nom);

    printf("Entrer le telephone: ");
    scanf("%s", personne[nbr_contact].tele);

    printf("Entrer l'email: ");
    scanf("%s", personne[nbr_contact].email);

    nbr_contact++;
    
}


void afficher() {
    if (nbr_contact == 0) {
        printf("Aucun contact a afficher.\n");
        return;
    }

    for (int i = 0; i < nbr_contact; i++) {
        printf("\nContact %d:\n", i + 1);
        printf("Nom: %s\n", personne[i].nom);
        printf("Telephone: %s\n", personne[i].tele);
        printf("Email: %s\n", personne[i].email);
    }
}

void rechercher() {
    char nomCherche[50];
    int i;

    printf("Entrer le nom a rechercher: ");
    scanf("%s", nomCherche);

    for (i = 0; i < nbr_contact; i++) {
        if (strcmp(personne[i].nom, nomCherche) == 0) {
            printf("Contact trouve:\n");
            printf("Nom: %s\n", personne[i].nom);
            printf("Telephone: %s\n", personne[i].tele);
            printf("Email: %s\n", personne[i].email);
            break;
        }
    }
    if (i == nbr_contact) {
        printf("Contact non trouve.\n");
    }
}


void modifier() {
    char nomCherche[50];
    int i;

    printf("Entrer le nom du contact a modifier: ");
    scanf("%s", nomCherche);

    for (i = 0; i < nbr_contact; i++) {
        if (strcmp(personne[i].nom, nomCherche) == 0) {
            printf("Entrer le nouveau telephone: ");
            scanf("%s", personne[i].tele);
            printf("Entrer le nouvel email: ");
            scanf("%s", personne[i].email);
    
            break;
        }
    }
    if (i == nbr_contact) {
        printf("Contact non trouve.\n");
    }
}


void supprimer() {
    char nomCherche[50];
    int i;

    printf("Entrer le nom du contact a supprimer: ");
    scanf("%s", nomCherche);

    for (i = 0; i < nbr_contact; i++) {
        if (strcmp(personne[i].nom, nomCherche) == 0) {
            for (int j = i; j < nbr_contact - 1; j++) {
                personne[j] = personne[j + 1];
            }
            nbr_contact--;
            printf("Contact supprime avec succes !\n");
            break;
        }
    }
    if (i == nbr_contact) {
        printf("Contact non trouve.\n");
    }
}


int main() {
    do {
        printf("\n----- Menu -----\n");
        printf("1 - Ajouter\n");
        printf("2 - Modifier\n");
        printf("3 - Supprimer\n");
        printf("4 - Afficher tous les contacts\n");
        printf("5 - Rechercher\n");
        printf("6 - Quitter\n");
        printf("Entrer votre choix: ");
        scanf("%d", &chois);

        switch (chois) {
            case 1: ajouter(); 
                    break;
            case 2: modifier();
                 break;
            case 3: supprimer(); 
                break;
            case 4: afficher(); 
                break;
            case 5: rechercher();
                     break;
            case 6: printf("Au revoir !\n");
                     break;
            default: printf("Choix invalide, reessayez.\n");
                    break;
        }

    } while (chois != 6);

    return 0;
}