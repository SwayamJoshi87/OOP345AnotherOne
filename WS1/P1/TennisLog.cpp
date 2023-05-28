#include "TennisLog.h"
#include <string>

namespace sdds {

	

	std::ostream& operator<<(std::ostream& os, const TennisMatch match)
	{
		if (match.isEmpty()) {
			std::cout << "Empty Match";
		}
		else {
			std::cout << std::right << std::setfill('.') << std::setw(20) << "Tourney ID" << " : " << std::left << std::setw(30) << match.tournamentID << std::endl;
			std::cout << std::right << std::setfill('.') << std::setw(20) << "Match ID" << " : " << std::left << std::setw(30) << match.matchID << std::endl;
			std::cout << std::right << std::setfill('.') << std::setw(20) << "Tourney" << " : " << std::left << std::setw(30) << match.tournamentName << std::endl;
			std::cout << std::right << std::setfill('.') << std::setw(20) << "Winner" << " : " << std::left << std::setw(30) << match.winner << std::endl;
			std::cout << std::right << std::setfill('.') << std::setw(20) << "Loser" << " : " << std::left << std::setw(30) << match.loser << std::endl;
		}
		return os;
	}

	bool TennisMatch::isEmpty()const {
		return tournamentID.empty();
	}

	//Defualt constructor
	TennisLog::TennisLog() {
		//set everything to empty state
		count = 0;
		matches = nullptr;
	}


	//Constructor with filename
	TennisLog::TennisLog(const char* filename) {
		//open file
		std::ifstream file(filename);
		
		//count the number of lines excluding the first one
		std::string line;
		
		while (std::getline(file, line)) {
			count++;
		}
		//First line not included
		--count;

		//allocate memory for the matches
		matches = new TennisMatch[count];

		//read from the file to the matches array
		file.clear();
		file.seekg(1, std::ios::beg);
		std::getline(file, line); //First line is not needed

		size_t counter = 0;
		while (std::getline(file, line) && counter < count) {
			
			//get the tournament ID
			matches[counter].tournamentID = line.substr(0, line.find(',')); //it reads until the first comma
			line.erase(0, line.find(',') + 1); //erase the part that was read
			//get the tournament name
			matches[counter].tournamentName = line.substr(0, line.find(',')); 
			line.erase(0, line.find(',') + 1);
			//get the match ID
			matches[counter].matchID = std::stoi(line.substr(0, line.find(',')));
			line.erase(0, line.find(',') + 1);
			//get the winner
			matches[counter].winner = line.substr(0, line.find(','));
			line.erase(0, line.find(',') + 1);
			//get the loser, current to the end of the string
			matches[counter].loser = line;
			++counter;
		}
	}



	//Find matches
	TennisLog TennisLog::findMatches(const std::string playername) const {
		//create a new TennisLog object
		TennisLog newLog;
		//loop through the matches array
		for (size_t i = 0; i < count; i++) {
			//check if the player name is the same as the winner or loser
			if (matches[i].winner == playername || matches[i].loser == playername) {
				//add the match to the new TennisLog object
				newLog.addMatch(matches[i]);
			}
		}
		return newLog;
	}
	
	//add match
	void TennisLog::addMatch(TennisMatch& match) {
		//create a new array with one more 
		TennisMatch* temp = new TennisMatch[count + 1];

		//copy the elements from the old array to the new one
		if (matches != nullptr) {
			for (size_t i = 0; i < count; i++) {
				temp[i] = matches[i];
			}
			temp[count] = match;
			//delete the old array
			delete[] matches;
			//set the old array to the new one
			
			//add the new match to the array
			count++;
		}
		else {
			//matches = new TennisMatch[1];
			temp[0] = match;
			count = 1;
		}
		matches = temp;
	}

	TennisMatch TennisLog::operator[](size_t idx) const {
		//check if the index is valid
		TennisMatch emptyMatch;
		if (idx >= count) {
			return emptyMatch;
		}
		return matches[idx];
	}
	TennisLog::operator size_t() const {
		return count;
	}

	TennisLog::~TennisLog() {
		if (matches != nullptr) {
			delete[] matches;
			matches = nullptr;
		}
	}
};