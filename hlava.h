#ifndef BOD2D_HLAVA_H
#define BOD2D_HLAVA_H

class Bod2D
{
private:
    float x;
    float y;
public:
    class streamError
    {
    private:
        const char* msg;
    public:
        streamError(const char *sprava):msg(sprava){};
        void getMsg() const;
    };

    Bod2D(float mojx, float mojy); // prerobit na inicializaciu
    Bod2D ();
    explicit Bod2D(float getx);// tiez inicializaciu
    //explicit Bod2D(float getx);
    float getx() const;
    float gety() const;
    void setSuradnicax(float getx);
    void setSuradnicay(float gety);
    void vypisBod() const;

    friend std::ostream & operator<<(std::ostream & os,const Bod2D & other);
    friend std::istream & operator>>(std::istream & is, Bod2D & other);

    Bod2D operator+(const Bod2D & otherBod) const;
    Bod2D operator-(const Bod2D & otherBod) const;

    Bod2D operator*(float cislo) const;
    friend Bod2D operator*(float cislo, Bod2D &other);
    Bod2D operator/(float cislo) const;
    //friend Bod2D operator/(float cislo, const Bod2D & other);

/*
    const Bod2D & operator+=(float cislo);
    const Bod2D & operator-=(float cislo);
    const Bod2D & operator*=(float cislo);
    const Bod2D & operator/=(float cislo);*/

    Bod2D Stred(const Bod2D & other);
    float vzdialenostodnuly() const;
    float vzdialenost(const Bod2D &other=Bod2D(0,0)) const;
    static void minimalVzd(std::istream & is);
    static void vysortovanie(std::istream & is);

    //TREBA OPRAVIT LEEBO BY MALI BYT V PRIVATE ALE POTOM TO BLBNE S VEKTOROM


    //nepouživame
    /*
    //float vzdialenostajnula(const Bod2D &other=Bod2D(0,0)) const;
    //static void nacitajBody(float a, float b);
*/



};

using Vektor = Bod2D;

class Usecka
{
private:
    Bod2D X {0,0};
    Bod2D Y {0,0};
public:
    Usecka(){};
    Usecka(Bod2D A, Bod2D B):X(A),Y(B){};
    explicit Usecka(Bod2D A):X(A), Y(A){};
    friend std::ostream & operator<<(std::ostream & os,const Usecka & usecka);
    friend std::istream & operator>>(std::istream & is, Usecka & usecka);
    bool operator<(const Usecka & other) const;
    bool operator>(const Usecka & other) const;
    float getDlzka() const;
    //ULOHA:metody co vratia normalovy vektor usecky a vektor smerovy
    Vektor getSmer() const;
    Vektor getNormal() const;
    Bod2D getStredovyusecky() const;

};

#endif




