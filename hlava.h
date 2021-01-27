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

    //nepouživame
    /*
    //float vzdialenostajnula(const Bod2D &other=Bod2D(0,0)) const;
    //static void nacitajBody(float a, float b);
*/


};




#endif
