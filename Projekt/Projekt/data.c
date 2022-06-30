#include "header.h"
#include <stdlib.h>

//ucitava node SLL-a iz binarne datoteke
STUDENT* loadStudentNode(FILE* fp, STUDENT* headNode, int numberOfNode)
{
	STUDENT* newHeadNode = NULL;

	allocateStudent(&newHeadNode);

	fseek(fp, sizeof(int), SEEK_SET);
	fseek(fp, numberOfNode * sizeof(STUDENT), SEEK_CUR);

	fread(newHeadNode, sizeof(STUDENT), 1, fp);

	newHeadNode->nextNode = headNode;

	return newHeadNode;
}

//ucitava SLL iz binarne datoteke
void loadStudentList(FILE* fp, STUDENT** headNode)
{
	int i,n;

	fseek(fp, 0L, SEEK_SET);
	fread(&n, sizeof(int), 1, fp);

	for (i = 0; i < n; i++)
	{
		*headNode = loadStudentNode(fp, *headNode, i);
	}

}

//upisuje node SLL-a u binarnu datoteku
void writeStudentNode(FILE* fp, STUDENT* s, int numberOfNode)
{
	fseek(fp, sizeof(int), SEEK_SET);
	fseek(fp, numberOfNode * sizeof(STUDENT), SEEK_CUR);

	fwrite(s, sizeof(STUDENT), 1, fp);
}

//upisuje cijeli SLL u binarnu datoteku
void writeStudentList(FILE* fp, STUDENT* s)
{
	int i, n;

	n = countStudents(s);

	fseek(fp, 0L, SEEK_SET);
	fwrite(&n, sizeof(int), 1, fp);

	for (i = 0; i < n; i++)
	{
		writeStudentNode(fp, s, i);
		s = s->nextNode;
	}
}

//pravi novi imenik ucenika
void newFile(STUDENT** headNode)
{
	*headNode = createStudentList();
	subMenuRuntime(headNode);
}

//otvara imenik ucenika
void openFile(STUDENT **headNode)
{
	FILE* fp = NULL;

	fp = fopen("data.bin", "r");
	if (fp == NULL)
	{
		perror("Error opening a binary file!");
		exit(2);
	}

	//ukoliko vec imamo nesto u memoriji moramo prvo to osloboditi
	if (*headNode != NULL)
	{
		*headNode = deleteAllStudents(*headNode);
	}

	loadStudentList(fp, headNode);
	fclose(fp);
	subMenuRuntime(headNode);
}

void saveFile(STUDENT **headNode)
{
	FILE* fp = NULL;

	//prvo provjerimo dali ima icega u memoriji, kako nebi bezveze obrisali podatke na disku
	if (*headNode == NULL)
	{
		system("cls");
		getchar();
		printf("Nema nicega u memoriji, spremanje nije izvrseno!\nPritisnite ENTER za povratak");
		getchar();
		return;
	}

	fp = fopen("data.bin", "w");
	if (fp == NULL)
	{
		perror("Error opening a binary file!");
		exit(2);
	}

	writeStudentList(fp, *headNode);
	fclose(fp);
}