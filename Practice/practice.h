#ifndef PRACTICE_H
#define PRACTICE_H
#include "dbmslib5.h"

const string DBNAME = "PracticeDBtxt";
const int NAME_FIELD_LENGTH = 15;
const int SCREEN_WIDTH = 80;
const string PATH = "../" + DBNAME + "/";
const string RESULTS_LIST = "Results-list";
const string STUDENTS_LIST = "Students-list";

using namespace dbmsLib5;

void createStudentsListFile(DBTableSet5& DB);

namespace practice {
	class Student {
	private:
		string				groupName_;
		map<string, size_t>	marks_;
		//map<string, string>	marks_;
		string				name_;
		string				studentId_;
	public:
		Student() { 
			/*this->studentId_ = 0; this->name_ = ""; this->marks_.insert(pair<string, size_t>());*/ 
		}
		Student(string groupName, string name, string id);
		Student(string groupName, string name, string id, map<string, size_t> marks);
		string				GetGroupName();
		string				GetName();
		string				GetId();
		map<string, size_t> GetMarks();

		void SetGroupName(string groupName);
		void SetMarks(map<string, size_t> marks);
		void SetName(string name);
		void SetId(string id);
	

		void AddMark(pair<string, size_t> mark);
		//void AddMark(pair<string, string> mark);
		void PrintStudentInfo();
	};

	class Group {
	private:
		string					groupName_;
		map<string, Student>	studentsList_;
		size_t					amountOfStudents_;
	public:
		Group() {}
		Group(string groupName);
		Group(string groupName, map<string, Student> studentsList);

		string					GetGroupName();
		map<string, Student>	GetStudentsList();
		size_t					GetAmountOfStudents();

		void SetGroupName(string groupName);
		void SetStudentsList(map<string, Student> studentsList);
		//void SetAmountOfStudents(size_t amountOfStudents);

		void AddStudent(Student Stud);
		void PrintGroup();

	};

	vector<practice::Group> getGroups1(DBTableSet5& DB);
	map<string, practice::Group> getGroups(DBTableSet5& DB);
	string V17(DBTableSet5& DB);
}

#endif // !PRACTICE_H
