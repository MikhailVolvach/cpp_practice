#include "practice.h"

namespace practice {
	Student::Student(size_t id, string name) {
		if (!(this->studentId_ || this->name_.size()))
		{
			exit(NOT_EMPTY_CLASS);
		}
		if (name.size() > 15)
		{
			exit(INCORRECT_INPUT);
		}
		this->studentId_ = id;
		this->name_ = name;
	}
	Student::Student(size_t id, string name, map<string, size_t> marks) {
		if (!(this->studentId_ || this->name_.size() || this->marks_.size()))
		{
			exit(NOT_EMPTY_CLASS);
		}
		if (name.size() > 15)
		{
			exit(INCORRECT_INPUT);
		}
		this->studentId_ = id;
		this->name_ = name;
		this->marks_ = marks;
	}

	string Student::GetName() {
		if (!this->name_.size())
		{
			cout << "Student::GetName()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		return this->name_;
	}
	size_t Student::GetId() {
		if (!this->studentId_)
		{
			cout << "Student::GetId()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		return this->studentId_;
	}
	map<string, size_t> Student::GetMarks() {
		if (!this->marks_.size())
		{
			cout << "Student::GetMarks()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		return this->marks_;
	}

	void Student::SetName(string name) {
		if (name.size() > 15)
		{
			cout << "Student::SetName(string name)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->name_ = name;
	}
	void Student::SetId(size_t id) {
		this->studentId_ = id;
	}
	void Student::SetMarks(map<string, size_t> marks) {
		for (pair<string, size_t> marksIter : marks)
		{
			if (marksIter.second > 5 || marksIter.second < 2)
			{
				cout << "Student::SetMarks(map<string, size_t> marks)" << endl;
				exit(INCORRECT_INPUT);
			}
		}
		this->marks_ = marks;
	}

	void Student::AddMark(pair<string, size_t> mark) {
		if (mark.second < 2 || mark.second > 5)
		{
			cout << "Student::AddMark(pair<string, size_t> mark)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->marks_.insert(mark);
	}
	void Student::PrintStudentInfo()
	{
		if (!(this->studentId_ || this->name_.size() || this->marks_.size())) {
			cout << "Student::PrintStudentInfo()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		cout << "-----------------" << endl;
		cout << "ID : " << this->GetId() << endl;
		cout << "Name : " << this->GetName() << endl;
		cout << "Marks:" << endl;
		for (pair<string, size_t> marksIter : this->GetMarks()) {
			cout << "\t" << marksIter.first << " : " << marksIter.second << endl;
		}
	}
	
	Group::Group(string groupName)
	{
		if (!this->groupName_.size())
		{
			cout << "Group::Group(string groupName)" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		this->groupName_ = groupName;
	}

	Group::Group(string groupName, vector<Student> studentsList, size_t amountOfStudents)
	{
		if (!(this->groupName_.size() || this->amountOfStudents_ || this->studentsList_.size()))
		{
			cout << "Group::Group(string groupName, vector<Student> studentsList, size_t amountOfStudents)" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		this->groupName_ = groupName;
		this->amountOfStudents_ = amountOfStudents;
		this->studentsList_ = studentsList;
	}

	string Group::GetGroupName()
	{
		if (!this->groupName_.size())
		{
			cout << "Group::GetGroupName()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		return this->groupName_;
	}

	vector<Student> Group::GetStudentsList()
	{
		if (!this->studentsList_.size())
		{
			cout << "Group::GetStudentsList()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		return this->studentsList_;
	}

	size_t Group::GetAmountOfStudents()
	{
		if (!this->amountOfStudents_)
		{
			cout << "Group::GetAmountOfStudents()" << endl;
			exit(EMPRTY_CLASS_FIELD);
		}
		return this->amountOfStudents_;
	}

	void Group::SetGroupName(string groupName)
	{
		if (this->groupName_.size())
		{
			cout << "Group::SetGroupName(string groupName)" << endl;
			exit(NOT_EMPTY_CLASS);
		}
		this->groupName_ = groupName;
	}

	void Group::SetStudentsList(vector<Student> studentsList)
	{
		if (this->studentsList_.size())
		{
			cout << "Group::SetStudentsList(vector<Student> studentsList)" << endl;
			exit(NOT_EMPTY_CLASS);
		}
		this->studentsList_ = studentsList;
	}

	void Group::SetAmountOfStudents(size_t amountOfStudents)
	{
		if (this->amountOfStudents_)
		{
			cout << "Group::SetAmountOfStudents(size_t amountOfStudents)" << endl;
			exit(NOT_EMPTY_CLASS);
		}
		this->amountOfStudents_ = amountOfStudents;
	}

	void Group::AddStudent(Student Stud)
	{
		for (Student groupStrudent : this->studentsList_)
		{
			if (groupStrudent.GetId() == Stud.GetId())
			{
				cout << "Group::AddStudent(Student Stud)" << endl;
				exit(INCORRECT_INPUT);
			}
		}
		this->studentsList_.push_back(Stud);
	}

	void Group::PrintGroup()
	{
		cout << "Group : " << this->GetGroupName() << endl;
		cout << "Amount of students : " << this->GetAmountOfStudents() << endl;
		cout << "Students: " << endl;
		for (Student groupStudent : this->GetStudentsList())
		{
			cout << "\t" << groupStudent.GetId() << " : " << groupStudent.GetName() << endl;
		}
	}

}