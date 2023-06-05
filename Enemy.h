#ifndef Enemy_H
#define Enemy_H

class Enemy
{
private:
    double x;
    double y;
    int letter;
public:
    Enemy();
    ~Enemy();
    double getX()const;
    double getY()const;
    void moveEnemy(double);
    void drawEnemy();
    void eraseEnemy();
    int random(int min, int max);
    void gotoxy(int x, int y);
    void boom();
};
#endif
