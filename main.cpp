#include <iostream>
#include "hlava.h"
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    int data[4];
    float V, Min=1000,z=0,k=0;


    std::ifstream input;
    try
    {
        input.open("suradnice.txt");
        if(!input.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }
        for(int i=0; i<100; ++i)
        {

            for (int & i : data)
            {
                input >> i;
            }
            Bod2D A(data[0], data[1]);
            Bod2D B(data[2], data[3]);

            V = A.vzdialenost(B);
            if (V < Min) {
                Min = V;
                k = z;
            }
            z++;
        }
        input.close();
    }
    catch (const Bod2D::streamError & ex)
    {
        ex.getMsg();
        return 1;
    }

    std::cout<<"Najmensia vzdialenost je: "<<Min<<" medzi bodmi v "<<k<<" riadku,"<<std::endl;

    /*Bod2D A(42,17);
    Bod2D B(2,32);
    Bod2D C(1,6);
    //Bod2D D(0,0);
    std::cout<<A<<B<<C;
    //std::cout<<Bod2D()<<Bod2D(3)<<Bod2D(1,6);
    //A = A + B;
    std::cout<<A+B;
    //A = A- B;
    std::cout<<A-B;
    //A = A *3;
    std::cout<<A*3;
    //B = B / 3;
    std::cout<<B/3;
    //A = 5/A;
    //std::cout<<5/A;
    //A = 5* A;
    std::cout<<5*A;
    std::cout<<"|AB| = "<<A.vzdialenost(B)<<std::endl;
    std::cout<<"Vzdialenost bodu A od nuly je : "<<A.vzdialenost()<<std::endl;
    std::cout<<"Stred medzi bodmi A a B je: "<<A.Stred(B)<<std::endl;*/

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

Bod2D operator*(float cislo, const Bod2D &other)
{
    return {cislo*other.x, cislo*other.y};
}

/*Bod2D operator/(float cislo, Bod2D &other)
{
    return {cislo/other.x, cislo/other.y};
}
*/
double Bod2D::vzdialenost(const Bod2D &other)const {

    return sqrt(pow((x-other.x),2)+pow((y-other.y),2));

}

Bod2D Bod2D::Stred(const Bod2D &other) const {

    return {((x+other.x)/2),((y+other.y)/2)};
}



void Bod2D::streamError::getMsg() const
{
    std::cout<<msg;
}

