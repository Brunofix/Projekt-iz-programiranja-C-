#include "header.h"

//glavni menu
int mainMenu(STUDENT** headNode)
{
	int choice;
	

	system("cls");

	printf("Dobro dosli u e-popis studenata.\nKreirao: Bruno Sarlija\n");
	printf("Odaberi koju stavku zelis:\n1 - Kreiraj imenik\n2 - Ucitaj imenik\n3 - Spremi imenik\n4 - Izadji iz aplikacije\n");
	do
	{
		printf("Unesi svoj odabir: ");
		scanf("%i", &choice);
	} while (choice < 1 || choice > 4);


	switch (choice)
	{
	case 1:
		printf("POZOR: kreiranje novog imenika ce obrisati sve podatke koji su prije spremljeni\nUnesi broj 1 ako si siguran ili 0 ako zelis natrag!\n");
		do
		{
			printf("Unesi svoj odabir: ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1) newFile(headNode);
		return 1;
	case 2:
		printf("Zelis li ucitati spremljeni imenik?\nUnesi broj 1 ako si siguran ili 0 ako zelis natrag\n");
		do
		{
			printf("Unesi svoj odabir: ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1) openFile(headNode);
		return 2;
	case 3:
		printf("POZOR: Prethodni podatci na disku ce biti obrisani\nUnesi broj 1 ako si siguran ili 0 ako zelis natrag\n");
		do
		{
			printf("Unesi svoj odabir: ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1) saveFile(headNode);
		return 3;
	case 4:
		printf("POZOR: Nespremljeni podatci ce biti izgubljeni, jeste li sigurni da zelite izaci\nUnesi broj 1 ako si siguran ili 0 ako zelis natrag\n");
		do
		{
			printf("Unesi svoj odabir: ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1)
		{
			headNode = deleteAllStudents(*headNode);
			return 0;
		}
		else return 4;
	}
}

//sub menu za manipuliranje imenikom
int subMenu(STUDENT** headNode)
{
	int choice, id;

	system("cls");

	printf("UPRAVLJANJE IMENIKOM\n1 - ispisi imenik\n2 - dodaj studenta\n3 - izbrisi studenta\n4 - povratak na main menu\n");

	do
	{
		printf("Unesite svoj odabir: ");
		scanf("%i", &choice);
	} while (choice < 1 || choice > 4);

	switch (choice)
	{
		case 1:
			printStudentList(*headNode);
			break;
		case 2:
			*headNode = addNewStudent(*headNode);
			break;
		case 3:
			printf("Unesite ID studenata kojeg zelite izbrisati: ");
			scanf("%i", &id);
			do
			{
				printf("Jeste li sigurni da zelite obrisati studenta po ID-u %i? 1 - Da, 0 - Ne\nUnesite svoj odabir: ", id);
				scanf("%i", &choice);
			} while (choice < 0 || choice > 1);

			deleteStudent(headNode, findStudentByID(*headNode, id));
			getchar();
			printf("Pritisnite ENTER da bi ste nastavili.");
			getchar();
			break;
		case 4:
			return 1;
	}
	return 0;
}

//odvija sub menu
void subMenuRuntime(STUDENT** headNode)
{
	int choice;

	do
	{
		choice = subMenu(headNode);
	} while (choice == 0);
}