/*#include <iostream>
#include "hlava.h"
#include "inout.h"
#include <cmath>
#include <string>
#define PI 3.14159265
//using namespace std;*/

#include"Bod.cpp"
#include "inout.h"

//int comp (const void *prva, const void *druha);

int main()
{
    using namespace inout;

    Bod2D Prvy(1,3);
    Bod2D Druhy(3,7);
    Bod2D Treti(5,8);
    Bod2D Stvrty(2,12);
    Usecka Prva{(Prvy),(Druhy)};
    Usecka Druha{(Treti),(Stvrty)};
    cout<<setprecision(2)<< Prva.getOsUhla(Druha)<<endl;
    //Prva.getUholR(Druha, 's');
    //cout<< Prva.jeRovnobezna(Druha) <<endl;
    //Prva.JeToNula(Druha);
    /*
    //Prva.getUhol(Druha);
    //Prva.getOs();
    //Usecka::VseRov pokus = Prva.getVseo();
    //Usecka::ParRov pokus = Prva.getPar();
    //(Usecka::VseRov)Prva;
    //(Usecka::ParRov)Prva;
    //cout<<Prva.getVseo();
    //cout<<pokus;*/
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
