#include <iostream>
#include "hlava.h"
#include<cmath>
#include<fstream>
#include"inout.h"
#define PI 3.14159265
int comp(const void *prva, const void *druha);
using namespace inout;
int main()
{
    srand(time(NULL));
    //int data[4];
    //float V, Min=1000,z=1,k=0;

    /*std::ofstream output;
    std::ifstream input;
    try
    {
        input.open("suradnice.txt");
        if(!input.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }
        Bod2D A;
        Bod2D B;
        input>>A>>B;
        Bod2D Temp1;
        Bod2D Temp2;
        float min = A.vzdialenost(B);
        float tmp;
        for(int i=0; i<100; ++i)
        {
            if(input>>A>>B,(tmp=A.vzdialenost(B))<min)
            {
                Temp1 = A;
                Temp2=B;
                min=tmp;
            }
            /*for (int & i : data)
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
            z++;*/
        //}
       /* input.close();
        input.open("suradnice.txt");
        Bod2D::getSortedDistance(input);
        input.close();
        std::cout<<"Najmensia vzdialenost je "<<min<<" medzi bodmi "<<Temp1<<" "<<Temp2<<std::endl;



    }



    catch (const Bod2D::streamError & ex)
    {
        ex.getMsg();
        return 1;
    }
*/



    /*Bod2D A(5,6);
    Bod2D B(7,8);
    Usecka AB {(A),(B)};
    std::cout<<"Usecka AB ma suradnice: "<<AB;
    Vektor F = (AB.getSmer());
    std::cout<<"Smernicovy vektor je : "<<F<<std::endl;
    Vektor FN = AB.getNormal();
    std::cout<<"Usecka ma stred v bode: "<<AB.getCenter()<<std::endl;
    std::cout<<"Normala usecky je : "<<FN<<std::endl;*/
    /*Bod2D A(1,3);
    Bod2D B(3,7);
    Bod2D C(5,8);
    Bod2D D(2,12);
    Usecka AB{A,B};
    Usecka CD{C,D};


    std::cout<<Usecka(A,B).getVseobecna();
    std::cout<<Usecka(A,B).getParametricka()<<std::endl;
    std::cout<<Usecka(A,B).getOs();
    std::cout<<"Uhol medzi useckami je : "<<std::endl<<Usecka(A,B).getUhol(Usecka(C,D))<<std::endl;
    Usecka(A,B).getRovn(Usecka(C,D));
    Usecka(A,B).getPoloha(Usecka(C,D));
    std::cout<<"Vseobecna rovnica osi uhla je : "<<AB.getOsUhla(CD)<<std::endl;*/
    Bod2D A (4,10);
    Bod2D B(2,12);
    Bod2D C (10,15);
    Trojuholnik ABC {A,B,C};
    Trojuholnik().getVelkostStrany('b');
    cout<<Trojuholnik(A,B,C).getVelkostStrany('b')<<endl;
    cout<<"Obvod trojuholnika je : "<<ABC.getObvod()<<endl;
    cout<<"Obsah trojuholnika je : "<<ABC.getObsah()<<endl;
    cout<<"Tazisko ma suradnice: "<<setprecision(2)<<ABC.getTazisko()<<endl;
    //cout<<"Taznica na stranu a ma: "<<Trojuholnik(A,B,C).getTaznica('a');
    cout<<"Ortocentrum je : "<<setprecision(2)<<ABC.getOrtocentrum()<<endl;
    Trojuholnik(A,B,C).getOpisanaKruznica();
    Trojuholnik(A,B,C).getVpisanaKruznica();
    cout<<"Eulerova priamka: "<<(Usecka::VR)ABC.getEulerovaPriamka()<<endl;
    ABC.getKruznicaDeviatichbodov();
    ABC.ShowS();
    ABC.ShowU();
    /*Bod2D C(1,6);
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
/*Bod2D::Bod2D()
{
    /*std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;*/
//}
/*Bod2D::Bod2D(float mojeX)
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


/*float Bod2D::getX() const
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



/*Bod2D Bod2D::operator*(float cislo)const
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
/*double Bod2D::vzdialenost(const Bod2D &other)const {

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


/*void Bod2D::streamError::getMsg() const
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


/*Bod2D Usecka::getCenter() const {
    //return Bod2D{(((X.getX())+(Y.getX()))/2),(((X.getY())+(Y.getY())))};
    //X.vzdialenost(Y)/2;
    return(X+Y)/2;
}
Vektor Usecka::getNormal() const
{
    /*Vektor premenna = getSmer();

    return Vektor{(premenna.getY()), -(premenna.getX())};*/
  /*  Bod2D tmp = Y-X;

    return {-tmp.getY(), tmp.getX()};

}*/




/*int comp(const void *prva, const void *druha )
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





  /*Usecka::VR Usecka::getVseobecna() const
{
    Vektor XY= getNormal();
    //cout << XY << endl;
    float C = (XY.getX() * X.getX() + XY.getY() * X.getY());
    return Usecka::VR(XY.getX(), XY.getY(), -C );
}

std::ostream &operator<<(std::ostream &os, const Usecka::VR &other)
{
    os<<showpos<<(other.a)<<"x"<<(other.b)<<"y"<<(other.c)<<"=0"<< std::endl;
    return os;
}


std::ostream &operator<<(std::ostream &os, const Usecka::PR &other) {
  os<<showpos<<"x = "<<(other.koeficienty[0])<<other.koeficienty[1]<<"t"<<std::endl<<showpos<<"y ="<<(other.koeficienty[2])<<other.koeficienty[3]<<"t";

  return os;
  }




/*Usecka::PR Usecka::getParametricka() const {
    Vektor AB = getSmer();
    return Usecka::PR(X.getX(), AB.getX(), X.getY(), AB.getY());
}

/*Usecka::VR Usecka::getOs() const {
      Vektor Z = getSmer();
      Bod2D L = getCenter();
      float C = Z.getX()*L.getX()+Z.getY()*L.getY();
      return Usecka::VR(Z.getX(),Z.getY(), -C);
}

/*float Usecka::getUhol(const Usecka &other, char typ) const {
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



/*void Usecka::getRovn(const Usecka &other)const
{
  /*
   bool -->
    Vektor s1 =  this->getSmer();
    Vektor s2 = other.getSmer();
    return (s1.getX()/s2.getX() == s1.getY() / s2.getY());
///

      Vektor V = getNormal();
  Vektor U = other.getNormal();
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
}*/

/*float Bod2D::getDlz() const
{
    //cout<<sqrt((getX()*getX()) + (getY()*getY()))<<endl;
    return sqrt(pow(getX(),2) + (pow(getY(),2)));
}*/