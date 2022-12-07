#include "Main.h"

/* Структуры и взаимодействия с ними на тему игры "Сапёр";
   game - не конкретно сапёр, а "карты" в нём;
   
   "аккаунты" для авторизации: 1) Volko, Qwerty123;
                               2) Dr.Drain, password;
                               3) RandomNickname123, random;
*/


class GameInfo {
    short int m_width;
    short int m_height;
    short int m_mineAmount;
    int m_clicksAmount;
    double m_gameTimeSec;

public:
    int m_inMenuID;

    GameInfo(int inMenuID, short int width, short int height, short int mineAmount, int clicksAmount, double gameTimeSec)
    {
        m_inMenuID = inMenuID;
        m_width = width;
        m_height = height;
        m_mineAmount = mineAmount;
        m_clicksAmount = clicksAmount;
        m_gameTimeSec = gameTimeSec;
    }

    void createGIMenuItem() {
        cout << m_inMenuID << ") Гра, пройдена за " << m_gameTimeSec
            << " секунди та " << m_clicksAmount << " клiкiв." << endl;
    }

    string gameTypeIdentify() {
        int m_gameTypeID;
        string m_gameType;
        if (m_width == 10 && m_height == 10 && m_mineAmount == 10) {
            m_gameTypeID = TYPE_BEGINNER;
            m_gameType = "Новачок";
        }
        else if (m_width == 16 && m_height == 16 && m_mineAmount == 40) {
            m_gameTypeID = TYPE_INTERMEDIATE;
            m_gameType = "Любитель";
        }
        else if (m_width == 30 && m_height == 16 && m_mineAmount == 99) {
            m_gameTypeID = TYPE_EXPERT;
            m_gameType = "Професiонал";
        }
        else {
            m_gameTypeID = TYPE_CUSTOM;
            m_gameType = "Користувацький";
        }
        return m_gameType;
    }

    void gameView();
};



// функция, которая проверяет корректный ввод
template <typename T>
T cin_checker(T &cinNumber) {
    cin >> cinNumber;
    while (1 == 1) {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Помилка!\nВведiть правильно: ";
            cin >> cinNumber;
        }
        else {
            cin.ignore(32767, '\n');
            break;
        }
    }
    return cinNumber;
}


void startMenu() {
    short int selectedMenuItem;
    cout << "Виберiть пункт меню:\n"
        << "1. Подивитися iнформацiю про користувача.\n"
        << "2. Подивитися iнформацiю про гру.\n"
        << "3. Подивитися топ-3 найчастiше виконуваних досягнень за рiк.\n"
        << "4. Подивитися список усiх iснуючих досягнень.\n"
        << "5. Вихiд iз меню." << endl;

    cin_checker(selectedMenuItem);

    switch (selectedMenuItem) {
    case MENU_PLAYER_CHECK:
        playerViewAuthorization();
        break;

    case MENU_GAME_CHECK:
        gameViewMenu();
        break;

    case MENU_TOP_ACHIEVEMENTS_CHECK:
        topAchievementsViewMenu();
        break;

    case MENU_ALL_ACHIEVEMENTS_CHECK:
        achievementView(ALL_ACHIEVEMENTS);
        break;

    case MENU_EXIT:
        cout << "Виконується вихiд..." << endl;
        exit(0);

    default:
        cout << "Такого пункту немає. Виконується вихiд iз програми..." << endl;
        exit(0);
    }
}


void playerViewAuthorization() {
    PlayerInfo player1 = { "Volko", "Qwerty123", 10844, 2631, 2194, 10 };
    PlayerInfo player2 = { "Dr.Drain", "password", 358, 48, 106, 3 };
    PlayerInfo player3 = { "RandomNickname123", "random", 7, 1, 2, 0 };

    string cin_login;
    cout << "\nЩоб отримати доступ до iнформацiї, авторизуйтеся."
        << "\nВведiть логiн: " << endl;

    for (int counter = 1; ; counter++) {

        cin_checker(cin_login);

        if (cin_login == player1.nickname
            || cin_login == player2.nickname
            || cin_login == player3.nickname) break;

        else cout << "Неправильний логiн (" << counter << " спроба), спробуйте ще раз." << endl;
    }

    string cin_password;
    cout << "\nВiтаю, " << cin_login << ", теперь пiдтвердiть, що це ви." << endl;

    for (int counter = 1; ; counter++) {

        cin_checker(cin_password);

        if (cin_login == player1.nickname && cin_password == player1.password) {
            playerView(player1);
            break;
        }
        else if (cin_login == player2.nickname && cin_password == player2.password) {
            playerView(player2);
            break;
        }
        else if (cin_login == player3.nickname && cin_password == player3.password) {
            playerView(player3);
            break;
        }

        else cout << "Неправильний пароль (" << counter << " спроба), спробуйте ще раз." << endl;
    }
}


void playerView(struct PlayerInfo player) {
    cout << "\nВи успiшно авторизувалися.\n" << endl;

    cout << "Ваш нiкнейм: " << player.nickname
         << "\nКiлькiсть зiграних iгор: " << player.gamesPlayedAmount
         << "\nКiлькiсть перемог: " << player.winsAmount
         << "\nКiлькiсть годин, проведених в iграх: " << player.hoursInGameAmount
         << "\nКiлькiсть виконаних досягнень: " << player.achievementsComplete << endl;
}


