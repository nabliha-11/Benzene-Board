#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
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

void GameMenu(sf::RenderWindow& window);

void howtoplay(sf::RenderWindow& window);

void aboutgame(sf::RenderWindow& window);


int main()
{

    sf::SoundBuffer music;
    sf::Sound Gamesound;

    if(!music.loadFromFile("SpeedofYouth.wav"))
    {

        //handle error
    }

    Gamesound.setBuffer(music);
    Gamesound.play();
    Gamesound.setLoop(true);
    Gamesound.setVolume(40.f);

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
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
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
            case sf::Event::KeyPressed:
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
                        aboutgame(window);

                        break;
                    case 2:
                        howtoplay(window);
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
    if (!font.loadFromFile("LATINWD.ttf"))
    {
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
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case::sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Enter)
                    game;

                if (event.key.code == sf::Keyboard::BackSpace)
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
void howtoplay(sf::RenderWindow& window)
{
    sf::Texture texture;
    sf::Sprite spritebg;

    if (!texture.loadFromFile("How.jpg"))
    {
        //handle error
    }
    spritebg.setTexture(texture);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case::sf::Event::KeyPressed:
                scnd;
                break;
            default:
                break;
            }
        }
        window.clear();
        window.draw(spritebg);
        window.display();
    }
}

void aboutgame(sf::RenderWindow& window)
{
    sf::Texture texture;
    sf::Sprite spritebg;

    if (!texture.loadFromFile("AboutGame.jpg"))
    {
        //handle error
    }
    spritebg.setTexture(texture);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case::sf::Event::KeyPressed:
                scnd;
                break;
            default:
                break;
            }
        }
        window.clear();
        window.draw(spritebg);
        window.display();
    }
}
using namespace std;
int arr[11][11];
int v=1;

//draw board
void Board()
{


    sf::CircleShape cell(50,6);

    int s=255,t=672,x=0,y,i=0,j=0,p,q,c=2;
    for(i=0; i<=8; i++)
    {
        if(i<=4)
        {
            p=s-i*43.3;
            q=t;
            for(j=4-i; j<=8; j++)
            {


                x=q+i*75;
                y=p+(j+i-4)*86.6;
                cell.setPosition(x,y);
                cell.setRotation(30);
                cell.setOutlineThickness(5);
                cell.setOutlineColor(sf::Color(100,14,129));
                window.draw(cell);
            }
        }

        else
        {
            p=82+(i-4)*43.3;
            q=t+5;
            for(j=0; j<=i+c; j++)
            {


                x=q+i*75;
                y=p+(j*86.6);
                cell.setPosition(x,y);
                cell.setRotation(30);
                cell.setOutlineThickness(5);
                cell.setOutlineColor(sf::Color(100,14,129));
                window.draw(cell);
            }
            c=c-2;
        }
    }
}
//change color of a cell
//Basically drawing another cell over the previous one


void change(int i, int j,int k)
{
    int s=255,t=672,x,y,p,q,c=2;

    sf::CircleShape cell(50,6);
    if(i<5)
    {
        p=s-i*43.3;
        q=t;
        x=q+i*75;
        y=p+(j+i-4)*86.6;
    }
    else
    {
        p=82+(i-4)*43.3;
        q=t+5;
        x=q+i*75;
        y=p+(j*86.6);
    }


    cell.setPosition(x,y);
    cell.setRotation(30);
    if(k==0)
        cell.setFillColor(sf::Color::White);
    else if(k==1)
        cell.setFillColor(sf::Color(200,0,0));
    else if(k==2)
        cell.setFillColor(sf::Color(49,91,255));
    else if(k==3)
        cell.setFillColor(sf::Color::Yellow);
    else if(k==4)
        cell.setFillColor(sf::Color::Black);
    else if(k==5||k==6)
    {
        if(arr[i][j]==3)
            cell.setFillColor(sf::Color::Yellow);
    }

    cell.setOutlineThickness(5);
    if(k==5)
        cell.setOutlineColor(sf::Color(222,120,255));
    else if(k==6)
        cell.setOutlineColor(sf::Color(164,212,95));
    else
        cell.setOutlineColor(sf::Color(100,14,129));
    window.draw(cell);

}


