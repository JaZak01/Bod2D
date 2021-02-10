#include <iostream>
#include "hlava.h"
#include "inout.h"
#include <cmath>
#include <string>

//using namespace std;
using namespace inout;

int comp (const void *prva, const void *druha);

int main()
{


    Bod2D Prvy(1,3);
    Bod2D Druhy(3,7);
    Usecka Prva{(Prvy),(Druhy)};
    //Usecka::VseRov pokus = Prva.getVseo();
    Usecka::ParRov pokus = Prva.getPar();
    (Usecka::VseRov)Prva;
    (Usecka::ParRov)Prva;
    //cout<<Prva.getVseo();
    //cout<<pokus;
    /*
    std::cout<<Prva;
    //std::cout<<Prva.getSmer(Prva)<<std::endl;
    Vektor Adam = (Prva.getSmer());
    std::cout<<Adam<<std::endl;
    Vektor Norm = Prva.getNormal();
    std::cout<<Prva.getStredovyusecky()<<std::endl;
    //Bod2D Stredovy = (Prva.getStredovyusecky());
    std::cout<<Norm<<std::endl;*/

    /*
    std::ofstream fout;
    std::ifstream fin;
    //std::string line;
    //int miesto[4];
    float min = 0;
    float teraz = 0;
    int riadok;
    //Bod2D usecky [100];*/

/*
    try
    {
        fin.open("suradnice.txt");
        if(!fin.is_open()) {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }
        Bod2D a;
        Bod2D b;
        fin >> a >> b;
        min = a.vzdialenost(b);


        for(int j  = 1; j <= 100;++j)
        {
            fin >> a >> b;

            for (int & i : miesto)
            {
                fin >> a >> b;

            }
            //Bod2D prvy(miesto[0], miesto[1]);
            //Bod2D druhy(miesto[2], miesto[3]);
            //std::cout<< "Vzdialenost bodov je: " <<prvy.vzdialenost(druhy) << std::endl;
            teraz = a.vzdialenost(b);
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
    }*/
/*
    try
    {
        Usecka dialky[100];
        fin.open("suradnice.txt");
        if(!fin.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }
        for(auto & i : dialky)
        {
            fin >> i;
        }
        qsort(dialky, 100, sizeof(Usecka),comp);
        std :: cout <<"utriedene:"<< std::endl;
        fout.open("vypis.txt");
        if(!fout.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }

        for (int i = 0;i<100;++i)
        {
            std::cout<<dialky[i].getDlzka()<<" "<<dialky[i];
            fout<<dialky[i].getDlzka()<<" "<<dialky[i]; //da sa to spravit v jednom cykle, naco dva....
        }
        fout.close();
        fin.close();
    }
    catch (const Bod2D::streamError & ex)
    {
        ex.getMsg();
        return 1;
    }*/
/*
    try
    {
        Usecka dialky[100];
        fin.open("suradnice.txt");
        if(!fin.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }
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
        fout.open("vypis.txt");
        for(auto & i : dialky)
        {
            fout<<i;
        }
        fout.close();
        fin.close();
    }

    catch (const Bod2D::streamError & ex)
    {
        ex.getMsg();
        return 1;
    }



    try
    {
        fout.open("vypis.txt");

        if(!fout.is_open())
        {
            throw Bod2D::streamError("Pri praci so suborom sa vyskytla chyba!");
        }

        for(auto & i : dialky)
        {
            fout<<i;

        }

        fout.close();
    }
    catch (const Bod2D::streamError & ex)
    {
        ex.getMsg();
        return 1;
    }*/
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

Bod2D Bod2D::Stred(const Bod2D &other)
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
    os<<showpos<<"Parametricka rovnica: "<<endl<< "x=" <<(other.koeficienty[0])<<"+t.("<<(other.koeficienty[1])<<")"<<endl<<"y=" <<(other.koeficienty[2])<<"+t.("<<(other.koeficienty[3])<<")   t patri R";
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