void gameViewMenu() {
    GameInfo game1{ 1, 10, 10, 10, 14, 7.5 };
    GameInfo game2{ 2, 16, 16, 40, 116, 46.8 };
    GameInfo game3{ 3, 30, 16, 99, 359, 186.6 };
    GameInfo game4{ 4, 5, 40, 12, 59, 31.2 };
    short int selectedMenuItem;

    cout << "\nВиберiть одну з цих iгор:" << endl;
    game1.createGIMenuItem();
    game2.createGIMenuItem();
    game3.createGIMenuItem();
    game4.createGIMenuItem();

    cin_checker(selectedMenuItem);

    if (selectedMenuItem == game1.m_inMenuID)
        game1.gameView();
    else if (selectedMenuItem == game2.m_inMenuID)
        game2.gameView();
    else if (selectedMenuItem == game3.m_inMenuID)
        game3.gameView();
    else if (selectedMenuItem == game4.m_inMenuID)
        game4.gameView();
    else cout << "Такої гри не iснує." << endl;
}


void GameInfo::gameView() {
    double clicksForSecond = m_clicksAmount / m_gameTimeSec;

    cout << "\nВи вибрали гру пiд номером " << m_inMenuID << "." << endl
        << "Розмiр iгрового поля: " << m_width << "x" << m_height << "x" << m_mineAmount << ";" << endl
        << "Тип гри:  " << gameTypeIdentify() << ";" << endl
        << "Кiлькiсть клiкiв: " << m_clicksAmount << " зi швидкiстю " 
        << setprecision(4) << clicksForSecond << " клiк/с;" << endl
        << "Гра пройдена за " << m_gameTimeSec << " секунд." << endl;
}


void achievementView(int achievementID) {

    switch (achievementID) {
    case ALL_ACHIEVEMENTS:
        cout << "\nСписок усiх iснуючих досягнень:" << endl;
           
    case PLAYED_HOURS_500:
        cout << "Провести в усiх iграх загалом 500 годин." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case GAME_80x80x999:
        cout << "Виграти гру з найбiльшим iгровим полем (80x80) та найбiльшою кiлькiстю мiн (999)." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case GAME_EXPERT_WITH_100_EFF:
        cout << "Виграти гру типу \"Професiонал\" з ефективнiстю як мiнiмум 100%." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case WON_250_GAMES_IN_24_HOURS:
        cout << "Виграти 250 iгор стандартного типу (\"Новачок\", \"Любитель\", \"Професiонал\") за 24 години." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case COMPLETE_BEGINNER_IN_5_SEC:
        cout << "Виграти гру типу \"Новачок\" за 5 секунд." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case COMPLETE_INTER_IN_50_SEC:
        cout << "Виграти гру типу \"Любитель\" за 50 секунд." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case COMPLETE_EXPERT_IN_150_SEC:
        cout << "Виграти гру типу \"Професiонал\" за 150 секунд." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case WIN_STREAK_50_BEGINNER:
        cout << "Виконати серiю перемог з 50 iгор типу \"Новачок\"." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case WIN_STREAK_25_INTER:
        cout << "Виконати серiю перемог з 25 iгор типу \"Любитель\"." << endl;
        if (achievementID != ALL_ACHIEVEMENTS) break;

    case WIN_STREAK_10_EXPERT:
        cout << "Виконати серiю перемог з 10 iгор типу \"Професiонал\"." << endl;
        break;
        
    default: 
        cout << "Такого досягнення не iснує." << endl;
    }
}


void topAchievementsViewMenu() {
    TopAchievements top1{2020, PLAYED_HOURS_500, GAME_80x80x999, COMPLETE_BEGINNER_IN_5_SEC };
    TopAchievements top2{2021, WIN_STREAK_25_INTER, PLAYED_HOURS_500, WIN_STREAK_50_BEGINNER };
    TopAchievements top3{2022, COMPLETE_INTER_IN_50_SEC, WON_250_GAMES_IN_24_HOURS, PLAYED_HOURS_500 };
    short int selectedYear;

    cout << "\nВведiть рiк, за який потрiбно подивитися топ:" << endl;

    cin_checker(selectedYear);

    if (selectedYear == top1.year)
        topAchievementsView(top1);
    else if (selectedYear == top2.year)
        topAchievementsView(top2);
    else if (selectedYear == top3.year)
        topAchievementsView(top3);
    else cout << "За цей рiк топу не iснує." << endl;
}

void topAchievementsView(struct TopAchievements &top) {
    cout << "\nТоп-3 найчастiше виконуваних досягнень за " << top.year << " рiк." << endl;

    cout << "1 мiсце: ";
    achievementView(top.first_achievement);
    cout << "2 мiсце: ";
    achievementView(top.second_achievement);
    cout << "3 мiсце: ";
    achievementView(top.third_achievement);
}


int main()
{
    setlocale(LC_ALL, "");
    startMenu();

    system("pause");
    return 0;
}