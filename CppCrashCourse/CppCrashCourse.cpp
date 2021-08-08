#include <iostream>

void gradeConvertor(char arr1[], int sizeOfArr1, int arr2[]);
double calculateGpa(int arr[], int sizeOfArr);
void gradePrompt(int arr[], int sizeOfArr);
int convertGradeToPoint(char args);
void testPointerArr(int* arg);
void testPointerWithRef(int* arg);
void testPointer(int* arg);

int main()
{
    //int grades[5] = {};
    //gradePrompt(grades, 5);

    //double result = calculateGpa(grades, 5);

    //std::cout << result;

    int numbers[3] = { 1,2,3 };
    //std::cout << numbers[2];
    testPointerArr(numbers);

    int num = 10;
    testPointerWithRef(&num);

    int num2 = 50;
    std::cout << &num2;
    std::cout << "\n";
    int* num2Ptr = &num2;
    std::cout << num2Ptr;
    testPointer(num2Ptr);

 /*   std::cout << "\n";
    std::cout << numbers[2];

    std::cout << "\n";
    std::cout << num;
    
    std::cout << "\n";
    std::cout << num2;*/

    system("pause>0");
}

void testPointerArr(int* num) {
    num[2] = 5;

}

void testPointerWithRef(int* num) {
    *num += 5;
}

void testPointer(int* num) {
    *num += 20;
}

void gradePrompt(int grades[], int gradesSize) {
    char charGrade;
    for (int i = 0; i < gradesSize; i++) {
        std::cout << "Enter your subject grade ";
        std::cout << i+1;
        std::cout << ": ";
        std::cin >> charGrade;

        int point = convertGradeToPoint(charGrade);

        if (point == -1) {
            i--;
            std::cout << "Invalid grade input\n";
            continue;
        } else {
            grades[i] = convertGradeToPoint(charGrade);
        }
    }
}

int convertGradeToPoint(char grade) {
    switch (std::toupper(grade)) {
    case 'A':
        return 4;
    case 'B':
        return 3;
    case 'C':
        return 2;
    case 'D':
        return 1;
    case 'F':
        return 0;
    default:
        return -1;
    }
}

void gradeConvertor(char grades[], int gradesSize, int gradePoints[]) {

    for (int i = 0; i < gradesSize; i++) {
        switch (std::toupper(grades[i])) {
            case 'A':
                gradePoints[i] = 4;
                break;
            case 'B':
                gradePoints[i] = 3;
                break;
            case 'C':
                gradePoints[i] = 2;
                break;
            case 'D':
                gradePoints[i] = 1;
                break;
            case 'F':
                gradePoints[i] = 0;
                break;
            default:
                std::cout << "Invalid grade input";
                break;
        }
    }
}

double calculateGpa(int grades[], int sizeOfGrades) {
    int subject1Credit = 2;
    int subject2Credit = 3;
    int subject3Credit = 3;
    int subject4Credit = 4;
    int subject5Credit = 4;
    int totalCredit = subject1Credit + subject2Credit + subject3Credit + subject4Credit + subject5Credit;

    double sum = 0;

    for (int i = 0; i < sizeOfGrades; i++) {

        switch (i + 1) {
            case 1: 
                sum += double(grades[i]) * double(subject1Credit);
                break;
            case 2:
                sum += double(grades[i]) * double(subject2Credit);
                break;
            case 3:
                sum += double(grades[i]) * subject3Credit;
                break;
            case 4:
                sum += double(grades[i]) * subject4Credit;
                break;
            case 5:
                sum += double(grades[i]) * subject5Credit;
                break;
            default:
                break;
        }
    }

    return sum / totalCredit;
}