#include <iostream>
#include "practice.h"

void testing() {
	//DBTableTxt5 db;
	//db.ReadDBTable5(path + "IU5-11.txt");
	//Header header = db.GetHeader();

	/*for (Header::iterator iter = header.begin(); iter != header.end(); ++iter)
	{
		cout << iter->second.colName << " " << iter->second.colType << " " << iter->second.length << endl;
	}*/
	//db.PrintTable5(SCREEN_WIDTH);

	DBTableSet5 DB(DBNAME);
	DB.ReadDB5();
	DB.PrintDB5(SCREEN_WIDTH);
}

vector<practice::Group> getGroups(DBTableSet5& DB) 
{
	map<string, DBTable5*> tables = DB.GetDB();

	const int NUMBER_OF_GROUPS = tables.size();
	vector<practice::Group> Groups;

	for (map<string, DBTable5*>::iterator tableIter = tables.begin(); tableIter != tables.end(); ++tableIter)
	{
		practice::Group group;
		group.SetGroupName(tableIter->first);
		group.SetAmountOfStudents(tableIter->second->GetSize());
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
					if(!strcmp(headerIter->second.colName, "Name"))
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
			student.PrintStudentInfo();
		}
		Groups.push_back(group);
	}
	return Groups;
}

int main()
{
	//setlocale(LC_ALL, "rus");
	system("chcp 1251>nul");

	DBTableSet5 DB(DBNAME);
	DB.ReadDB5();
	vector<practice::Group> groups = getGroups(DB);



	system("pause");
	return 0;
}