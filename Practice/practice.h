#ifndef PRACTICE_H
#define PRACTICE_H
#include "dbmslib5.h"
#include <iostream>

const string DBNAME = "PracticeDBtxt";
const int NAME_FIELD_LENGTH = 15;
const int SCREEN_WIDTH = 80;
const string PATH = "../" + DBNAME + "/";
const string RESULTS_LIST = "Results-List";
const string STUDENTS_LIST = "Students-list";

using namespace dbmsLib5;

void createStudentsListFile(DBTableSet5& DB);

namespace practice {
	class Student {
	private:
		string				groupName_;
		map<string, size_t>	marks_;
		string				name_;
		string				studentId_;
	public:
		Student() { 
			/*this->studentId_ = 0; this->name_ = ""; this->marks_.insert(pair<string, size_t>());*/ 
		}
		//Student(size_t id, string name);
		Student(string groupName, string name, string id);
		Student(string groupName, map<string, size_t> marks, string name, string id);

		string				GetGroupName();
		string				GetName();
		string				GetId();
		map<string, size_t> GetMarks();

		void SetGroupName(string groupName);
		void SetMarks(map<string, size_t> marks);
		void SetName(string name);
		void SetId(string id);
	

		void AddMark(pair<string, size_t> mark);
		void PrintStudentInfo();
	};

	class Group {
	private:
		string groupName_;
		vector<Student> studentsList_;
		size_t amountOfStudents_;
	public:
		Group() {}
		Group(string groupName);
		Group(string groupName, vector<Student> studentsList);

		string GetGroupName();
		vector<Student> GetStudentsList();
		size_t GetAmountOfStudents();

		void SetGroupName(string groupName);
		void SetStudentsList(vector<Student> studentsList);
		//void SetAmountOfStudents(size_t amountOfStudents);

		void AddStudent(Student Stud);
		void PrintGroup();

	};

	vector<practice::Group> getGroups1(DBTableSet5& DB);
	vector<practice::Group> getGroups(DBTableSet5& DB);
	string V17(DBTableSet5& DB);
}

#endif // !PRACTICE_H
