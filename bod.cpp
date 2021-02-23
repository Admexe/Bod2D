//
// Created by User on 16. 2. 2021.
//
#include<cstring>
#include <iostream>
#include "hlava.h"
#include<cmath>
#include<fstream>
#include"inout.h"
#define PI 3.14159265
int comp(const void *prva, const void *druha);
using namespace inout;
Bod2D::Bod2D()
{
    /*std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;*/
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
    os<<"["<<other.x<<","<<other.y<<"]"<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Bod2D &other) {
    is>>other.x>>other.y;
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

void Bod2D::getSortedDistance(std::istream &input)
{
    Usecka Usecky[100];
    for(auto & i :Usecky)
    {
        input>>i;
    }
    qsort(Usecky,100,sizeof(Usecka),comp);
    std::cout<<"Utriedenie podla velkosti"<<std::endl;
    for(auto i : Usecky)
    {
        std::cout<<i.getDlzka()<<" "<<i;
    }


}




/*void Bod2D::MVzdialenost(std::istream &is)
{










}*/


void Bod2D::streamError::getMsg() const
{
    std::cout<<msg;
}

float Usecka::getDlzka() const
{

    return X.vzdialenost(Y);
}

std::istream &operator>>(std::istream &is, Usecka &usecka) {
    is>>usecka.X>>usecka.Y;
    return is;
}

bool Usecka::operator<(const Usecka &other) const {
    return this->getDlzka()<other.getDlzka();
}

std::ostream &operator<<(std::ostream &os, const Usecka &usecka) {
    os<<usecka.X<<usecka.Y<<std::endl;
    return os;
}
Vektor Usecka::getSmer()const
{
    //return Vektor {((X.getX())-(Y.getX())),((X.getY())-(Y.getY()))};
    return Y-X;
}


Bod2D Usecka::getCenter() const {
    //return Bod2D{(((X.getX())+(Y.getX()))/2),(((X.getY())+(Y.getY())))};
    //X.vzdialenost(Y)/2;
    return(X+Y)/2;
}
Vektor Usecka::getNormal() const
{
    /*Vektor premenna = getSmer();

    return Vektor{(premenna.getY()), -(premenna.getX())};*/
    Bod2D tmp = Y-X;

    return {-tmp.getY(), tmp.getX()};

}




int comp(const void *prva, const void *druha )
{
    auto * A = (Usecka *)prva;
    auto * B = (Usecka *)druha;
    return ((*A)<(*B))?1:((*A)>(*B))?-1:0;

}
bool Usecka::operator>(const Usecka &other)const
{
    return this->getDlzka()>other.getDlzka();
}

/*std::ostream &operator<<(std::ostream &os, const Usecka::VR &other) {

    std::showpos(cout<<other.a+other.b+other.c);
    return os;
}*/

/*Usecka::VR Usecka::getVseobecna() const {
    float a,b,c;
    Usecka AB;
    Vektor FN = AB.getNormal();
    a = getNormal().getX();
    b = getNormal().getY();
    c = ;
    return Usecka::VR(a,b,c);
}*/





Usecka::VR Usecka::getVseobecna() const
{
    Vektor XY= getNormal();
    //cout << XY << endl;
    float C = (XY.getX() * X.getX() + XY.getY() * X.getY());
    return Usecka::VR(XY.getX(), XY.getY(), -C );
}

/*std::ostream &operator<<(std::ostream &os, const Usecka::VR &other)
{
    os<<showpos<<(other.a)<<"x"<<(other.b)<<"y"<<(other.c)<<"=0"<< std::endl;
    return os;
}
*/

std::ostream &operator<<(std::ostream &os, const Usecka::PR &other) {
    os<<showpos<<"x = "<<(other.koeficienty[0])<<other.koeficienty[1]<<"t"<<std::endl<<showpos<<"y ="<<(other.koeficienty[2])<<other.koeficienty[3]<<"t";

    return os;
}




Usecka::PR Usecka::getParametricka() const {
    Vektor AB = getSmer();
    return Usecka::PR(X.getX(), AB.getX(), X.getY(), AB.getY());
}

Usecka::VR Usecka::getOs() const {
    Vektor Z = getSmer();
    Bod2D L = getCenter();
    float C = Z.getX()*L.getX()+Z.getY()*L.getY();
    return Usecka::VR(Z.getX(),Z.getY(), -C);
}

float Usecka::getUhol(const Usecka &other, char typ) const {
    Vektor AB = getSmer();
    cout << " s / r" << std::endl;
    cin >> typ;
    if (typ == 's') {
        float par = acos((AB.getX() * other.getSmer().getX() + AB.getY() * other.getSmer().getY()) /
                         (AB.getDlz() * other.getSmer().getDlz()));
        return par * 180 / PI;
    } else {
        float par = acos((AB.getX() * other.getSmer().getX() + AB.getY() * other.getSmer().getY()) /
                         (AB.getDlz() * other.getSmer().getDlz()));
        return par;

    }


}



bool Usecka::getRovn(const Usecka &other)const
{

      Vektor V =  this->getSmer();
      Vektor U = other.getSmer();
      if((V.getX()/U.getX() == V.getY() / U.getY())) std::cout<<"Priamky su rovnobezne!";
      else cout<<"Priamky niesu rovnobezne!";


   /* Vektor V = getSmer();
    Vektor U = other.getSmer();
    if ((V.getX() == U.getX()) && (V.getY() == U.getY()))
    {
        cout << "su totozne" << std::endl;
    }
    else if (((V.getX() == U.getX()) || (V.getY() == U.getY())) || ((V.getX() / U.getX()) == (V.getY() / U.getY())))
    {
        cout << "su rovnobezne" << std::endl;
    }
    else
    {
        cout << "su roznobezne" << std::endl;
    }
*/
}

Usecka::Poloha Usecka::getPoloha(const Usecka &other) const {

    Usecka::VR A = getVseobecna();
    Usecka::VR B = other.getVseobecna();
    float D1 = (A[0]*B[1]) - (A[1]*B[0]);
    float D2 = ((-A[2])*B[1]) - ((-B[2])*A[1]);
    float D3 = (A[0]*(-B[2])) - (B[0]*(-A[2]));
    //cout << D1<<";"<<D2<<";"<<D3<<endl;
    cout << "prienik X ma suradnicke"<<Bod2D((D2/D1),(D3/D1))<<endl;
    return Usecka::Poloha (nullptr, Bod2D((D2/D1),(D3/D1)));
    /*if(this->getTotozna(other))
    {
        return Usecka::Poloha("totozna",Bod2D{0,0});
    }
    if(this->getRovn(other))
    {
        return Usecka::Poloha("Rovnobezne",Bod2D{0,0});

    }
    auto A = this->getVseobecna();
    auto B = other.getVseobecna();
    float D = A[0] * B[1] - A[1] * B[0];
    float D1 = -A[2]*B[1] - A[1]* B[2] * (-1);
    float D2 = -A[0] * B[2] - B[0] * A[2] * -1;
    return Usecka::Poloha("Roznobezna",{D1/D,D2/D});*/

}


float Bod2D::getDlz() const
{
    //cout<<sqrt((getX()*getX()) + (getY()*getY()))<<endl;
    return sqrt(pow(getX(),2) + (pow(getY(),2)));
}

Bod2D Bod2D::getJedn()const
{
    return Bod2D{this->x/this->getDlz(),this->y/this->getDlz()};
}

std::ostream &operator<<(std::ostream &os, const Usecka::VR &other) {
    os<<showpos<<"Vseobecna rovnica: "<<(other.koeficienty[0])<<"x"<<(other.koeficienty[1])<<"y"<<(other.koeficienty[2])<<"=0"<< std::endl;
    return os;
}

Usecka::VR Usecka::getOsUhla(const Usecka &other) const {
    Usecka::Poloha AB = getPoloha(other);
    Bod2D X = AB.getPriesecnik();
    Vektor C = this->getSmer();
    Vektor D = other.getSmer();
    Vektor B1 = C.getJedn();
    Vektor B2 = D.getJedn();
    Vektor B3 = {-(B1.getY()+B2.getY()),(B1.getX()+B2.getX())};
    return Usecka::VR(B3.getX(),B3.getY(),-(B3.getX()*X.getX()+B3.getY()*X.getY()));
}
bool Usecka::getTotozna(const Usecka &other) const {
    VR A = this->getVseobecna();
    VR B = other.getVseobecna();
    return A[0]/B[0]==A[1]/B[1]==A[2]/B[2];
}


Usecka::Poloha::Poloha(char *text, const Bod2D &prienik) : priesecnik(prienik)
{
        std::strncpy(popis,text,10);
        popis[10]='\0';
}
;