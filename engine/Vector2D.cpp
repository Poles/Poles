#include "vector2d.h"
#include <sstream>

/**
 * Constructor por defecto. Inicializa los valores de ambas coordenadas a 0.
 */
Vector2D::Vector2D()
{
    _x = 0.0f;
    _y = 0.0f;
}

/**
 * Constructor por parametros.
 * @param x     Coordenada en el eje x.
 * @param y     Coordenada en el eje y.
 */
Vector2D::Vector2D(float x, float y)
: _x(x), _y(y)
{

}

/**
 * Constructor copia.
 * @param orig  Vector a copiar.
 */
Vector2D::Vector2D(const Vector2D& orig)
{
    _x = orig._x;
    _y = orig._y;
}

/**
 * Destructor.
 */
Vector2D::~Vector2D()
{
}

/**
 * Operador de asignacion.
 * @param vector        Vector que asignar al actual.
 * @return              Referencia al vector ya asignado.
 */
Vector2D& Vector2D::operator =(const Vector2D& vector)
{
    _x = vector._x;
    _y = vector._y;
    return *this;
}

/**
 * Operador de suma.
 * @param vector        Vector a sumar con el actual.
 * @return              Nuevo vector resultado de la suma de los dos.
 */
Vector2D Vector2D::operator +(const Vector2D& vector)
{
    return Vector2D(_x + vector._x, _y + vector._y);
}

/**
 * Multiplicacion por un factor.
 * @param f     Factor de escala del vector.
 * @return      Vector resultado de la escala por el factor.
 */
Vector2D Vector2D::operator *(float f)
{
    return Vector2D(_x * f,_y * f);
}

Vector2D Vector2D::operator -(const Vector2D& vector)
{
    return Vector2D(_x - vector._x, _y - vector._y);
}

bool Vector2D::operator !=(const Vector2D &vector)
{
    return _x - vector._x != 0.0f || _y - vector._y != 0.0f;
}

bool Vector2D::operator ==(const Vector2D &vector)
{
    return _x - vector._x == 0.0f && _y - vector._y == 0.0f;
}

/**
 * Calcula la longitud cuadratica del vector.
 * @return      Longitud cuadratica (sin aplicar la raiz) del vector.
 */
float Vector2D::lengthSquared()
{
    return (_x * _x + _y * _y);
}

/**
 * Calcula la longitud del vector.
 * @return      Longitud del vector.
 */

float Vector2D::length() {
    return sqrt(_x * _x + _y * _y);
}

/**
 * Calcula la distancia cuadratica hasta otro vector.
 * @param vector        Vector respecto al cual calcular la distancia.
 * @return              Distancia cuadratica hasta el vector indicado.
 */
float Vector2D::distanceSquared(const Vector2D& vector) {
    float Ax,Ay;
    
    Ax = _x - vector._x;
    Ay = _y - vector._y;
    
    return (Ax*Ax + Ay*Ay);
}

/**
 * Calcula la distancia hasta otro vector.
 * @param vector        Vector respecto al cual calcular la distancia.
 * @return              Distancia hasta el vector indicado.
 */
float Vector2D::distance(const Vector2D& vector) {
    float Ax,Ay;
    
    Ax = _x - vector._x;
    Ay = _y - vector._y;
    
    return sqrt(Ax*Ax + Ay*Ay);
}

/**
 * Normaliza el vector.
 */
Vector2D& Vector2D::normalize() {
    float lengthsq = (_x * _x + _y * _y);
    
    if( lengthsq == 0)
    {
        _x = 0.0f;
        _y = 0.0f;
        return *this;
    }
    
    float recip = invSqrt( lengthsq);
    _x *= recip;
    _y *= recip;
    
    return *this;
}

std::string Vector2D::toString()
{
    std::stringstream str;
    
    str << "(" << _x << "," << _y << ")";
    
    return str.str();
}


//----------------------------------------------------------------------------//
/**
 * Calcula de la raiz inversa.
 * @param number        Numero al que calcula la raiz inversa
 * @return 
 */
float Vector2D::invSqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    //  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    //Ladis, en serio, que cojones es esto???? xD
    return y;
}

/**
 * Implementacion propia del calculo de la raiz mediante el numero magico.
 * Se trata de una implementacion usada en videojuegos desde su aparicion en Quake 3
 * @param x     Numero al que calcular la raiz.
 * @return      Raiz aproximada del numero indicado.
 */
float Vector2D::sqrt(float x) {
    const float xhalf = 0.5f*x;

    union // get bits for floating value
    {
    float x;
    int i;
    } u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
    return x*u.x*(1.5f - xhalf*u.x*u.x);// Newton step, repeating increases accuracy
}
