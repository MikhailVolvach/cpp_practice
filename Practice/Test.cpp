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

int main()
{
	//setlocale(LC_ALL, "rus");
	system("chcp 1251>nul");

	DBTableSet5 DB(DBNAME);
	DB.ReadDB5();
	//vector<practice::Group> groups = practice::getGroups(DB);

	practice::V17(DB);

	system("pause");
	return 0;
}