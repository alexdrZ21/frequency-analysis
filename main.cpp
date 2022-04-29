#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <windows.h>


using namespace std;

string readFile(const string& fileName)
{
    ifstream f(fileName);
    stringstream sst;
    sst << f.rdbuf();
    return sst.str();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string delim(".:;,()-?!'");
    string str;
    map<string, int> freq; // словарь (ключ/значение)
    cout << "string" << endl;
    getline(cin, str);
    int str_count = 0; // число слов
    int index;
    while ((index = str.find_first_of(delim)) != string::npos) // замена всех стоп знаков на пробелы
        str[index] = ' ';
    // строки делим на слова, помещаем слова в слолварь(ключ/значение)
    stringstream ss(str);
    while (ss >> str)
    {
        ++str_count;
        freq[str]++;
    }
    cout << "frequency" << endl;
    for (map<string, int>::iterator iter = freq.begin(); iter != freq.end(); ++iter) // подсчёт частоты
    {
        double p = static_cast<double>(iter->second) / static_cast<double>(str_count) * 100;
        cout << iter->first << ": " << p << "%" << endl;
    }
    system("pause"); //если не указать, то консоль вылетит
    return 0;
}
