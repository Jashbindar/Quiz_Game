// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <algorithm>
#include <array>
#include <fstream>

using namespace std;

// Global variables
int start, menuOpt, streak, score, Namecount;
int difficulty = 1; // Default difficulty level
int lives = 99; // Default number of lives
int x = 25; // Default number of questions in quiz
int quizLength = 2;
string diff = "Normal"; // Default difficulty mode
string name;
char ans;
char replay = 'Y'; // Variable to decide if the user wants to replay the game
int ScoreArray[20];
string NameArray[20];

const int questioncount = 50;

// Array holding the questions
string questionbank[questioncount] = {
    "What is the capital of France?\n A. Rome\n B. Berlin\n C. Paris\n D. Madrid",
    "Who wrote the play 'Romeo and Juliet'?\n A.Charles Dickens\n B.William Shakespeare\n C.Mark Twain\n D.Jane Austen",
    "What is the largest planet in our solar system?\n A.Earth\n B.Mars\n C.Saturn\n D.Jupiter",
    "Who painted the Mona Lisa?\n A.Vincent van Gogh\n B.Pablo Picasso\n C.Leonardo da Vinci\n D.Claude Monet",
    "What is the smallest country in the world by area?\n A.Monaco\n B.Vatican City\n C.San Marino\n D.Liechtenstein",
    "In which year did the Titanic sink?\n A. 1905\n B. 1918\n C. 1912\n D. 1925",
    "What is the chemical symbol for gold?\n A.Ag\n B.Au\n C.Pt\n D.Fe",
    "Who is known as the 'Father of Computers'?\n A.Charles Babbage\n B.Alan Turing\n C.Bill Gates\n D.Steve Jobs",
    "What is the hardest natural substance on Earth?\n A. Diamond\n B.Quartz\n C.Topaz\n D.Ruby ",
    "What is the longest river in the world?\n A.Amazon River\n B.The Nile River\n C.Yangtze River\n D.Mississippi River",
    "Who was the first President of the United States?\n A.Thomas Jefferson\n B.John Adams\n C.George Washington\n D.Abraham Lincoln",
    "Which planet is known as the Red Planet?\n A.Venus\n B.Mars\n C.Mercury\n D.Jupiter",
    "What is the largest ocean on Earth?\n A.The Pacific Ocean\n B.The Atlantic Ocean\n C.The Indian Ocean\n D.The Southern Ocean",
    "Who invented the telephone?\n A.Thomas Edison\n B.Alexander Graham Bell\n C.Nikola Tesla\n D.Guglielmo Marconi",
    "How many continents are there on Earth?\n A. Five\n B.Six\n C.Seven\n D.eight",
    "In which year did World War II end?\n A. 1939\n B. 1942\n C. 1945\n D. 1950",
    "What is the capital of Japan?\n A.Seoul\n B.Beijing\n C.Bangkok\n D.Tokyo",
    "Which element has the atomic number 1?\n A.Helium\n B.Oxygen\n C.Carbon\n D.Hydrogen",
    "Who wrote the novel '19o84'?\n A.Aldous Huxley\n B.George Orwell\n C.Ray Bradbury\n D.J.R.R.Tolkien",
    "What is the largest mammal in the world?\n A.Elephant\n B.The Blue Whale\n C.Giraffe\n D.Hippopotamus",
    "What is the most widely spoken language in the world?\n A.English\n B.Mandarin Chinese\n C.Spanish\n D.Hindi",
    "Who was the first person to walk on the Moon?\n A.Buzz Aldrin\n B.Neil Armstrong\n C.Michael Collins\n D.Yuri Gagarin",
    "What is the currency of the United Kingdom?\n A.Euro\n B.Pound Sterling\n C.Dollar\n D.Franc",
    "What is the square root of 144?\n A. 10\n B. 11\n C. 12\n D. 13",
    "Who discovered penicillin?\n A.Louis Pasteur\n B.Alexander Fleming\n C.Marie Curie\n D.Joseph Lister",
    "What is the chemical formula for water?\n A.CO2\n B.NaCl\n C.H2O\n D.O2",
    "Which country is known as the Land of the Rising Sun?\n A.China\n B.South Korea\n C.Japan\n D.Thailand",
    "What is the capital city of Australia?\n A.Sydney\n B.Melbourne\n C.Brisbane\n D.Canberra",
    "In which continent is the Sahara Desert located?\n A.Asia\n B.South America\n C.Africa\n D.North America",
    "What is the main ingredient in guacamole?\n A.Tomato\n B.Onion\n C.Avocado\n D.Lime",
    "How many sides does a hexagon have?\n A.Five\n B.Six\n C.Seven\n D.Eight",
    "Who was the author of 'Harry Potter' series?\n A.J.R.R.Tolkien\n B.George R.R.Martin\n C.J.K.Rowling\n D.C.S.Lewis",
    "What is the primary gas found in the Earth's atmosphere?\n A.Oxygen\n B.Nitrogen\n C.Carbon Dioxide\n D.Argon",
    "Who painted the ceiling of the Sistine Chapel?\n A.Raphael\n B.Michelangelo\n C.Leonardo da Vinci\n D.Donatello",
    "What is the largest land animal?\n A.Giraffe\n B.African Elephant\n C.Rhinoceros\n D.Hippopotamus",
    "Which country is the largest by land area?\n A.Russia\n B.Canada\n C.China\n D.United States",
    "What is the currency used in Japan?\n A.Won\n B.Yuan\n C.Peso\n D.Yen",
    "What is the name of the longest mountain range in the world?\n A.Rocky Mountains\n B.The Andes\n C.The Himalayas\n D.The Alps",
    "Who was the first woman to win a Nobel Prize?\n A.Rosalind Franklin\n B.Mother Teresa\n C.Jane Addams\n D.Marie Curie",
    "In which city is the Statue of Liberty located?\n A.Los Angeles\n B.Chicago\n C.New York City\n D.Washington DC",
    "What is the main component of the sun?\n A.Helium\n B.Oxygen\n C.Hydrogen\n D.Carbon",
    "Which planet is closest to the sun?\n A.Venus\n B.Mars\n C.Mercury\n D.Earth",
    "Who is the author of 'Pride and Prejudice'?\n A.Jane Austen\n B.Emily Brontë\n C.Mary Shelley\n D.Charlotte Brontë",
    "What is the largest island in the world?\n A.Australia\n B.Greenland\n C.New Guinea\n D.Borneo",
    "How many bones are in the adult human body?\n A. 205\n B. 206\n C. 207\n D. 208",
    "Which ocean is the Bermuda Triangle located in?\n A.Indian Ocean\n B.Atlantic Ocean\n C.Pacific Ocean\n D.Southern Ocean",
    "Who was the British Prime Minister during World War II?\n A.Winston Churchill\n B.Neville Chamberlain\n C.Clement Attlee\n D.Anthony Eden",
    "What is the most popular sport in the world?\n A.Soccer\n B.Basketball\n C.Baseball\n D.Cricket",
    "Who discovered the theory of relativity?\n A.Isaac Newton\n B.Galileo Galilei\n C.Albert Einstein\n D.Niels Bohr",
    "What is the capital of Canada?\n A.Toronto\n B.Vancouver\n C.Montreal\n D.Ottawa"
};

