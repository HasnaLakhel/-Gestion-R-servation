#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Date
{
    int jour;
    int mois;
    int annee;
};

struct Reservation
{
    int id;
    char Nom[100];
    char Prenom[150];
    char Telephone[20];
    int Age;
    char Statut[20];
    struct Date Date_R;
};

int Nbr_reservation = 10;

struct Reservation MAX_Reservation[500] = {
    {1, "HASNA", "lakhel", "0645234567", 22, "valide", {3, 2, 2024}},
    {2, "HOUSSAM", "lakhelA", "0645234567", 22, "annule", {11, 12, 2024}},
    {3, "HALIMA", "BAHOM", "0645234567", 23, "reporte", {12, 3, 2024}},
    {4, "MARYAM", "AZIKI", "0645234567", 13, "valide", {25, 9, 2024}},
    {5, "WISAL", "ARFT", "0645234567", 34, "annule", {27, 10, 2024}},
    {6, "HASNA", "NATIF", "0645234567", 43, "reporte", {15, 4, 2024}},
    {7, "SALMA", "HARIT", "0645234567", 52, "traite", {18, 6, 2024}},
    {8, "DOHA", "BAHI", "0645234567", 28, "valide", {19, 5, 2024}},
    {9, "MALIKA", "ASMI", "0645234567", 11, "reporte", {28, 7, 2024}},
    {10, "ABOUBAKER", "ANAA", "0645234567", 22, "annule", {34, 7, 2024}}};

int valid_date(int jour, int mois, int annee){
    if (annee > 9999 || annee < 2024){
        return 0;}
    if (mois < 1 || mois > 12){
        return 0;}
    if (jour < 1 || jour > 31){
        return 0;}
    return 1;}

char valid_Telephone(char Telephone[10]){
    if (strlen(Telephone) != 10){
        return 0;}
    for (int i = 0; i < 10; i++){
        if (!isdigit(Telephone[i])){
            return 0;}
    }
    if ((Telephone[0] != '0' || (Telephone[1] != '6' && Telephone[1] != '7'))){
        return 0;
    }
    for (int i = 0; i < Nbr_reservation; i++){
        if (strcmp(MAX_Reservation[i].Telephone, Telephone) == 0){
            return 0;
        } 
    }
    return 1;
}

int valid_Statut(char statut[20])
{
    return strcmp(statut, "valide") == 0 || strcmp(statut, "reporte") == 0 ||
           strcmp(statut, "annule") == 0 || strcmp(statut, "traite") == 0;
}

char valid_Nom(char Nom[50]){
    for (int i = 0; Nom[i]!= '\0' ; i++){
        if (!isalpha(Nom[i])){
            return 0;
        }
    }return 1;
}
char valid_Prenom(char Prenom[50]){
    for (int i = 0; Prenom[i]!= '\0' ; i++){
        if (!isalpha(Prenom[i])){
            return 0;
        }
    }return 1;
}

int valide_age(int Age ){
    if (Age > 100){
        return 0 ;
    }
    return 1 ;  
}

void Ajouter_reservation()
{
    struct Reservation Reservation_Info;

    if (Nbr_reservation < 500)
    {
        do
        {
            printf("entre le Nom\n");
            getchar(); 
            fgets(Reservation_Info.Nom, sizeof(Reservation_Info.Nom), stdin);
            Reservation_Info.Nom[strcspn(Reservation_Info.Nom, "\n")] = '\0'; 
            if (!valid_Nom(Reservation_Info.Nom)) {
                printf("Nom invalide.\n");
            }
        } while (!valid_Nom(Reservation_Info.Nom));
        do
        {
            printf("entre le Prénom\n");
            getchar(); 
            fgets(Reservation_Info.Prenom, sizeof(Reservation_Info.Prenom), stdin);
            Reservation_Info.Prenom[strcspn(Reservation_Info.Prenom, "\n")] = '\0'; 
            if (!valid_Prenom(Reservation_Info.Prenom)) {
                printf("Prenom invalide.\n");
            }
        } while (!valid_Prenom(Reservation_Info.Prenom));
        do
        {
            printf("entre le numero de Téléphone\n");
            scanf("%s", Reservation_Info.Telephone);
            if (!valid_Telephone(Reservation_Info.Telephone))
            {
                printf("Téléphone invalide.\n");
            }
        } while (!valid_Telephone(Reservation_Info.Telephone));
        do
        {
            printf("entre l'Âge\n");
            scanf("%d", &Reservation_Info.Age);
            if (!valide_age(Reservation_Info.Age))
            {
                printf("Age invalide.\n");
            }
        } while (!valide_age(Reservation_Info.Age));
        
        do
        {
            printf("entre le Statut  (valide, reporte, annule, traite)\n");
            scanf("%s", Reservation_Info.Statut);
            if (!valid_Statut(Reservation_Info.Statut))
            {
                printf("Statut invalide.\n");
            }
        } while (!valid_Statut(Reservation_Info.Statut));

        do
        {
            printf("entre le Date de réservation\n");
            printf("entre le jour \n");
            scanf("%d", &Reservation_Info.Date_R.jour);
            printf("entre le mois \n");
            scanf("%d", &Reservation_Info.Date_R.mois);
            printf("entre l'annee \n");
            scanf("%d", &Reservation_Info.Date_R.annee);
            if (!valid_date(Reservation_Info.Date_R.jour, Reservation_Info.Date_R.mois, Reservation_Info.Date_R.annee))
            {
                printf("Date invalide, veuillez réessayer.\n");
            }

        } while (!valid_date(Reservation_Info.Date_R.jour, Reservation_Info.Date_R.mois, Reservation_Info.Date_R.annee));
        printf("Réservation ajoutée avec succès!\n");
        MAX_Reservation[Nbr_reservation++] = Reservation_Info; 
        int max_id = 0;
        for (int i = 0; i < Nbr_reservation; i++){
            if (MAX_Reservation[i].id > max_id){
                max_id=MAX_Reservation[i].id;
            }
        }
        Reservation_Info.id=max_id + 1;
    }
    else
    {
        printf("le reservation est plein!\n");
    }
}

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////

