#ifndef ASSOCIATION_H
#define ASSOCIATION_H

template<typename T>
class Association{
    private:
        int key;
        T value;
    public:
        Association(int _key, T _value) : key(_key), value(_value) {};

        T getValue(){return value;}
        int getKey(){return key;}

        ~Association(){}
};
#endif