#include <iostream>
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Vector{
    public:
    Vector() {}
    Vector(float X, float Y){
        x = X;
        y = Y;
    }
    float Length() const;
    float LengthSqr() const;

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(float s) const;
    Vector operator/(float s) const;

    Vector Normalized() const;

    float x, y;
};

Vector Vector::operator+(const Vector& v) const{
   Vector retV;
   retV.x = x + v.x;
   retV.y = y + v.y;
   return retV;
}
Vector Vector::operator-(const Vector& v) const{
   return Vector(x - v.x, y - v.y);
}

class Point{
    public:
    Point() {}
    Point(float X, float Y){
        x = X;
        y = Y;
    }
    Point AddVector(Vector c);
    float x, y;
};

Vector Vector:: Normalized() const {
    Vector normalized;

    normalized = (*this) / Length();
    return normalized;
}

 Vector Vector::operator* (float s) const {
    Vector scaled;
    scaled.x = x * s;
    scaled.y = y * s;
    return scaled;
}

Vector Vector::operator/(float s) const {
    Vector scaled;
    scaled.x = x / s;
    scaled.y = y / s;
    return scaled;
}

float Vector::Length() const {
    float length;
    length = sqrt((x * x) + (y * y));
    return length;
}

float Vector::LengthSqr() const {
    float length;
    length = ((x * x) + (y * y));
    return length;
}

Vector operator-(Point a, Point b) {
    Vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return v;
}

Point Point::AddVector(Vector v) {
    Point pPrime;

    pPrime.x = x + v.x;
    pPrime.y = y + v.y;
    return pPrime;
}

void gotoxy(int col, int In){
  COORD coord;
  coord.X = col;
  coord.Y = In;
  SetConsoleCursorPosition(
     GetStdHandle(STD_OUTPUT_HANDLE),
     coord);
}
int wherex(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD result;
    if(!GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE), &csbi));
        return -1;
    return result.X;
}
int wherey(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD result;
    if(!GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE), &csbi));
        return -1;
    return result.Y;
}

int main(){
    system("cls");

    Vector player1; /// X
    player1.x = 1;
    player1.y = 2;
    Point p1(1, 2);

    Vector player2; /// O
    player2.x = 1;
    player2.y = 4;
    Point p2(1, 4);

    Sleep(3000);
    gotoxy(player1.x, player1.y);
    cout << "X";
    gotoxy(player2.x, player2.y);
    cout << "O";

    gotoxy(29, 1); cout << "|";
    gotoxy(29, 2); cout << "|";
    gotoxy(29, 3); cout << "|";
    gotoxy(29, 4); cout << "|";
    gotoxy(29, 5); cout << "|";

    for(int x1 = 2; x1 < 30; x1++){
        Sleep(500);
        system("cls");
        srand((unsigned) time(0));

        p1.x += 1 + (rand() % 2);
        p1.AddVector(player1);
        gotoxy(p1.x, p1.y);
        cout << "X";

        p2.x += 1 + (rand() % 2);
        p2.AddVector(player2);
        gotoxy(p2.x, p2.y);
        cout << "O";


        gotoxy(29, 1); cout << "|";
        gotoxy(29, 2); cout << "|";
        gotoxy(29, 3); cout << "|";
        gotoxy(29, 4); cout << "|";
        gotoxy(29, 5); cout << "|";

        if(p1.x >=30){
            gotoxy(0, 8); cout << "Player 1 wins" << endl;
            break;
        }
        if(p2.x >=30){
            gotoxy(0, 8); cout << "Player 2 wins" << endl;
            break;
        }

    }

    return 0;
}
