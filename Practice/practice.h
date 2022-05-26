#ifndef PRACTICE_H
#define PRACTICE_H
#include "dbmslib5.h"
#include <iostream>

const int SCREEN_WIDTH = 80;
const int NAME_FIELD_LENGTH = 15;
const string DBNAME = "PracticeDBtxt";
const string path = "../" + DBNAME + "/";

using namespace dbmsLib5;



namespace practice {
	class Student {
	private:
		size_t studentId_;
		string name_;
		map<string, size_t> marks_;
	public:
		Student() { 
			/*this->studentId_ = 0; this->name_ = ""; this->marks_.insert(pair<string, size_t>());*/ 
		}
		//Student(size_t id, string name);
		Student(size_t id, string name, map<string, size_t> marks);

		string GetName();
		size_t GetId();
		map<string, size_t> GetMarks();

		void SetName(string name);
		void SetId(size_t id);
		void SetMarks(map<string, size_t> marks);

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
		Group(string groupName, vector<Student> studentsList, size_t amountOfStudents);

		string GetGroupName();
		vector<Student> GetStudentsList();
		size_t GetAmountOfStudents();

		void SetGroupName(string groupName);
		void SetStudentsList(vector<Student> studentsList);
		//void SetAmountOfStudents(size_t amountOfStudents);

		void AddStudent(Student Stud);
		void PrintGroup();

	};

	vector<practice::Group> getGroups(DBTableSet5& DB);
	string V17(DBTableSet5& DB);
}

#endif // !PRACTICE_H
