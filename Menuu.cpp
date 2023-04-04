#include "Menuu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Algerian Regular.ttf"))
	{
		// handle error
	}
	menu[0].setOutlineThickness(15);
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2.6, height / (MAX_NUMBER_OF_ITEMS + .2) * 1.5));
	menu[0].setCharacterSize(70);

	menu[1].setOutlineThickness(15);
	menu[1].setOutlineColor(sf::Color::Black);
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("About Game");
	menu[1].setPosition(sf::Vector2f(width / 2.6, height / (MAX_NUMBER_OF_ITEMS + 1.7) * 2.75));
	menu[1].setCharacterSize(70);

	menu[2].setOutlineThickness(15);
	menu[2].setOutlineColor(sf::Color::Black);
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("How To Play");
	menu[2].setPosition(sf::Vector2f(width / 2.6, height / (MAX_NUMBER_OF_ITEMS + 2.7) * 4));
	menu[2].setCharacterSize(70);

	menu[3].setOutlineThickness(15);
	menu[3].setOutlineColor(sf::Color::Black);
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 2.6, height / (MAX_NUMBER_OF_ITEMS + 3.4) * 5.3));
	menu[3].setCharacterSize(70);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
