#pragma once
#include "../pch.hpp"
#include "BJ_Service_Functions.hpp"

void Greetings()
{
	std::cout << "Добро ожаловать в игру Блэкджек! Хотите ли вы ознаковиться с правилами? ";
	if (YesNoHelper() == true)
	{
		std::cout << "\nПравила довольно просты. В начале игры всем игрокам сдаётся 2 карты. \nДилер также сдаёт 2 карты себе, но одну из них оставляет закрытой. \n\nДалее игроки смотрят на свои карты и говорят хотят ли они добрать ещё. \nПосле того как игроки закончили набирать карты, дилер открывает свою вторую карту и если нужно, берёт ещё в открытую." << std::endl;
		std::cout << "\nУ всех карт своя стоимость: стоимость числовых карт равна их значению, валет, дама и король дают по 10 очков. \nТуз даёт 11 очков если сумма карт игрока не превышает 21, в противном случае туз стоит 1 очко. \n\nИгроки набравшие больше дилера но не больше 21 - побеждают. Угроки набравшие больше 21 или меньше дилера - проигрывают" << std::endl;
		std::cout << "\nТеперь, когда мы во всём разобрались - приступим!\n" << std::endl;
	}
	else
	{
		std::cout << "Тогда приступим!\n" << std::endl;
	}
	return;
}

bool YesNoHelper()
{
	std::string inpoot;
	for (;;)
	{
		std::cin >> inpoot;
		if (inpoot == "yes" || inpoot == "Yes" || inpoot == "y" || inpoot == "Y" || inpoot == "да" || inpoot == "д" || inpoot == "Да" || inpoot == "Д" || inpoot == "no" || inpoot == "No" || inpoot == "n" || inpoot == "N" || inpoot == "нет" || inpoot == "н" || inpoot == "Нет" || inpoot == "Н")
			break;
		else
		{
			std::cout << "Некорректный ввод! Нажмите Enter и попробуйне снова!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			inpoot.clear();
		}
	}
	if (inpoot == "yes" || inpoot == "Yes" || inpoot == "y" || inpoot == "Y" || inpoot == "да" || inpoot == "д" || inpoot == "Да" || inpoot == "Д")
		return true;
	else
		return false;
}

size_t GetIntHelper()
{
	int inpoot;
	for (;;)
	{
		std::cin >> inpoot;
		if (std::cin.fail())
		{
			std::cout << "Некорректный ввод! Нажмите Enter и попробуйне снова!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			inpoot = 0;
		}
		else
			break;
	}

	return inpoot;
}