//Erase an element from the vectors
void erase_element(int i,int j,int k)
{
    if(k==0)
        for(itr=empT.begin(); itr!=empT.end(); itr++)
        {
            if(itr->first==i&&itr->second==j)
            {
                empT.erase(itr);
                break;
            }
        }
    else if(k==1)
        for(itr=red.begin(); itr!=red.end(); itr++)
        {
            if(itr->first==i&&itr->second==j)
            {
                red.erase(itr);
                break;
            }
        }
    else
        for(itr=blue.begin(); itr!=blue.end(); itr++)
        {
            if(itr->first==i&&itr->second==j)
            {
                blue.erase(itr);
                break;
            }
        }
}
//Initial state of the vectors
void vector_elements()
{

    int x,y,c=2;
    for(x=0; x<=8; x++)
    {
        if(x<=4)
        {
            for(y=4-x; y<=8; y++)
                empT.push_back(make_pair(x,y));
        }

        else
        {
            for(y=0; y<=x+c; y++)
                empT.push_back(make_pair(x,y));

            c=c-2;
        }

    }

    red.push_back(make_pair(0,4));
    red.push_back(make_pair(4,8));
    red.push_back(make_pair(8,0));

    blue.push_back(make_pair(4,0));
    blue.push_back(make_pair(0,8));
    blue.push_back(make_pair(8,4));


    //These became red
    erase_element(0,4,0);
    erase_element(4,8,0);
    erase_element(8,0,0);
    //These became blue
    erase_element(4,0,0);
    erase_element(0,8,0);
    erase_element(8,4,0);
    //These became yellow
    erase_element(5,3,0);
    erase_element(3,5,0);
    //This one is blocked
    erase_element(4,4,0);


}

void permanent_color()
{
    for(itr=color.begin(); itr!=color.end(); itr++)
        change(itr->first,itr->second,arr[itr->first][itr->second]);
}

