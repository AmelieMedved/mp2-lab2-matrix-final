#ifndef _TVECTOR_H_
#define _TVECTOR_H_
#include <iostream>

using namespace std;

template <class T>
class TVector
{
protected:
  T* pVector;
  int size;
  int start_index;
public:
  TVector(int _size = 1, int _start_index = 0); // конструктор по умолчанию
  TVector(const TVector& _v); // конструктор копирования
  ~TVector(); // деструктор

  int GetSize() { return size; } // получить размер
  int GetStartIndex() { return start_index; } // получить начальный индекс
  T& operator[](int pos); // оператор индексации
  bool operator==(const TVector& _v) const; // оператор сравнения
  bool operator!=(const TVector& _v) const; // оператор сравнения
  TVector& operator=(const TVector& _v); // оператор присваивания

  // операции со скалярами
  TVector  operator+(const T& val);
  TVector  operator-(const T& val);
  TVector  operator*(const T& val);

  // векторные операции
  TVector operator+(const TVector& _v);
  TVector operator-(const TVector& _v);
  TVector operator*(const TVector& _v);
  TVector operator /(TVector& _v); // деление
  TVector& operator +=(TVector& _v); // сложение
  TVector& operator -=(TVector& _v); // вычитание

  // ввод-вывод
  template<class T1>
  friend ostream& operator << (ostream& out, const TVector<T1>& _v);
  template <class T1>
  friend istream& operator >> (istream& in, TVector<T1>& _v);
};

template<class T>
TVector<T>::TVector(int _size, int _start_index) 
{
  if (_size < 0 || _start_index < 0)
    throw -1;

  pVector = new T[_size];
  this->size = _size;
  this->start_index = _start_index;
  for (int i = 0; i < _size; i++)
    pVector[i] = 0;
}

template<class T>
TVector<T>::TVector(const TVector& _v)
{
  pVector = new T[_v.size];
  this->size = _v.size;
  this->start_index = _v.start_index;

  for (int i = 0; i < size; i++)
    pVector[i] = _v.pVector[i];
}

template<class T>
TVector<T>::~TVector()
{
  size = 0;
  start_index = 0;
  if (pVector != nullptr)
    delete[] pVector;
  pVector = nullptr;
}

template<class T>
bool TVector<T>::operator==(const TVector& _v) const
{
  if (size != _v.size)
    return false;
  for (int i = 0; i < size; i++)
    if (pVector[i] != _v.pVector[i])
      return false;
  return true;
}

template<class T>
bool TVector<T>::operator!=(const TVector& _v) const
{
  if (size != _v.size)
    return true;
  for (int i = 0; i < size; i++)
    if (pVector[i] != _v.pVector[i])
      return true;
  return false;
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector& _v)
{
  if (this == &_v)
    return *this;

  if (size != _v.size)
  {
    size = _v.size;
    if (pVector != nullptr)
      delete[] pVector;
    pVector = new T[size];
  }

  size = _v.size;
  start_index = _v.start_index;
  for (int i = 0; i < size; i++)
    pVector[i] = _v.pVector[i];

  return *this;
}

template<class T>
TVector<T> TVector<T>::operator+(const T& val)
{
  TVector res(*this);
  for (int i = start_index; i < size; i++)
    res.pVector[i] = pVector[i] + val;
  return res;
}

template<class T>
TVector<T> TVector<T>::operator-(const T& val)
{
  TVector res(*this);
  for (int i = start_index; i < size; i++)
    res.pVector[i] = pVector[i] - val;
  return res;
}

template<class T>
TVector<T> TVector<T>::operator*(const T& val)
{
  TVector res(*this);
  for (int i = start_index; i < size; i++)
    res.pVector[i] = pVector[i] * val;
  return res;
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  TVector<T> res(*this);
  res.pVector = new T[res.size];
  for (int i = 0; i < res.size; i++)
    res.pVector[i] = pVector[i] + _v.pVector[i];
  return res;
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  TVector<T> res(*this);
  res.pVector = new T[res.size];
  for (int i = 0; i < res.size; i++)
    res.pVector[i] = pVector[i] - _v.pVector[i];
  return res;
}

template <class T>
TVector<T> TVector<T>::operator /(TVector<T>& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  TVector<T> res(*this);
  res.pVector = new T[res.size];
  for (int i = 0; i < res.size; i++)
    res.pVector[i] = pVector[i] / _v.pVector[i];
  return res;
}

template <class T>
TVector<T>& TVector<T>::operator +=(TVector<T>& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  for (int i = 0; i < size; i++)
    pVector[i] += _v.pVector[i];
  return *this;
}

template <class T>
TVector<T>& TVector<T>::operator -=(TVector<T>& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  for (int i = 0; i < size; i++)
    pVector[i] -= _v.pVector[i];
  return *this;
}

template <class T> 
TVector<T> TVector<T>::operator*(const TVector<T>& _v)
{
  if (size != _v.size)
   throw - 1;
  TVector<T> res(*this);

  for (int i = 0; i < res.Size; i++)
    res.pVector[i] = pVector[i] * v.pVector[i];

  return res;
}

template<class T>
T& TVector<T>::operator[](int pos)
{
  if (pos < 0 || pos > size)
    throw - 1;
  return pVector[pos - start_index];
}

template<class T1>
ostream& operator<<(ostream& out, const TVector<T1>& _v)
{
  for (int i = 0; i < _v.size; i++)
    out << _v.pVector[i] << ' ';
  return out;
}

template<class T1>
istream& operator>>(istream& in, TVector<T1>& _v)
{
  for (int i = 0; i < _v.size; i++)
    in >> _v.pVector[i];
  return in;
}

#endif