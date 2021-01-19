//
// Created by User on 15. 1. 2021.
//

#ifndef BOD2D_HLAVA_H
#define BOD2D_HLAVA_H

class bod2d
{
private:
    float x;
    float y;

public:
    float getX() const;
    float getY() const;
    void setX (float mojeX);
    void setY (float mojeY);
    void rnd();
    bod2d();
    bod2d(float mojeX, float mojeY);
    explicit bod2d(float mojeX);
    //explicit bod2d(float mojeY);
    friend std::ostream & operator <<(std::ostream & os, const bod2d & other);
    friend std::istream & operator>>(std::istream & is, bod2d & other);
    bod2d spocitaj(const bod2d &other)const;
    bod2d odcitaj(const bod2d &other)const;
    bod2d vynasob(const bod2d, float cislo)const;
    void vypisBod() const;
    bod2d operator*(float cislo)const;
};




#endif //BOD2D_HLAVA_H
