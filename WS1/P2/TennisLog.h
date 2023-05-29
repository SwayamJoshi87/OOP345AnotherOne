#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

namespace sdds {

	struct TennisMatch {
		std::string tournamentID = "";
		std::string tournamentName = "";
		//Using unsigned here as it is specifically mentioned to use a positive number
		size_t matchID = 0;
		std::string winner = "";
		std::string loser = "";

	
		//overload the insertion operator 
		friend std::ostream& operator<<(std::ostream& os, const TennisMatch match);

		//Check if the Match is empty
		bool isEmpty() const;	
	};

	class TennisLog {
		size_t count = 0;
		TennisMatch* matches = nullptr;

	public:
		TennisLog();
		TennisLog(const char* filename);
		void addMatch(TennisMatch& match);
		TennisLog findMatches(const std::string playername) const;
		TennisMatch operator[](size_t idx) const;
		operator size_t() const;
		~TennisLog();

		//Copy constructor
		TennisLog(const TennisLog& src);
		//Copy assignment operator
		TennisLog& operator=(const TennisLog& src);
		//Move constructor
		TennisLog(TennisLog&& src);
		//Move assignment operator
		TennisLog& operator=(TennisLog&& src);

	};

};
#endif // !SDDS_TENNISLOG_H





