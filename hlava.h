//
// Created by User on 15. 1. 2021.
//

#ifndef BOD2D_HLAVA_H
#define BOD2D_HLAVA_H

class Bod2D
{
private:
    float x{};
    float y{};

public:
    float getX() const;
    float getY() const;
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
    friend Bod2D operator *(float cislo, Bod2D &other);
    friend Bod2D operator /(float cislo, Bod2D &other);
    double vzdialenost(const Bod2D & other)const;
    void Stred(const Bod2D & other);
    double vzdialenost0() const;

};




#endif //BOD2D_HLAVA_H
