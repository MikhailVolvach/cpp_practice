#include <iostream>
#include "practice.h"

string practice::V16(map<string, practice::Group> Groups) {
	
	pair<string, size_t> maxScore;
	maxScore.first = "";
	maxScore.second = 0;

	map <string, size_t> GroupAndScore;
	map <string, size_t> totalDisScore;

	for (size_t i = 0; i < 4; i++)
	{
		pair<string, size_t> mark;
		mark.second = 0;
		if (i == 0)
		{
			mark.first = "math";
		}
		if (i == 1)
		{
			mark.first = "nach gem";
		}
		if (i == 2)
		{
			mark.first = "prog";
		}
		if (i == 3)
		{
			mark.first = "ptp";
		}
		totalDisScore.insert(mark);
	}

	for (auto group : Groups) GroupAndScore.insert({ group.first, 0 });

	for (auto group : Groups) {
		for (auto student : group.second.GetStudentsList()) {
			for (pair<string, size_t> mark : student.second.GetMarks()) {
				if (mark.first == "math") totalDisScore["math"] += mark.second;
				else {
					if (mark.first == "nach gem") totalDisScore["nach gem"] += mark.second;
					else {
						if (mark.first == "prog") totalDisScore["prog"] += mark.second;
						else {
							if (mark.first == "ptp") totalDisScore["ptp"] += mark.second;
						}
					}
				}
			}
		}
		GroupAndScore[group.first] = totalDisScore["math"] + totalDisScore["nach gem"] + totalDisScore["prog"] + totalDisScore["ptp"];
		GroupAndScore[group.first] /= group.second.GetAmountOfStudents();
	}

	for (size_t i = 1; i < 4; i++)
	{
		if (GroupAndScore["IU5-1" + to_string(i)] > maxScore.second)
		{
			maxScore.first = "IU5-1" + to_string(i);
			maxScore.second = GroupAndScore["IU5-1" + to_string(i)];
		}
	}
	maxScore.second /= Groups[maxScore.first].GetAmountOfStudents();
	cout << "Лучшая группа кафедры ИУ5: " << maxScore.first << endl;
	return maxScore.first;
}