// Array holding the correct answers corresponding to questions
char questionAns[questioncount] = {
    'C', 'B', 'D', 'C', 'B', 'C', 'B', 'A', 'A', 'B', 'C', 'B', 'A', 'B', 'A', 'C', 'D', 'D', 'B',
    'B', 'B', 'B', 'B', 'C', 'B', 'C', 'C', 'D', 'C', 'C', 'B', 'C', 'B', 'B', 'B', 'A', 'D', 'B',
    'D', 'C', 'C', 'A', 'C', 'C', 'A', 'C', 'B', 'C', 'B', 'D'
};

void reloadQuestionBank(){
    // Array holding the questions
    string questionbank[questioncount] = {
        "What is the capital of France?\n A. Rome\n B. Berlin\n C. Paris\n D. Madrid",
        "Who wrote the play 'Romeo and Juliet'?\n A.Charles Dickens\n B.William Shakespeare\n C.Mark Twain\n D.Jane Austen",
        "What is the largest planet in our solar system?\n A.Earth\n B.Mars\n C.Saturn\n D.Jupiter",
        "Who painted the Mona Lisa?\n A.Vincent van Gogh\n B.Pablo Picasso\n C.Leonardo da Vinci\n D.Claude Monet",
        "What is the smallest country in the world by area?\n A.Monaco\n B.Vatican City\n C.San Marino\n D.Liechtenstein",
        "In which year did the Titanic sink?\n A. 1905\n B. 1918\n C. 1912\n D. 1925",
        "What is the chemical symbol for gold?\n A.Ag\n B.Au\n C.Pt\n D.Fe",
        "Who is known as the 'Father of Computers'?\n A.Charles Babbage\n B.Alan Turing\n C.Bill Gates\n D.Steve Jobs",
        "What is the hardest natural substance on Earth?\n A. Diamond\n B.Quartz\n C.Topaz\n D.Ruby ",
        "What is the longest river in the world?\n A.Amazon River\n B.The Nile River\n C.Yangtze River\n D.Mississippi River",
        "Who was the first President of the United States?\n A.Thomas Jefferson\n B.John Adams\n C.George Washington\n D.Abraham Lincoln",
        "Which planet is known as the Red Planet?\n A.Venus\n B.Mars\n C.Mercury\n D.Jupiter",
        "What is the largest ocean on Earth?\n A.The Pacific Ocean\n B.The Atlantic Ocean\n C.The Indian Ocean\n D.The Southern Ocean",
        "Who invented the telephone?\n A.Thomas Edison\n B.Alexander Graham Bell\n C.Nikola Tesla\n D.Guglielmo Marconi",
        "How many continents are there on Earth?\n A. Five\n B.Six\n C.Seven\n D.eight",
        "In which year did World War II end?\n A. 1939\n B. 1942\n C. 1945\n D. 1950",
        "What is the capital of Japan?\n A.Seoul\n B.Beijing\n C.Bangkok\n D.Tokyo",
        "Which element has the atomic number 1?\n A.Helium\n B.Oxygen\n C.Carbon\n D.Hydrogen",
        "Who wrote the novel '1984'?\n A.Aldous Huxley\n B.George Orwell\n C.Ray Bradbury\n D.J.R.R.Tolkien",
        "What is the largest mammal in the world?\n A.Elephant\n B.The Blue Whale\n C.Giraffe\n D.Hippopotamus",
        "What is the most widely spoken language in the world?\n A.English\n B.Mandarin Chinese\n C.Spanish\n D.Hindi",
        "Who was the first person to walk on the Moon?\n A.Buzz Aldrin\n B.Neil Armstrong\n C.Michael Collins\n D.Yuri Gagarin",
        "What is the currency of the United Kingdom?\n A.Euro\n B.Pound Sterling\n C.Dollar\n D.Franc",
        "What is the square root of 144?\n A. 10\n B. 11\n C. 12\n D. 13",
        "Who discovered penicillin?\n A.Louis Pasteur\n B.Alexander Fleming\n C.Marie Curie\n D.Joseph Lister",
        "What is the chemical formula for water?\n A.CO2\n B.NaCl\n C.H2O\n D.O2",
        "Which country is known as the Land of the Rising Sun?\n A.China\n B.South Korea\n C.Japan\n D.Thailand",
        "What is the capital city of Australia?\n A.Sydney\n B.Melbourne\n C.Brisbane\n D.Canberra",
        "In which continent is the Sahara Desert located?\n A.Asia\n B.South America\n C.Africa\n D.North America",
        "What is the main ingredient in guacamole?\n A.Tomato\n B.Onion\n C.Avocado\n D.Lime",
        "How many sides does a hexagon have?\n A.Five\n B.Six\n C.Seven\n D.Eight",
        "Who was the author of 'Harry Potter' series?\n A.J.R.R.Tolkien\n B.George R.R.Martin\n C.J.K.Rowling\n D.C.S.Lewis",
        "What is the primary gas found in the Earth's atmosphere?\n A.Oxygen\n B.Nitrogen\n C.Carbon Dioxide\n D.Argon",
        "Who painted the ceiling of the Sistine Chapel?\n A.Raphael\n B.Michelangelo\n C.Leonardo da Vinci\n D.Donatello",
        "What is the largest land animal?\n A.Giraffe\n B.African Elephant\n C.Rhinoceros\n D.Hippopotamus",
        "Which country is the largest by land area?\n A.Russia\n B.Canada\n C.China\n D.United States",
        "What is the currency used in Japan?\n A.Won\n B.Yuan\n C.Peso\n D.Yen",
        "What is the name of the longest mountain range in the world?\n A.Rocky Mountains\n B.The Andes\n C.The Himalayas\n D.The Alps",
        "Who was the first woman to win a Nobel Prize?\n A.Rosalind Franklin\n B.Mother Teresa\n C.Jane Addams\n D.Marie Curie",
        "In which city is the Statue of Liberty located?\n A.Los Angeles\n B.Chicago\n C.New York City\n D.Washington DC",
        "What is the main component of the sun?\n A.Helium\n B.Oxygen\n C.Hydrogen\n D.Carbon",
        "Which planet is closest to the sun?\n A.Venus\n B.Mars\n C.Mercury\n D.Earth",
        "Who is the author of 'Pride and Prejudice'?\n A.Jane Austen\n B.Emily Brontë\n C.Mary Shelley\n D.Charlotte Brontë",
        "What is the largest island in the world?\n A.Australia\n B.Greenland\n C.New Guinea\n D.Borneo",
        "How many bones are in the adult human body?\n A. 205\n B. 206\n C. 207\n D. 208",
        "Which ocean is the Bermuda Triangle located in?\n A.Indian Ocean\n B.Atlantic Ocean\n C.Pacific Ocean\n D.Southern Ocean",
        "Who was the British Prime Minister during World War II?\n A.Winston Churchill\n B.Neville Chamberlain\n C.Clement Attlee\n D.Anthony Eden",
        "What is the most popular sport in the world?\n A.Soccer\n B.Basketball\n C.Baseball\n D.Cricket",
        "Who discovered the theory of relativity?\n A.Isaac Newton\n B.Galileo Galilei\n C.Albert Einstein\n D.Niels Bohr",
        "What is the capital of Canada?\n A.Toronto\n B.Vancouver\n C.Montreal\n D.Ottawa"
    };

    // Array holding the correct answers corresponding to questions
    char questionAns[questioncount] = {
        'C', 'B', 'D', 'C', 'B', 'C', 'B', 'A', 'A', 'B', 'C', 'B', 'A', 'B', 'A', 'C', 'D', 'D', 'B',
        'B', 'B', 'B', 'B', 'C', 'B', 'C', 'C', 'D', 'C', 'C', 'B', 'C', 'B', 'B', 'B', 'A', 'D', 'B',
        'D', 'C', 'C', 'A', 'C', 'C', 'A', 'C', 'B', 'C', 'B', 'D'
    };
}

