#ifndef UNIVERGROUPSLAB_VECTOR_H
#define UNIVERGROUPSLAB_VECTOR_H

namespace Vector {

    template<class T>
    class MyVecIt {
    private:
        T *m_data;

    public:
        MyVecIt() : m_data(0) { }
        explicit MyVecIt(T *v) : m_data(v) { }
        MyVecIt(const MyVecIt<T> &iterator) = default;

        MyVecIt<T> &operator=(const MyVecIt<T> &) = default;
        MyVecIt<T> &operator++(){
          ++m_data;
          return *this;
        }
        MyVecIt<T> operator++(int num){
          MyVecIt<T> res(*this);
          ++m_data;
          return res;
        }
        MyVecIt<T> &operator--() {
          --m_data;
          return *this;
        }
        MyVecIt<T> operator--(int num){
          MyVecIt<T> res(*this);
          --m_data;
          return res;
        }
        MyVecIt<T> operator +(int index) { MyVecIt<T> res(m_data + index); return res; }
        MyVecIt<T> operator -(int index) { MyVecIt<T> res(m_data - index); return res; }
        MyVecIt<T> operator +=(int index) { m_data += index; return *this; }
        MyVecIt<T> operator -=(int index) { m_data -= index; return *this; }
        T &operator*() { return *m_data; }
        T &operator->() { return m_data; }
        bool operator == (const MyVecIt<T> &v) { return m_data == v.m_data; }
        bool operator != (const MyVecIt<T> &v) { return m_data != v.m_data; }
        bool operator < (const MyVecIt<T> &iter) { return m_data < iter.m_data; }
        bool operator > (const MyVecIt<T> &iter) { return m_data > iter.m_data; }
        bool operator <= (const MyVecIt<T> &iter) { return m_data <= iter.m_data; }
        bool operator >= (const MyVecIt<T> &iter) { return m_data >= iter.m_data; }
    };


    template<class T>
    class MyVec {
    private:
        int len;
        int capacity;
        T *m_data;
        const int QUOTE = 5;

    public:
        friend class MyVecIt<T>;
        // TODO to be added const iterator

        MyVec() {
          len = 0;
          capacity = QUOTE;
          m_data = new T[QUOTE];
        }

        explicit MyVec(int length) {
          int n = length / QUOTE;
          if (length % QUOTE != 0){
            n++;
          }
          m_data = new T[QUOTE * n];
          capacity = QUOTE * n;
          len = length;
        }

        // копирующий
        MyVec(const MyVec<T> &v){
          m_data = new T[v.len];
          len = v.len;
          capacity = v.capacity;
          for (int i = 0; i < len; ++i){
            m_data[i] = v.m_data[i];
          }
        }

        // переносящий
        MyVec( MyVec<T> &&v)  noexcept : len(v.len), capacity(v.capacity), m_data(v.m_data) {
          v.m_data = nullptr;
        }

        MyVec & operator = (const MyVec<T>& v) {
          if (this != &v){
            delete[] m_data;
            m_data = new T[v.capacity];
            len = v.len;
            capacity = v.capacity;
            for (int i = 0; i < len; ++i){
              m_data[i] = v.m_data[i];
            }
          }
          return *this;
        }

        MyVec & operator =(MyVec<T> &&v) noexcept {
          if (this != &v){
            std::swap(len, v.len);
            std::swap(capacity, v.capacity);
            std::swap(m_data, v.m_data);
          }
           return *this;
        }

        ~MyVec() {
          delete[] m_data;
        }

        void swap(MyVec<T> &v){
          std::swap(len, v.len);
          std::swap(capacity, v.capacity);
          std::swap(m_data, v.m_data);
        }

        void clear() {
          delete[] m_data;
          m_data = nullptr;
          len = 0;
          capacity = 0;
        }

        T &operator[] (int index) {
          if (index < 0 || index > len){
            throw std::out_of_range("Incorrect index!");
          }
          return m_data[index];
        }

        const T &operator[](int index) const {
          if (index < 0 || index > len){
            throw std::out_of_range("Incorrect index!");
          }
          return m_data[index];
        }

        bool isEmpty() {
          if (len == 0){
            return true;
          } else {
            false;
          };
        }

        // -1 = error
        int getIndex(T &s) const {
          for (int i = 0; i < len; ++i){
            if (m_data[i] == s){
              return i;
            }
          }
          return -1;
        }

        void delete_elem(T &elem){
          int ind;
          if ((ind = getIndex(elem)) == -1){
            throw std::invalid_argument("[!Err] No such object found!");
          }
          T *new_dat = new T[capacity];
          for (int i = 0; i < len; i++){
            if (i < ind){
              new_dat[i] = m_data[i];
            } else if (i > ind){
              new_dat[i-1] = m_data[i];
            }
          }
          delete[] m_data;
          len -= 1;
          m_data = new_dat;
        }

        void push_back(T& elem){
          // expanding
          if (len >= capacity){
            int n = (capacity / QUOTE) + 1;
            T *new_dat = new T[n * QUOTE];
            for (int i = 0; i < len; i++){
              new_dat[i] = m_data[i];
            }
            capacity = n * QUOTE;
            delete[] m_data;
            m_data = new_dat;
          }

          m_data[len] = elem;
          len += 1;
        }

        int getLen() { return len; }

        friend bool operator== (const MyVec<T> &v1, const MyVec<T> &v2){
          bool answer = ((v1.len == v2.len) && (v1.capacity == v2.capacity));
          if (!answer){
            return false;
          }
          for (int i = 0; i < v1.len; ++i){
            if (v1.m_data[i] != v2.m_data[i]){
              return false;
            }
          }
          return true;
        }

        friend bool operator != (const MyVec<T> &v1, const MyVec<T> &v2){
          return !(v1 == v2);
        }

        typedef MyVecIt<T> Iterator;
        Iterator begin();
        Iterator end();
        Iterator find(const T &);

    };

    template<class T>
    MyVecIt<T> MyVec<T>::begin() {
      return MyVecIt<T>(this->m_data);
    }

    template<class T>
    MyVecIt<T> MyVec<T>::end() {
      return MyVecIt<T>(this->m_data + len);
    }

    template<class T>
    MyVecIt<T> MyVec<T>::find(const T &s) {
      int index = getIndex(s);
      if (index < 0){
        index = len;
      }
      return MyVecIt<T>(this->m_data + index);
    }
}

#endif //UNIVERGROUPSLAB_VECTOR_H
