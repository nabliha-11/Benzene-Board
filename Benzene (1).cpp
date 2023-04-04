#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Menuu.h"
#include "header.h"
#define thrd thirdMenu(window);
#define scnd secondMenu(window);
#define game GameMenu(window);
#define ENTER_KEY 13
void thirdMenu(sf::RenderWindow& window);

void secondMenu(sf::RenderWindow& window);

int home_page()
{


	sf::SoundBuffer music;
	sf::Sound Gamesound;
	if(!music.loadFromFile("Disney.mp3"))
		//handle error


	Gamesound.setBuffer(music);

	sf::Texture button;
	sf::Sprite bg;

	if (!button.loadFromFile("MenuButton.png"))
	{
		//handle error
	}
	bg.setTexture(button);
	bg.setPosition(400, 400);
	window.setKeyRepeatEnabled(false);


	sf::Texture texture;
	sf::Sprite spritebackground;
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;

	if (!texture.loadFromFile("images.jpg"))
	{
		return -1;
	}
	spritebackground.setTexture(texture);


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {
			case::sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter)
					scnd;
				break;
			default:
				break;
			}
		}
		window.clear();
		window.draw(spritebackground);
		window.draw(bg);
		window.display();
	}

}

void secondMenu(sf::RenderWindow& window)
{
	Menu menu(window.getSize().x, window.getSize().y);
	sf::Font font;
	if (!font.loadFromFile("LATINWD.ttf"))
	{
		//handle error
	}
	sf::Text text;



	sf::Texture texture;
	sf::Sprite spritebackground;
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;

	if (!texture.loadFromFile("images.jpg"))
	{
		//handle error
	}
	spritebackground.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						thrd;
						break;
					case 1:
						std::cout << "About Game button has been pressed" << std::endl;
						break;
					case 2:
						std::cout << "How To Play button has been pressed" << std::endl;
						break;
					case 3:
						window.close();
						break;
					}
					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();


		window.draw(spritebackground);
		menu.draw(window);
		window.draw(text);

		window.display();
	}
}

void thirdMenu(sf::RenderWindow& window)
{

	sf::Texture texture;
	sf::Sprite spritebackground;


	if (!texture.loadFromFile("3rdMenu.jpg"))
	{
		//handle error
	}
	spritebackground.setTexture(texture);
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("LATINWD.ttf")) {
		//handle error
	}
	text.setFont(font);
	text.setString("Start Game");
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(75);
	text.setPosition(600, 800);
	text.setOutlineThickness(20);
	text.setOutlineColor(sf::Color::Black);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {
			case::sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter)
					scnd;
				break;
			default:
				break;
			}
		}
		window.clear();
		window.draw(spritebackground);
		window.draw(text);
		window.display();
	}

}
