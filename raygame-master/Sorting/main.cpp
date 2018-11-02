#include "HighScoreTable.h"
#include "MergeSort.h"
#include <vector>
#include <iostream>

int main() {
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highscores.txt");
	//std::cout << hst.hsVector.at(hst.hsVector.size - 1).Name << std::endl;

	//retrieve the top 10 scores
	//std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them


	//prune the bottom 3 scores from the table
	//hst.pruneBottomNNScores(3);

	//retrieve the top 10 scores
	//std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them

	//int Array[] = { 1,4,2,5 };
	//MergeSort(&hst.hsVector, 0, hst.hsVector.size() - 1);
	//MergeSort(Array, 0, 3);

	hst.LocalMergeSort();
	return 0;
}