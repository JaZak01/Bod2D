#include <iostream>
#include "hlava.h"
#include <math.h>
#include<fstream>
#include <string>
using namespace std;

int main()
{
    std::ofstream fout;
    std::ifstream fin;
    std::string line;
    int miesto[4];
    float min = 5000;
    float teraz = 0;
    int riadok;

    try
    {
        fin.open("suradnice.txt");
        if(!fin.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }


        for(int j  = 0; j < 100;++j)
        {
            for (int & i : miesto)
            {
                fin >> i;
            }
            Bod2D prvy(miesto[0], miesto[1]);
            Bod2D druhy(miesto[2], miesto[3]);
            //std::cout<< "Vzdialenost bodov je: " <<prvy.vzdialenost(druhy) << std::endl;
            teraz = prvy.vzdialenost(druhy);
            //std :: cout << teraz<< "\n";
            if (teraz < min)
            {
                riadok = j;
                min = teraz;
            }
        }
        std :: cout <<"najmensia vzdialenost je "<< min <<" v riadku " << riadok << std::endl;
        fin.close();
    }

    catch (const Bod2D::streamError & ex)
    {
        ex.getMsg();
        return 1;
    }

/*
    Bod2D Prvy;
    Bod2D Druhy(5);
    //Bod2D Treti(0,0);

    std::cout<<"Prva suradnica x je: "<<Prvy.getx()<<std::endl;
    std::cout<<"Druha suradnica y je: "<<Prvy.gety()<<std::endl;
    std::cout<<Bod2D()<<Bod2D(3)<<Bod2D(1,6);
    std::cin>>Bod2D;

    std::cout<<Bod2D();
    std::cout<<Prvy+Druhy;
    std::cout<<Prvy-Druhy;
    std::cout<<Prvy*3;
    std::cout<<Prvy/3;


    std::cout<< Prvy*2 << std::endl;
    std::cout<< 2*Prvy << std::endl;
    //std::cout<< "Vzdialenost bodu od nuly je: " <<Prvy.vzdialenostodnuly() << std::endl;
    //std::cout<< "Stred bodov je: "<<Prvy.Stred(Druhy)<< std::endl;
    std::cout<< "Vzdialenost bodov je: " <<Prvy.vzdialenost(Druhy) << std::endl;
    std::cout<< "Vzdialenost bodu od nuly je: " <<Prvy.vzdialenost() << std::endl;
    //Prvy.Stred(Druhy);*/

    return 0;
}

Bod2D::Bod2D(float mojx, float mojy):x(mojx),y(mojy)
{

}

Bod2D::Bod2D()
{

    std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;
}

Bod2D::Bod2D(float mojx)
{
    x = mojx;
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
    os<<"Bod  ["<<other.x<<","<<other.y<<"]"<<std::endl;
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
/*
float Bod2D::vzdialenostodnuly() const
{
    return sqrt((x*x)+(y*y));
}*/

Bod2D Bod2D::Stred(const Bod2D &other)
{

    return Bod2D (((x+other.x)/2),((y+other.y)/2));
    //std::cout<< "Stred medzi bodmi je: " << other/2 << std::endl;
}

void Bod2D::streamError::getMsg() const
{
    std::cout<<msg;
}
/*
void Bod2D::nacitajBody(float line)
{
    Bod2D prvy (line);

    std::cout <<"["<<prvy<<"]"<<std::endl;
}*/



