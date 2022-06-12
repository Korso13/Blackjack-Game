#pragma once
#include "../pch.hpp"
#include "BJ_Service_Functions.hpp"

void Greetings()
{
	std::cout << "����� ��������� � ���� ��������! ������ �� �� ������������ � ���������? ";
	if (YesNoHelper() == true)
	{
		std::cout << "\n������� �������� ������. � ������ ���� ���� ������� ������ 2 �����. \n����� ����� ���� 2 ����� ����, �� ���� �� ��� ��������� ��������. \n\n����� ������ ������� �� ���� ����� � ������� ����� �� ��� ������� ���. \n����� ���� ��� ������ ��������� �������� �����, ����� ��������� ���� ������ ����� � ���� �����, ���� ��� � ��������." << std::endl;
		std::cout << "\n� ���� ���� ���� ���������: ��������� �������� ���� ����� �� ��������, �����, ���� � ������ ���� �� 10 �����. \n��� ��� 11 ����� ���� ����� ���� ������ �� ��������� 21, � ��������� ������ ��� ����� 1 ����. \n\n������ ��������� ������ ������ �� �� ������ 21 - ���������. ������ ��������� ������ 21 ��� ������ ������ - �����������" << std::endl;
		std::cout << "\n������, ����� �� �� ��� ����������� - ���������!\n" << std::endl;
	}
	else
	{
		std::cout << "����� ���������!\n" << std::endl;
	}
	return;
}

bool YesNoHelper()
{
	std::string inpoot;
	for (;;)
	{
		std::cin >> inpoot;
		if (inpoot == "yes" || inpoot == "Yes" || inpoot == "y" || inpoot == "Y" || inpoot == "��" || inpoot == "�" || inpoot == "��" || inpoot == "�" || inpoot == "no" || inpoot == "No" || inpoot == "n" || inpoot == "N" || inpoot == "���" || inpoot == "�" || inpoot == "���" || inpoot == "�")
			break;
		else
		{
			std::cout << "������������ ����! ������� Enter � ���������� �����!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			inpoot.clear();
		}
	}
	if (inpoot == "yes" || inpoot == "Yes" || inpoot == "y" || inpoot == "Y" || inpoot == "��" || inpoot == "�" || inpoot == "��" || inpoot == "�")
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
			std::cout << "������������ ����! ������� Enter � ���������� �����!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			inpoot = 0;
		}
		else
			break;
	}

	return inpoot;
}