//Вариант 17
//Определить по результатам сессии в 1 - ом семестре дисциплину, по которой студенты вашей (второй) группы имеют наименьший средний балл.

#include "practice.h"

string practice::V17(DBTableSet5& DB) {
	map<string, practice::Group> groups = practice::getGroups(DB);

	practice::Group myGroup = groups["IU5-12"];

	map<string, size_t> totalDiscipleScore;

	for (auto student : myGroup.GetStudentsList())
	{
		for (pair<string, size_t> mark : student.second.GetMarks())
		{
			if (mark.first.size())
			{
				totalDiscipleScore[mark.first] += mark.second;
			}
		}
	}
	pair<string, size_t> minimum;
	minimum.first = "";
	minimum.second = 10e6;
	for (auto disciple : totalDiscipleScore)
	{
		if (disciple.second < minimum.second)
		{
			minimum.first = disciple.first;
			minimum.second = disciple.second;
		}
	}

	cout << "Дисциплина с наименьшим средним баллом во второй группе кафедры ИУ5: " << minimum.first << endl;

	return minimum.first;
}
