#include "practice.h"

namespace practice {
	Student::Student(string groupName, string id)
	{
		if (!id.size() && !groupName.size() && id.size() != 7 && groupName.size() > 8)
		{
			cout << "Student::Student(size_t id, string name)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
		this->studentId_ = id;
	}

	Student::Student(string groupName, string name, string id) {
		if (!name.size() && !id.size() && !groupName.size() && name.size() > 15 && id.size() != 7 && groupName.size() > 8)
		{
			cout << "Student::Student(size_t id, string name)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
		this->name_ = name;
		this->studentId_ = id;
	}
	
	Student::Student(string groupName, string name, string id, map<string, size_t> marks)
	{
		if (!name.size() && !id.size() && !groupName.size() && !marks.size() && name.size() > 15 && id.size() != 7 && groupName.size() > 8)
		{
			cout << "Student::Student(size_t id, string name, map<string, size_t> marks)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
		this->marks_ = marks;
		this->name_ = name;
		this->studentId_ = id;
	}

	string Student::GetGroupName() {
		if (!this->groupName_.size())
		{
			cout << "Student::GetGroupName()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->groupName_;
	}

	map<string, size_t> Student::GetMarks()
	{
		if (!this->marks_.size())
		{
			cout << "Student::GetMarks()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->marks_;
	}

	string Student::GetName() {
		if (!this->name_.size())
		{
			cout << "Student::GetName()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->name_;
	}
	string Student::GetId() {
		if (!this->studentId_.size())
		{
			cout << "Student::GetId()" << endl;
			exit(EMPTY_CLASS_FIELD);
		}
		return this->studentId_;
	}
	
	void Student::SetGroupName(string groupName)
	{
		if (!groupName.size())
		{
			cout << "Student::SetGroupName(string groupName)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
	}

	void Student::SetMarks(map<string, size_t> marks) 
	{
		if (!marks.size())
		{
			cout << "Student::SetMarks(map<string, size_t> marks): 1" << endl;
			exit(INCORRECT_INPUT);
		}
		for (pair<string, size_t> marksIter : marks)
		{
			if (marksIter.second > 5 || marksIter.second < 2)
			{
				cout << "Student::SetMarks(map<string, size_t> marks): 2" << endl;
				exit(INCORRECT_INPUT);
			}
		}
		this->marks_ = marks;
	}

	void Student::SetName(string name) {
		if (name.size() > 15)
		{
			cout << "Student::SetName(string name)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->name_ = name;
	}

	void Student::SetId(string id) {
		this->studentId_ = id;
	}
	

	void Student::AddMark(pair<string, size_t> mark) 
	{
		if (mark.second < 2 && mark.second > 5 && !mark.first.size())
		{
			cout << "Student::AddMark(pair<string, size_t> mark)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->marks_.insert(mark);
	}
	void Student::PrintStudentInfo()
	{
		if (!(this->studentId_.size() && this->name_.size() && this->marks_.size())) {
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

	Group::Group(string groupName)
	{
		if (!groupName.size() && groupName.size() > 8)
		{
			cout << "Group::Group(string groupName)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
	}

	Group::Group(string groupName, map<string, Student> studentsList)
	{
		if (!groupName.size() && !studentsList.size() && groupName.size() > 8)
		{
			cout << "Group::Group(string groupName, map<string, Student> studentsList)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
		this->amountOfStudents_ = studentsList.size();
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

	map<string, Student> Group::GetStudentsList()
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

	void Group::SetStudentsList(map<string, Student> studentsList)
	{
		if (!studentsList.size())
		{
			cout << "Group::SetStudentsList(vector<Student> studentsList)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->studentsList_ = studentsList;
		this->amountOfStudents_ = studentsList.size();
	}

	void Group::AddStudent(Student Stud)
	{
		for (auto groupStrudent : this->studentsList_)
		{
			if (groupStrudent.second.GetId() == Stud.GetId())
			{
				cout << "Group::AddStudent(Student Stud)" << endl;
				exit(INCORRECT_INPUT);
			}
		}
		this->studentsList_.insert(pair<string, Student>(Stud.GetId(), Stud));
		this->amountOfStudents_++;
	}

	void Group::DeleteStudent(string studentId)
	{
		if (this->studentsList_.count(studentId) == 0)
		{
			cout << "Такого студента нет!" << endl;
		}
		else
		{
			this->studentsList_.erase(studentId);
			this->amountOfStudents_--;
		}
			
	}

	void Group::UpdateStudent(Student student, string name)
	{
		map<string, size_t> marks = this->GetStudentsList()[student.GetId()].GetMarks();
		this->DeleteStudent(student.GetId());

		Student stud(student.GetGroupName(), name, student.GetId(), marks);
		this->AddStudent(stud);
	}

	void Group::PrintGroup()
	{
		cout << "Group : " << this->GetGroupName() << endl;
		cout << "Amount of students : " << this->GetAmountOfStudents() << endl;
		cout << "Students: " << endl;
		for (auto groupStudent : this->GetStudentsList())
		{
			cout << "\t" << groupStudent.second.GetId() << " : " << groupStudent.second.GetName() << endl;
		}
	}

	void Group::WriteGroupToFile()
	{
		ofstream FILE(PATH + this->GetGroupName() + ".txt");

		FILE << this->GetGroupName() << "|" << this->GetGroupName() << "\n";



		for (auto student : this->GetStudentsList())
		{
			for (pair<string, size_t> studentMarks : student.second.GetMarks())
			{

			}

			break;
		}
		
	}

	map<string, practice::Group> getGroups(DBTableSet5& DB)
	{
		DBTable5* StudentsFile = DB[STUDENTS_LIST];
		DBTable5* ResultsFile = DB[RESULTS_LIST];

		// Парсинг ResultsFile: получение названий предметов, размера соответствующей ячейки в таблице и типа данных для ячейки
		Header ResultsFIleHeader = ResultsFile->GetHeader();
		for (auto ResultsFileHeaderIter : ResultsFIleHeader)
		{
			Discipline currentDisc = { ResultsFileHeaderIter.second.colName, ResultsFileHeaderIter.second.colType, ResultsFileHeaderIter.second.length };
			disciplines.push_back(currentDisc);
		}

		// Парсинг ResultsFile: получение ID и оценок студента
		// и разбиение студентов на группы 
		vector<Row> ResultsFileData = ResultsFile->GetData();

		map<string, Group> groups;
		map<string, Group> resultGroups;
		map<string, Student> students;

		string prevId;
		for (Row ResultsFileDataIter : ResultsFileData)
		{
			string id =			deleteSpaces(	ResultsFile->valueToString(ResultsFileDataIter, "ID"));
			string discipline = deleteSpaces(	ResultsFile->valueToString(ResultsFileDataIter, "discipline"));
			string groupName =	deleteSpaces(	ResultsFile->valueToString(ResultsFileDataIter, "group"));
			int mark =			stoi(			ResultsFile->valueToString(ResultsFileDataIter, "mark"));
			
			if (students.count(id) == 0)
			{
				Student newStudent(groupName, id);
				students.insert({ id, newStudent });
			}

			students[id].AddMark({ discipline, mark });

			if (groups.count(groupName) == 0)
			{
				Group newGroup(groupName);
				groups.insert({ groupName, newGroup });
			}
		}
		
		for (auto group : groups)
		{
			for (auto student : students)
			{
				string groupNameGroup = group.first;
				string groupNameStudent = student.second.GetGroupName();
				if (groupNameGroup == groupNameStudent)
				{
					cout << " Yes";
					group.second.AddStudent(student.second);
				}
				cout << endl;
			}
			resultGroups.insert(group);
		}


		// Парсинг StudentsFile: получение Name студента
		vector<Row> StudentsFileData = StudentsFile->GetData();
		for (Row StudentsFileDataIter : StudentsFileData)
		{
			string name =		deleteSpaces(StudentsFile->valueToString(StudentsFileDataIter, "Name"));
			string id =			deleteSpaces(StudentsFile->valueToString(StudentsFileDataIter, "ID"));
			string groupName =	deleteSpaces(StudentsFile->valueToString(StudentsFileDataIter, "Group"));
			resultGroups[groupName].UpdateStudent(resultGroups[groupName][id], name);
		}

		for (auto group : groups)
		{
			for (auto student : students)
			{
				string groupNameGroup = group.first;
				string groupNameStudent = student.second.GetGroupName();
				if (groupNameGroup == groupNameStudent)
				{
					cout << " Yes";
					group.second.AddStudent(student.second);
				}
				cout << endl;
			}
			resultGroups.insert(group);
		}
		return resultGroups;
	}

	string deleteSpaces(string str) 
	{
		string::iterator it = std::find_if(str.begin(), str.end(), not1(ptr_fun(isspace)));
		str.erase(remove(str.begin(), it, ' '), it);

		return str;
	}
}