// Function to remove a question from the bank based on the index
void removeQuestion(int index, int questionCount){
    for (int i = index; i < questioncount - 1; i++){
        questionbank[i] = questionbank[i + 1];
        questionAns[i] = questionAns[i + 1];
    }
}

// Main game function
void game() {
    reloadQuestionBank(); // Seed for random number generation

    int count = 0;

    if (difficulty == 1) {
        // Normal mode game logic
        while (count < x && lives != 0) {
            int random = rand() % x; // Select a random question
            cout << "\n\n" << count + 1 << "." << questionbank[random]; // Print the question
            cout << "\n\nEnter your answer: ";
            cin >> ans;
            ans = toupper(ans);
            while (!(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D')) {
                    cout << "Invalid input. Please enter Y or N: ";
                    cin >> ans;
                    ans = toupper(ans);
            }

            if (ans == questionAns[random]) {
                cout << "Correct!\n\n";
                streak += 1;
                score += 1;
                cout << "Current Streak: " << streak << "\nCurrent Score: " << score;
            }
            else {
                cout << "Incorrect! :(\n\n";
                streak = 0;
                cout << "Current Streak: " << streak << "\nCurrent Score: " << score << '\n';
            }
            removeQuestion(random, questioncount); // Remove the question once answered
            count++;
        }
    }
    else {
        // Hard mode game logic
        while (count < x) {

            if (lives > 0) {
                int random = rand() % x; // Select a random question
                cout << "\n\n" << count + 1 << "." << questionbank[random]; // Print the question
                cout << "\n\nEnter your answer: ";
                cin >> ans;
                ans = toupper(ans);
                while (!(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D')) {
                    cout << "Invalid input. Please enter Y or N: ";
                    cin >> ans;
                    ans = toupper(ans);
                }

                if (ans == questionAns[random]) {
                    cout << "Correct!\n\n";
                    streak += 1;
                    score += 1;
                    cout << "Current Streak: " << streak << "\nCurrent Score: " << score << "\nLives Left: " << lives;
                }
                else {
                    cout << "Incorrect! :(\n\n";
                    streak = 0;
                    lives -= 1;
                    cout << "Current Streak: " << streak << "\nCurrent Score: " << score << "\nLives Left: " << lives;
                }
                removeQuestion(random, questioncount); // Remove the question once answered
                count++;
            } 
            else {
                system("cls");
                cout << "You have run out of lives. \nBetter luck next time!" << "Final score: " << score << "\n\n";
                break;
            }
        }
    }

    cout << "\nWould you like to replay? (Y/N): ";
    cin >> replay;
    replay = toupper(replay);
    while (!(replay == 'Y' || replay == 'N')) {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> replay;
        replay = toupper(replay);

    }
}

// Display menu and handle menu options
void menu() {
    system("cls");
    cout << "*********\n";
    cout << "Welcome to the Quiz Game!\n";
    cout << "*********\n";

    cout << "1. Start Game \t 2. Quiz Length\n";
    cout << "3. Gamemode \t 4. Quit";

    cout << "\n\nEnter your option: ";
    cin >> menuOpt;
}

// Set the length of the quiz
void length() {
    system("cls");
    cout << "Quiz Length \n\n 1. Short \n 2. Medium \n 3. Long \n\nEnter your option : ";
    cin >> quizLength;

    switch (quizLength) {
    case 1: 
        cout << "You have chosen a short length quiz. 10 questions will be given.\n\n"; 
        x = 10;
        break;
    case 2: 
        cout << "You have chosen a medium length quiz. 25 questions will be given.\n\n"; 
        x = 25;
        break;
    case 3: 
        cout << "You have chosen a long length quiz. 50 questions will be given.\n\n"; 
        x = 50;
        break;
    default: 
        cout << "Invalid input. Enter a valid number please! \n\n"; 
        length();
    }
}

// Set the game mode
void gamemode() {
    system("cls");
    cout << "Quiz Game Modes \n\n1. Normal Mode\n2. Hard Mode \n\nEnter your option: ";
    cin >> difficulty;

    switch (difficulty) {
    case 1: 
        cout << "You have chosen normal mode. You will have unlimited lives.\n\n"; 
        diff = "Normal"; 
        lives = 99;
        break;
    case 2: 
        cout << "You have chosen hard mode. You will lose if you get 3 questions wrong.\n\n"; 
        diff = "Hard"; 
        lives = 3;
        break;
    default: 
        cout << "Invalid input. Enter a valid number please! \n\n"; 
        gamemode();
    }
}

void saveScore(string name, int score) {
    // Open the file for appending
    ofstream outputFile("Scoreboard.txt", ios::app);
    
    if (outputFile.is_open()) {
        // Write the score to the file
        outputFile << "Player name: " << name << " || Score: " << score << endl;
        outputFile.close(); // Ensure file is closed properly
    } else {
        // Error handling if file cannot be opened
        cout << "Unable to open file for writing!" << endl;
    }
}

// Main function to drive the game
int main() {
    while (replay == 'Y') {
        menuOpt = 0;
        
        while (menuOpt != 1) {
            menu();

            switch (menuOpt) {
            case 1: 
                system("cls"); 
                cout << "GAME START!\n" << "Mode: " << diff << "\n" << "Length: " << x << " questions\n\n";
                cout << "Type in your name to start: ";
                cin >> name;
                NameArray[Namecount] = name;
                if (difficulty == 1) {
                    lives = 99;
                }
                else {
                    lives = 10;
                }
                game();
                saveScore(name, score);
                break;
            case 2: 
                length(); // Set the length of the quiz
                break;
            case 3: 
                gamemode(); // Set the game mode
                break;
            case 4: 
                cout << "Thank you for visiting our game!!"; // End the game
                exit(0);
                break;
            default: 
                cout << "Invalid input. Enter a valid input please!: \n\n";
            }
        }
        Namecount++;
        
    } 
    cout << "Thank you for visiting our game!!";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file