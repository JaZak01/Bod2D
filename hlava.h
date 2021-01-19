#ifndef BOD2D_HLAVA_H
#define BOD2D_HLAVA_H

class Bod2D
{
private:
    float x;
    float y;

public:
    Bod2D(float getx, float gety);
    Bod2D ();
    explicit Bod2D(float getx);
    //explicit Bod2D(float getx);
    float getx() const;
    float gety() const;
    void setSuradnicax(float getx);
    void setSuradnicay(float gety);
    void vypisBod() const;

    friend std::ostream & operator<<(std::ostream & os,const Bod2D & other);
    friend std::istream & operator>>(std::istream & is, Bod2D & other);

    Bod2D spocitaj(const Bod2D &other)const;
    Bod2D odcitaj(const Bod2D &other)const;

    Bod2D operator*(float cislo) const;
    Bod2D operator/(float cislo) const;

    //Bod2D vydel(float cislo)const;
    //Bod2D vydel(float cislo)const;
    //Bod2D vzdialenosť(const Bod2D &other)const;




};




#endif
