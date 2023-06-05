#include "Enemy.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include<Windows.h>

using namespace std;

int Enemy::random(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
void Enemy::gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

Enemy::Enemy()
{
    x = random(10, 70);
    y = 4;
    letter = random(65, 90);
}

Enemy::~Enemy()
{
    this->eraseEnemy();
    moveEnemy(30);
}

double Enemy::getX()const
{
    return x;
}
double Enemy::getY()const
{
    return y;
}
void Enemy::moveEnemy(double ny)
{
    y = ny;
}
void Enemy::drawEnemy()
{
    gotoxy(x, y - 2);
    cout << " " << (char)letter << (char)letter << (char)letter << " ";
    gotoxy(x, y - 1);
    cout << (char)letter << (char)letter << (char)letter << (char)letter << (char)letter;
    gotoxy(x, y);
    cout << " " << (char)letter << (char)letter << (char)letter << " ";
}
void Enemy::eraseEnemy()
{
    gotoxy(x, y - 2);
    cout << "     ";
    gotoxy(x, y - 1);
    cout << "     ";
    gotoxy(x, y);
    cout << "     ";
}

void  Enemy::boom()
{
    int b= random(1, 2);
    switch (b)
    {
    case 1:
        gotoxy(x, y - 1);
        cout << "  " << (char)letter << (char)letter << (char)letter << "  ";
        gotoxy(x, y);
        cout << (char)letter << (char)letter << (char)letter << (char)letter << (char)letter << (char)letter << (char)letter;
        this_thread::sleep_for(chrono::milliseconds(150));
        gotoxy(x, y - 1);
        cout << "     ";
        gotoxy(x, y);
        cout << "       ";
        break;
    case 2:
        gotoxy(x, y - 2);
        cout << " " << (char)letter << (char)letter << (char)letter << " ";
        gotoxy(x, y - 1);
        cout << (char)letter << " " << " " << " " << (char)letter;
        gotoxy(x, y);
        cout << " " << (char)letter << (char)letter << (char)letter << " ";
        this_thread::sleep_for(chrono::milliseconds(150));
        gotoxy(x, y - 2);
        cout << "     ";
        gotoxy(x, y - 1);
        cout << "     ";
        gotoxy(x, y);
        cout << "     ";
        break;
    }
}