void Afficher_reservation()
{
    struct Reservation Reservation_Info;
    if (Nbr_reservation == 0)
    {
        printf("Aucun contact disponible.\n");
    }
    else
    {
        printf("\n======= tout les reservation ========\n");
        for (int i = 0; i < Nbr_reservation; i++)
        {
            printf("\n======= %d les reservation ========\n", i + 1);
            printf("id : %d\n", MAX_Reservation[i].id);
            printf("le Nom: %s\n", MAX_Reservation[i].Nom);
            printf("le Prénom : %s\n", MAX_Reservation[i].Prenom);
            printf("le Téléphone %s\n", MAX_Reservation[i].Telephone);
            printf("Âge : %d\n", MAX_Reservation[i].Age);
            printf("Statut :%s\n", MAX_Reservation[i].Statut);
            printf("Date de réservation  : %d-%d-%d \n", MAX_Reservation[i].Date_R.jour, MAX_Reservation[i].Date_R.mois, MAX_Reservation[i].Date_R.annee);
        }
    }
}

/// /////////////////////////////////////////////////////////////////// //////////////////////

void Modifier_reservation()
{
    struct Reservation Reservation_Info;
    int id_Reservation;
    printf("entre la référence unique:");
    scanf("%d", &id_Reservation);
    int trouve = 0;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        if (id_Reservation == MAX_Reservation[i].id)
        {
            trouve = 1;
            printf("Modifier la réservation ID: %d\n", MAX_Reservation[i].id);
            printf("Nouveau Nom: \n");
            scanf("%s", MAX_Reservation[i].Nom);
            printf("Nouveau Prénom: \n");
            scanf("%s", MAX_Reservation[i].Prenom);
            do
            {
                printf("Nouveau Téléphone: \n");
                scanf("%s", MAX_Reservation[i].Telephone);
                if (!valid_Telephone)
                {
                    printf("Téléphone invalide");
                }

            } while (!valid_Telephone);

            printf("Nouvel Âge: \n");
            scanf("%d", &MAX_Reservation[i].Age);
            do
            {
                printf("Nouveau Statut: \n");
                scanf("%s", MAX_Reservation[i].Statut);
                if (!valid_Telephone)
                {
                    printf("Statut invalide ");
                }
            } while (!valid_Statut);
            do
            {
                printf("Nouvelle Date: \n");
                printf("entre le jour \n");
                scanf("%d", &Reservation_Info.Date_R.jour);
                printf("entre le mois \n");
                scanf("%d", &Reservation_Info.Date_R.mois);
                printf("entre l'annee \n");
                scanf("%d", &Reservation_Info.Date_R.annee);
                if (!valid_Telephone)
                {
                    printf("Date invalide ");
                }
            } while (!valid_date);

            printf("Réservation modifiée avec succès!\n");
        }
    }
    if (!trouve)
    {
        printf("Réservation non trouvée!\n");
    }
}

void Supprimer_reservation()
{
    struct Reservation Reservation_Info;
    int id_Reservation;
    printf("entre la référence unique:");
    scanf("%d", &id_Reservation);
    int trouve = 0;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        if (MAX_Reservation[i].id == id_Reservation)
        {
            trouve = 1;
            for (int j = i; j < Nbr_reservation - 1; j++)
            {
                MAX_Reservation[j] = MAX_Reservation[j + 1];
            }
            Nbr_reservation--;
            printf("Réservation supprimée avec succès!\n");
            break;
        }
    }
    if (!trouve)
    {
        printf("Réservation non trouvée!\n");
    }
}

