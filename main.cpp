#include <iostream>
#include "hlava.h"
#include<cmath>
int main()
{
    Bod2D A;
    Bod2D B(-7);
    Bod2D C(1,6);
    std::cout<<A<<B<<C;



    //std::cout<<Bod2D()<<Bod2D(3)<<Bod2D(1,6);
    /*A = A + B;
    std::cout<<A;
    A = A- B;
    std::cout<<A;
    A = A *3;
    std::cout<<A;
    B = B / 3;
    std::cout<<B;
    A = 5/A;
    std::cout<<A;
    A = 5* A;
    std::cout<<A;*/
    std::cout<<"|AB| = "<<A.vzdialenost(B)<<std::endl;


    return 0;
}
Bod2D::Bod2D()
{
    std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;
}
Bod2D::Bod2D(float mojeX)
{
    x = mojeX;
    std::cout<< "Zadaj suradnicu y: ";
    std::cin>>y;
}

Bod2D::Bod2D(float mojeX, float mojeY)
{
    y = mojeY;
    x = mojeX;
}


float Bod2D::getX() const
{
    return x;
}

float Bod2D::getY() const {
    return y;
}

void Bod2D::setX(float mojeX)
{
 x = mojeX;
}

void Bod2D::setY(float mojeY)
{
    y = mojeY;
}

std::ostream &operator<<(std::ostream &os, const Bod2D &other) {
    os<<"Bod ma suradnice ["<<other.x<<","<<other.y<<"]"<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Bod2D &other) {
    std::cout<<"Zadaj suradnicu x: ";
    is>>other.x;
    std::cout<<"Zadaj suradnicu y: ";
    is>>other.y;
    return is;

}



void Bod2D::vypisBod()  const
{
    std::cout <<"Bod ma suradnice ["<<x<<","<<y<<"]"<<std::endl;
}



Bod2D Bod2D::operator*(float cislo)const
{
    return{(x*cislo),(y*cislo)};
}

Bod2D Bod2D::operator/(float cislo)const
{
    return {(x/cislo),(y/cislo)};
}

Bod2D Bod2D::operator-(const Bod2D &other) const {
    return {(x-other.x),(y-other.y)};
}

Bod2D Bod2D::operator+(const Bod2D &other) const {
    return {(x+other.x),(y+other.y)};
}

Bod2D operator*(float cislo, Bod2D &other)
{
    return {cislo*other.x, cislo*other.y};
}

Bod2D operator/(float cislo, Bod2D &other)
{
    return {cislo/other.x, cislo/other.y};
}

double Bod2D::vzdialenost(const Bod2D &other)const {

    return sqrt(pow((x-other.x),2)+pow((y-other.y),2));
}

void Bod2D::Stred(const Bod2D &otherBod)
{
    Bod2D other(x+otherBod.x,y+otherBod.y);
    std::cout<< "Stred medzi bodmi je: " << other/2 << std::endl;
}