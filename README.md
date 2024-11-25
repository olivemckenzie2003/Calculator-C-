# Calculator-C-

using namespace std;

    #include <iostream>: Used for input and output operations (cin, cout).
    
    #include <string>: Provides the string type and string operations.
    
    #include <ctime>: Provides the time function, used to seed the random number generator.
    
    using namespace std;   : Allows direct usage of standard library names without the std:: prefix.
    

2. Random Seed Initialization

srand(time(0));

srand(time(0)) seeds the random number generator with the current time to ensure random results every time the program is run.

3. Data Structures

char predictions[][90] = { "Multiply", "Add", "Subtract","Divide" };

char actions[][90] = { "*", "+", "-","/" };

Predictions contains the names of the operations as strings.
    
Actions contains the corresponding symbols for each operation.

4. Main Loop

bool end{ false };

A while (!end) loop is used to repeatedly generate and solve problems until the user decides to exit.

5. Random Number and Operation Selection

int random_num = rand() % 199 + 1; // [1, 199]

int random_num1 = rand() % 199 + 1;

size_t rand_num = static_cast<size_t>(rand() % size(predictions));

Two random numbers between 1 and 199 are generated.

A random index is chosen to select an operation from predictions and actions.

6. Problem Display

cout << "What is " << random_num << " " << actions[rand_num] << " " << random_num1 << "?" << endl;

Displays the arithmetic problem using the randomly generated numbers and operation.

7. Correct Answer Calculation

if (predictions[rand_num] == string("Multiply")) {

    correctAnswer = random_num * random_num1;
    
} else if (predictions[rand_num] == string("Add")) {

    correctAnswer = random_num + random_num1;
    
} else if (predictions[rand_num] == string("Subtract")) {

    correctAnswer = random_num - random_num1;
    
} else if (predictions[rand_num] == string("Divide")) {

    correctAnswer = random_num / random_num1;
}

Determines the correct answer based on the randomly selected operation.

8. User Input and Validation

cin >> userAnswer;

if (cin.fail()) {

    cin.clear();
    
    cin.ignore(10000, '\n');
    
    cout << "Invalid input. Please enter a number." << endl;
    
    continue;
}

    The program takes user input and validates it.
    
    If the input is invalid (e.g., not a number), the program clears the error state and prompts the user again.

9. Answer Feedback

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

    If the user’s answer is correct, they are notified.
    If incorrect, they are given the option to retry or reveal the correct answer.

10. Continuation Prompt

cout << "Do you want to continue using the world's best calculator? (Y/N): ";

char continueCalc;

cin >> continueCalc;

end = (continueCalc == 'N' || continueCalc == 'n');

    After solving a problem, the program asks if the user wants to continue or exit.

11. Exit Message

cout << "That's all I have for you today. Best wishes!" << endl;

    A farewell message is displayed before the program ends.

Key Points

    Randomness: Operations and numbers are randomized.
    
    User Interaction: The program is interactive, providing feedback and allowing retries.
    
    Validation: Handles invalid inputs gracefully.
    
    Simple Logic: Implements basic arithmetic operations in a fun, gamified way.
