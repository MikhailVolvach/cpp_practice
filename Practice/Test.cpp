#include <iostream>
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
	practice::Student student1(1, "Mikhail", marks);
	student1.PrintStudentInfo();
	
	student1.SetId(2);
	student1.PrintStudentInfo();

	student1.SetName("Fyodor");
	student1.PrintStudentInfo();
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
		student.SetId(i);
		student.SetName(to_string(i) + " Name");
		student.SetMarks(marks);
		group1.AddStudent(student);
	}

	group1.PrintGroup();
}

int main()
{
	//setlocale(LC_ALL, "rus");
	system("chcp 1251>nul");

	DBTableSet5 DB(DBNAME);
	DB.ReadDB5();
	//vector<practice::Group> groups = practice::getGroups(DB);

	//practice::V17(DB);

	//StudentMethodsTest();
	GroupsMethodsTest();

	system("pause");
	return 0;
}