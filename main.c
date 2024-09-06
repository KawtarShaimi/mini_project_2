#include <stdio.h>
#include <stdlib.h>

    struct Contact {
        char nom[50], numero[10],email[70];
    };
        struct Contact carnet[100];
        char nom[50];
        int contact_c=0;
        int i, j;
        char nv_numero[10];
        char nv_email[70];

    void ajouter(){
        if(contact_c>=100){
            printf("Le carnet est plein ! \n");
            return;
        }
            printf("Entrez le nom :");
            scanf("%s",carnet[contact_c].nom);
            printf("Entrez le numero de telephone: ");
            scanf("%s",carnet[contact_c].numero);
            printf("Entrez l email : ");
            scanf("%s",carnet[contact_c].email);
            contact_c++;

    }

    void afficher(){
        if(contact_c>0){
            for(i=0;i<contact_c;i++){
                printf("Nom :%s \nNumero : %s \nEmail : %s \n", carnet[i].nom ,carnet[i].numero, carnet[i].email);
            }
        }else{
            printf(" //   Aucun contact a afficher   // \n");
        }
    }

    void chercher(){
            int founded =0;
            if(contact_c>0){
                     printf("entez le nom du contact ");
                     scanf("%s",nom);
                    for(i=0;i<contact_c;i++){
                        if (strcmp(nom,carnet[i].nom)==0){
                        printf("Nom :%s \nNumero %s \nEmail %s \n",carnet[i].nom ,carnet[i].numero ,carnet[i].email );
                        founded = 1;
                        }
                    }
                    if(!founded){
                        printf(" Aucun contact avec ce nom .");
                    }
            }else{
                printf("Aucun contact a afficher .");
            }
    }

    void modifier(){
            int updated=0;
            if (contact_c>0){
                printf("Enrez le nom:");
                scanf("%s", nom);
                printf("Entrez le nouveau telephone :");
                scanf("%s", nv_numero);
                printf("Entrez le nouveau email :");
                scanf("%s", nv_email);
                for(i=0;i<contact_c;i++){
                    if(strcmp(nom,carnet[i])==0){
                    strcpy(carnet[i].numero,nv_numero);
                    strcpy(carnet[i].email,nv_email);
                    updated=1;
                    //break;
                    }
                }
                if(!updated){
                        printf(" Aucun contact avec ce nom !\n");
                }else{
                    printf(" Ce contact est modifier avec success !\n");
                }
            }else{
                printf("Aucun contact trouver . \n");
            }
    }

    void supprimer (){
        int deleted=0;
        if(contact_c>0){
            printf("Entrez le nom :");
            scanf("%s",nom);
            for(i=0;i<contact_c;i++){
                if(strcmp(nom,carnet[i].nom)==0){
                    contact_c--;
                    for(j=i;j<contact_c;j++){
                        strcpy(carnet[j].nom,carnet[j+1].nom);
                        strcpy(carnet[j].numero,carnet[j+1].numero);
                        strcpy(carnet[j].email,carnet[j+1].email);
                    }
                    deleted=1;
                    //reinitialiser i par -1 pour supprimer les autres contacts avec le meme nom
                    i= -1;
                }
            }
            if(!deleted){
                printf("No contact avec ce nom ! \n");
            }else{
                printf(" Ce contact est supprimer avec success \n !");
            }
        }else{
            printf("Aucun contact trouver  \n");
        }
    }
int main()
{
    int choix;
    while(1){
        printf("1 Pour ajouter un contact  \n");
        printf("2 Pour afficher contact  \n");
        printf("3 Pour chercher un contact \n");
        printf("4 Pour modifier un contact  \n");
        printf("5 Pour supprimer un contact \n");
        printf("6 Pour quitter \n");
        printf("<< ajoutez votre choix >> \n");
        scanf("%d",&choix);

        switch(choix){
            case 1 : {
                ajouter();break;
            }
            case 2 : {
                afficher();break;
            }
            case 3 : {
                chercher();break;
            }
            case 4 :{
                modifier();break;
            }
            case 5 : {
                supprimer();break;
            }
            default:
                printf(" Invalid option \n");
        }
    }

    return 0;
}
