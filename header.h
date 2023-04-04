#pragma once
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#endif // HEADER_H_INCLUDED


#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 sf::RenderWindow window(sf::VideoMode(1920,1080), "Benzene Board",sf::Style::Default);
void change(int i, int j, int k);
    vector<pair<int,int>> red;
    vector<pair<int,int>> blue;
    vector<pair<int,int>> empT;
    vector<pair<int,int>> color;
    vector<pair<int,int>> cselect;
    vector<pair<int,int>> jselect;
vector<pair<int,int>>::iterator itr;



