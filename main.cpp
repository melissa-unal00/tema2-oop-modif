#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
ifstream in ("date.in");

class farmacie_abstracta
{
protected:
    string denumire;
public:
    virtual int calcul_venit()=0;
    farmacie_abstracta(string denumire) /// constructor cu parametri
    {
        this->denumire = denumire;

    }
        farmacie_abstracta(const farmacie_abstracta& obj) ///constructor de copiere
    {
        denumire = obj.denumire;
    }
    ~farmacie_abstracta()
    {
    denumire.clear();
    }
    void citire()
    {
        string d;
        cin>>d;
        denumire=d;
    }
    void afisare()
    {
        cout<<this->denumire;
    }
    friend istream &operator>>(istream &, farmacie_abstracta&);

};
class farmacie_offline : public farmacie_abstracta
{
protected:
    int nr_luni;
    double *cifra_afaceri_luna;
public:

    farmacie_offline(string denumire) : farmacie_abstracta(denumire)  /// constructor cu parametri
    {
        this->nr_luni = nr_luni;
        this->cifra_afaceri_luna = cifra_afaceri_luna;
    }

        farmacie_offline(const farmacie_offline& obj) : farmacie_abstracta(obj) ///constructor de copiere
    {
        nr_luni = obj.nr_luni;
        cifra_afaceri_luna = obj.cifra_afaceri_luna;
    }
    ~farmacie_offline()
    {
        nr_luni=0;
        delete cifra_afaceri_luna;
    }
    farmacie_offline operator=(farmacie_offline);
    int calcul_venit()
    {
        int i=0;
        double total = 0;
        while(cifra_afaceri_luna[i]!=NULL)
                    {
                        total += cifra_afaceri_luna[i];
                        i++;
                    }

                    return total;
    }
    void farmacie_offline::afisare();


};
void farmacie_offline::Afisare()
{
	Farmacie_abstracta::Afisare();
	cout <<endl;
	cout <<this->nr_luni = nr_luni<<endl;
    cout <<this->cifra_afaceri_luna = cifra_afaceri_luna;

}

void farmacie_online::afisare()
{
	farmacie_abstracta::afisare();
	cout << endl;
	cout <<this->nr_vizitatori << endl;
	cout <<this->adresa_web << endl;

}



farmacie_offline& farmacie_offline::operator=(farmacie_offline &C) ///supraincarcarea operatorului =
{
    if (this==&C)
    return *this;
}

class farmacie_online : public farmacie_abstracta
{
protected:
    int nr_luni;
    double *cifra_afaceri_luna;
    char *adresa_web;
    int nr_vizitatori;
public:
    ~farmacie_online
    {
        nr_luni=0;
        delete cifra_afaceri_luna;
        delete adresa_web;
        nr_vizitatori=0;
    }
    void farmacie_online::afisare();
};

void farmacie_online::afisare()
{
	farmacie_abstracta::afisare();
	cout << endl;
	cout <<this->nr_vizitatori << endl;
	cout <<this->adresa_web << endl;

}

class farmacie_dubla_specializare : public farmacie_offline, public farmacie_online
{
protected:
    int nr_angajati;
public:
    farmacie_dubla_specializare(string denumire) : farmacie_online(denumire),farmacie_offline(denumire)  /// constructor cu parametri
    {
        this->nr_angajati = nr_angajati;
    }

        farmacie_dubla_specializare(const farmacie_dubla_specializare& obj) : farmacie_online(obj),farmacie_offline(obj) ///constructor de copiere
    {
        nr_angajati = obj.nr_angajati;
    }
    farmacie_dubla_specializare
    {
     nr_angajati=0;
    }
    void farmacie_dubla_specializare::afisare()
{
	farmacie_offline::afisare();
	farmacie_online::afisare();

	cout << endl << this->nr_angajati << endl;

}


};

istream&  operator>>(istream &in, farmacie_abstracta &f)
{
    ifstream file;
    file.open("date.in");
    file>>f.denumire;
    return file;
}

int main()
{
    farmacie_abstracta *farmacie[100];
    int c = 0;
    farmacie[c]=new farmacie_offline("Catena");
    c++;
    farmacie[c]=new farmacie_online("HelpNet");
    c++;
    return 0;
}
