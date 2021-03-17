
#include <iostream>
#include "hlava.h"
#include "inout.h"
#include <cmath>
#include <string>
#include <cstring>
#include<random>


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

Bod2D Bod2D::Stred(const Bod2D & other) const {

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
    //
    // cout<<Usecka::VseRov(XY.getx(), XY.gety(), -C );
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

bool Usecka::rovnobezne(const Usecka &other) const
{
    Vektor v = this -> getSmer();
    Vektor u = other.getSmer();
    return (v.getx() / u.gety() == v.gety() / u.gety());
}
bool Usecka::totozne(const Usecka &other) const
{
    VseRov prva = this->getVseo();
    VseRov druha = other.getVseo();
    return prva[0]/druha[0]==prva[1]/druha[1]==prva[2]/druha[2];
}
/*
Usecka::Poloha Usecka::getPoloha(const Usecka &other) const
{

    if(this->totozne(other))
    {
        return Usecka::Poloha ("totozne", Bod2D{0,0});
    }
    if(this->rovnobezne(other))
    {
        return Usecka::Poloha ("rovnobezne", Bod2D{0,0});
    }

    auto prva = this -> getVseo();
    auto druha = other.getVseo();
    float D = (prva[0] * druha[1]) - druha[0]*prva[1];
    float D1 = (-prva[2] * druha[1]) - prva[1]*druha[2] * (-1);
    float D2 = (-prva[0] * druha[2]) - druha[0]* prva[2] * (-1);
    //cout << Usecka::Poloha ("roznobezna", Bod2D((D1/D),(D2/D)));
    return Usecka::Poloha ((char *) "Rovznobezna", {(D1/D),(D2/D)});

}*/

Usecka::Poloha Usecka::getPoloha(const Usecka &other) const
{

    if(this->totozne(other))
    {
        return Usecka::Poloha((char *)"totozne",Bod2D{0,0});
    }
    if(this->rovnobezne(other))
    {
        return Usecka::Poloha((char *)"Rovnobezne",Bod2D{0,0});

    }
    auto A = this->getVseo();
    auto B = other.getVseo();
    float D = A[0] * B[1] - A[1] * B[0];
    float D1 = -A[2]*B[1] - A[1]* B[2] * (-1);
    float D2 = -A[0] * B[2] - B[0] * A[2] * -1;
    return Usecka::Poloha((char *)"Roznobezna",{D1/D,D2/D});

}

Usecka::Poloha::Poloha(char const *text, const Bod2D &prienik) : priesecnik(prienik)
{
    std::strncpy(popis,text, 10);
    popis[10]='\0';  // musim byt pri strncpy
}

std::ostream &operator<<(std::ostream &os, const Usecka::Poloha &poloha)
{
    os<<"Poloha prieniku: " <<(poloha.getPriesecnik())<<endl;
    return os;
}

Usecka::VseRov Usecka::getOsUhla(const Usecka &other) const
{
    Usecka::Poloha adam = getPoloha(other);
    Bod2D PR = adam.getPriesecnik();

    Vektor J = this -> getSmer();
    Vektor D = other.getSmer();

    Vektor B1 = J.getJednotkovy();
    Vektor B2 = D.getJednotkovy();

    //Vektor B = {(B1.getx()+B2.getx()),(B1.gety()+B2.gety())}; // smerovy vektor z jednotkovych
    Vektor XY = {-(B1.gety()+B2.gety()),(B1.getx()+B2.getx())}; // rovno som vypocital normalovy
    //Vektor XY = {-B.gety(),B.getx()}; // premena na normalovy
    //float C = (XY.getx() * PR.getx() + XY.gety() * PR.gety()); // vypocet C
    //cout<<Usecka::VseRov(XY.getx(), XY.gety(), - (XY.getx() * PR.getx() + XY.gety() * PR.gety())); // vypocet som dosadil a aj v returne

    return Usecka::VseRov(XY.getx(), XY.gety(), -(XY.getx() * PR.getx() + XY.gety() * PR.gety()));
}

Usecka Usecka::getOsU() const
{
    Bod2D stred=getStredovyusecky();
    Bod2D N = getNormal();
    return {stred, stred + N};
}

Usecka Usecka::getOsUhlaU(const Usecka &other) const
{
    Bod2D B1 = this->getPoloha(other).getPriesecnik();

    Vektor J = this -> getSmer();//.getJednotkovy();
    Vektor D = other.getSmer();//.getJednotkovy();

    Vektor B4 = J.getJednotkovy();
    Vektor B5 = D.getJednotkovy();

    Bod2D B2 = B5+B4+B1;
    return Usecka {B1,B2};
}

Bod2D Bod2D::getJednotkovy() const
{
    return Bod2D{(getx()/getDlzka()), (gety()/getDlzka())};
}

bool Trojuholnik::existuje(Bod2D x, Bod2D y, Bod2D z)
{
    float a = x.vzdialenost(y);
    float b = x.vzdialenost(z);
    float c = y.vzdialenost(z);

    try
    {
        cout << "Tri body:" << x << y<< z<< " ";
        if (!((a+b>c) * (a+c>b) * (b+c > a)))
        {
            throw Trojuholnik::MsgErr("Tento trojuholnik neexistuje");
        }
        cout<<"Trojuholnik existuje"<<endl;

    }
    catch(const Trojuholnik::MsgErr &e)
    {
        e.getMsg();
        return false;
    }

    return true;
}

Trojuholnik::Trojuholnik(Bod2D x, Bod2D y, Bod2D z)
{
    existuje(x, y, z);
    A = x;
    B = y;
    C = z;


}

int Trojuholnik::generuj(int min, int max) const
{
    std::random_device rd; //random cislo z hardveru
    std::mt19937 eng(rd()); // inicializacia generatora ktory som si vytvoril
    std::uniform_int_distribution<int> distr (min, max);
    return distr(eng);
}

Trojuholnik::Trojuholnik()
{
    /* generuj nejde na windows
    Bod2D x{static_cast<float>(generuj(0, 10)),static_cast<float> (generuj (0, 10))};
    Bod2D y{static_cast<float>(generuj(0, 10)),static_cast<float> (generuj (0, 10))};
    Bod2D z{static_cast<float>(generuj(0, 10)),static_cast<float> (generuj (0, 10))};*/
    srand (time(NULL));
    Bod2D x = {static_cast<float>(rand()  % 10 + 1),static_cast<float>(rand()  % 10 + 1)};
    Bod2D y = {static_cast<float>(rand()  % 10 + 1),static_cast<float>(rand()  % 10 + 1)};
    Bod2D z = {static_cast<float>(rand()  % 10 + 1),static_cast<float>(rand()  % 10 + 1)};


    if (!existuje(x,y,z))
    {
        EXIT_FAILURE;
    }

    A = x;
    B = y;
    C = z;

    //cout <<"Body su: "<< x << y << z;

}

float Trojuholnik::getDlzkastrany(char strana) const
{
    if (strana == 'a')
    {
        Usecka BC = {(B),(C)};
        return (BC.getDlzka());
    }
    else if (strana == 'b')
    {
        Usecka AC = {(A),(C)};
        return (AC.getDlzka());
    }
    else if (strana == 'c')
    {
        Usecka AB = {(A),(B)};
        return (AB.getDlzka());
    }
    else
    {
        cout << "zle zladane"<<endl;
        float nic = 0;
        return nic;
    }


}

void Trojuholnik::MsgErr::getMsg() const
{
    cout<<msg;
}


float Trojuholnik::getvelkostUhla(char uhol) const
{

    if (uhol == 'a')
    {
        return (Usecka (A,B).getUhol(Usecka (A,C)));
    }
    else if (uhol == 'b')
    {
        return (Usecka (B,A).getUhol(Usecka (B,C)));
    }
    else if (uhol == 'c')
    {
        return (Usecka (C,A).getUhol(Usecka (C,B)));
    }
    else
    {
        return (Usecka (A,B).getUhol(Usecka (A,C)));
    }
}

float Trojuholnik::getObvod() const
{
    return  getDlzkastrany('a')+getDlzkastrany('b')+getDlzkastrany('c');
}

float Trojuholnik::getObsah() const
{
    float s = getObvod()/2;
    return (float)std::sqrt(s*(s-getDlzkastrany('a'))*(s-getDlzkastrany('b'))*(s-getDlzkastrany('c')));
}

Usecka Trojuholnik::getVyska(char naStranu) const
{
    Vektor smerovy;
    Bod2D bNV;
    if (naStranu == 'a')
    {
        smerovy = Usecka(C,B).getNormal();
        bNV= {smerovy+A};
        return {bNV,A};
    }
    else if (naStranu == 'b')
    {
        smerovy = Usecka(A,C).getNormal();
        bNV = {smerovy+B};
        return {bNV,B};
    }
    else if (naStranu == 'c')
    {
        smerovy = Usecka(A,B).getNormal();
        bNV = {smerovy+C};
        return {bNV,C};
    }
    else
    {
        smerovy = Usecka(C,B).getNormal();
        bNV= {smerovy+A};
        return {(bNV),(A)};
    }
}

Bod2D Trojuholnik::getTazisko() const
{
    Bod2D D = A.Stred(B);
    return Bod2D(((C-D)/3) + D);
}

Bod2D Trojuholnik::getOrtocentrum() const
{
    return Bod2D((getVyska('a').getPoloha(getVyska('b')).getPriesecnik()));
}

void Trojuholnik::getOpisanaKruznica() const
{
    Usecka AB = {(A),(B)};
    Usecka BA = {(B),(C)};
    Usecka osAB = AB.getOsU();
    Usecka osBC = BA.getOsU();
    Bod2D SKr = osAB.getPoloha(osBC).getPriesecnik();
    cout << SKr << endl;
    float r = SKr.vzdialenost(A);
    //cout << "kruznica ma stred: " << Ta << "a polomer: " << r << endl;
    cout << "Opisana je: ( x - " <<setprecision(2)<< SKr.getx() << ")^2 + ( y - " << setprecision(2)<< SKr.gety() << ")^2 = " << r*r << endl;
}

void Trojuholnik::getVpisanaKruznica() const
{
    Usecka osA = Usecka(A,B).getOsUhlaU(Usecka(A,C));
    Usecka osB = Usecka(B,A).getOsUhlaU(Usecka(B,C));
    Bod2D SK = osA.getPoloha(osB).getPriesecnik();
    Usecka vC = getVyska('c');
    Bod2D pC = vC.getPoloha(Usecka(A,B)).getPriesecnik();
    cout << pC << endl;
    float r = SK.vzdialenost(pC);
    //cout << "kruznica ma stred: " << Or << "a polomer: " << r << endl;
    cout << "Vpisana je: (x - " <<setprecision(2)<< SK.getx() << ")^2 + (y - " <<setprecision(2)<< SK.gety() << ")^2 = " << (r*r) << endl;
}


void Trojuholnik::getKruznicaDeviatichbodov() const //nedorobene
{
    Bod2D S = A.Stred(B); // iba na vypocet r
    Bod2D Ta = getTazisko();
    Bod2D Or = getOrtocentrum();
    Bod2D K = Ta.Stred(Or);
    float r = (Ta.vzdialenost(S)/2);
    //cout << "stred ma v: " << K << "a polomer: " << r << endl;
    cout << "Kruznica 9 bodov je: ( x - " << K.getx() << ")^2 + ( y - " << K.gety() << ")^2 = " << (r*r) << endl;
}

Usecka Trojuholnik::getEulerovapriamka() const // nedorobene
{
    Bod2D O = getOrtocentrum();
    Bod2D T = getTazisko();

    Usecka Eu = {(O),(T)};
    cout <<"Eulerova priamka: " << Eu.getVseo();
    return Usecka {(O),(T)};
}





