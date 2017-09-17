#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class record {
public:
	int num;
	string name;
	int score1;
	int score2;
	int score3;
};

int main()
{
	ifstream indata;
	indata.open("test.txt");
	if (indata.fail())
	{
		cout << "Unanble to find the file!" << endl;
		system("pause");
		return -1;
	}
	record Stu[11];
	int i;
	double Average[11];
	double Ave[3];
	double Min[3];
	double Max[3];

	for (i = 0; i < 3; i++)
	{
		Ave[i] = Max[i] = 0;
		Min[i] = 100;
	}
	for (i = 1; i <= 10; i++)
	{
		Stu[i].num = i ;
		indata >> Stu[i].name;
		indata >> Stu[i].score1;
		indata >> Stu[i].score2;
		indata >> Stu[i].score3;
		Average[i] = (Stu[i].score1 + Stu[i].score2 + Stu[i].score3) / 3;
		Ave[0] += Stu[i].score1;
		Ave[1] += Stu[i].score2;
		Ave[2] += Stu[i].score3;
		if (Stu[i].score1 > Max[0])
			Max[0] = Stu[i].score1;
		if (Stu[i].score2 > Max[1])
			Max[1] = Stu[i].score2;
		if (Stu[i].score3 > Max[2])
			Max[2] = Stu[i].score3;
		if (Stu[i].score1 < Min[0])
			Min[0] = Stu[i].score1;
		if (Stu[i].score2 < Min[1])
			Min[1] = Stu[i].score2;
		if (Stu[i].score3 < Min[2])
			Min[2] = Stu[i].score3;
		//cout << Stu[i].name << " " << endl;
		//cout << Stu[i].num << " " << endl;
		//cout << Stu[i].score1 << " " << endl;
		//cout << Stu[i].score2 << " " << endl;
		//cout << Stu[i].score3 << "\n" << endl;
	}
	
		Ave[0] /= 10 ;
		Ave[1] /= 10;
		Ave[2] /= 10;

		cout << "No.\t" << "Name\t" << "Score1\t" << "Score2\t" << "Score3\t" << "|Average" << endl;
		for(i=1 ; i<=10 ; i++)
		{
			cout << Stu[i].num<< "\t" << Stu[i].name<<"\t" << Stu[i].score1 << "\t" << Stu[i].score2 << "\t" << Stu[i].score3 << "\t" << "|"<<Average[i] << endl;
		}
		cout << "！！！！！！！！！！！！！！！！！！！！" << endl;
		cout << "\t" << "Average\t" << Ave[0] << "\t" << Ave[1] << "\t" << Ave[2] << endl;
		cout << "\t" << "Min\t" << Min[0] << "\t" << Min[1] << "\t" << Min[2] <<  endl;
		cout << "\t" << "Max\t" << Max[0] << "\t" << Max[1] << "\t" << Max[2] <<endl;
	system("pause");
}