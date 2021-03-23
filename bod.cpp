//
// Created by User on 16. 2. 2021.
//
#include <string>
#include<cstring>
#include <iostream>
#include "hlava.h"
#include<cmath>
#include<fstream>
#include"inout.h"
#include <random>
#define PI 3.14159265
#include<ctime>
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

std::ostream &operator<<(std::ostream &os, const Usecka::PR &other)
{
    os<<showpos<<"x = "<<(other.koeficienty[0])<<other.koeficienty[1]<<"t"<<std::endl<<showpos<<"y ="<<(other.koeficienty[2])<<other.koeficienty[3]<<"t";

    return os;
}




Usecka::PR Usecka::getParametricka() const
{
    Vektor AB = getSmer();
    return Usecka::PR(X.getX(), AB.getX(), X.getY(), AB.getY());
}



float Usecka::getUhol(const Usecka &other, char typ) const
{
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
      /*if((V.getX()/U.getX() == V.getY() / U.getY())) std::cout<<"Priamky su rovnobezne!";
      else cout<<"Priamky niesu rovnobezne!"<<endl;*/


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


return {V.getX()/U.getX() == V.getY() / U.getY()};

}

Usecka::Poloha Usecka::getPoloha(const Usecka &other) const
{

    /*Usecka::VR A = getVseobecna();
    Usecka::VR B = other.getVseobecna();
    float D1 = (A[0]*B[1]) - (A[1]*B[0]);
    float D2 = ((-A[2])*B[1]) - ((-B[2])*A[1]);
    float D3 = (A[0]*(-B[2])) - (B[0]*(-A[2]));
    //cout << D1<<";"<<D2<<";"<<D3<<endl;
    cout << "prienik X ma suradnicke"<<Bod2D((D2/D1),(D3/D1))<<endl;
    return Usecka::Poloha (nullptr, Bod2D((D2/D1),(D3/D1)));*/
    if(this->getTotozna(other))
    {
        return Usecka::Poloha((char *)"totozna",Bod2D{0,0});
    }
    if(this->getRovn(other))
    {
        return Usecka::Poloha((char *)"Rovnobezne",Bod2D{0,0});

    }
    auto A = this->getVseobecna();
    auto B = other.getVseobecna();
    float D = A[0] * B[1] - A[1] * B[0];
    float D1 = -A[2]*B[1] - A[1]* B[2] * (-1);
    float D2 = -A[0] * B[2] - B[0] * A[2] * -1;
    return Usecka::Poloha((char *)"Roznobezna",{D1/D,D2/D});

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

std::ostream &operator<<(std::ostream &os, const Usecka::VR &other)
{
    os<<showpos<<"Vseobecna rovnica: "<<(other.koeficienty[0])<<"x"<<(other.koeficienty[1])<<"y"<<(other.koeficienty[2])<<"=0"<< std::endl;
    return os;
}

Usecka Usecka::getOsUhla(const Usecka &other) const
{
    /*Usecka::Poloha AB = getPoloha(other);
    Bod2D X = AB.getPriesecnik();
    Vektor C = this->getSmer();
    Vektor D = other.getSmer();
    Vektor B1 = C.getJedn();
    Vektor B2 = D.getJedn();
    Vektor B3 = {-(B1.getY()+B2.getY()),(B1.getX()+B2.getX())};
    return Usecka::VR(B3.getX(),B3.getY(),-(B3.getX()*X.getX()+B3.getY()*X.getY()));*/
    /*Bod2D Z = C + D + X;
    auto os=Usecka(X,Z);
    cout<<os.getVseobecna();
    return os.getVseobecna();*/
    Bod2D A = this->getPoloha(other).getPriesecnik();
    Vektor z = this->getSmer().getJedn();
    Vektor B = other.getSmer().getJedn();
    Bod2D C = z+B+A;
    return {A,C};



}
bool Usecka::getTotozna(const Usecka &other) const
{
    VR A = this->getVseobecna();
    VR B = other.getVseobecna();
    return A[0]/B[0]==A[1]/B[1]==A[2]/B[2];
}

Usecka Usecka::getOs() const
{
    Bod2D stred=getCenter();
    return {stred,stred+getNormal()};
}

Usecka::operator VR() const {
    return getVseobecna();
}

Usecka::operator PR() const {
    return getParametricka();
}


Usecka::Poloha::Poloha(char *text, const Bod2D &prienik) : priesecnik(prienik)
{
        std::strncpy(popis,text,10);
        popis[10]='\0';
}

int Trojuholnik::generuj(int max) const
{
    /*std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int>distr(min,max);
    return distr(eng);*/
    return std::rand()%max;
}

bool Trojuholnik::existuje(Bod2D x, Bod2D y, Bod2D z) {
    float a = x.vzdialenost(y);
    float b = x.vzdialenost(z);
    float c = y.vzdialenost(z);
    try {

        if (!((a + b > c) * (a + c > b) * (b + c) > a)) {
            throw Trojuholnik::MsgErr("Trojuholnik s vrcholmi v tychto bodom neexistuje! ");
        }
        cout << "Trojuholnik existuje! " << endl;
    }
    catch (const Trojuholnik::MsgErr &e) {
        e.getMsg();
        return false;

    }
    return true;
}



    /*Usecka XY {(x),(y)};
    Usecka XZ{(x),(z)};
    Vektor X = XY.getSmer();
    Vektor Z = XZ.getSmer();
    return X.getX()/Z.getX()!=X.getY()/Z.getY();*/
    /*if((X.getX() / Z.getX() == X.getY() / Z.getY()))
    {
        std::cout<<"Trojuholnik neexistuje!";
        return 0;
    }
   else{
       std::cout<<"Trojuholnik existuje!";
        return 1;
                }
    }*/

Trojuholnik::Trojuholnik()
{
    /*Bod2D x{static_cast<float>(generuj(1,10)),static_cast<float>(generuj(1,10))};
    Bod2D y{static_cast<float>(generuj(1,10)),static_cast<float>(generuj(1,10))};
    Bod2D z{static_cast<float>(generuj(1,10)),static_cast<float>(generuj(1,10))};
    cout<<"Body su: "<<x << y << z;
    if(!existuje(x,y,z))
    {
        EXIT_FAILURE;
    }*/
    Bod2D x{static_cast<float>(generuj(10+1)),static_cast<float>(generuj(10+1))};
    Bod2D y{static_cast<float>(generuj( 10+1)),static_cast<float>(generuj(10+1))};
    Bod2D z{static_cast<float>(generuj(10+1)),static_cast<float>(generuj(10+1))};
    cout<<"Body su: "<<x << y<< z;
    if(!existuje(x,y,z))
    {
        EXIT_FAILURE;
    }

    /*if((Trojuholnik(A, B, C).existuje) == 1)
    {
        std::cout<<"Trojuholnik neexistuje!";
        std::cout <<A;
        cout<<B;
        cout<<C;
    }
    else
    {
        std::cout<<"Trojuholnik existuje!";
        cout<<A;
        cout<<B;
        cout<<C;
    }*/
}

float Trojuholnik::getVelkostStrany(char strana) const {
    if(strana == 'b')
   {
        return A.vzdialenost(C);
   }
   if(strana == 'c')
   {
       return A.vzdialenost(B);
   }
    else
   {
        return B.vzdialenost(C);
   }
}

float Trojuholnik::getObvod() const {

    return A.vzdialenost(B) + A.vzdialenost(C) + B.vzdialenost(C);
}

float Trojuholnik::getObsah() const
{
   float s = getObvod() /2;
   return(float)std::sqrt(s*(s-getVelkostStrany('a'))*(s-getVelkostStrany('b'))*(s-getVelkostStrany('c')));
}

/*Usecka Trojuholnik::getTaznica(char naStranu)const {

    if(naStranu == 'a')
    {
        return{Usecka(A,B.Stred(C))};
    }
    if(naStranu == 'b')
    {
        return{Usecka(B,A.Stred(C))};
    }
    if(naStranu == 'c')
    {
        return{Usecka(C,A.Stred(B))};
    }
    else
        return EXIT_FAILURE;*/


//}

Bod2D Trojuholnik::getTazisko() const {
    return Bod2D((C-(A.Stred(B)))*1/3+A.Stred(B));
}

Bod2D Trojuholnik::getOrtocentrum() const {
    /*Usecka OS1 = {(A),(B)};
    Usecka OS2 = {(A),(C)};
    Usecka OS12 = OS1.getOsUhla(OS2);
    Usecka OS3 = {(B),(C)};
    Usecka OS4 = {(B),(A)};
    Usecka OS34 = OS3.getOsUhla(OS4);
    Usecka::Poloha ret =(OS12.getPoloha(OS34));
    Bod2D ret1 = ret.getPriesecnik();*/
    return Usecka(getVyska('a')).getPoloha(getVyska('b')).getPriesecnik();
}

void Trojuholnik::getOpisanaKruznica() const
{
    /*Usecka AB = {(A),(B)};
    Bod2D X = Trojuholnik(A,B,C).getTazisko();
    float r = X.vzdialenost(A);
    cout<<"(x"<<-X.getX()<<")^2 + (y "<<-X.getY()<<")^2 = "<<r*r<<endl;*/


    Usecka osAB = Usecka(A, B).getOs();
    Usecka osBC = Usecka(B, C).getOs();
    Bod2D stredKruznice = osAB.getPoloha(osBC).getPriesecnik();
    float polomerKruznice= stredKruznice.vzdialenost(A);
    cout<<showpos<<"Opisana kruznica: (x"<<setprecision(2)<<stredKruznice.getX()<<")^2 + (y"<<setprecision(2)<<stredKruznice.getY()<<")^2 = "<<setprecision(2)<<std::noshowpos<<polomerKruznice*polomerKruznice<<endl;
}

void Trojuholnik::getVpisanaKruznica() const
{
    /*Bod2D X = Trojuholnik(A,B,C).getOrtocentrum();
    Bod2D Z = A.Stred(B);
    float r = X.vzdialenost(Z);
    cout<<"(x"<<-X.getX()<<")^2 + (y "<<-X.getY()<<")^2 = "<<r*r<<endl;*/
    Usecka Alfa = Usecka(A,B).getOsUhla(Usecka(A,C));
    Usecka Beta = Usecka(B,A).getOsUhla(Usecka(B,C));
    Bod2D stredKruznice = Alfa.getPoloha(Beta).getPriesecnik();
    Usecka VC = getVyska('c');
    Bod2D PVA = VC.getPoloha(Usecka(A,B)).getPriesecnik();
    float polomerKruznice = stredKruznice.vzdialenost(PVA);
    cout<<showpos<<"Vpisana kruznica: (x"<<setprecision(2)<<stredKruznice.getX()<<")^2 + (y"<<setprecision(2)<<stredKruznice.getY()<<")^2 = "<<setprecision(2)<<std::noshowpos<<polomerKruznice*polomerKruznice<<endl;



}

Usecka Trojuholnik::getEulerovaPriamka() const {
    return {getOrtocentrum(),getTazisko()};
}

Usecka Trojuholnik::getVyska(char naStranu) const {
        Vektor smer;
        Bod2D bodNaVyske;
        switch (naStranu)
        {
            case 'a':
                smer = Usecka(C,B).getNormal();
                bodNaVyske= {smer+A};
                return {bodNaVyske,A};
            case 'b':
                smer = Usecka(A,C).getNormal();
                bodNaVyske = {smer+B};
                return {bodNaVyske,B};
            case 'c':
                smer = Usecka(A,B).getNormal();
                bodNaVyske = {smer+C};
                return {bodNaVyske,C};
            default:
                smer = Usecka(C,B).getNormal();
                bodNaVyske= {smer+A};
                return {bodNaVyske,A};
        }
    }

void Trojuholnik::getKruznicaDeviatichbodov() const {

    Bod2D S = A.Stred(B); // iba na vypocet r
    Bod2D Ta = getTazisko();
    Bod2D Or = getOrtocentrum();
    Bod2D K = Ta.Stred(Or);
    float r = (Ta.vzdialenost(S)/2);
    //cout << "stred ma v: " << K << "a polomer: " << r << endl;
    cout << "Kruznica 9 bodov je: ( x - " << K.getX() << ")^2 + ( y - " << K.getY() << ")^2 = " << (r*r) << endl;
}

float Trojuholnik::getVlStrany(char strana)const
{
    float vysledok;
    while(true)
    {
        try
        {
            switch(strana)
            {
                case 'a':
                    vysledok=B.vzdialenost(C);
                    break;
                case 'b':
                    vysledok=A.vzdialenost(C);
                    break;
                case 'c':
                    vysledok=A.vzdialenost(B);
                    break;
                default:
                    throw Trojuholnik::MsgErr("Taka strana nie je!");
            }
            return vysledok;
        }
        catch (const Trojuholnik::MsgErr &e)
        {
            e.getMsg();
            cout<<" Zadaj stranu:";
            cin>>strana;
            continue;
        }
    }


    }

void Trojuholnik::ShowS() const
{
    cout<<"Strany trojuholnika: ";
    cout<<setw(5)<<setprecision(3)<<"a= "<<getVlStrany('a')<<setw(5)<<"b="<<getVlStrany('b')<<setw(5)<<"c="<<getVlStrany('c')<<endl;
}

float Trojuholnik::getVelUhla(char * uhol) const
{
    float vysledok;
    while(true)
    {
        try
        {
            if (strcmp(uhol,"alfa")==0)
            {
                vysledok=Usecka(A,B).getUhol(Usecka(A,C));
            }
            else if(strcmp(uhol,"beta")==0)
            {
                vysledok=Usecka(B,A).getUhol(Usecka(B,C));
            }
            else if(strcmp(uhol,"gama")==0)
            {
                vysledok=Usecka(C,A).getUhol(Usecka(C,B));
            }
            else
            {
                throw Trojuholnik::MsgErr("Taky uhol v trojuholniku ABC nie je!");
            }
            return vysledok ;
        }
        catch (const Trojuholnik::MsgErr & e)
        {
            e.getMsg();
            cout<<" Zadaj spravny uhol (alfa,beta,gama): ";
            cin>>uhol;
            continue;
        }
    }

}

void Trojuholnik::ShowU()const
{
    cout<<"Uhly trojuholnika:(stupne) ";
    cout<<setw(5)<<setprecision(3)<<"alfa = "<<getVelUhla((char *)"alfa")<<setw(5)<<" beta = "<<getVelUhla((char *)"beta")<<setw(5)<<" gama = "<<getVelUhla((char *)"gama")<<endl;
}


void Trojuholnik::MsgErr::getMsg() const
{
    cout<<msg;
}