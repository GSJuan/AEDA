#include <iostream>
class MiClave {
public:
int key;
static int contador;
bool operator<(const int& pivote) {
    contador++;
    return key < pivote;
}

bool operator>(const int& pivote) {
    contador++;
    return key > pivote;
}

bool operator<(const MiClave& clave) {
    contador++;
    return key < clave.key;
}

bool operator<=(const MiClave& clave) {
    contador++;
    return key <= clave.key;
}

bool operator>(const MiClave& clave) {
    contador++;
    return key > clave.key;
}

void operator=(int& value) {
  key = value;
}

void operator=(const int& value) {
  key = value;
}

void operator=(const MiClave& clave) {
  key = clave.key;
}

bool operator==(const MiClave& clave) {
  contador++;
  return key == clave.key;
}

friend std::ostream& operator<<(std::ostream& os, const MiClave& clave) {
  os << clave.key;
  return os;
}

};