void Notice(int n,int z)
{
    sf::RectangleShape box(sf::Vector2f(357.14,178.57));
    box.setFillColor(sf::Color(83,7,180));
    box.setPosition(25,71.43);
    box.setOutlineColor(sf::Color(237,217,252));
    box.setOutlineThickness(5);
    window.draw(box);
    sf::Font font;
    font.loadFromFile("Fonts/CALIFB.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(29);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color(127,9,210));
    text.setOutlineThickness(2);

    if(n==1)
    {
        if(z==2)
            text.setString("Player1 gains two cells");
        else
            text.setString("Player2 gains 2 cells");
    }
    else
    {
        if(z==2)
            text.setString("Player1 loses two cells");
        else
            text.setString("Player2 loses 2 cells");
    }

    text.setPosition(57,135.7);

    window.draw(text);



}

int surprise_cell(int z)
{

    srand((unsigned)time(NULL));
    int t,p,m,k,l;
    t=rand()%2;
    cout<<"T= "<<t<<endl;
    srand((unsigned)time(NULL));


    if(t==0)
    {

        for(m=0; m<2; m++)
        {

            if(z==1)
            {
                if(red.size()==0)
                    break;
                for(itr=red.begin(); itr!=red.end(); itr++)
                    cout<<"reds "<<itr->first<<" "<<itr->second<<endl;

                p=rand()%red.size();
                cout<<"P= "<<p<<endl;

                itr=red.begin()+p;

                k=itr->first;
                l=itr->second;
                empT.push_back(make_pair(k,l));
                arr[k][l]=0;
                //    change(k,l,0);
                color.push_back(make_pair(k,l));
                cout<<"delete x="<<k<<" y="<<l<<endl;

                red.erase(itr);

            }
            else
            {
                if(blue.size()==0)
                    break;
                p=rand()%blue.size();
                itr=blue.begin()+p;

                k=itr->first;
                l=itr->second;
                empT.push_back(make_pair(k,l));
                arr[k][l]=0;
                //     change(k,l,0);
                color.push_back(make_pair(k,l));
                cout<<"delete x="<<k<<" y="<<l<<endl;

                blue.erase(itr);

            }
        }
        return 0;
    }
    else
    {

        for(m=0; m<2; m++)
        {
            if(z==1)
            {
                for(itr=red.begin(); itr!=red.end(); itr++)
                    cout<<"reds "<<itr->first<<" "<<itr->second<<endl;
                if(empT.size()!=0)
                {

                    p=rand()%empT.size();

                    itr=empT.begin()+p;
                    k=itr->first;
                    l=itr->second;
                    red.push_back(make_pair(k,l));
                    arr[k][l]=1;
                    //    change(k,l,1);
                    color.push_back(make_pair(k,l));
                    empT.erase(itr);
                }
                else
                {

                    p=rand()%blue.size();

                    itr=blue.begin()+p;
                    k=itr->first;
                    l=itr->second;
                    red.push_back(make_pair(k,l));
                    arr[k][l]=1;
                    //    change(k,l,1);
                    color.push_back(make_pair(k,l));
                    blue.erase(itr);
                }





            }
            else
            {
                if(empT.size()!=0)
                {

                    p=rand()%empT.size();
                    itr=empT.begin()+p;
                    k=itr->first;
                    l=itr->second;
                    blue.push_back(make_pair(k,l));
                    arr[k][l]=2;
                    //    change(k,l,2);
                    color.push_back(make_pair(k,l));
                    empT.erase(itr);
                }
                else
                {
                    p=rand()%red.size();
                    itr=red.begin()+p;
                    cout<<"redsize= "<<empT.size()<<" P= "<<p;
                    k=itr->first;
                    l=itr->second;
                    blue.push_back(make_pair(k,l));
                    arr[k][l]=2;
                    //    change(k,l,2);
                    color.push_back(make_pair(k,l));
                    red.erase(itr);
                }


            }
        }

        return 1;
    }
}

//write coordinates on each cell
void coordinates()
{
    int s=255,t=672,x=0,y,i=0,j=0,p,q,c=2;
    string str1,str2,str;
    sf::Font font;
    font.loadFromFile("Fonts/STENCIL.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(22);
    text.setFillColor(sf::Color(57,2,95));
    for(i=0; i<=8; i++)
    {
        if(i<=4)
        {
            p=s-i*43.3;
            q=t;
            for(j=4-i; j<=8; j++)
            {


                x=q+i*75;
                y=p+(j+i-4)*86.6;
                if(i==4&&j==4)
                    continue;
                str1=to_string(i);
                str2=to_string(j);
                str=str1+","+str2;

                text.setString(str);

                text.setPosition(x,y+50);
                window.draw(text);
            }
        }
        else

        {
            p=82+(i-4)*43.3;
            q=t+5;
            for(j=0; j<=i+c; j++)
            {

                x=q+i*75;
                y=p+(j*86.6);
                str1=to_string(i);
                str2=to_string(j);
                str=str1+","+str2;
                text.setString(str);
                text.setPosition(x,y+50);
                window.draw(text);

            }
            c=c-2;

        }
    }
}

void input_and_texts(int n)
{
    sf::Font font;
    font.loadFromFile("Fonts/CALIFB.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(32);
    // text.setFillColor(sf::Color(241,221,255));
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color(127,9,210));
    text.setOutlineThickness(2);

    text.setString("Enter the number of cells in the following format: x,y");
    text.setPosition(40,890);
    window.draw(text);
    text.setString("\nFrom: ");
    text.setPosition(40,910);
    window.draw(text);
    text.setString("\nTo: ");
    text.setPosition(40,960);
    window.draw(text);

    //scores
    int R=red.size(),B=blue.size();
    string str1,str2;
    str1=to_string(R);
    str2=to_string(B);

    text.setString("Scores:");
    text.setPosition(1500,890);
    window.draw(text);
    text.setString("\nPlayer1: ");
    text.setPosition(1500,910);
    window.draw(text);
    text.setString(str1);
    text.setPosition(1643,945);
    window.draw(text);
    text.setString("\nPlayer2: ");
    text.setPosition(1500,950);
    window.draw(text);
    text.setString(str2);
    text.setPosition(1643,985);
    window.draw(text);

    if(n==1)
        text.setString("Player1's Turn:\n");
    else
        text.setString("Player2's Turn:\n");

    text.setPosition(40,840);
    window.draw(text);
    text.setString("Press Esc to return to menu");
    text.setCharacterSize(20);
    text.setPosition(100,25);
    window.draw(text);

}

//if the first input is valid
int out_of_boundary(int x,int y)
{
    int flag=0;
    if((x<4&&y>=(4-x))||(x==0&&y>=4)||(y==8&&x<5)||(x>=4&&y<=12-x)||(x==8&&y<5)||(y==0&&x>=4))
        flag=1;

    if(x<0||x>8||y<0||y>8)
        flag=2;
    return flag;
    /*if(!flag)
        cout<<"Invalid"<<endl;
        else
            cout<<"Valid"<<endl;*/

}
//notice for invalid move/input
int Invalid(int t)
{
    sf::Font font;
    font.loadFromFile("Fonts/CALIFB.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(25);

    if(t==-1)
    {
        text.setString("Invalid Input");
        text.setPosition(1600,71.43);
        window.draw(text);
    }
    else
    {
        text.setString("Invalid Move");
        text.setPosition(1600,71.43);
        window.draw(text);
    }
}

//Is first input the same color as the player
int playercolor(int x,int y,int z)
{
    if (z==1)
    {
        if(arr[x][y]!=1)
        {
            v=0;
            return 0;
        }
        else return 1;
    }
    else if(z==2)
    {
        if(arr[x][y]!=2)
        {
            v=0;
            return 0;
        }
        else return 1;
    }
}

//check if the move is valid
int check(int x,int y,int x1,int y1,int z)
{

    int k;
    int p=playercolor(x,y,z);
    if(p==0)
        return -1;
    int valid1=out_of_boundary(x,y);
    int valid2=out_of_boundary(x1,y1);

    if(!valid1||!valid2)
    {
        v=0;
        cout<<"Invalid input"<<endl;

        return -1;
    }


    if (arr[x1][y1]==0||arr[x1][y1]==3)
    {

        if((x1==x&&y1==y-1)||(x1==x+1&&y1==y-1)||(x1==x+1&&y1==y)||(x1==x&&y1==y+1)||(x1==x-1&&y1==y+1)||(x1==x-1&&y1==y))
        {
            if(arr[x1][y1]==3)
                k=3;
            arr[x1][y1]=arr[x][y];
            change (x1,y1,arr[x][y]);
            if(arr[x][y]==1)
                red.push_back(make_pair(x1,y1));
            else
                blue.push_back(make_pair(x1,y1));
            erase_element(x,y,0);
            color.push_back(make_pair(x1,y1));
            if(k==3)
                return 3;

            return 1;
        }
        else if((x1==x&&y1==y-2)||(x1==x+1&&y1==y-2)||(x1==x+2&&y1==y-2)||(x1==x+2&&y1==y-1)||(x1==x+2&&y1==y)||(x1==x+1&&y1==y+1)||(x1==x&&y1==y+2)||(x1==x-1&&y1==y+2)||(x1==x-2&&y1==y+2)||(x1==x-2&&y1==y+1)||(x1==x-2&&y1==y)||(x1==x-1&&y1==y-1))
        {
            if(arr[x1][y1]==3)
                k=3;
            arr[x1][y1]=arr[x][y];

            change (x1,y1,arr[x1][y1]);
            if(arr[x][y]==1)
                red.push_back(make_pair(x1,y1));
            else
                blue.push_back(make_pair(x1,y1));
            erase_element(x1,y1,0);
            change (x,y,0);
            if(arr[x][y]==1)
                erase_element(x,y,1);
            else
                erase_element(x,y,2);
            empT.push_back(make_pair(x,y));
            color.push_back(make_pair(x1,y1));
            arr[x][y]=0;
            if(k==3)
                return 3;

            return 1;
        }
        else
        {
            v=0;
            cout<<"Invalid"<<endl;

            return 0;
        }
    }
    else
    {
        v=0;
        cout<<"Invalid"<<endl;
        return 0;
    }
}

//function for copy or jump
int opponent(int x1,int y1, int z)
{
    int f1,f2,f3,f4,f5,f6;
    f1=out_of_boundary(x1,y1-1),f2=out_of_boundary(x1+1,y1-1),f3=out_of_boundary(x1+1,y1),
    f4=out_of_boundary(x1,y1+1),f5=out_of_boundary(x1-1,y1+1),f6=out_of_boundary(x1-1,y1);

    int g;
    if (z==1) g=2;
    else g=1;

    if(f1==1 && arr[x1][y1-1]==g)
    {
        arr[x1][y1-1]=z;
        change (x1,y1-1,z);
        if(z==1)
        {
            red.push_back(make_pair(x1,y1-1));
            erase_element(x1,y1-1,2);
        }
        else if(z==2)
        {
            blue.push_back(make_pair(x1,y1-1));
            erase_element(x1,y1-1,1);
        }
        color.push_back(make_pair(x1,y1-1));

    }
    if(f2==1 && arr[x1+1][y1-1]==g)
    {
        arr[x1+1][y1-1]=z;
        change (x1+1,y1-1,arr[x1][y1]);
        if(z==1)
        {
            red.push_back(make_pair(x1+1,y1-1));
            erase_element(x1+1,y1-1,2);
        }
        else if(z==2)
        {
            blue.push_back(make_pair(x1+1,y1-1));
            erase_element(x1+1,y1-1,1);
        }
        color.push_back(make_pair(x1+1,y1-1));

    }
    if(f3==1 && arr[x1+1][y1]==g)
    {
        arr[x1+1][y1]=z;
        change (x1+1,y1,arr[x1][y1]);
        if(z==1)
        {
            red.push_back(make_pair(x1+1,y1));
            erase_element(x1+1,y1,2);
        }
        else if(z==2)
        {
            blue.push_back(make_pair(x1+1,y1));
            erase_element(x1+1,y1,1);
        }
        color.push_back(make_pair(x1+1,y1));

    }
    if(f4==1 && arr[x1][y1+1]==g)
    {
        arr[x1][y1+1]=z;
        change (x1,y1+1,arr[x1][y1]);
        if(z==1)
        {
            red.push_back(make_pair(x1,y1+1));
            erase_element(x1,y1+1,2);
        }
        else if(z==2)
        {
            blue.push_back(make_pair(x1,y1+1));
            erase_element(x1,y1+1,1);
        }
        color.push_back(make_pair(x1,y1+1));

    }
    if(f5==1 && arr[x1-1][y1+1]==g)
    {
        arr[x1-1][y1+1]=z;
        change (x1-1,y1+1,arr[x1][y1]);
        if(z==1)
        {
            red.push_back(make_pair(x1-1,y1+1));
            erase_element(x1-1,y1+1,2);
        }
        else if(z==2)
        {
            blue.push_back(make_pair(x1-1,y1+1));
            erase_element(x1-1,y1+1,1);
        }
        color.push_back(make_pair(x1-1,y1+1));

    }
    if(f6==1 && arr[x1-1][y1]==g)
    {
        arr[x1-1][y1]=z;
        change (x1-1,y1,arr[x1][y1]);
        if(z==1)
        {
            red.push_back(make_pair(x1-1,y1));
            erase_element(x1-1,y1,2);
        }
        else if(z==2)
        {
            blue.push_back(make_pair(x1-1,y1));
            erase_element(x1-1,y1,1);
        }
        color.push_back(make_pair(x1-1,y1));

    }
}

int options(int x,int y)
{
    if(arr[x][y-1]==0||arr[x][y-1]==3)
        cselect.push_back(make_pair(x,y-1));
    if(arr[x][y+1]==0||arr[x][y+1]==3)
        cselect.push_back(make_pair(x,y+1));
    if(arr[x+1][y]==0||arr[x+1][y]==3)
        cselect.push_back(make_pair(x+1,y));
    if(arr[x-1][y]==0||arr[x-1][y]==3)
        cselect.push_back(make_pair(x-1,y));
    if(arr[x+1][y-1]==0||arr[x+1][y-1]==3)
        cselect.push_back(make_pair(x+1,y-1));
    if(arr[x-1][y+1]==0||arr[x-1][y+1]==3)
        cselect.push_back(make_pair(x-1,y+1));

    if(arr[x][y-2]==0||arr[x][y-2]==3)
        jselect.push_back(make_pair(x,y-2));
    if(arr[x][y+2]==0||arr[x][y+2]==3)
        jselect.push_back(make_pair(x,y+2));
    if(arr[x+1][y-2]==0||arr[x+1][y-2]==3)
        jselect.push_back(make_pair(x+1,y-2));
    if(arr[x-1][y+2]==0||arr[x-1][y+2]==3)
        jselect.push_back(make_pair(x-1,y+2));
    if(arr[x+2][y-2]==0||arr[x+2][y-2]==3)
        jselect.push_back(make_pair(x+2,y-2));
    if(arr[x-2][y+2]==0||arr[x-2][y+2]==3)
        jselect.push_back(make_pair(x-2,y+2));
    if(arr[x+2][y-1]==0||arr[x+2][y-1]==3)
        jselect.push_back(make_pair(x+2,y-1));
    if(arr[x-2][y+1]==0||arr[x-2][y+1]==3)
        jselect.push_back(make_pair(x-2,y+1));
    if(arr[x+2][y]==0||arr[x+2][y]==3)
        jselect.push_back(make_pair(x+2,y));
    if(arr[x-2][y]==0||arr[x-2][y]==3)
        jselect.push_back(make_pair(x-2,y));
    if(arr[x-1][y-1]==0||arr[x-1][y-1]==3)
        jselect.push_back(make_pair(x-1,y-1));
    if(arr[x+1][y+1]==0||arr[x+1][y+1]==3)
        jselect.push_back(make_pair(x+1,y+1));


}

int gameover(int z)
{
    int w,k,s=0,i,j;
    if(empT.size()==0||red.size()==0||blue.size()==0)
        return 1;
    if(z==1)
    {

        for(itr=red.begin(); itr!=red.end(); itr++)

        {
            i=itr->first;
            j=itr->second;

            if(arr[i][j-1]==0||arr[i+1][j-1]==0||arr[i+1][j]==0||arr[i][j+1]==0||arr[i-1][j+1]==0||arr[i-1][j]==0||arr[i][j-1]==3||arr[i+1][j-1]==3||arr[i+1][j]==3||arr[i][j+1]==3||arr[i-1][j+1]==3||arr[i-1][j]==3||
                    arr[i][j-2]==0||arr[i+1][j-2]==0||arr[i+2][j-2]==0||arr[i+2][j-1]==0||arr[i+2][j]==0||arr[i+1][j+1]==0||arr[i][j+2]==0||arr[i-1][j+2]==0||arr[i-2][j+2]==0||arr[i-2][j+1]==0||arr[i-2][j]==0||arr[i-1][j-1]==0||
                    arr[i][j-2]==3||arr[i+1][j-2]==3||arr[i+2][j-2]==3||arr[i+2][j-1]==3||arr[i+2][j]==3||arr[i+1][j+1]==3||arr[i][j+2]==3||arr[i-1][j+2]==3||arr[i-2][j+2]==3||arr[i-2][j+1]==3||arr[i-2][j]==3||arr[i-1][j-1]==3)
            {

                return 0;
            }

        }
        while(empT.size()!=0)
        {
            itr=empT.begin();
            blue.push_back(make_pair(itr->first,itr->second));
            arr[itr->first][itr->second]=2;
            color.push_back(make_pair(itr->first,itr->second));
            permanent_color();
            empT.erase(itr);
        }
        return 1;
    }
    else
    {
        for(itr=blue.begin(); itr!=blue.end(); itr++)

        {
            i=itr->first;
            j=itr->second;

            if(arr[i][j-1]==0||arr[i+1][j-1]==0||arr[i+1][j]==0||arr[i][j+1]==0||arr[i-1][j+1]==0||arr[i-1][j]==0||arr[i][j-1]==3||arr[i+1][j-1]==3||arr[i+1][j]==3||arr[i][j+1]==3||arr[i-1][j+1]==3||arr[i-1][j]==3||
                    arr[i][j-2]==0||arr[i+1][j-2]==0||arr[i+2][j-2]==0||arr[i+2][j-1]==0||arr[i+2][j]==0||arr[i+1][j+1]==0||arr[i][j+2]==0||arr[i-1][j+2]==0||arr[i-2][j+2]==0||arr[i-2][j+1]==0||arr[i-2][j]==0||arr[i-1][j-1]==0||
                    arr[i][j-2]==3||arr[i+1][j-2]==3||arr[i+2][j-2]==3||arr[i+2][j-1]==3||arr[i+2][j]==3||arr[i+1][j+1]==3||arr[i][j+2]==3||arr[i-1][j+2]==3||arr[i-2][j+2]==3||arr[i-2][j+1]==3||arr[i-2][j]==3||arr[i-1][j-1]==3)

            {

                return 0;
            }

        }
        while(empT.size()!=0)
        {
            itr=empT.begin();
            red.push_back(make_pair(itr->first,itr->second));
            arr[itr->first][itr->second]=2;
            color.push_back(make_pair(itr->first,itr->second));
            permanent_color();
            empT.erase(itr);
        }

        return 1;
    }


}
void winner()
{
    sf::RectangleShape box(sf::Vector2f(1000,360));
    box.setFillColor(sf::Color(83,7,180));
    box.setPosition(510.71,357.14);
    box.setOutlineColor(sf::Color(237,217,252));
    box.setOutlineThickness(5);
    window.draw(box);

    sf::Font font;
    font.loadFromFile("Fonts/CALIFB.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color(127,9,210));
    text.setOutlineThickness(2);
    if(red.size()>blue.size())
        text.setString("Player1 WINS!");
    else if(red.size()<blue.size())
        text.setString("Player2 WINS!");
    else
        text.setString("It's a TIE");

    text.setPosition(700,471.43);
    window.draw(text);


}


void GameMenu(sf::RenderWindow& window)
{

    char ch1,ch2;
    int x1=9,y1=9,x2,y2,tt=0,turn=1,p,ss,C=0,o;
    std::string s;
    sf::Texture texture;
    texture.loadFromFile("Images/pp.png");
    sf::Sprite spritebackground;
    spritebackground.setTexture(texture);
    sf::Font font;
    font.loadFromFile("Fonts/CALIFB.ttf");
    sf::String str,str2;
    sf::Text text1(str,font,32);
    text1.setPosition(160,950);
    sf::Text text2(str2,font,32);
    text2.setPosition(160,1000);

    sf::RectangleShape box1(sf::Vector2f(143,35.7));
    box1.setFillColor(sf::Color(83,7,180));
    box1.setPosition(150,950);
    box1.setOutlineColor(sf::Color(237,217,252));
    box1.setOutlineThickness(5);
    sf::RectangleShape box2(sf::Vector2f(143,35.7));
    box2.setFillColor(sf::Color(202,132,215));
    box2.setPosition(150,1000);
    box2.setOutlineColor(sf::Color(237,217,252));
    box2.setOutlineThickness(5);

    sf::RectangleShape colorP1(sf::Vector2f(25,25));
    colorP1.setFillColor(sf::Color(200,0,0));
    colorP1.setPosition(1460,955);
    colorP1.setOutlineColor(sf::Color(237,217,252));
    colorP1.setOutlineThickness(5);
    sf::RectangleShape colorP2(sf::Vector2f(25,25));
    colorP2.setFillColor(sf::Color(49,91,255));
    colorP2.setPosition(1460,995);
    colorP2.setOutlineColor(sf::Color(237,217,252));
    colorP2.setOutlineThickness(5);



    int z,k1=0,k2=0,is_valid=2,is_gameover;
    for(int i=0; i<=10; i++)
    {

        for(int j=0; j<=10; j++)
        {
            o=out_of_boundary(i,j);
            if(o==1)
                arr[i][j]=0;
            else arr[i][j]=-1;
        }

    }


    for(int i=-2; i<=10; i++)
    {

        for(int j=-2; j<=10; j++)
        {
            if(i<0||j<0)
                arr[i][j]=-1;
            cout<<"a["<<i<<"]["<<j<<"]="<<arr[i][j]<<endl;
        }

    }


    vector_elements();

    int random,first,second;
    srand((unsigned)time(NULL));
    random=rand()%51;
    itr=empT.begin()+random;
    first=itr->first;
    second=itr->second;
    erase_element(first,second,0);

    arr[first][second]=3;
    arr[0][4]=1;
    arr[0][8]=2;
    arr[4][8]=1;
    arr[8][4]=2;
    arr[8][0]=1;
    arr[4][0]=2;
    arr[3][5]=3;
    arr[5][3]=3;
    arr[4][4]=4;

    color.push_back(make_pair(0,4));
    color.push_back(make_pair(0,8));
    color.push_back(make_pair(4,8));
    color.push_back(make_pair(8,4));
    color.push_back(make_pair(8,0));
    color.push_back(make_pair(4,0));
    color.push_back(make_pair(3,5));
    color.push_back(make_pair(5,3));
    color.push_back(make_pair(4,4));
    color.push_back(make_pair(first,second));

    while (window.isOpen())
    {

        is_gameover=gameover(turn);

        sf::Event event;
        while (window.pollEvent(event))
        {

            switch(event.type)
            {


            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                cout<<"New window height: "<<event.size.height<<"  New window width: "<<event.size.width<<endl;
                break;
            case::sf::Event::KeyPressed:
                if(is_gameover==1)
                    if (event.key.code == sf::Keyboard::Enter)
                    {

                        scnd;
                    }


                break;
            case sf::Event::TextEntered:
                if(event.text.unicode == 27)
                        scnd;
                if(tt==0)
                {
                    if(event.text.unicode==8)

                    {
                        if(str.getSize()<=0)
                            continue;
                        str.erase(str.getSize()-1,str.getSize());
                        text1.setString(str);
                    }
                    // Handles only the numbers and some signs
                    else if (event.text.unicode < 58&&event.text.unicode>43)

                    {
                        str += static_cast<char>(event.text.unicode);

                        text1.setString(str);
                        s=text1.getString().toAnsiString();
                        ch1=s.at(0);
                        x1=(int)ch1-48;

                        if(str.getSize()>2)
                        {
                            ch2=s.at(2);
                            y1=(int)ch2-48;

                        }
                    }
                }
                if(str.getSize()==3&&event.text.unicode==13)
                {
                    tt=1;
                    k1=1;
                    options(x1,y1);
                }
                if(tt==1)
                {
                    if(event.text.unicode==8)

                    {
                        if(str2.getSize()<=0)
                            continue;
                        str2.erase(str2.getSize()-1,str2.getSize());
                        text2.setString(str2);
                    }
                    // Handles only the numbers and some signs

                    else if (event.text.unicode < 58&&event.text.unicode>43)

                    {
                        str2 += static_cast<char>(event.text.unicode);

                        text2.setString(str2);
                        s=text2.getString().toAnsiString();
                        ch1=s.at(0);
                        x2=(int)ch1-48;

                        if(str2.getSize()>2)
                        {
                            ch2=s.at(2);
                            y2=(int)ch2-48;

                        }
                    }
                }
                if(str2.getSize()==3&&event.text.unicode==13)
                {

                    tt=0;
                    k2=1;
                    cselect.clear();
                    jselect.clear();

                    if(str.getSize()>0)
                        str.erase(str.getSize()-3,str.getSize());
                    text1.setString(str);
                    if(str2.getSize()>0)
                        str2.erase(str2.getSize()-3,str2.getSize());
                    text2.setString(str2);
                }
            }
        }


        if(k1==1&&k2==1)
        {

            is_valid=check(x1,y1,x2,y2,turn);

            cout<<"a["<<x1<<"]["<<y1<<"]="<<arr[x1][y1]<<endl;
            cout<<"a["<<x2<<"]["<<y2<<"]="<<arr[x2][y2]<<endl;
            k1=0;
            k2=0;
            cout<<"valid? "<<is_valid<<endl;

            if(is_valid==1||is_valid==3)
            {
                if(is_valid==3)
                {
                    arr[x2][y2]=turn;
                    ss=surprise_cell(turn);

                }
                opponent(x2,y2,turn);
                for(itr=red.begin(); itr!=red.end(); itr++)
                    cout<<"red x="<<itr->first<<" y="<<itr->second<<endl;
                for(itr=blue.begin(); itr!=blue.end(); itr++)
                    cout<<"blue x="<<itr->first<<" y="<<itr->second<<endl;

                if (turn==1)
                    turn=2;
                else turn=1;
            }
        }


        window.clear();

        window.draw(spritebackground);
        Board();

        if(ss==1)
        {
            Notice(1,turn);
            C++;
        }

        else if(ss==0)
        {
            Notice(0,turn);
            C++;
        }
        if(C==150)
        {
            ss=-1;
            C=0;
        }

        if(is_valid==-1||is_valid==0)
            Invalid(is_valid);

        permanent_color();

        input_and_texts(turn);



        if((playercolor(x1,y1,turn))==1)
        {
            for(itr=jselect.begin(); itr!=jselect.end(); itr++)
            {
                if((out_of_boundary(itr->first,itr->second))==1);
                change(itr->first,itr->second,6);
            }

            for(itr=cselect.begin(); itr!=cselect.end(); itr++)
            {
                if((out_of_boundary(itr->first,itr->second))==1);
                change(itr->first,itr->second,5);
            }
        }


        coordinates();

        if(is_gameover==1)
        {

            winner();
        }

        window.draw(box1);
        window.draw(box2);
        window.draw(text1);
        window.draw(text2);
        window.draw(colorP1);
        window.draw(colorP2);

        window.display();

    }


}
