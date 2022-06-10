//������� 17
//���������� �� ����������� ������ � 1 - �� �������� ����������, �� ������� �������� ����� (������) ������ ����� ���������� ������� ����.

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

	cout << "���������� � ���������� ������� ������ �� ������ ������ ������� ��5: " << minimum.first << endl;

	return minimum.first;
}
