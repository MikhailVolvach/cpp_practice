//#include "practice.h"
//
//void createStudentsListFile(DBTableSet5 &DB) {
//	map<string, practice::Group> groups = practice::getGroups(DB);
//
//	ofstream File("../PracticeDBTxt/Students-list.txt");
//
//	//Первая строка
//	File << "Students-list|Students-list" << endl;
//	//Вторая строка
//	File << "Group|String|8|ID|String|8|Name|String|15" << endl;
//
//	//Студенты
//	for (auto group : groups)
//	{
//		for (auto student : group.second.GetStudentsList())
//		{
//			File << setw(8 - group.second.GetGroupName().size()) << setfill(' ') << group.second.GetGroupName() << "|";
//			string ID = group.second.GetGroupName().substr(group.second.GetGroupName().find_last_of('-') + 1) + student.second.GetName().substr(student.second.GetName().find_last_of(' ') + 1, 1) + student.second.GetName().substr(student.second.GetName().size() - 1) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
//			File << setw(8 - ID.size()) << ID << "|";
//			File << setw(15) << student.second.GetName().substr(student.second.GetName().find_last_of(' ') + 1) << endl;
//		}
//	}
//}
