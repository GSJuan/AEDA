#include <string>
class Alumno {

private:
    std::string nombre;
    std::string alu;

public:

    Alumno() {}

    operator unsigned() const {
        return stoi(alu);
    } 

    bool operator==(const Alumno& pepe)  {
        return alu == pepe.GetAlu();
    }

    std::string GetNombre() {
        return nombre;
    }

    std::string GetAlu() const {
        return alu;
    }

    void SetAlu(std::string& new_alu) {
        alu = new_alu;
    }

    void SetName(std::string& new_name) {
        nombre = new_name;
    }

};