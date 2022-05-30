#include "practice.h"

void createStudentsListFile(DBTableSet5 &DB) {
	vector<practice::Group> groups = practice::getGroups(DB);

	ofstream File("../PracticeDBTxt/Students-list.txt");

	//Первая строка
	File << "Students-list|Students-list" << endl;
	//Вторая строка
	File << "Group|String|8|ID|String|8|Name|String|15" << endl;

	//Студенты
	for (practice::Group group : groups)
	{
		for (practice::Student student : group.GetStudentsList())
		{
			File << setw(8 - group.GetGroupName().size()) << setfill(' ') << group.GetGroupName() << "|";
			string ID = group.GetGroupName().substr(group.GetGroupName().find_last_of('-') + 1) + student.GetName().substr(student.GetName().find_last_of(' ') + 1, 1) + student.GetName().substr(student.GetName().size() - 1) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
			File << setw(8 - ID.size()) << ID << "|";
			File << setw(15) << student.GetName().substr(student.GetName().find_last_of(' ') + 1) << endl;
		}
	}
}