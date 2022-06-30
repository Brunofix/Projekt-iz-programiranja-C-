#include "header.h"
#include <stdlib.h>

//kreira SLL
STUDENT* createStudentList(void)
{
	STUDENT* headNode = NULL;

	printf("Kreiranje imenika...\n");

	allocateStudent(&headNode);
	unosPodataka(headNode);

	printf("Prvi student je uspjesno kreiran!\n");
	return headNode;
}

//alocira memoriju za studenta, predaje se pokazivac na pokazivac na koji cemo staviti memorijsku adresu novo alocirane strukture
void allocateStudent(STUDENT** s)
{
	*s = (STUDENT*)calloc(1, sizeof(STUDENT));
	if (*s == NULL)
	{
		perror("Zauzimanje memorije za strukturu student nije moguce");
		exit(-1);
	}
}

//unos podataka u strukturu
void unosPodataka(STUDENT* s)
{
	system("cls");
	getchar();
	printf("Unesite ime studenta: ");
	scanf("%19[^\n]", s->ime);
	getchar();
	printf("Unesite prezime studenta: ");
	scanf("%19[^\n]", s->prezime);
	printf("Unesite ID ucenika (broj): ");
	scanf("%i", &(s->ID));
	printf("Unesite prosjek studenta: ");
	scanf("%f", &(s->prosjek));
	printf("Unesite smjer studenta (rednim brojem)\n1 - Racunarstvo\n2 - Elektroenergetika\n3 - Automatika\n");
	do
	{
		printf("Unesite svoj odabir: ");
		scanf("%i", &(s->smjer));
	} while (s->smjer < 1 || s->smjer > 3);
	
	getchar();
	printf("Student uspjesno kreairan. Pritisnite ENTER kako bi nastavili");
	getchar();
}

//dodaje novog studenta na pocetak SLL
STUDENT* addNewStudent(STUDENT* headNode)
{
	STUDENT* newHeadNode = NULL;

	printf("Dodavanje novog studenta...\n");

	allocateStudent(&newHeadNode);
	unosPodataka(newHeadNode);

	newHeadNode->nextNode = headNode;

	printf("Student uspjesno dodan!\n");
	return newHeadNode;
}

//pretrazuje SLL i trazi studenta po ID. Vraca pokazivac na prvog studenta (strukturu) koji zadovoljava uvijet
STUDENT* findStudentByID(STUDENT* headNode, int ID)
{
	while (headNode)
	{
		if (headNode->ID == ID) return headNode;
		headNode = headNode->nextNode;
	}
	printf("Student nije pronadjen!");
	return NULL;
}

//ispisuje strukturu student
void printStudentNode(STUDENT* s)
{
	printf("Ime: %s\nPrezime: %s\n", s->ime, s->prezime);
	printf("ID: %i\nProsjek: %.2f\n", s->ID, s->prosjek);

	switch (s->smjer)
	{
		case racunarstvo:
			printf("Smjer: racunarstvo\n");
			break;
		case elektro:
			printf("Smjer: elektroenergetika\n");
			break;
		case automatika:
			printf("Smjer: automatika\n");
			break;
	}
}

//ispisuje cijeli SLL
void printStudentList(STUDENT* headNode)
{
	system("cls");

	printf("Imenik studenata:\n");

	while (headNode)
	{
		printStudentNode(headNode);
		headNode = headNode->nextNode;
	}

	getchar();
	printf("Pritisnite ENTER kako biste nastavili");
	getchar();
}

//prebrojava koliko ima studenata u SLL
int countStudents(STUDENT* headNode)
{
	int i = 0;

	while (headNode)
	{
		i++;
		headNode = headNode->nextNode;
	}

	return i;
}

//brise studenta iz SLL i memorije
void deleteStudent(STUDENT** headNode, STUDENT* s)
{
	STUDENT* traverseNode;

	if (*headNode == s)
	{
		*headNode = (*headNode)->nextNode;
		free(s);
		printf("Student uspjesno obrisan\n");
		return;
	}

	traverseNode = *headNode;
	while (traverseNode->nextNode)
	{
		if (traverseNode->nextNode == s)
		{
			traverseNode->nextNode = s->nextNode;
			free(s);
			printf("Student uspjesno obrisan");
			return;
		}
		traverseNode = traverseNode->nextNode;
	}
	printf("Nije moguce brisanje studenta! Student nije pronadjen u imeniku!");
}

//brise cijeli SLL iz memorije
STUDENT* deleteAllStudents(STUDENT* s)
{
	STUDENT* deleteNode = NULL;

	while (s)
	{
		deleteNode = s;
		s = s->nextNode;
		free(deleteNode);
	}
	return NULL;
}