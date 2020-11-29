#pragma once

#include "vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T>>
{
  using TVector<TVector<T> >::pVector;
  using TVector<TVector<T> >::size;
  using TVector<TVector<T> >::start_index;
public:
  TMatrix(int _size = 1); // конструктор по умолчанию
  TMatrix(const TMatrix& _m); // конструктор копирования
  TMatrix(const TVector<TVector<T> >& _m);
  bool operator==(const TMatrix& _m) const; // оператор сравнения матриц
  bool operator!=(const TMatrix& _m) const; // оператор сравнения матриц
  TMatrix& operator= (const TMatrix& _m); // оператор присваивания матриц
  TMatrix  operator+ (const TMatrix& _m); // оператор сложения матриц
  TMatrix  operator- (const TMatrix& _m); // оператор вычитания матриц

  // ввод-вывод
  template <class T1>
  friend ostream& operator<<(ostream& out, const TMatrix<T1>& _m);
  template <class T1>
  friend istream& operator>>(istream& in, TMatrix<T1>& _m);
};

template<class T>
TMatrix<T>::TMatrix(int _size) : TVector<TVector<T> >(_size)
{
  if (_size > 0)
  {
    for (int i = 0; i < _size; i++)
      pVector[i] = TVector<T>(_size, i);
  }
  else throw - 1;
}

template<class T>
TMatrix<T>::TMatrix(const TMatrix<T>& _m) : TVector<TVector<T> >(_m)
{
}

template<class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> >& _m) : TVector<TVector<T> >(_m)
{
}

template<class T>
bool TMatrix<T>::operator==(const TMatrix<T>& _m) const
{
  if (size != _m.size)
    return false;
  for (int i = 0; i < _m.size; i++)
    if (pVector[i] != _m.pVector[i])
      return false;
  return true;
}

template<class T>
bool TMatrix<T>::operator!=(const TMatrix<T>& _m) const
{
  if (size != _m.size)
    return true;
  for (int i = 0; i < size; i++)
    if (pVector[i] != _m.pVector[i])
      return true;
  return false;
}

template<class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& _m)
{
  if (this != &_m)
  {
    if (size != _m.size)
    {
      delete[] pVector;
      pVector = new TVector<T>[_m.size];
    }
    size = _m.size;
    start_index = _m.start_index;
    for (int i = 0; i < size; i++)
      pVector[i] = _m.pVector[i];
  }
  return *this;
}

template<class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix& _m)
{
  return TVector<TVector<T> >::operator+(_m);
}

template<class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix& _m)
{
  return TVector<TVector<T> >::operator-(_m);
}

template<class T1>
ostream& operator<< (ostream& out, const TMatrix<T1>& _m)
{
  for (int i = 0; i < _m.size; i++)
    out << _m.pVector[i] << endl;
  return out;
}

template<class T1>
istream& operator>> (istream& in, TMatrix<T1>& _m)
{
  for (int i = 0; i < _m.size; i++)
    in >> _m.pVector[i];
  return in;
}
