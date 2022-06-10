#include "practice.h"

void test()
{
	practice::Student stud;

	stud.GetName();
}

practice::Group findStudent(string ID, map<string, practice::Group> groups)
{
	for (auto group : groups)
	{
		if (group.second.GetStudentsList().count(ID))
		{
			return group.second;
		}
	}
	exit(INCORRECT_INPUT);
}

int menu()
{
	cout	<< "================= МАКЕТ СУБД ===================" << endl
			<< "\t1 - Чтение БД из файла" << endl
			<< "\t2 - Печать БД" << endl
			<< "\t3 - Печать сгруппированных таблиц" << endl
			<< "\t4 - Запись БД в файл" << endl
			<< "\t5 - Запись сгруппированных таблиц в файлы" << endl
			<< "\t6 - Зарегистрировать студента" << endl
			<< "\t7 - Удалить студента из таблицы" << endl
			<< "\t8 - Печать информации о студенте" << endl
			<< "\t9 - Определить дисциплину с наименьшим средним баллом во второй группе кафедры ИУ5" << endl
			<< "\t10 - Определить лучшую группу кафедры ИУ5" << endl
			<< "\t100 - Выход" << endl;
	int choice;
	cout << "Выберите действие\n";
	cin >> choice;
	while (cin.fail()) {
		cout << "Ошибка ввода. Повторите ввод\n";
		cin.clear();
		cin.ignore(10, '\n');
		cin >> choice;
	}
	return choice;
}

void printGroups(map<string, practice::Group> groups)
{
	for (auto group : groups)
	{
		group.second.PrintGroup();
	}
}
void writeGroups(map<string, practice::Group> groups)
{
	for (auto group : groups)
	{
		group.second.WriteGroupToFile();
	}

	cout << "======== Запись в файл завершена =========" << endl;
}

void WriteDB(DBTableSet5& DB, map<string, practice::Group> groups)
{
	DBTable5* StudentsFile = DB[STUDENTS_LIST];
	DBTable5* ResultsFile = DB[RESULTS_LIST];

	ofstream StudentsFILE(PATH + STUDENTS_LIST + ".txt");
	StudentsFILE << STUDENTS_LIST << "|" << STUDENTS_LIST << endl;
	StudentsFILE << "Group|String|8|ID|String|8|Name|String|15" << endl;

	for (auto group : groups)
	{
		for (pair<string, practice::Student> student : group.second.GetStudentsList())
		{
			StudentsFILE << setw(8) << group.first << "|" << setw(8) << student.second.GetId() << "|" << setw(15) << student.second.GetName() << "\n";
		}
	}
	StudentsFILE.close();

	ofstream ResultsFILE(PATH + RESULTS_LIST + ".txt");
	ResultsFILE << RESULTS_LIST << "|" << RESULTS_LIST << endl;
	ResultsFILE << "Group|String|8|ID|String|8|discipline|String|12|mark|Int32|8" << endl;

	for (auto group : groups)
	{
		for (pair<string, practice::Student> student : group.second.GetStudentsList())
		{
			for (auto mark : student.second.GetMarks())
			{
				ResultsFILE << setw(8) << group.first << "|" << setw(8) << student.second.GetId() << "|" << setw(12) << mark.first << "|" << setw(8) << mark.second << "\n";
 			}
		}
	}

	cout << "======== Запись в файл завершена =========" << endl;
}

void registerNewUser(map<string, practice::Group>& groups)
{
	practice::Student student;
	string surname;
	string groupName;
	cout << "Введите фамилию студента: "; cin >> surname;
	student.SetName(surname);
	cout << "Введите номер группы студента: "; cin >> groupName;
	student.SetGroupName(groupName);
	string ID = groupName.substr(groupName.find_last_of('-') + 1) + surname.substr(surname.find_last_of(' ') + 1, 1) + surname.substr(surname.size() - 1) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
	student.SetId(ID);
	char answer;
	cout << "Ввести оценки? (y/n) "; cin >> answer;
	
	if (answer != 'n')
	{
		map<string, size_t> marks;
		pair<string, size_t> mark;
		do
		{
			cout << "Введите название предмета (. - отмена): "; cin >> mark.first;
			if (mark.first != ".")
			{
				cout << "Введите оценку: "; cin >> mark.second;
				marks.insert(mark);
			}
		} while (mark.first != ".");
		if (marks.size())
		{
			student.SetMarks(marks);
		}
	}
	if (groups.count(groupName) == 0)
	{
		practice::Group newGroup(groupName);
		newGroup.AddStudent(student);
		groups.insert({ newGroup.GetGroupName(), newGroup });
	}
	else
	{
		groups[groupName].AddStudent(student);
	}

	cout << "========= Успешная регистрация ===========" << endl;
}

void deleteStudentFromTable(map<string, practice::Group>& groups)
{
	printGroups(groups);
	string ID;
	cout << "Введите ID студента: "; cin >> ID;
	practice::Group group = findStudent(ID, groups);
	group.DeleteStudent(ID);
	groups.erase(group.GetGroupName());
	groups.insert({ group.GetGroupName(), group });
	cout << "========Студент удалён=======" << endl;
	printGroups(groups);
}

void printStudentInfo(map<string, practice::Group> groups)
{
	printGroups(groups);
	string ID;
	cout << "Введите ID студента: "; cin >> ID;
	practice::Group group = findStudent(ID, groups);
	group[ID].PrintStudentInfo();
}

int main()
{
	system("chcp 1251>nul");

	DBTableSet5 DB(DBNAME);
	if (!DB.GetDBName().size())
	{
		cout << "Не удалось открыть файл DBTables.txt";
		exit(UNABLE_TO_OPEN_FILE);
	}
	map<string, practice::Group> groups;
	map<string, practice::Group> tmpGroups;
	while (true)
	{
		switch (menu())
		{
		case 1:
			DB.ReadDB5();
			tmpGroups = groups;
			groups = practice::getGroups(DB);
			for (auto tmp : tmpGroups)
			{
				groups.insert(tmp);
			}
			cout << "========== Считывание завершено ==========" << endl;
			break;
		case 2:
			DB.PrintDB5(SCREEN_WIDTH);
			break;
		case 3:
			printGroups(groups);
			break;
		case 4:
			WriteDB(DB, groups);
			break;
		case 5:
			writeGroups(groups);
			break;
		case 6:
			registerNewUser(groups);
			break;
		case 7:
			deleteStudentFromTable(groups);
			break;
		case 8:
			printStudentInfo(groups);
			break;
		case 9:
			practice::V17(DB);
			break;
		case 10:
			practice::V16(groups);
			break;
		
		case 100:
			return 0;
			break;
			
		default:
			cout << "Недопустимое действие. Повторите выбор\n";
			break;
		}
	}

	system("pause");
	return 0;
}