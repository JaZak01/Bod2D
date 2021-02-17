
#include <iostream>
#include "hlava.h"
#include "inout.h"
#include <cmath>
#include <string>
#define PI 3.14159265

using namespace inout;

int comp (const void *prva, const void *druha);

Bod2D::Bod2D(float mojx, float mojy):x(mojx),y(mojy)
{

}

Bod2D::Bod2D()
{
/*
    std::cout<<"Zadaj suradnicu x: ";
    std::cin>>x;
    std::cout<<"Zadaj suradnicu y: ";
    std::cin>>y;*/
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
    os<<"["<<other.x<<","<<other.y<<"]";
    return os;
}

std::istream &operator>>(std::istream &is, Bod2D &other)
{
    is >> other.x >> other.y;
    /*std::cout<<"zadaj x";
    is>>other.x;
    std::cout<<"zadaj y";
    is>>other.y;*/

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
    return {(x+other.x), (y+other.y)};
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

Bod2D Bod2D::Stred(const Bod2D & other)
{

    return Bod2D (((x+other.x)/2),((y+other.y)/2));
    //std::cout<< "Stred medzi bodmi je: " << other/2 << std::endl;
}

void Bod2D::vysortovanie(std::istream &fin)
{
    Usecka dialky[100];
    for(auto & i : dialky)
    {
        fin>>i;

    }
    qsort(dialky, 100, sizeof(Usecka),comp);

    std :: cout <<"utriedene:"<< std::endl;
    for (int i = 0;i<100;++i)
    {
        std::cout<<dialky[i].getDlzka()<<" "<<dialky[i];
    }

}

void Bod2D::minimalVzd(std::istream &fin)
{
    float min = 0;
    float teraz = 0;
    int riadok;

    Bod2D a;
    Bod2D b;
    fin >> a >> b;
    min = a.vzdialenost(b);

    for(int j  = 1; j <= 100;++j)
    {
        fin >> a >> b;
        teraz = a.vzdialenost(b);

        if (teraz < min)
        {
            riadok = j;
            min = teraz;
        }
    }
    std :: cout <<"najmensia vzdialenost je "<< min <<" v riadku " << riadok << std::endl;
}

float Bod2D::getDlzka() const
{
    //cout<<sqrt((getx()*getx()) + (gety()*gety()))<<endl;
    return sqrt((getx()*getx()) + (gety()*gety()));
}

/*
void Bod2D::sortovanie()
{

}*/

void Bod2D::streamError::getMsg() const
{
    std::cout<<msg;
}

std::ostream &operator<<(std::ostream &os, const Usecka &usecka)
{
    os<<usecka.X<<usecka.Y<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Usecka &usecka)
{
    is >> usecka.X >> usecka.Y;
    return is;
}

float Usecka::getDlzka() const
{
    return X.vzdialenost(Y);
}

bool Usecka::operator<(const Usecka &other) const
{
    return this->getDlzka()<other.getDlzka();
}

bool Usecka::operator>(const Usecka &other) const
{
    return this -> getDlzka()>other.getDlzka();
}

Vektor Usecka::getSmer() const
{
    //return Vektor{((X.getx())-(Y.getx())), ((X.gety())-(Y.gety()))};
    return Y-X;
}

Vektor Usecka::getNormal() const
{
    Vektor premenna = getSmer();
    //return Vektor{(premenna.gety()), -(premenna.getx())};
    return {-premenna.gety(),premenna.getx()};
}

Bod2D Usecka::getStredovyusecky() const
{
    //return Bod2D{(((X.getx())+(Y.getx()))/2), (((X.gety())+(Y.gety()))/2)};
    return (X+Y)/2;
}

int comp(const void *prva, const void *druha)
{
    Usecka * A = (Usecka *)prva;
    Usecka * B = (Usecka *)druha;

    //return ((*A)<(*B)?1:((*A)>(*B))?(-1):);
    //return (*A)<(*B);
/*
    if ((*A)<(*B))
    {
        return -1;
    }
    if ((*A)>(*B))
    {
        return 1;
    }*/
    float adist=A->getDlzka();
    float bdist=B->getDlzka();
    return (adist>bdist)-(adist<bdist);
}

std::ostream &operator<<(std::ostream &os, const Usecka::VseRov &other)
{
    os<<showpos<<"Vseobecna rovnica: "<<(other.koeficienty[0])<<"x"<<(other.koeficienty[1])<<"y"<<(other.koeficienty[2])<<"=0"<< std::endl;
    return os;
}

Usecka::VseRov Usecka::getVseo() const
{
    Vektor XY= getNormal();
    //cout << XY << endl;
    float C = (XY.getx() * X.getx() + XY.gety() * X.gety());
    cout<<Usecka::VseRov(XY.getx(), XY.gety(), -C );
    return Usecka::VseRov(XY.getx(), XY.gety(), -C );
}

std::ostream &operator<<(std::ostream &os, const Usecka::ParRov &other)
{
    os<<showpos<<"Parametricka rovnica: "<<endl<< "x=" <<(other.koeficienty[0])<<"+t.("<<(other.koeficienty[1])<<")"<<endl<<"y=" <<(other.koeficienty[2])<<"+t.("<<(other.koeficienty[3])<<")   t patri R"<<endl;
    return os;
}

Usecka::ParRov Usecka::getPar() const
{
    Vektor pomocny=getSmer();
    cout<<Usecka::ParRov(X.getx(), pomocny.getx(), X.gety(), pomocny.gety());
    return Usecka::ParRov(X.getx(), pomocny.getx(), X.gety(), pomocny.gety());
}

Usecka::operator VseRov() const
{
    return getVseo();
}

Usecka::operator ParRov() const
{
    return getPar();
}

Usecka::VseRov Usecka::getOs() const
{
    getVseo();
    Vektor Sm = getSmer();
    Vektor St = getStredovyusecky();
    float C = (Sm.getx() * St.getx() + Sm.gety() * St.gety());
    cout<< Usecka::VseRov(Sm.getx(), Sm.gety(), (-C));
    return Usecka::VseRov(Sm.getx(), Sm.gety(), (-C));
}

float Usecka::getUhol(const Usecka &other, char typ) const
{
    Vektor jed = getSmer();
    Vektor dva = other.getSmer();
    float Dl1 = jed.getDlzka();
    float Dl2 = dva.getDlzka();
    cout << "pre vysledok v stupnoch stlacte s, inak je vypis v radianoch"<<endl;
    cin >> typ;
    if (typ == 's')
    {
        float par = (acos (((jed.getx()*dva.getx())+(jed.gety()*dva.gety()))/(Dl1*Dl2)))*(180/PI);
        cout << par<<endl;
    }
    else //if (typ == 'r')
    {
        float par = acos (((jed.getx()*dva.getx())+(jed.gety()*dva.gety()))/(Dl1*Dl2));
        cout << par<<endl;
    }
    return 0;
}

/*
void Usecka::JeToNula(const Usecka &other) const
{
    Vektor jed = getSmer();
    Vektor dva = other.getSmer();

    if ((jed.getx() == dva.getx()) && (jed.gety() == dva.gety()))
    {
        cout << "su totozne" << endl;
    }
    else if (((jed.getx() == dva.getx()) || (jed.gety() == dva.gety())) || ((jed.getx() / dva.getx()) == (jed.gety() / dva.gety())))
    {
        cout << "su rovnobezne rozne" << endl;
    }
        else if ((jed.getx() / dva.getx()) == (jed.gety() / dva.gety()))
        {
            cout << "su rovnobezne rozne"<< endl;
        }
    else
    {
        cout <<"nie su rovnobezne"<< endl;
    }

    float Dl1 = jed.getDlzka();
    float Dl2 = dva.getDlzka();
    float par = acos (((jed.getx()*dva.getx())+(jed.gety()*dva.gety()))/(Dl1*Dl2));
    if (par == 0)
    {
        cout << "Su rovnobezne."<<endl;
    }
    else
    {
        cout << "nie su rovnobezne."<<endl;
    }

}*/

float Usecka::getUholR(const Usecka &other, char typ) const
{
    Vektor jed = getSmer();
    Vektor dva = other.getSmer();
    float Dl1 = jed.getDlzka();
    float Dl2 = dva.getDlzka();
    float cislo = (((jed.getx()*dva.getx())+(jed.gety()*dva.gety()))/(Dl1*Dl2));

    (typ == 'o')?cout <<"Uhol je "<<acos(cislo)<< " rad alebo ":cout <<acos(cislo)*(180/PI)<<" st"<<endl;
    return  (typ == 'o')?std::acos(cislo):std::acos(cislo)*(180/PI);

}

bool Usecka::jeRovnobezna(const Usecka &other) const
{
    Vektor jed = this -> getSmer();
    Vektor dva = other.getSmer();
    if (jed.getx() / dva.gety() != jed.gety() / dva.gety())
    {
        this->getPoloha(other);
    }
    return (jed.getx() / dva.gety() == jed.gety() / dva.gety());
}



Usecka::Poloha Usecka::getPoloha(const Usecka &other) const
{

        Usecka::VseRov pomocna = getVseo();
        Usecka::VseRov pomocna1 = other.getVseo();
        float D1 = (pomocna[0]*pomocna1[1]) - (pomocna1[0]*pomocna[1]);
        float D2 = ((-pomocna[2])*pomocna1[1]) - ((-pomocna1[2])*pomocna[1]);
        float D3 = (pomocna[0]*(-pomocna1[2])) - (pomocna1[0]*(-pomocna[2]));
        cout << D1<<";"<<D2<<";"<<D3<<endl;
        //Bod2D X ((D2/D1),(D3/D1));
        cout << "prienik X ma suradnicke"<<Bod2D((D2/D1),(D3/D1))<<endl;
        return Usecka::Poloha (nullptr, Bod2D((D2/D1),(D3/D1)));

}

Usecka::Poloha::Poloha(char *text, const Bod2D &prienik)
{
    popis[0] = 'X';
    priesecnik = Bod2D(0,0);
}
