//
// Created by User on 15. 1. 2021.
//

#ifndef BOD2D_HLAVA_H
#define BOD2D_HLAVA_H
#include<iosfwd>
class Bod2D
{
private:
    float x{};
    float y{};

public:
    float getX()/*{return x;}*/ const;
    float getY()/*{return y;}*/ const;
    void setX (float mojeX);
    void setY (float mojeY);
    Bod2D();
    Bod2D(float mojeX, float mojeY);
    explicit Bod2D(float mojeX);
    friend std::ostream & operator <<(std::ostream & os, const Bod2D & other);
    friend std::istream & operator>>(std::istream & is, Bod2D & other);
    Bod2D operator-(const Bod2D & other)const;
    Bod2D operator+(const Bod2D & other)const;
    void vypisBod() const;
    Bod2D operator*(float cislo)const;
    Bod2D operator/(float cislo)const;
    friend Bod2D operator *(float cislo, const Bod2D &other);
    //friend Bod2D operator /(float cislo, Bod2D &other);
    double vzdialenost(const Bod2D & other=Bod2D(0,0))const;
    Bod2D Stred(const Bod2D & other) const;
    //static void MVzdialenost(std::istream & is);
    static void getSortedDistance(std::istream & input);
    float getDlz() const;
    Bod2D getJedn() const;

public:
    class streamError
    {
        const char*msg;
    public:
        explicit streamError(const char *sprava):msg(sprava){};
        void getMsg() const;

    };

};
using Vektor = Bod2D;

class Usecka
{



private:
    Bod2D X{0,0};
    Bod2D Y{0,0};
public:
    class VR
    {
    private:
        //float a;
        //float b;
        //float c;
        float koeficienty[3];
    public:
        //VR(float ka, float kb, float kc):a(ka),b(kb),c(kc){};
        friend std::ostream & operator<<(std::ostream & os, const VR &other);
        //friend std::ostream & operator<<(std::ostream & os,const VR &other);
        VR(float ka, float kb, float kc):koeficienty{ka,kb,kc}{};
        float & operator[](int index){return koeficienty [index];};
        const float & operator[](int index) const{return koeficienty [index];}
    };
    class PR {
    private:
        float koeficienty[4];
    public:
        PR(float ka1, float kv1, float ka2, float kv2):koeficienty{ka1,kv1,ka2,kv2}{};
        friend std::ostream &operator<<(std::ostream & os,const PR & other);
        float & operator[](int index){return koeficienty[index];};
        const float & operator[](int index) const{return koeficienty[index];}
    };
    class Poloha
    {
    private:
        char popis[11];
        Bod2D priesecnik;
    public:
        Poloha(char *text, const Bod2D& prienik);
        Bod2D getPriesecnik()const{return priesecnik;};
        friend std::ostream &operator<<(std::ostream &os, const Poloha &poloha);


    };



    Usecka(){};
    Usecka(Bod2D A, Bod2D B):X(A),Y(B){};
    explicit Usecka(Bod2D A):X(A),Y(A){};
    friend std::ostream & operator<<(std::ostream & os,const Usecka & usecka);
    friend std::istream & operator>>(std::istream & is, Usecka & usecka);
    bool operator<(const Usecka &other) const;
    bool operator>(const Usecka &other) const;
    float getDlzka() const;
    Vektor getNormal()const;
    Vektor getSmer()const;
    Bod2D getCenter() const;
    VR getVseobecna() const;
    PR getParametricka()const;
    Usecka getOs()const;
    float getUhol(const Usecka &other, char typ='r') const;
    bool getRovn(const Usecka &other) const;
    Poloha getPoloha(const Usecka & other) const;
    Usecka getOsUhla(const Usecka &other) const;
    bool getTotozna(const Usecka &other) const;






};
class Trojuholnik
        {
    class MsgErr : public std::exception
    {
    private:
        const char *msg;
    public:
        explicit MsgErr(const char * sprava):msg(sprava){};
        void getMsg() const;

    };
        private:
    Bod2D A;
    Bod2D B;
    Bod2D C;
    static bool existuje(Bod2D x,Bod2D y, Bod2D z);
    int generuj(int min ,int max)const;
public:
    Trojuholnik (Bod2D x,Bod2D y, Bod2D z):A(x),B(y),C(z){;};
    Trojuholnik();
    float getVelkostStrany(char strana='a')const;
    float getObvod() const;
    float getObsah() const;
    Bod2D getTazisko() const;
    Bod2D getOrtocentrum(Usecka &other) const;
    Usecka getVyska(char naStranu)const;
    Usecka getTaznica(char naStranu) const;

        };



#endif //BOD2D_HLAVA_H
