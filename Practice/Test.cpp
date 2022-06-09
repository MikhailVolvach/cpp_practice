#include "practice.h"

//void testing() {
//	//DBTableTxt5 db;
//	//db.ReadDBTable5(path + "IU5-11.txt");
//	//Header header = db.GetHeader();
//
//	/*for (Header::iterator iter = header.begin(); iter != header.end(); ++iter)
//	{
//		cout << iter->second.colName << " " << iter->second.colType << " " << iter->second.length << endl;
//	}*/
//	//db.PrintTable5(SCREEN_WIDTH);
//
//	DBTableSet5 DB(DBNAME);
//	DB.ReadDB5();
//	//DB.PrintDB5(SCREEN_WIDTH);
//}

void test()
{
	practice::Student stud;

	stud.GetName();
}

void StudentMethodsTest()
{
	map<string, size_t> marks;
	pair<string, size_t> mark;
	mark.first= "math";
	mark.second = 4;
	marks.insert(mark);
	mark.first = "nachert";
	mark.second = 5;
	marks.insert(mark);
	practice::Student student1("IU5-11", "Mikhail", "ffffff");
	//student1.PrintStudentInfo();
	
	student1.AddMark({ "inzh", 4 });
	student1.PrintStudentInfo();

	//student1.SetId(2);
	//student1.PrintStudentInfo();

	/*student1.SetName("Fyodor");
	student1.PrintStudentInfo();*/
}

void GroupsMethodsTest()
{
	practice::Group group1;
	vector<practice::Student> studentsList;
	group1.SetGroupName("IU7-22");
	for (size_t i = 1; i < 4; i++)
	{
		practice::Student student;
		map<string, size_t> marks;
		pair<string, size_t> mark;
		mark.first = "math";
		mark.second = 4;
		marks.insert(mark);
		//student.SetId(i);
		student.SetName(to_string(i) + " Name");
		//student.SetMarks(marks);
		group1.AddStudent(student);
	}

	group1.PrintGroup();
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
			<< "\t7 - Изменить данные студента" << endl
			<< "\t8 - Удалить студента из таблицы" << endl
			<< "\t9 - Печать информации о студенте" << endl
			<< "\t10 - Определить дисциплину с наименьшим средним баллом" << endl
			<< "\t11 - Определить лучшую группу кафедры ИУ5" << endl
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

int changeStudentMenu()
{
	cout << "======== Изменение данных пользователя =========" << endl
		<< "\t1 - Напечатать информацию о студенте" << endl
		<< "\t2 - Изменить имя студента" << endl
		<< "\t3 - Перевести студента в другую группу" << endl
		<< "\t4 - Перезаполнить список оценок студента" << endl
		<< "\t10 - Выход" << endl;
		
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

void pringGroups(map<string, practice::Group> groups)
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
}

void changeStudentData(map<string, practice::Group> groups)
{
	practice::Student tmpStudent;
	string studentID;
	string inputString;
	int inputNum;

	map<string, size_t> marks;
	pair<string, size_t> mark;

	cout << "Введите ID студента: "; cin >> studentID;
	practice::Group group = findStudent(studentID, groups);
	while (true)
	{
		switch (changeStudentMenu())
		{
		case 1:
			group[studentID].PrintStudentInfo();
			break;
		case 2: /*Изменение имени студента*/
			cout << "Введите новое имя студента: "; cin >> inputString;
			group[studentID].SetName(inputString);
			group.UpdateStudent(group[studentID], inputString);
			group[studentID].PrintStudentInfo();
			break;
		case 3: /*Изменение номера группы студента*/
			cout << "Введите новый номер группы студента: "; cin >> inputString;
			tmpStudent = group[studentID];
			tmpStudent.SetGroupName(inputString);
			group.UpdateStudent(tmpStudent, tmpStudent.GetName());
			//group.DeleteStudent(studentID);
			//groups[inputString].AddStudent(tmpStudent);
			groups[inputString][studentID].PrintStudentInfo();
			break;
		case 4: /*Изменение списка оценок*/
			do
			{
				cout << "Введите название предмета (. - отмена): "; cin >> mark.first;
				if (mark.first != ".")
				{
					cout << "Введите оценку: "; cin >> mark.second;
					marks.insert(mark);
				}
			} while (mark.first != ".");
			//tmpStudent = group[studentID];
			tmpStudent = {group[studentID].GetGroupName(), group[studentID].GetName(), studentID, marks};
			//tmpStudent.SetMarks(marks);
			group.DeleteStudent(studentID);
			group.AddStudent(tmpStudent);
			//group.UpdateStudent(tmpStudent, tmpStudent.GetName());
			//group[studentID].SetMarks(marks);

			group[studentID].PrintStudentInfo();
			break;
		case 10:
			return;
		default:
			break;
		}
	}
}

int main()
{
	//setlocale(LC_ALL, "rus");
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
		case 1: /*Чтение БД из файла*/
			DB.ReadDB5();
			tmpGroups = groups;
			groups = practice::getGroups(DB);
			for (auto tmp : tmpGroups)
			{
				groups.insert(tmp);
			}
			cout << groups.size() << endl;
			cout << "========== Считывание завершено ==========" << endl;
			break;
		case 2: /*Печать БД*/
			DB.PrintDB5(SCREEN_WIDTH);
			break;
		case 3: /*Печать сгруппированных таблиц*/
			pringGroups(groups);
			break;
		case 4: /*Запись БД в файл*/
			WriteDB(DB, groups);
			cout << "======== Запись в файл завершена =========" << endl;
			break;
		case 5: /*Запись сгруппированных таблиц в файлы*/
			writeGroups(groups);
			cout << "======== Запись в файл завершена =========" << endl;
			break;
		case 6: /*Зарегистрировать студента*/
			registerNewUser(groups);
			cout << "========= Успешная регистрация ===========" << endl;
			break;
		case 7: /*Изменить данные студента*/
			changeStudentData(groups);
			break;
		case 8: /*Удалить студента из таблицы*/
			break;
		case 9: /*Печать информации о студенте*/

			break;
		case 10:
			practice::V17(DB);
			break;
		case 11:
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
	

	
	//DB.ReadDB5();
	//map<string, practice::Group> groups = practice::getGroups(DB);

	system("pause");
	return 0;
}