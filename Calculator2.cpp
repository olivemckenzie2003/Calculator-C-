#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    char predictions[][90] = { "Multiply", "Add", "Subtract","Divide" };
    char actions[][90] = { "*", "+", "-","/"};

    bool end{ false };

    const int max_length{ 15 };
    char name[max_length]{};

    cout << "Welcome to the greatest calculator on earth!" << endl;
    cout << "This Calculator will randomly select to multiply, subtract,add, divide two numbers between 1 and 199." << endl;
    cout << endl;

    while (!end) {
        // Generate two random numbers
        int random_num = std::rand() % 199 + 1; // [1, 199]
        int random_num1 = std::rand() % 199 + 1;

        // Choose a random operation
        size_t rand_num = static_cast<size_t>(rand() % size(predictions));

        cout << "What is " << random_num << " " << actions[rand_num] << " " << random_num1 << "?" << endl;

        int userAnswer;
        int correctAnswer{ 0 };

        // Calculate the correct answer based on the operation
        if (predictions[rand_num] == string("Multiply")) {
            correctAnswer = random_num * random_num1;
        } else if (predictions[rand_num] == string("Add")) {
            correctAnswer = random_num + random_num1;
        } else if (predictions[rand_num] == string("Subtract")) {
            correctAnswer = random_num - random_num1;
        }else if (predictions[rand_num] == string("Divide")) {
            correctAnswer = random_num / random_num1;
        }

        // User input and validation loop
        bool answeredCorrectly{ false };

        while (!answeredCorrectly) {
            cout << "Enter your answer: ";
            cin >> userAnswer;

            if (cin.fail()) {
                cin.clear(); // Clear the error state
                cin.ignore(10000, '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            if (userAnswer == correctAnswer) {
                cout << "Correct Answer!" << endl;
                answeredCorrectly = true;
            } else {
                cout << "Wrong Answer. Do you want to try again? (Y/N): ";
                char tryAgain;
                cin >> tryAgain;

                if (tryAgain == 'N' || tryAgain == 'n') {
                    cout << "The correct answer is: " << correctAnswer << endl;
                    answeredCorrectly = true;
                }
            }
        }

        // Ask if the user wants to continue
        cout << "Do you want to continue using the world's best calculator? (Y/N): ";
        char continueCalc;
        cin >> continueCalc;

        end = (continueCalc == 'N' || continueCalc == 'n');
    }

    cout << "That's all I have for you today. Best wishes!" << endl;
    return 0;
}