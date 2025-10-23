#include <iostream>
#include <vector>

// функция для нахождения максимальной по длине последовательности подряд идущих символов,
// которые составляют подстроку "youit"

int youItCheck(std::string &str) // строка передается по ссылке, чтобы не выделять новую память под строку
{
    std::string youItStr = "youit";
    int count = 0, maxCount = 0; // счетчик текущей серии совпадений символов и максимальной
    auto i = str.begin();        // указатель на символы строки, в которой будет осуществлятся поиск
    auto j = youItStr.begin();   // указатель на символы строки шаблона

    while (i != str.end()) // цикл работает, пока не закончится строка str. При этом указатели i и j могут увеличиваются параллельно
    {
        if (*i == *j) // если символы строк совпадают, увеличиваем оба указателя и увеличиваем счетчик
        {
            ++count;
            ++i;
            ++j;
        }
        else // если не совпадают, то переводим итератов строки шаблона в начало строки, обнуляем счетчик
        {
            j = youItStr.begin();
            if (*i != *j) // увеличиваем счетчик i только если он не равен первой ьукве строки шаблона, то есть 'y'
                ++i;

            count = 0;
        }
        if (j == youItStr.end()) // следим, чтобы указатель строки шаблона перемешался в начало строки при достижении конца
            j = youItStr.begin();

        if (count > maxCount) // увеличиваем максимальный счеткик,если он меньше текущего
            maxCount = count;
    }

    return maxCount; // возвращаем максимальное значение совпадений
}

int main()
{
    int testNumber;
    std::vector<std::string> vecForCheck; // используем вектор для динамического выделения памяти для хранения строк
    std::string strForCheck;
    std::cin >> testNumber;

    for (int i = 0; i < testNumber; ++i) // добавляем в конец вектора нововведенные строки
    {
        std::cin >> strForCheck;
        vecForCheck.push_back(strForCheck);
    }

    for (auto &it : vecForCheck) // применяем функцию youItCheck(...) к каждой строке вектора и выводим ее резутьтат
    {
        std::cout << youItCheck(it) << std::endl;
    }

    return 0;
}

/*
    {"youityou",
       "bbbbbybbb",
       "xyz",
       "youiyouit",
       "t",
       "y",
       "youitxyouityouit",
       "yoyoyoy",
       "abcyouityouityouityouityouityouityoui"};
    */