void Manipulation()
{
    int Mani;
    do
    {
        printf("\n======= Modifier ou supprimer une réservation ========\n");
        printf("1. Modifier des réservations .\n");
        printf("2.supprimer des réservations \n");
        printf("3. Quitter\n");
        scanf("%d", &Mani);
        switch (Mani)
        {
        case 1:
            Modifier_reservation();
            break;
        case 2:
            Supprimer_reservation();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (Mani != 3);
}

/// /////////////////////////////////////////////////////////////////// //////////////////////

void Tri_par_Nom()
{
    struct Reservation temp;
    for (int i = 0; i < Nbr_reservation - 1; i++)
    {
        for (int j = i + 1; j < Nbr_reservation; j++)
        {
            if (strcmp(MAX_Reservation[i].Nom, MAX_Reservation[j].Nom) > 0)
            {
                temp = MAX_Reservation[i];
                MAX_Reservation[i] = MAX_Reservation[j];
                MAX_Reservation[j] = temp;
            }
        }
    }
    printf("\n======= Réservations triées par Nom ========\n");
    for (int i = 0; i < Nbr_reservation; i++)
    {
        printf("le Nom: %s\n", MAX_Reservation[i].Nom);
        printf("le Prenom: %s\n", MAX_Reservation[i].Prenom);
        printf("le numero de Téléphone: %s\n", MAX_Reservation[i].Telephone);
        printf("l'age: %d\n", MAX_Reservation[i].Age);
        printf("le statut: %s\n", MAX_Reservation[i].Statut);
        printf("Date de réservation: %d-%d-%d\n",
               MAX_Reservation[i].Date_R.jour,
               MAX_Reservation[i].Date_R.mois,
               MAX_Reservation[i].Date_R.annee);
        printf("------------------------------------------\n");
    }
}

void Tri_par_statut()
{
    struct Reservation temp;
    struct Reservation Reservation_Info;
    for (int i = 0; i < Nbr_reservation - 1; i++)
    {
        for (int j = i + 1; j < Nbr_reservation; j++)
        {
            if (strcmp(MAX_Reservation[i].Statut, MAX_Reservation[j].Statut) > 0)
            {
                temp = MAX_Reservation[i];
                MAX_Reservation[i] = MAX_Reservation[j];
                MAX_Reservation[j] = temp;
            }
        }
    }

    printf("\n======= Réservations triées par statut ========\n");
    for (int i = 0; i < Nbr_reservation; i++)
    {
        printf("le Nom: %s\n", MAX_Reservation[i].Nom);
        printf("le Prenom: %s\n", MAX_Reservation[i].Prenom);
        printf("le numero de Téléphone: %s\n", MAX_Reservation[i].Telephone);
        printf("l'age: %d\n", MAX_Reservation[i].Age);
        printf("le statut: %s\n", MAX_Reservation[i].Statut);
        printf("Date de réservation: %d-%d-%d\n",
               MAX_Reservation[i].Date_R.jour,
               MAX_Reservation[i].Date_R.mois,
               MAX_Reservation[i].Date_R.annee);
        printf("------------------------------------------\n");
    }
}

void Trier_reservation()
{
    int trier;
    do
    {
        printf("\n======= Tri des réservations  ========\n");
        printf("1. Tri des réservations par Nom.\n");
        printf("2. Tri des réservations par statut\n");
        printf("3. Quitter\n");
        scanf("%d", &trier);
        switch (trier)
        {
        case 1:
            Tri_par_Nom();
            break;
        case 2:
            Tri_par_statut();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (trier != 3);
}
/// /////////////////////////////////////////////////////////////////// //////////////////////
void Recherche_par_Nom()
{
    char RecheNom[100];
    printf("entre le Nom \n");
    scanf("%s", RecheNom);
    int trouve = 0;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        if (strcmp(MAX_Reservation[i].Nom, RecheNom) == 0)
        {
            trouve = 1;
            printf("le reservation a recherche est:\n");
            printf("id : %d\n", MAX_Reservation[i].id);
            printf("le Nom: %s\n", MAX_Reservation[i].Nom);
            printf("le Prénom : %s\n", MAX_Reservation[i].Prenom);
            printf("le Téléphone %s\n", MAX_Reservation[i].Telephone);
            printf("Âge : %d\n", MAX_Reservation[i].Age);
            printf("Statut :%s\n", MAX_Reservation[i].Statut);
            printf("Date de réservation  : %d-%d-%d \n", MAX_Reservation[i].Date_R.jour, MAX_Reservation[i].Date_R.mois, MAX_Reservation[i].Date_R.annee);
            printf("------------------------------------------\n");
        }
    }
    if (!trouve)
    {
        printf("Réservation non trouvée!\n");
    }
}

void Recherche_par_ID()
{
    int id_R;
    printf("entre le référence unique \n");
    scanf("%d", &id_R);
    int trouve = 0;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        if (MAX_Reservation[i].id == id_R)
        {
            trouve = 1;
            printf("la reservation a recherche est:\n");
            printf("id : %d\n", MAX_Reservation[i].id);
            printf("le Nom: %s\n", MAX_Reservation[i].Nom);
            printf("le Prénom : %s\n", MAX_Reservation[i].Prenom);
            printf("le Téléphone %s\n", MAX_Reservation[i].Telephone);
            printf("Âge : %d\n", MAX_Reservation[i].Age);
            printf("Statut :%s\n", MAX_Reservation[i].Statut);
            printf("Date de réservation  : %d-%d-%d \n", MAX_Reservation[i].Date_R.jour, MAX_Reservation[i].Date_R.mois, MAX_Reservation[i].Date_R.annee);
        }
    }
    if (!trouve)
    {
        printf("Réservation non trouvée!\n");
    }
}

void Rechercher_reservation()
{
    int Rechercher;
    do
    {
        printf("\n======= Recherche des réservations  ========\n");
        printf("1. Recherche d'une réservation par référence unique..\n");
        printf("2.Recherche d'une réservation par nom.\n");
        printf("3. Quitter\n");
        scanf("%d", &Rechercher);
        switch (Rechercher)
        {
        case 1:
            Recherche_par_ID();
            break;
        case 2:
            Recherche_par_Nom();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (Rechercher != 3);
}

/// /////////////////////////////////////////////////////////////////// //////////////////////

void moyenne_age()
{
    float total = 0;
    float Moyenne;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        total += MAX_Reservation[i].Age;
    }
    Moyenne = total / Nbr_reservation;
    printf("La moyenne d'âge des patients est : %.2f \n", Moyenne);
}

void nbr_patients_par_tranche()
{
    int tranche_0_18 = 0, tranche_19_35 = 0, tranche_36 = 0;
    int age;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        age = MAX_Reservation[i].Age;
        if (age <= 18)
        {
            tranche_0_18++;
        }
        else if (age >= 19 && age <= 35)
        {
            tranche_19_35++;
        }
        else
        {
            tranche_36++;
        }
    }
    printf("Nombre de patients entre 0-18 ans : %d\n", tranche_0_18);
    printf("Nombre de patients entre 19-35 ans : %d\n", tranche_19_35);
    printf("Nombre de patients de 36 ans et plus : %d\n", tranche_36);
}

void nbr_total_par_statut()
{
    int valide = 0, annule = 0, reporte = 0, traite = 0;
    for (int i = 0; i < Nbr_reservation; i++)
    {
        if (strcmp(MAX_Reservation[i].Statut, "valide") == 0)
            valide++;
        else if (strcmp(MAX_Reservation[i].Statut, "annule") == 0)
            annule++;
        else if (strcmp(MAX_Reservation[i].Statut, "reporte") == 0)
            reporte++;
        else if (strcmp(MAX_Reservation[i].Statut, "traite") == 0)
            traite++;
    }
    printf("Nombre de réservations validées : %d\n", valide);
    printf("Nombre de réservations annulées : %d\n", annule);
    printf("Nombre de réservations reportées : %d\n", reporte);
    printf("Nombre de réservations traitées : %d\n", traite);
}

void Statistiques_reservation()
{
    int Statis;
    do
    {
        printf("\n======= Statistiques reservation  ========\n");
        printf("1.Afficher la moyenne d'âge des patients \n");
        printf("2.Afficher le nombre de patients par tranche d'âge.\n");
        printf("3.Afficher le nombre total de réservations par statut \n");
        printf("4. Quitter\n");
        scanf("%d", &Statis);
        switch (Statis)
        {
        case 1:
            moyenne_age();
            break;
        case 2:
            nbr_patients_par_tranche();
            break;
        case 3:
            nbr_total_par_statut();
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (Statis != 4);
}

int main()
{
    int choix;
    do
    {
        printf("\n======= Menu Principal ========\n");
        printf("1. Ajouter une réservation\n");
        printf("2. Afficher  les réservations\n");
        printf("3. Modifier OU Supprimer une réservation\n");
        printf("4. Trier les réservations \n");
        printf("5. Rechercher une réservation \n");
        printf("6. Statistiques\n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            Ajouter_reservation();
            break;
        case 2:
            Afficher_reservation();
            break;
        case 3:
            Manipulation();
            break;
        case 4:
            Trier_reservation();
            break;
        case 5:
            Rechercher_reservation();
            break;
        case 6:
            Statistiques_reservation();
            break;
        default:
            printf("Option invalide. Veuillez entrer un nombre entre 1 et 4.\n");
            break;
        }

    } while (choix != 6);

    return 0;
}