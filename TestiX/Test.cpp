#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <time.h>
using namespace std;

struct studentAge
{
    int studentDayBirth;
    int studentMonthBirth;
};

struct test
{
    string sudentAnswer;
    string studentName;
    string studentSurname;
    string studentGroup;
    string startedTime;
    string finalTime;
    studentAge age;
};

const int QUANTITY_OF_TASKS = 10;
const int LUCKY_NUMBER_MIN = 1;
const int LUCKY_NUMBER_MAX = 1000;

const string currentDateTime();
string printTasksFromFile(string);
int getAge(test, int);
int testFileTasks(string);
void writeInStruct(test);
void writeALLAnswersInFile(string, test, int);
void showStudentAnswers(test);
void answerOFendingTest(test, int);
void answerOneTaskOfStruct(test);
void writeSudentName(test);
void luckAnswers(test);
void testMenu(test, int);
void testStarted();

const string currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);
    return buf;
}

string printTasksFromFile(string fileName)
{
    string result = "";
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "File opening error!" << endl;
    }
    while (!file.eof())
    {
        result = "";
        getline(file, result);
        cout << result << "\n";
    }
    file.close();
    return result;
}

int getAge(test *list, int &mark)
{
    cout << "Enter your birthday: ";
    cin >> list->age.studentDayBirth;
    cout << "Enter the month of birth: ";
    cin >> list->age.studentMonthBirth;
    time_t t = time(0);
    tm *now = localtime(&t);
    if (list->age.studentDayBirth == now->tm_mday && list->age.studentMonthBirth == now->tm_mon + 1)
    {
        mark++;
    }
    return mark;
}

int studentMark(int &mark)
{
    string stringAnswers;
    string stringRightAnswers;
    ifstream rightFile("rightAnswers.txt");
    ifstream answers("answers.txt");
    if (!rightFile.is_open())
    {
        cout << "An error occurred: rating" << endl;
    }
    int numberOfLines = 0;
    while (numberOfLines < 10)
    {
        getline(answers, stringAnswers);
        getline(rightFile, stringRightAnswers);
        numberOfLines++;
        if (stringAnswers == stringRightAnswers)
        {
            mark++;
        }
    }
    rightFile.close();
    answers.close();
    return mark;
}

int plusPoint(int &mark)
{
    if (mark > 10)
    {
        cout << mark - (mark % 10) << " + " << mark % 10 << "point" << endl;
        return 0;
    }
    return mark;
}

int testFileTasks(string fileName)
{
    char *arr = new char[2048];
    int count = 0;
    ifstream file(fileName);
    while (!file.eof())
    {
        file.getline(arr, 2048, '\n');
        count++;
    }
    file.close();
    if (count != QUANTITY_OF_TASKS)
    {
        return -1;
    }
    return count;
    delete[] arr;
}

void writeInStruct(test *list)
{
    for (int i = 1; i <= QUANTITY_OF_TASKS; i++)
    {
        cout << i << ". ";
        cin >> list[i].sudentAnswer;
    }
}

void writeALLAnswersInFile(string fileName, test *list, int &mark)
{
    ofstream file(fileName);
    if (!file.is_open())
    {
        cout << "File opening error!" << endl;
    }

    for (int i = 1; i <= QUANTITY_OF_TASKS; i++)
    {
        if (i == 10)
        {
            file << i << ". " << list[i].sudentAnswer;
        }
        else
        {
            file << i << ". " << list[i].sudentAnswer << endl;
        }
    }
    file << "\nSurname: " << list->studentSurname << endl;
    file << "Name: " << list->studentName << endl;
    file << "Group: " << list->studentGroup << endl;
    file << "Mark: " << mark << endl;
    file << "Test start time: " << list->startedTime << endl;
    file << "Test end time: " << list->finalTime;
    file.close();
}

void showStudentAnswers(test *list)
{
    for (int i = 1; i <= QUANTITY_OF_TASKS; i++)
    {
        cout << i << ". " << list[i].sudentAnswer << endl;
    }
}

void answerOFendingTest(test *list, int &mark)
{
    cout << "\nIs this the final answer?\t0 - yes\t1 - no\t3 - show my answers" << endl;
    int userSelection;
    cin >> userSelection;
    if (userSelection == 0)
    {
        writeALLAnswersInFile("answers.txt", list, mark);
    }
    else if (userSelection == 1)
    {
        testMenu(list, mark); 
    }
    else if (userSelection == 3)
    {
        cout << "Your answers: " << endl;
        showStudentAnswers(list);
    }
}

