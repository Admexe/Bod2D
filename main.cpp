#include <iostream>
#include "hlava.h"
int main()
{
    bod2d Prvy;
    bod2d Druhy(3);
    bod2d Treti(1,6);
    std::cout<<Prvy<<Druhy<<Treti;
    //std::cout<<bod2d()<<bod2d(3)<<bod2d(1,6);
    Prvy.spocitaj(Druhy).vypisBod();
    Prvy.odcitaj(Druhy).vypisBod();
    Prvy = Prvy *3;
    bod2d(Prvy).vypisBod();
}
bod2d::bod2d()
{
    std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;
}
bod2d::bod2d(float mojeX)
{
    x = mojeX;
    std::cout<< "Zadaj suradnicu y: ";
    std::cin>>y;
}

bod2d::bod2d(float mojeX, float mojeY)
{
    y = mojeY;
    x = mojeX;
}


float bod2d::getX() const
{
    return x;
}

float bod2d::getY() const {
    return y;
}

void bod2d::setX(float mojeX)
{
 x = mojeX;
}

void bod2d::setY(float mojeY)
{
    y = mojeY;
}

std::ostream &operator<<(std::ostream &os, const bod2d &other) {
    os<<"Bod ma suradnice ["<<other.x<<","<<other.y<<"]"<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, bod2d &other) {
    std::cout<<"Zadaj suradnicu x: ";
    is>>other.x;
    std::cout<<"Zadaj suradnicu y: ";
    is>>other.y;
    return is;

}

bod2d bod2d::spocitaj(const bod2d &other) const
{
    return {x+other.x,y+other.y};
}

void bod2d::vypisBod()  const
{
    std::cout <<"Bod ma suradnice ["<<x<<","<<y<<"]"<<std::endl;
}

bod2d bod2d::odcitaj(const bod2d &other)const {
    return {x-other.x,y-other.y};
}

bod2d bod2d::operator*(float cislo)const
{
    return{(x*cislo),(y*cislo)};
}


