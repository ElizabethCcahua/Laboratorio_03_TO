#include <iostream>
#include <string>
using namespace std;

class ContagioRapido {
public:
    void expandirse() const {
        cout << "  Se disemina con facilidad en ambientes cerrados y aglomeraciones." << endl;
    }
};

class ResistenciaVacunal {
public:
    void sortearDefensas() const {
        cout << "  Consigue sortear parte de la inmunidad generada por dosis anteriores." << endl;
    }
};

class ImpactoRespiratorio {
public:
    void comprometerPulmones() const {
        cout << "  Afecta con mayor fuerza el sistema respiratorio en pacientes vulnerables." << endl;
    }
};

//Cepas (herencia multiple)
class CepaBeta : public ContagioRapido, public ImpactoRespiratorio {
    string lugarDeteccion;
public:
    CepaBeta(string lugar) : lugarDeteccion(lugar) {}

    void perfil() const {
        cout << "Cepa Beta (detectada en: " << lugarDeteccion << ")" << endl;
        expandirse();
        comprometerPulmones();
    }
};

class CepaGamma : public ContagioRapido, public ImpactoRespiratorio, public ResistenciaVacunal {
    string lugarDeteccion;
public:
    CepaGamma(string lugar) : lugarDeteccion(lugar) {}

    void perfil() const {
        cout << "Cepa Gamma (detectada en: " << lugarDeteccion << ")" << endl;
        expandirse();
        comprometerPulmones();
        sortearDefensas();
    }
};

class CepaLambda : public ContagioRapido, public ResistenciaVacunal {
    string lugarDeteccion;
public:
    CepaLambda(string lugar) : lugarDeteccion(lugar) {}

    void perfil() const {
        cout << "Cepa Lambda (detectada en: " << lugarDeteccion << ")" << endl;
        expandirse();
        sortearDefensas();
    }
};




int main() {
    CepaBeta beta("Brasil");
    CepaGamma gamma("Japon");
    CepaLambda lambda("Peru");

    beta.perfil();
    cout << endl;
    gamma.perfil();
    cout << endl;
    lambda.perfil();

    return 0;
}
