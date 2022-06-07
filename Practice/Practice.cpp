#include "practice.h"

namespace practice {
	Student::Student(string groupName, string id)
	{
		if (!id.size() && !groupName.size() && id.size() != 7 && groupName.size() > 8)
		{
			/*cout << "Error: Incorrect name size" << endl;*/
			cout << "Student::Student(size_t id, string name)" << endl;
			exit(INCORRECT_INPUT);
		}
		this->groupName_ = groupName;
		this->studentId_ = id;
	}

	Student::Student(string groupName, string name, string id) {
		if (!name.size() && !id.size() && !groupName.size() && name.size() > 15 && id.size() != 7 && groupName.size() > 8)
		{
			/*cout << "Error: Incorrect name size" << endl;*/
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
			//cout << "Error: Incorrect name size" << endl;
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

	vector<practice::Group> getGroups1(DBTableSet5& DB)
	{
		map<string, DBTable5*> tables = DB.GetDB();

		vector<practice::Group> Groups;


		//for (map<string, DBTable5*>::iterator tableIter = tables.begin(); tableIter != tables.end(); ++tableIter)
		//{
		//	practice::Group group;
		//	group.SetGroupName(tableIter->first);
		//	//group.SetAmountOfStudents(tableIter->second->GetSize());
		//	vector<Row> tableData = tableIter->second->GetData();
		//	for (Row row : tableData)
		//	{
		//		Header tableHeader = tableIter->second->GetHeader();
		//		practice::Student student;
		//		for (Header::iterator headerIter = tableHeader.begin(); headerIter != tableHeader.end(); ++headerIter)
		//		{
		//			/*cout << headerIter->second.colName << " : " << tableIter->second->valueToString(row, headerIter->second.colName) << endl;*/
		//			/*cout << headerIter->second.colName << " " << headerIter->second.colType << " " << (headerIter->second.colName == "Name") << endl;*/
		//			if (!strcmp(headerIter->second.colName, "ID"))
		//			{
		//				student.SetId(stoul(tableIter->second->valueToString(row, headerIter->second.colName)));
		//			}
		//			else
		//			{
		//				if (!strcmp(headerIter->second.colName, "Name"))
		//				{
		//					student.SetName(tableIter->second->valueToString(row, headerIter->second.colName));
		//				}
		//				else
		//				{
		//					pair<string, size_t> mark;
		//					mark.first = headerIter->second.colName;
		//					mark.second = stoul(tableIter->second->valueToString(row, headerIter->second.colName));
		//					student.AddMark(mark);
		//				}
		//			}
		//		}
		//		group.AddStudent(student);
		//		//student.PrintStudentInfo();
		//	}
		//	Groups.push_back(group);
		//}
		return Groups;
	}

	//map<string, practice::Group> getGroups(DBTableSet5& DB)
	//{
	//	/////////////////////////////////
	//	// TODO: поменять местами парсинг файлов: сначала парсить результаты, а потом к ним добавлять данные о студенте
	//	/////////////////////////////////


	//	//DB.PrintDB5(80);

	//	// Парсинг StudentsFile: получение первичной инфы (имя и ID) о студенте
	//	// и разбиение студентов на группы 
	//	DBTable5* StudentsFile = DB[STUDENTS_LIST];
	//	DBTable5* ResultsFile = DB[RESULTS_LIST];

	//	map<string, practice::Group> Groups;

	//	vector<Row> ResultsFileData = ResultsFile->GetData();

	//	map<string, map<string, size_t>> students; // {id, {discipline, mark}}

	//	for (Row ResultsFileDataIter : ResultsFileData)
	//	{
	//		string id = ResultsFile->valueToString(ResultsFileDataIter, "ID");
	//		string::iterator it = find_if(id.begin(), id.end(), not1(ptr_fun(isspace)));
	//		id.erase(remove(id.begin(), it, ' '), it);
	//		cout << id << endl;
	//		string discipline = ResultsFile->valueToString(ResultsFileDataIter, "discipline");
	//		it = find_if(discipline.begin(), discipline.end(), not1(ptr_fun(isspace)));
	//		discipline.erase(remove(discipline.begin(), it, ' '), it);

	//		size_t mark = stoul(ResultsFile->valueToString(ResultsFileDataIter, "mark"));
	//		students[id][discipline] = mark;
	//		for (auto currentGroup : Groups)
	//		{
	//			map<string, Student> list = currentGroup.second.GetStudentsList();
	//			for (auto student : list)
	//			{
	//				if (student.second.GetId() == id)
	//				{
	//					student.second.AddMark({ discipline, mark });
	//				}
	//			}
	//		}
	//	}

	//	for (pair<string, Group> group : Groups)
	//	{
	//		auto studentsList = group.second.GetStudentsList();
	//		for (auto student : students)
	//		{
	//			group.second.GetStudentsList()[student.first].SetMarks(student.second);
	//		}
	//		Group newGroup(group.second.GetGroupName(), group.second.GetStudentsList());
	//		newGroup.GetStudentsList()["11An471"];
	//	}



	//	vector<Row> StudentsFileData = StudentsFile->GetData();

	//	

	//	for (Row StudentsFileDataIter : StudentsFileData)
	//	{
	//		string groupName = StudentsFile->valueToString(StudentsFileDataIter, "Group");
	//		string::iterator it = find_if(groupName.begin(), groupName.end(), not1(ptr_fun(isspace)));
	//		groupName.erase(remove(groupName.begin(), it, ' '), it);
	//		if (Groups.count(groupName) == 0) // Проверка на существование группы. Если уже есть, новая не создаётся.
	//		{
	//			Group newGroup(groupName);	// Создание новой группы
	//			Groups.insert(pair<string, practice::Group>(groupName, newGroup));
	//		}
	//		
	//		string id = StudentsFile->valueToString(StudentsFileDataIter, "ID");
	//		it = std::find_if(id.begin(), id.end(), not1(ptr_fun(isspace)));
	//		id.erase(remove(id.begin(), it, ' '), it);

	//		string name = StudentsFile->valueToString(StudentsFileDataIter, "Name");
	//		it = std::find_if(name.begin(), name.end(), not1(ptr_fun(isspace)));
	//		name.erase(remove(name.begin(), it, ' '), it);

	//		Student newStudent(groupName, name, id);

	//		Groups[newStudent.GetGroupName()].AddStudent(newStudent);
	//	}

	//	// Парсинг ResultsFile: получение данных об оценках студентов
	//	// и внесение их в базу (это база!).

	//	//for (Row ResultsFileDataIter : ResultsFileData)
	//	//{
	//	//	for (auto currentGroup : Groups)
	//	//	{
	//	//		string id = ResultsFile->valueToString(ResultsFileDataIter, "ID");
	//	//		string::iterator it = find_if(id.begin(), id.end(), not1(ptr_fun(isspace)));
	//	//		id.erase(remove(id.begin(), it, ' '), it);
	//	//		if (currentGroup.second.GetStudentsList().count(id) == 1)
	//	//		{
	//	//			string discipl = ResultsFile->valueToString(ResultsFileDataIter, "discipline");
	//	//			it = find_if(discipl.begin(), discipl.end(), not1(ptr_fun(isspace)));
	//	//			discipl.erase(remove(discipl.begin(), it, ' '), it);

	//	//			size_t mark = stoul(ResultsFile->valueToString(ResultsFileDataIter, "mark"));
	//	//			//string mark = ResultsFile->valueToString(ResultsFileDataIter, "mark");

	//	//			cout << discipl << " " << id << " " << mark << endl;

	//	//			//currentGroup.second.GetStudentsList()[id].AddMark({ "math", 4});
	//	//			 currentGroup.second.GetStudentsList()[id].AddMark(make_pair(discipl, mark));
	//	//			//currentGroup.second.GetStudentsList()[id].PrintStudentInfo();
	//	//		}
	//	//	}
	//	//}

	//	return Groups;
	//}

	map<string, practice::Group> getGroups(DBTableSet5& DB)
	{
		/////////////////////////////////
		// TODO: поменять местами парсинг файлов: сначала парсить результаты, а потом к ним добавлять данные о студенте
		/////////////////////////////////


		DBTable5* StudentsFile = DB[STUDENTS_LIST];
		DBTable5* ResultsFile = DB[RESULTS_LIST];

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
				//cout << group.first << " " << student.second.GetGroupName();
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

			//resultGroups[groupName][id].SetName(name);
			/*map<string, size_t> marks = resultGroups[groupName][id].GetMarks();
			resultGroups[groupName].DeleteStudent(id);

			Student stud(groupName, name, id, marks);
			resultGroups[groupName].AddStudent(stud);*/
			resultGroups[groupName].UpdateStudent(resultGroups[groupName][id], name);
			//resultGroups[groupName].GetStudentsList()[id].SetName(name);
		}

		for (auto group : groups)
		{
			for (auto student : students)
			{
				//cout << group.first << " " << student.second.GetGroupName();
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