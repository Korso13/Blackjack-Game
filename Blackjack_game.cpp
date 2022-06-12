#include "pch.hpp"
#include "func/BJ_Classes_Functions.h"
#include "func/BJ_Extra_Functions.hpp"
#include "func/BJ_Service_Functions.hpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Greetings();
    //=======================================================================================================================================
    //Task 5. Main function
    //=======================================================================================================================================
    bool RetrySame{true}, RetryNew{true};
    std::vector<std::string> PlayersNames;
    //outer cycle for restarting game with new player names
    do
    {
        PlayersNames.clear();
        PlayersNames.resize(0);
        PlayersNames.shrink_to_fit();
        //Getting to know our players (their count and names)
        size_t playerCount;
        std::cout << "Введите кол-во игроков: ";
        playerCount = GetIntHelper(); //function to get correct size_t inpoot
        PlayersNames.resize(playerCount);
        auto it = PlayersNames.begin();
        for (size_t i = 1; i <= playerCount; i++)
        {
            std::cout << "Введите имя игрока номер " << i << ": ";
            std::cin >> *it;
            if (i < playerCount)
                it++;
        }
        //inner cycle for restarting game with same player names
            do
            {
                //starting the game
                std::cout << "Начинаем!\n" << std::endl;
                std::shared_ptr<Game> game = std::make_shared<Game>(PlayersNames);
                game->play();
                std::cout << "Желаете сыграть ещё раз тем же составом? ";
                RetrySame = YesNoHelper(); //function to extract boolean from Y/N answers in English and Russian
            } while (RetrySame == true);
        std::cout << "Желаете сыграть ещё раз но уже другим составом? ";
        RetryNew = YesNoHelper();
    } while (RetryNew == true);
    
    std::cout << "Всего хорошего!" << std::endl;
    return 0;
}