void answerOneTaskOfStruct(test *list)
{
    int userSelection;
    bool program;
    while (!program)
    {
        cout << "Choose a specific task to answer: " << endl;
        cin >> userSelection;
        switch (userSelection)
        {
        case 1:
            cout << "1. ";
            cin >> list[1].sudentAnswer;
            break;
        case 2:
            cout << "2. ";
            cin >> list[2].sudentAnswer;
            break;
        case 3:
            cout << "3. ";
            cin >> list[3].sudentAnswer;
            break;
        case 4:
            cout << "4. ";
            cin >> list[4].sudentAnswer;
            break;
        case 5:
            cout << "5. ";
            cin >> list[5].sudentAnswer;
            break;
        case 6:
            cout << "6. ";
            cin >> list[6].sudentAnswer;
            break;
        case 7:
            cout << "7. ";
            cin >> list[7].sudentAnswer;
            break;
        case 8:
            cout << "8. ";
            cin >> list[8].sudentAnswer;
            break;
        case 9:
            cout << "9. ";
            cin >> list[9].sudentAnswer;
            break;
        case 10:
            cout << "10. ";
            cin >> list[10].sudentAnswer;
            break;
        default:
            cout << "There is no such question!" << endl;
            break;
        }
        cout << "Press 0 for further selection\tPress 1 to complete the selection" << endl;
        cin >> program;
    }
}

void writeSudentName(test *list)
{
    cout << "\nEnter your last name- ";
    cin >> list->studentSurname;
    cout << "Enter your name- ";
    cin >> list->studentName;
    cout << "Enter your group- ";
    cin >> list->studentGroup;
}

void luckAnswers(test *list)
{
    int userSelection;
    cout << "\nFill in all tasks randomly - 1\tFill in the selected tasks randomly - 2" << endl;
    cin >> userSelection;
    switch (userSelection)
    {
    case 1:
        for (int i = 0; i <= QUANTITY_OF_TASKS; i++)
        {
            list[i].sudentAnswer = rand() % (LUCKY_NUMBER_MAX - LUCKY_NUMBER_MIN + 1) + LUCKY_NUMBER_MIN;
        }
        break;
    case 2:
        int point, numberOfTasks;
        cout << "How many tasks do you want to complete randomly?" << endl;
        cin >> numberOfTasks;
        cout << "Which task should I fill out randomly?" << endl;
        for (int i = 0; i < numberOfTasks; i++)
        {
            cin >> point;
            list[point].sudentAnswer = rand() % (LUCKY_NUMBER_MAX - LUCKY_NUMBER_MIN + 1) + LUCKY_NUMBER_MIN;
        }
        break;
    default:
        cout << "There is no such choice!" << endl;
        break;
    }
}

void testMenu(test *list, int &mark)
{
    int userSelection;
    bool program;
    while (!program)
    {
        cout << "\nIf you know all the answers, press - 1\tSolve one number - 2\tIf you want to try your luck - 3\tIt's my birthday! - 4\tI don't want to change - 5" << endl;
        cin >> userSelection;
        switch (userSelection)
        {
        case 1:
            writeInStruct(list);
            answerOFendingTest(list, mark);
            break;
        case 2:
            answerOneTaskOfStruct(list);
            answerOFendingTest(list, mark);
            break;
        case 3:
            luckAnswers(list);
            answerOFendingTest(list, mark);
            break;
        case 4:
            getAge(list, mark);
            answerOFendingTest(list, mark);
            break;
        case 5:
            answerOFendingTest(list, mark);
            break;
        default:
            cout << "There is no such option!" << endl;
            break;
        }
        cout << "Press 0 to change\tPress 1 to complete the test" << endl;
        cin >> program;
        if (program == 1)
        {
            writeALLAnswersInFile("answers.txt", list, mark);
        }
    }
}

void testStarted()
{
    cout << "Get ready!\tThe test will start in 3 seconds" << endl;
    for (int i = 3; i > 0; i--)
    {
        if (i == 1)
        {
            cout << i << " second" << endl;
        }
        else
        {
            cout << i << " seconds" << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    srand(time(NULL));
    int mark = 0;
    int testVal = testFileTasks("tasks.txt");
    if (testVal == -1)
    {
        cout << "Contact the teacher!\tThere is an error in the tasks. " << endl;
        return 0;
    }
    cout << "\n\tAre you ready to start testing?\tThe time is recorded\nAlways ready! - 1\tNo.. - 0" << endl;
    bool userSelection;
    cin >> userSelection;
    if (userSelection == 0)
    {
        return 0;
    }
    testStarted(); 
    test *list = new test[QUANTITY_OF_TASKS];

    cout << "\nWelcome to the test!\tA test of 10 questions.\tOne question - one point.\tBirthday persons +1 to the rating\n"
         << endl;
    cout << "Your tasks: \n"
         << printTasksFromFile("tasks.txt") << endl;
    list->startedTime = currentDateTime();
    writeSudentName(list);
    testMenu(list, mark);
    cout << "The test is completed!\tYour rating: ";
    studentMark(mark);
    plusPoint(mark);
    list->finalTime = currentDateTime();
    writeALLAnswersInFile("answers.txt", list, mark);
    return 0;
}
