#include <SFML/Graphics.hpp>
#include "header.h"

void change(int x, int y,int z)
{
    int i=1200,j=300;

    sf::CircleShape cell(70,6);
    if(x<5)
    {
        if(y<x)
            cell.setPosition(i-((x-y)*105),j+(x+y)*60.6f);
        else if(x<y)
            cell.setPosition(i+(y-x)*105,j+(x*2-(y-x))*60.6f);
        else
            cell.setPosition(i,j+y*121.2f);
    }
    else
    {
        if(y<=4)
            cell.setPosition(i-((4-y)*105),j+(4+y)*60.6f+(x-4)*121.2f);

        else
            cell.setPosition((i+(y-4)*105),j+(4*2-(y-4))*60.6f+(x-4)*121.2f);
    }
    cell.setRotation(30);
    if(z==0)
        cell.setFillColor(sf::Color::White);
    else if(z==1)
        cell.setFillColor(sf::Color::Red);
    else if(z==2)
        cell.setFillColor(sf::Color::Blue);
    else if(z==3)
        cell.setFillColor(sf::Color::Yellow);
    else
        cell.setFillColor(sf::Color::Black);

    cell.setOutlineThickness(5);
    cell.setOutlineColor(sf::Color(100,14,129));
    window.draw(cell);

}
