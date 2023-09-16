// Caesar.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

// Функция для шифрования строки шифром Цезаря с заданным сдвигом
string caesarCipher(const string& text, int shift) 
{
    string result = text;
    for (char& c : result) 
    {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return result;
}

int main() 
{
    setlocale(0, "");
    string inputFileName, outputFileName;
    int shift;

    try 
    {
        cout << "Введите имя входного файла: ";
        cin >> inputFileName;

        cout << "Введите имя выходного файла: ";
        cin >> outputFileName;

        cout << "Введите сдвиг для шифра Цезаря: ";
        cin >> shift;

        ifstream inputFile(inputFileName);
        if (!inputFile)
        {
            throw runtime_error("Не удалось открыть входной файл.");
        }

        ofstream outputFile(outputFileName, ios::binary);
        if (!outputFile) 
        {
            throw runtime_error("Не удалось создать выходной файл.");
        }

        // Шифруем строку и записываем в выходной файл в бинарном виде
        string line;
        while (getline(inputFile, line))
        {
            string encryptedLine = caesarCipher(line, shift);
            outputFile.write(encryptedLine.c_str(), encryptedLine.size());
        }

        inputFile.close();
        outputFile.close();

        cout << "Шифрование завершено." << endl;

    }
    catch (const exception& e) 
    {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}

