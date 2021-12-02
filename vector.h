#ifndef UNIVERGROUPSLAB_VECTOR_H
#define UNIVERGROUPSLAB_VECTOR_H

template <class T>
class MyVecIt {
private:
    T *m_current;

public:

};


template <class T>
class MyVec {
private:
    int len;
    int capacity;
    T *m_data;
    const int QUOTE = 5;

public:
    MyVec() { len = 0; capacity = QUOTE; m_data = new T[QUOTE]; }

    int getLen() { return len; }


    void push_back(T elem){
      // expand
      if (len >= capacity){

      }
    }

};



#endif //UNIVERGROUPSLAB_VECTOR_H
