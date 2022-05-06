#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <streambuf>

using namespace std;

void del_conv(ifstream& inp, ofstream& outp)
{
    char x;
    while (inp.get(x))
    {
        if (x == ',')
            x = ' ';
        outp << x;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    string delim(".:;&#,()*-?!'");
    ifstream t("D:/pushkin-metel.txt");
    string str((std::istreambuf_iterator<char>(t)),
        istreambuf_iterator<char>());
    map<string, int> freq; // словарь (ключ/значение)
    int str_count = 0; // число слов
    int index;
    while ((index = str.find_first_of(delim)) != string::npos) // замена всех стоп знаков на пробелы
        str[index] = ' ';
    // строки делим на слова, помещаем слова в слолварь(ключ/значение)
    
    stringstream ss(str);
    ofstream out("D:/out.txt");
    ifstream del("D:/del.txt");
    ofstream _del("D:/delNEW.txt");
    del_conv(del, _del);
    _del.close();
    ifstream delet("D:/delNEW.txt");
    while (delet >> str) // удаление стоп слов
    {
        freq.erase(str);
    }
    while (ss >> str)
    {
        ++str_count;
        freq[str]++;
    }
    cout << "frequency" << endl;
    for (map<string, int>::iterator iter = freq.begin(); iter != freq.end(); ++iter) // подсчёт частоты
    {
        double p = static_cast<double>(iter->second) / static_cast<double>(str_count) * 100;
        out << iter->first << ": " << p << "%" << endl;
    }
    system("pause"); //если не указать, то консоль вылетит

    return 0;
}
