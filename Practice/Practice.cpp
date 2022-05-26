#include "practice.h"

namespace practice {
	Student::Student(size_t id, string name, map<string, size_t> marks) {
		if (name.size() > 15 || !name.size())
		{
			cout << "Error: Incorrect name size" << endl;
			cout << "Student::Student(size_t id, string name, map<string, size_t> marks)" << endl;
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
			exit(EMPTY_CLASS_FIELD);
		}
		return this->name_;
	}
	size_t Student::GetId() {
		if (!this->studentId_)
		{
			cout << "Student::GetId()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->studentId_;
	}
	map<string, size_t> Student::GetMarks() {
		if (!this->marks_.size())
		{
			cout << "Student::GetMarks()" << endl;
			exit(EMPTY_CLASS_FIELD);
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
		if (!marks.size())
		{
			cout << "Student::SetMarks(map<string, size_t> marks)" << endl;
			exit(INCORRECT_INPUT);
		}
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
		if (mark.second < 2 || mark.second > 5 || !mark.first.size())
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
			exit(EMPTY_CLASS_FIELD);
		}
		cout << "-----------------" << endl;
		cout << "ID : " << this->GetId() << endl;
		cout << "Name : " << this->GetName() << endl;
		cout << "Marks:" << endl;
		for (pair<string, size_t> marksIter : this->GetMarks()) {
			cout << "\t" << marksIter.first << " : " << marksIter.second << endl;
		}
	}

	Group::Group(string groupName, vector<Student> studentsList, size_t amountOfStudents)
	{
		this->groupName_ = groupName;
		this->amountOfStudents_ = amountOfStudents;
		this->studentsList_ = studentsList;
	}

	string Group::GetGroupName()
	{
		if (!this->groupName_.size())
		{
			cout << "Group::GetGroupName()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->groupName_;
	}

	vector<Student> Group::GetStudentsList()
	{
		if (!this->studentsList_.size())
		{
			cout << "Group::GetStudentsList()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->studentsList_;
	}

	size_t Group::GetAmountOfStudents()
	{
		return this->amountOfStudents_;
	}

	void Group::SetGroupName(string groupName)
	{
		if (!groupName.size())
		{
			cout << "Group::SetGroupName(string groupName)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
	}

	void Group::SetStudentsList(vector<Student> studentsList)
	{
		if (!studentsList.size())
		{
			cout << "Group::SetStudentsList(vector<Student> studentsList)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->studentsList_ = studentsList;
		this->amountOfStudents_ = studentsList.size();
	}

	/*void Group::SetAmountOfStudents(size_t amountOfStudents)
	{
		if (!amountOfStudents)
		{
			cout << "Group::SetAmountOfStudents(size_t amountOfStudents)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->amountOfStudents_ = amountOfStudents;
	}*/

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
		this->amountOfStudents_++;
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

	vector<practice::Group> getGroups(DBTableSet5& DB)
	{
		map<string, DBTable5*> tables = DB.GetDB();

		vector<practice::Group> Groups;

		for (map<string, DBTable5*>::iterator tableIter = tables.begin(); tableIter != tables.end(); ++tableIter)
		{
			practice::Group group;
			group.SetGroupName(tableIter->first);
			//group.SetAmountOfStudents(tableIter->second->GetSize());
			vector<Row> tableData = tableIter->second->GetData();
			for (Row row : tableData)
			{
				Header tableHeader = tableIter->second->GetHeader();
				practice::Student student;
				for (Header::iterator headerIter = tableHeader.begin(); headerIter != tableHeader.end(); ++headerIter)
				{
					/*cout << headerIter->second.colName << " : " << tableIter->second->valueToString(row, headerIter->second.colName) << endl;*/
					/*cout << headerIter->second.colName << " " << headerIter->second.colType << " " << (headerIter->second.colName == "Name") << endl;*/
					if (!strcmp(headerIter->second.colName, "ID"))
					{
						student.SetId(stoul(tableIter->second->valueToString(row, headerIter->second.colName)));
					}
					else
					{
						if (!strcmp(headerIter->second.colName, "Name"))
						{
							student.SetName(tableIter->second->valueToString(row, headerIter->second.colName));
						}
						else
						{
							pair<string, size_t> mark;
							mark.first = headerIter->second.colName;
							mark.second = stoul(tableIter->second->valueToString(row, headerIter->second.colName));
							student.AddMark(mark);
						}
					}
				}
				group.AddStudent(student);
				//student.PrintStudentInfo();
			}
			Groups.push_back(group);
		}
		return Groups;
	}

}

