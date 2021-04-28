// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Clase Hormiga que contiene las características de la hormiga de langton

class Ant {

    private:

    int row_pos;
    int column_pos;
    char direction;


    public:

    Ant();
    Ant(int, int, char);
    ~Ant();

    int GetRow(void); //devulve la fila en la que se encuentra la hormiga
    int GetColumn(void); //devulve la columna en la que se encuentra la hormiga
    char GetDirection(void); //devuelve la dirección que tiene la hormiga

    void SetRow(int);
    void SetColumn(int);
    void SetDirection(char);

    void Update(void); //Hace que la hormiga avance su posición una casilla en función de su dirección
    void Turn90R(void); //cambia la dirección de la hormiga 90 grados a la derecha
    void Turn90L(void); //cambia la dirección de la hormiga 90 grados a la izquierda
};