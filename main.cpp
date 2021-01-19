#include <iostream>
#include "hlava.h"
#include <math.h>

int main()
{

    Bod2D Prvy;
    Bod2D Druhy(5);
    /*Bod2D Treti(5,5);
    std::cout<<"Prva suradnica x je: "<<Prvy.getx()<<std::endl;
    std::cout<<"Druha suradnica y je: "<<Prvy.gety()<<std::endl;*/
    //std::cout<<Bod2D()<<Bod2D(3)<<Bod2D(1,6);
    //std::cin>>Bod2D;
    //std::cout<<Bod2D();
    Prvy.spocitaj(Druhy).vypisBod();
    Prvy.odcitaj(Druhy).vypisBod();
    Prvy= Prvy*3;
    Prvy.vypisBod();
    Prvy= Prvy/3;
    Prvy.vypisBod();

    return 0;
}

Bod2D::Bod2D(float getx, float gety)
{
    x=getx;
    y=gety;
}

Bod2D::Bod2D()
{

    std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;
}

Bod2D::Bod2D(float getx)
{
    x = getx;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;
}

/*Bod2D::Bod2D(float gety)
{
    y = gety;
    std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
}*/

float Bod2D::getx() const
{
    return  x;
}

float Bod2D::gety() const
{
    return y;

}

void Bod2D::setSuradnicax(float getx)
{
    x = getx;
}

void Bod2D::setSuradnicay(float gety)
{
    y = gety;
}

std::ostream &operator<<(std::ostream &os, const Bod2D &other)
{
    os<<"Bod ma ["<<other.x<<","<<other.y<<"]"<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Bod2D &other)
{
    std::cout<<"zadaj x";
    is>>other.x;
    std::cout<<"zadaj y";
    is>>other.y;

    return is;
}
void Bod2D::vypisBod() const
{
    std::cout <<"Bod ma suradnice ["<<x<<","<<y<<"]"<<std::endl;
}

Bod2D Bod2D::spocitaj(const Bod2D &other) const
{
     return {(x+other.x), (y+other.y)};
}

Bod2D Bod2D::odcitaj(const Bod2D &other) const
{
    return {(x-other.x), (y-other.y)};
}

Bod2D Bod2D::operator*(float cislo) const
{
    return {(x*cislo), (y*cislo)};
}

Bod2D Bod2D::operator/(float cislo) const
{
    return {(x/cislo), (y/cislo)};
}
/*
Bod2D Bod2D::vzdialenosť(const Bod2D &other) const
{
    return {sqrt(((other.x*other.x)-(x*x))+((y*y)+(other.y*other.y)))};
}*/
