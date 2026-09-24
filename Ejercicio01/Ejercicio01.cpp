#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Profesional {
protected:
    string nombre;
    int anioIngreso;

public:
    Profesional(string nom, int anio) : nombre(nom), anioIngreso(anio) {}
    virtual ~Profesional() {}

    void mostrarPerfil() const {
        cout << nombre << " (desde " << anioIngreso << ") -> ";
    }

    virtual void desempenarFuncion() const = 0;
};

class Arquitecto : public Profesional {
    double metrosDisenados;
public:
    Arquitecto(string nom, int anio, double metros)
        : Profesional(nom, anio), metrosDisenados(metros) {}

    void desempenarFuncion() const override {
        cout << "disena estructuras, lleva " << metrosDisenados << " m2 en planos." << endl;
    }
};

class Doctor : public Profesional {
    int pacientesHoy;
public:
    Doctor(string nom, int anio, int pacientes)
        : Profesional(nom, anio), pacientesHoy(pacientes) {}

    void desempenarFuncion() const override {
        cout << "atiende consultas, hoy lleva " << pacientesHoy << " pacientes." << endl;
    }
};

class Enfermera : public Profesional {
    string unidadAsignada;
public:
    Enfermera(string nom, int anio, string unidad)
        : Profesional(nom, anio), unidadAsignada(unidad) {}

    void desempenarFuncion() const override {
        cout << "cuida pacientes en la unidad de " << unidadAsignada << "." << endl;
    }
};

class Bombero : public Profesional {
    int emergenciasAtendidas;
public:
    Bombero(string nom, int anio, int emergencias)
        : Profesional(nom, anio), emergenciasAtendidas(emergencias) {}

    void desempenarFuncion() const override {
        cout << "responde emergencias, van " << emergenciasAtendidas << " este mes." << endl;
    }
};

int main() {
    vector<Profesional*> equipo;
    equipo.push_back(new Arquitecto("Karen", 2018, 3200.5));
    equipo.push_back(new Doctor("Renzo", 2015, 14));
    equipo.push_back(new Enfermera("Fiorella", 2020, "Pediatria"));
    equipo.push_back(new Bombero("Diego", 2019, 7));

    for (Profesional* p : equipo) {
        p->mostrarPerfil();
        p->desempenarFuncion();
    }

    for (Profesional* p : equipo) {
        delete p;
    }

    return 0;
}
