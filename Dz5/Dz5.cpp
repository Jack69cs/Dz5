#include <iostream>
#include <vector>

// Задание 1
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return 0; // Неверный месяц
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int totalDays = 0;

    // Проверяем, если первая дата позже второй, меняем их местами
    if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2)) {
        int tempDay = day1, tempMonth = month1, tempYear = year1;
        day1 = day2; month1 = month2; year1 = year2;
        day2 = tempDay; month2 = tempMonth; year2 = tempYear;
    }

    // Считаем дни до конца первого месяца
    totalDays += daysInMonth(month1, year1) - day1;

    // Считаем дни в полных месяцах первого года
    month1++;
    while (month1 <= 12) {
        totalDays += daysInMonth(month1, year1);
        month1++;
    }

    // Считаем дни в полных годах между датами
    year1++;
    while (year1 < year2) {
        totalDays += isLeapYear(year1) ? 366 : 365;
        year1++;
    }

    // Считаем дни в месяцах второго года
    month2 = 1;
    while (month2 < month2) {
        totalDays += daysInMonth(month2, year2);
        month2++;
    }

    // Считаем дни в последнем месяце
    totalDays += day2;

    return totalDays;
}

// Задание 2
double average(const std::vector<int>& arr) {
    if (arr.empty()) return 0.0;

    double sum = 0.0;
    for (size_t i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum / arr.size();
}

// Задание 3
void countElements(const std::vector<int>& arr, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            positiveCount++;
        }
        else if (arr[i] < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    // Задание 1
    int day1, month1, year1, day2, month2, year2;
    std::cout << "Введите первую дату (день месяц год): ";
    std::cin >> day1 >> month1 >> year1;
    std::cout << "Введите вторую дату (день месяц год): ";
    std::cin >> day2 >> month2 >> year2;
    int difference = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    std::cout << "Разность в днях между датами: " << difference << " дней." << std::endl;

    // Задание 2
    std::vector<int> numbers1 = { 1, 2, 3, 4, 5 };
    std::cout << "Среднее арифметическое: " << average(numbers1) << std::endl;

    // Задание 3
    std::vector<int> numbers2 = { 1, -2, 0, 3, -4, 5, 0 };
    int positiveCount, negativeCount, zeroCount;
    countElements(numbers2, positiveCount, negativeCount, zeroCount);

    std::cout << "Положительные: " << positiveCount << std::endl;
    std::cout << "Отрицательные: " << negativeCount << std::endl;
    std::cout << "Нулевые: " << zeroCount << std::endl;

    return 0;
}


