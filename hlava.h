#ifndef BOD2D_HLAVA_H
#define BOD2D_HLAVA_H
#include <iosfwd>


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
    Bod2D ();//:x(0),y(0){};
    explicit Bod2D(float getx);// tiez inicializaciu
    //explicit Bod2D(float getx);
    float getx() const;//float getx(){return x;} const;
    float gety() const;// float gety() {return y;} const;
    void setSuradnicax(float getx);//void setSuradnicax(float getx) {x = getx;};
    void setSuradnicay(float gety);//void setSuradnicay(float gety) {y = gety;};
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

    Bod2D Stred(const Bod2D & other) ;
    float vzdialenostodnuly() const;
    float vzdialenost(const Bod2D &other=Bod2D(0,0)) const;
    static void minimalVzd(std::istream & is);
    static void vysortovanie(std::istream & is);
    float getDlzka() const;



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
    class VseRov {
    private:
        float koeficienty[3];
    public:
        VseRov(float ka, float kb, float kc) : koeficienty{ka, kb, kc} {};
        friend std::ostream &operator<<(std::ostream &os, const VseRov &other);
        float &operator[](int index) { return koeficienty[index];};
        const float & operator[](int index) const{return koeficienty[index];};
    };

    class ParRov{
    private:
        float koeficienty[4];
    public:
        ParRov (float ka1, float kv1, float ka2, float kv2): koeficienty{ka1,kv1,ka2,kv2}{};
        friend std::ostream & operator<<(std::ostream & os,const ParRov &other);
        float & operator[](int index){return koeficienty[index];};
        const float & operator[](int index) const{return koeficienty[index];};
    };

    class Poloha
    {
        char popis[11];
        Bod2D priesecnik;
    public:
        Poloha (char const *text, const Bod2D &prienik);
        Bod2D getPriesecnik()const{return priesecnik;};
        friend std::ostream &operator<<(std::ostream &os, const Poloha &poloha);
    };


    Usecka(){};
    Usecka(Bod2D A, Bod2D B):X(A),Y(B){};
    explicit Usecka(Bod2D A):X(A), Y(A){};
    friend std::ostream & operator<<(std::ostream & os,const Usecka & usecka);
    friend std::istream & operator>>(std::istream & is, Usecka & usecka);
    bool operator<(const Usecka & other) const;
    bool operator>(const Usecka & other) const;
    explicit operator VseRov()const;
    explicit operator ParRov()const;
    float getDlzka() const;
    //ULOHA:metody co vratia normalovy vektor usecky a vektor smerovy
    Vektor getSmer() const;
    Vektor getNormal() const;
    Bod2D getStredovyusecky() const;
    VseRov getVseo() const;
    ParRov getPar() const;
    VseRov getOs() const;
    float getUhol(const Usecka & other, char typ = 'r') const;
    float getUholR (const Usecka & other, char typ = 'o') const;
    void JeToNula(const Usecka & other) const;
    bool jeRovnobezna(const Usecka &other) const;
    Poloha getPoloha(const Usecka & other) const;
    VseRov getOsUhla(const Usecka & other) const;

};

#endif




