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

int menu()
{
	cout	<< "================= МАКЕТ СУБД ===================" << endl
			<< "\t1 - Чтение БД из файла" << endl
			<< "\t2 - Печать БД" << endl
			<< "\t3 - Печать сгруппированных таблиц" << endl
			<< "\t4 - Запись БД в файл" << endl
			<< "\t5 - Запись сгруппированных таблиц в файлы" << endl
			<< "\t6 - Зарегистрировать студента" << endl
			<< "\t7 - Определить дисциплину с наименьшим средним баллом" << endl
			<< "\t8 - Определить лучшую группу кафедры ИУ5" << endl
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
		student.SetMarks(marks);
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
	while (true)
	{
		switch (menu())
		{
		case 1:
			DB.ReadDB5();
			groups = practice::getGroups(DB);
			cout << groups.size() << endl;
			cout << "========== Считывание завершено ==========" << endl;
			break;
		case 2:
			DB.PrintDB5(SCREEN_WIDTH);
			break;
		case 3:
			pringGroups(groups);
			break;
		case 4:
			WriteDB(DB, groups);
			cout << "======== Запись в файл завершена =========" << endl;
			break;
		case 5:
			writeGroups(groups);
			cout << "======== Запись в файл завершена =========" << endl;
			break;
		case 6:
			registerNewUser(groups);
			cout << "========= Успешная регистрация ===========" << endl;
			break;
		case 7:
			practice::V17(DB);
			break;
		case 8:
			practice::V16(groups);
			break;
		case 9:
			test();
			break;
		case 10:
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