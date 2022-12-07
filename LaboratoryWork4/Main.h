#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


enum InfoSettings {
    MENU_PLAYER_CHECK = 1,
    MENU_GAME_CHECK,
    MENU_TOP_ACHIEVEMENTS_CHECK,
    MENU_ALL_ACHIEVEMENTS_CHECK,
    MENU_EXIT,

    TYPE_BEGINNER = 10,
    TYPE_INTERMEDIATE,
    TYPE_EXPERT,
    TYPE_CUSTOM,
};

enum Achievements {
    ALL_ACHIEVEMENTS = 100,
    PLAYED_HOURS_500,
    GAME_80x80x999,
    GAME_EXPERT_WITH_100_EFF,
    WON_250_GAMES_IN_24_HOURS,
    COMPLETE_BEGINNER_IN_5_SEC,
    COMPLETE_INTER_IN_50_SEC,
    COMPLETE_EXPERT_IN_150_SEC,
    WIN_STREAK_50_BEGINNER,
    WIN_STREAK_25_INTER,
    WIN_STREAK_10_EXPERT,
};


struct PlayerInfo
{
    string nickname; // ник одновременно выступает и в роли логина
    string password;
    int gamesPlayedAmount;
    int winsAmount;
    int hoursInGameAmount;
    short int achievementsComplete;
};


struct TopAchievements
{
    short int year;
    short int first_achievement;
    short int second_achievement;
    short int third_achievement;
};


void startMenu();

void playerViewAuthorization();
void playerView(struct PlayerInfo player);

void gameViewMenu();

void achievementView(int ID);
void topAchievementsViewMenu();
void topAchievementsView(struct TopAchievements &top);