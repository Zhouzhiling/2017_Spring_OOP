#include <stdio.h>
#include <string.h>
struct course
{
	char CourseName[10];
	int Score;
	struct course* NextCou;
};

struct student
{
	char StuName[10];
	struct student* NextStu;
	struct course* NextCou;
};

int main()
{
	struct student *head = (struct student*)malloc(sizeof(struct student));
	struct student *pts = (struct student*)malloc(sizeof(struct student));
	struct student *ptspre = (struct student*)malloc(sizeof(struct student));

	head->NextStu = pts;
	scanf("%s", pts->StuName);
	while (pts->StuName[0] != '0')
	{
		ptspre = pts;
		pts = (struct student*)malloc(sizeof(struct student));
		ptspre->NextStu = pts;
		struct course *ptc = (struct course*)malloc(sizeof(struct course));
		struct course *ptcpre = ptc;
		ptspre->NextCou = ptc;
		scanf("%s", ptc->CourseName);
		while (ptc->CourseName[0] != '0')
		{
			ptcpre = ptc;
			ptc = (struct student*)malloc(sizeof(struct student));
			ptcpre->NextCou = ptc;
			scanf("%s", ptc->NextCou);
		}
		ptcpre->NextCou = NULL;

		scanf("%s", pts->StuName);
	}
	ptspre->NextStu = NULL;

	struct course *output = head->NextStu->NextCou;
	for (pts = head->NextStu; pts != NULL; pts = pts->NextStu)
	{
		printf("%s   ", pts->StuName);
			for (; output != NULL; output = output->NextCou)
				printf("%s   %d    ", output->CourseName,output->Score);
			printf("\n");
	}
}
