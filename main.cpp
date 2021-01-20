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
    /*
    Prvy=Prvy+Druhy;
    std::cout<<Prvy;
    Prvy=Prvy-Druhy;
    std::cout<<Prvy;
    Prvy= Prvy*3;
    std::cout<<Prvy;
    Prvy= Prvy/3;
    std::cout<<Prvy;*/
    /*
    std::cout<< Prvy*2 << std::endl;
    std::cout<< 2*Prvy << std::endl;*/
    //std::cout<< "Vzdialenost bodu od nuly je: " <<Prvy.vzdialenostodnuly() << std::endl;
    std::cout<< "Vzdialenost bodov je: "<<Prvy.vzdialenost(Druhy)<< std::endl;
    Prvy.Stred(Druhy);

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
    std::cout <<"["<<x<<","<<y<<"]"<<std::endl;
}
/*
Bod2D Bod2D::spocitaj(const Bod2D &other) const
{
     return {(x+other.x), (y+other.y)};
}

Bod2D Bod2D::odcitaj(const Bod2D &other) const
{
    return {(x-other.x), (y-other.y)};
}*/

Bod2D Bod2D::operator*(float cislo) const
{
    return {(x*cislo), (y*cislo)};
}

Bod2D Bod2D::operator/(float cislo) const
{
    return {(x/cislo), (y/cislo)};
}

Bod2D operator*(float cislo, Bod2D &other)
{
    return {(cislo*other.x),(cislo*other.y)};
}
Bod2D operator/(float cislo, const Bod2D & other)
{
    return {(cislo/other.x),(cislo/other.y)};
}

Bod2D Bod2D::operator+(const Bod2D &other) const
{
    return {(x+other.x), (y+other.y)};;
}

Bod2D Bod2D::operator-(const Bod2D &other) const
{
    return{(x-other.x), (y-other.y)};
}

float Bod2D::vzdialenost(const Bod2D &other) const
{
    return sqrt(((x-other.x)*(x-other.x))+((y-other.y)*(y-other.y)));
}

float Bod2D::vzdialenostodnuly() const
{
    return sqrt((x*x)+(y*y));
}

void Bod2D::Stred(const Bod2D &otherBod)
{

    Bod2D other(x+otherBod.x,y+otherBod.y);
    std::cout<< "Stred medzi bodmi je: " << other/2 << std::endl;
}

