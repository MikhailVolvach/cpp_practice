//������� 17
//���������� �� ����������� ������ � 1 - �� �������� ����������, �� ������� �������� ����� (������) ������ ����� ���������� ������� ����.

#include "practice.h"

//string practice::V17(DBTableSet5& DB) {
//	vector<practice::Group> groups = practice::getGroups(DB);
//
//	practice::Group myGroup = groups[1];
//
//	//cout << myGroup.GetGroupName() << endl;
//	map<string, size_t> totalDiscipleScore;
//
//	for (auto mark : myGroup.GetStudentsList()[1].GetMarks())
//	{
//		if (mark.first.size())
//		{
//			pair<string, size_t> disciple;
//			disciple.first = mark.first;
//			disciple.second = 0;
//		}
//	}
//
//	for (Student student : myGroup.GetStudentsList())
//	{
//		for (pair<string, size_t> mark : student.GetMarks())
//		{
//			if (mark.first.size())
//			{
//				totalDiscipleScore[mark.first] += mark.second;
//			}
//		}
//	}
//	pair<string, size_t> minimum;
//	minimum.first = "";
//	minimum.second = 10e6;
//	for (auto disciple : totalDiscipleScore)
//	{
//		if (disciple.second < minimum.second)
//		{
//			minimum.first = disciple.first;
//			minimum.second = disciple.second;
//		}
//	}
//
//	cout << "Minimum (" << minimum.second << ") : " << minimum.first << endl;
//
//	return minimum.first;
//}