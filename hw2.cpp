#include <iostream>
#include <string>
#include <list>
using namespace std;

class Course {
public:
	Course();								//¹¹Ôì¿Î³Ìº¯Êý
	Course(std::string name, int score);	//ÊäÈë¿Î³ÌÃûºÍ·ÖÊý
	~Course();								//Îö¹¹º¯Êý
	void input_info();						//ÊäÈëÐÅÏ¢
	void print_info();						//´òÓ¡ÐÅÏ¢
	float get_average();					//¼ÆËãÆ½¾ù·Ö
private:
	int score;	
	float average;
	string name;
};

class Student {
public:
	Student();							//Ä¬ÈÏ¹¹Ôìº¯Êý
	Student(const std::string buff);	//ÊäÈëÐÕÃû
	void input_info();					//ÊäÈëÐÅÏ¢
	void print_info();					//Êä³öÐÅÏ¢
	~Student();

private:
	int course_no, score_sum;			//¿Î³ÌÊýÁ¿ºÍ×Ü·Ö ÓÃÓÚ¼ÆËãÆ½¾ù
	std::string name;
	float average;
	list<Course> CourseList;
};

class Class {
public:
	Class();
	~Class();
	void input_info();
	void print_info();
private:
	list<Student> hisStuList;
};

Class::Class() {
}


void Class::input_info() {
	string buff;
	cout << "Input the Name of the Student" << endl;
	cin >> buff;
	Student temp(buff);
	temp.input_info();
	hisStuList.push_back(temp);

}

void Class::print_info() {
	list<Student>::iterator iter = hisStuList.begin();
	while (iter != hisStuList.end()) {
		iter->print_info();
		iter++;
	}
}


Class::~Class() {

}

Course::Course() {
	static int no_count = 0;
	no_count++;
}

Course::Course(string name, int score) : name(name), score(score) {
	static int no_count = 0, sum = 0;
	no_count++, sum += score;
	average = 1.0 * sum / no_count;
}

void Course::input_info() {
	cout << "Input Course and Score\n";
	cin >> name;
	cin >> score;
}

void Course::print_info() {
	cout << name << ":" << score << "\t";
}
float Course::get_average() {
	return average;
}

Course::~Course() {

}

Student::Student() {

}

Student::Student(const string buff) {
	course_no = 0, score_sum = 0;		//³õÊ¼»¯Ñ§ÉúµÄ¿Î³ÌÊýºÍ·ÖÊýÎª0
	name = buff;						//ÊäÈëÃû×Ö
}

void Student::input_info() {
	cout << "Adding information to Stu\nInput Course and score, input # as an end" << endl;
	string sbuff;
	int ibuff;
	while (1) {
		cin >> sbuff;						//ÊäÈë¿Î³ÌÃû³Æ
		if (sbuff == "#") return;			//Èç¹û½áÊø#£¬Ôò·µ»Ø
		cin >> ibuff;						//ÊäÈë¿Î³Ì·ÖÊý
		Course *p = new Course(sbuff, ibuff);
		CourseList.push_back(*p);
		course_no++, score_sum += ibuff;	//ÀÛ¼ÓÆä¿Î³Ì×ÜÊý¼°·ÖÊý×ÛºÏ
		average = score_sum / course_no;	//¸üÐÂÆ½¾ù·Ö
	}
}

void Student::print_info() {
	cout << name << "\t" << " average:" << average << "\t";
	list<Course>::iterator iter = CourseList.begin();
	while (iter != CourseList.end()) {
		iter->print_info();
		iter++;
	}
	std::cout << endl;
}

Student::~Student() {

}


void print_menu() {
	cout << "Choose an action" << endl <<
		"Input 1 to See Information of All the Students" << endl <<
		"Input 2 to Add Information about a  Student" << endl <<
		"Input 0 to Exit" << endl;
}

int main() {
	Class Case;
	char buff;
	for (;;) {
		print_menu();
		cin >> buff;
		switch (buff) {
		case '1': Case.print_info();	break;
		case '2': Case.input_info();	break;
		case '0': return 0;
		default: cout << "Something wrong!" << endl; break;
		}
	}
}
