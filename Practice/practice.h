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

//void createStudentsListFile(DBTableSet5& DB);

namespace practice {
	static struct Discipline
	{
		string disciplineName;
		dbmsLib5::DBType type;
		size_t length;
	};

	class Student {
	private:
		string				groupName_;
		map<string, size_t>	marks_;
		string				name_;
		string				studentId_;
	public:
		Student() {}
		Student(string groupName, string id);
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
		void PrintStudentInfo();
	};

	class Group {
	private:
		string					groupName_;
		map<string, Student>	studentsList_;
		size_t					amountOfStudents_;
		map<string, Discipline>	disciplines_;
	public:
		Group() {}
		Group(string groupName);
		Group(string groupName, map<string, Student> studentsList);

		string					GetGroupName();
		map<string, Student>	GetStudentsList();
		size_t					GetAmountOfStudents();

		void SetGroupName(string groupName);
		void SetStudentsList(map<string, Student> studentsList);

		void AddStudent(Student Stud);
		void DeleteStudent(string studentId);
		void UpdateStudent(Student student, string name);
		void PrintGroup();
		void AddDiscipline(Discipline discipline);
		void PrintStudent(string studentID);

		Student operator[](string studentId) { 
			return studentsList_[studentId];
		}

		void WriteGroupToFile();
	};

	map<string, practice::Group> getGroups(DBTableSet5& DB);
	string V17(DBTableSet5& DB);
	string V16(map<string, practice::Group> Groups);
	string deleteSpaces(string str);	
}

#endif // !PRACTICE_H