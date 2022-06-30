#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

typedef enum smjer {racunarstvo = 1, elektro, automatika}SMJER;

typedef struct student
{
	char ime[20];
	char prezime[20];
	int ID;
	float prosjek;
	SMJER smjer;
	struct student *nextNode;
}STUDENT;

STUDENT* createStudentList(void);

void allocateStudent(STUDENT** s);

void unosPodataka(STUDENT* s);

STUDENT* addNewStudent(STUDENT* headNode);

STUDENT* findStudentByID(STUDENT* headNode, int ID);

void deleteStudent(STUDENT** headNode, STUDENT* s);

STUDENT* deleteAllStudents(STUDENT* s);

void printStudentNode(STUDENT* s);

void printStudentList(STUDENT* headNode);

int countStudents(STUDENT* headNode);

STUDENT* loadStudentNode(FILE* fp, STUDENT* headNode, int numberOfNode);

void loadStudentList(FILE* fp, STUDENT** headNode);

void writeStudentNode(FILE* fp, STUDENT* s, int numberOfNode);

void writeStudentList(FILE* fp, STUDENT* s);

void openFile(STUDENT** headNode);

int mainMenu(STUDENT** headNode);

void newFile(STUDENT** headNode);

int subMenu(STUDENT** headNode);

void subMenuRuntime(STUDENT** headNode);
#endif