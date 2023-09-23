#include "convert.h"

std::string convert(int n) {

    if (n == 0) {
        return "sıfır";
    }

    std::string s = "";

    switch (n / 10)
    {
        case 1 : {
            s += "on";
        }
        break;

        case 2 : {
            s += "yirmi";
        }
        break;

        case 3 : {
            s += "otuz";
        }
        break;

        case 4 : {
            s += "kırk";
        }
        break;

        case 5 : {
            s += "elli";
        }
        break;

        case 6 : {
            s += "altmış";
        }
        break;

        case 7 : {
            s += "yetmiş";
        }
        break;

        case 8 : {
            s += "seksen";
        }
        break;

        case 9 : {
            s += "doksan";
        }
        break;
    }

    if (n / 10 != 0 && n % 10 != 0) {
        s += " ";
    }

    switch (n % 10) {
        case 1 : {
            s += "bir";
        }
        break;

        case 2 : {
            s += "iki";
        }
        break;

        case 3 : {
            s += "üç";
        }
        break;

        case 4 : {
            s += "dört";
        }
        break;

        case 5 : {
            s += "beş";
        }
        break;

        case 6 : {
            s += "altı";
        }
        break;

        case 7 : {
            s += "yedi";
        }
        break;

        case 8 : {
            s += "sekiz";
        }
        break;

        case 9 : {
            s += "dokuz";
        }
        break;
    }
    
    return s;
}
