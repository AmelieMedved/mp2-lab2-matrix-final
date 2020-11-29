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
  TVector(int _size = 1, int _start_index = 0); // ����������� �� ���������
  TVector(const TVector& _v); // ����������� �����������
  ~TVector(); // ����������

  int GetSize() { return size; } // �������� ������
  int GetStartIndex() { return start_index; } // �������� ��������� ������
  T& operator[](int pos); // �������� ����������
  bool operator==(const TVector& _v) const; // �������� ���������
  bool operator!=(const TVector& _v) const; // �������� ���������
  TVector& operator=(const TVector& _v); // �������� ������������

  // �������� �� ���������
  TVector  operator+(const T& val);
  TVector  operator-(const T& val);
  TVector  operator*(const T& val);

  // ��������� ��������
  TVector  operator+(const TVector& _v);
  TVector  operator-(const TVector& _v);
  T  operator*(const TVector& _v);
  TVector<T> operator /(TVector<T>& _v); // �������
  TVector<T>& operator +=(TVector<T>& _v); // ��������
  TVector<T>& operator -=(TVector<T>& _v); // ���������

  // ����-�����
  template<class T1>
  friend ostream& operator << (ostream& out, const TVector<T1>& _v);
  template <class T1>
  friend istream& operator >> (istream& in, TVector<T1>& _v);
};

template<class T>
TVector<T>::TVector(int _size, int _start_index) : size(_size), start_index(_start_index), pVector(nullptr)
{
  if (size < 0)
    throw "negative vector size";
  if (start_index < 0)
    throw "negative startindex";
  pVector = new T[_size];
  for (int i = 0; i < _size; i++)
    pVector[i] = 0;
}

template<class T>
TVector<T>::TVector(const TVector& _v) : size(_v.size), start_index(_v.start_index), pVector(nullptr)
{
  pVector = new T[size];
  for (int i = 0; i < size; i++)
    pVector[i] = _v.pVector[i];
}

template<class T>
TVector<T>::~TVector()
{
  size = 0;
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
  else
  {
    if (size != _v.size)
    {
      size = _v.size;
      delete[] pVector;
      pVector = new T[size];
    }
    start_index = _v.start_index;
    for (int i = 0; i < size; i++)
      pVector[i] = _v.pVector[i];
  }
  return *this;
}

template<class T>
TVector<T> TVector<T>::operator+(const T& val)
{
  TVector res(size, start_index);
  for (int i = start_index; i < size; i++)
    res.pVector[i] = pVector[i] + val;
  return res;
}

template<class T>
TVector<T> TVector<T>::operator-(const T& val)
{
  TVector res(size, start_index);
  for (int i = start_index; i < size; i++)
    res.pVector[i] = pVector[i] - val;
  return res;
}

template<class T>
TVector<T> TVector<T>::operator*(const T& val)
{
  TVector res(size, start_index);
  for (int i = start_index; i < size; i++)
    res.pVector[i] = pVector[i] * val;
  return res;
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  TVector<T> res(size, start_index);
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
  TVector<T> res(size, start_index);
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
  TVector<T> res(size, start_index);
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

template<class T>
T TVector<T>::operator*(const TVector& _v)
{
  if ((size != _v.size) || (start_index != _v.start_index))
    throw "different sizes of vectors";
  T res = 0;
  for (int i = start_index; i < size; i++)
    res += pVector[i] * _v.pVector[i];
  return res;
}

template<class T>
T& TVector<T>::operator[](int pos)
{
  if ((pos < start_index) || (pos >= size) || (pos < 0))
    throw "wrong position";
  return pVector[pos];
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