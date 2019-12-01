#pragma once
#include "game.h"
#include <string>

class Board
{
public:
	int selectAction(const int menu)
	{
		switch (menu)
		{
		case INPUT_ENTER:
			return game.takeTurn();
			break;
		default:
			return game.playTillParticularInning(menu);
			break;
		}
	}

	int startBoard()
	{
		Menu::printMenu();
		std::string input;
		getline(std::cin, input);
		while (!Menu::isValidMenu(input))
		{
			std::cout << "에러: 1에서 6 사이 이닝 혹은 enter를 눌러주세요!";
			getline(std::cin, input);
		} 
		return selectAction(atoi(input.c_str()));
	}

	void readBoard(int isEnded)
	{
		std::cout << "+-------------------------------- +" << std::endl;
		renderScore();
		std::cout << "+-------------------------------- +" << std::endl;
		renderPlayers();
		renderTotalStatistics();
		if (isEnded)
		{
			exit(0);
		}
	}

	std::string teamScoreToString(Team& team)
	{
		std::string result = "| " + team.getName();
		int* teamScoreHistory = team.getTeamScoreHistory();
		for (int i = 1; i <= Game::INNING_LIMIT; i++)
		{
			result = result + " " + std::to_string(teamScoreHistory[i - 1]) + "     ";
		}
		result += "|    " + std::to_string(team.getTeamTotalScore()) + "     |";
		return result;
	}

	void renderScore()
	{
		std::cout << "|      1      2      3      4      5      6    |    TOT    |" << std::endl;
		std::cout << teamScoreToString(game.getTeam1()) << std::endl;
		std::cout << teamScoreToString(game.getTeam2()) << std::endl;
	}

	std::string teamPlayersToString(Team& team1, Team& team2)
	{
		std::string result = "";
		Player* team1Players = team1.getTeamPlayers();
		Player* team2Players = team2.getTeamPlayers();
		for (int i = 0; i < TEAM_NUMBER_LIMITS; i++)
		{
			result += "|" + team1Players[i].getName() + team1Players[i].readHistory() + "                                                        " + team2Players[i].readHistory()  + team2Players[i].getName() + "|\n";
		}
		return result;
	}

	void renderPlayers()
	{
		std::cout << "|                                                          |" << std::endl;
		std::cout << "|" + game.getTeam1().getName() + "                                                  " + game.getTeam2().getName() + "|" << std::endl;
		std::cout << teamPlayersToString(game.getTeam1(), game.getTeam2()) << std::endl;
	}

	std::string teamStatisticsToString(Team& team1, Team& team2)
	{
		std::string result = "";
		result += "|투구: " + std::to_string(team1.readTeamTotalThrow()) + "                                             " + std::to_string(team2.readTeamTotalThrow())+ "\n" +
		+ "|안타: "+ std::to_string(team1.readTeamTotalHit()) + "                                             " + std::to_string(team2.readTeamTotalHit())+ "\n" +
		+ "|삼진: " + std::to_string(team1.readTeamTotalOut()) + "                                             " + std::to_string(team2.readTeamTotalOut());
		return result;
	}

	void renderTotalStatistics()
	{
		std::cout << "|                                                             |" << std::endl;
		std::cout << teamStatisticsToString(game.getTeam1(), game.getTeam2()) << std::endl;
		std::cout << "+-----------------------------------------------------------------+" << std::endl;
	}

private:
	Game game;
	static constexpr int INPUT_ENTER = 0;
	constexpr static int TEAM_NUMBER_LIMITS = 5;
};