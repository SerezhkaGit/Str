

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
using namespace std;

class Str {
private:
    char* text;
    int size;

public:
    Str() : text{ nullptr }, size{ 0 } {}
    Str(const char* text) {
        this->size = strlen(text)+1;//стосовно +1. Якщо її не додати то потрібно внести зміни до перенавантаженого оператора виводу.
        this->text = new char[size];
        strncpy(this->text, text, size);
    }

    friend std::ostream& operator<<(std::ostream& out, const Str& text) {
        out << text.text;
        return out;
    }

    void insert(int index, const char* c) //вставляє рядок : )
    {
        int NEWsize = size + strlen(c);
        int j = 0, k = 0;
        char* tmp = new char[NEWsize + 1];

        for (int i = 0; i < NEWsize; i++)
        {

            if (i == index)
            {
                while (c[k] != '\0')
                {
                    tmp[i] = c[k];
                    k++;
                    i++;
                }
                i--;//якщо не додати то виведеться Kuziv(сміття)HelloSergi;
            }

            else
            {

                tmp[i] = text[j];
                j++;
            }

        }
        tmp[NEWsize] = '\0';


        delete[] text;
        size = NEWsize;
        text = tmp;
    }
 

    void pop_back()
    {
        if (size > 0)
        {
            int new_size = size - 1;
            char* tmp = new char[new_size + 1];

            for (int i = 0; i < new_size; i++)
            {
                tmp[i] = text[i];
            }

            tmp[new_size] = '\0';

            delete[] text;
            size = new_size;
            text = tmp;
        }
    }

    friend Str& operator+=(Str& s1, const Str& s2)
    {
        int new_size = (s1.size - 1) + (s2.size - 1);
        char* tmp = new char[new_size + 1];

        int j = 0;
        for (int i = 0; i < s1.size - 1; i++)
        {
            tmp[i] = s1.text[i];
        }

        for (int i = s1.size - 1; i < new_size; i++)
        {
            tmp[i] = s2.text[j];
            j++;
        }

        tmp[new_size] = '\0';

        delete[] s1.text;
        s1.text = tmp;
        s1.size = new_size;

        return s1;
    }




    void clear() {
        delete[] text;
        text = nullptr;
        size = 0;
    }

    ~Str() { clear(); }
};

int main() 
{
    Str m = "klass";
    cout << m << endl;
    Str k = "Hello";
    Str s = "Sergiy";
    k += s;
    cout << k << endl;
    k.pop_back();
    cout << k << endl;;

    k.insert(0, "Kuziv");
    cout << k;

    return 0;
}