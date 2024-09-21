#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Streak {
    int length;
    int rank;
};

bool compareStreaks(const Streak& a , const Streak& b){
    return a.length > b.length;
}

int calculateRank(vector<Streak> streaks, int streakLength){
    if (streaks.empty() || streakLength == streaks[0].length){
        return 1;
    }


    int rank = 1;
    int prevLength = INT_MAX;

    sort(streaks.begin(), streaks.end(), compareStreaks);

    for (int i = 0; i < streaks.size(); i++){
        if (streaks[i].length < streakLength){
            break;
        };
        rank++;
    }

    return rank;
}

void streakIncrement(int& streakCount, int& highest_streak, Streak streaks[]){
    const int MAX_STREAKS = 10;

    if (streakCount < MAX_STREAKS) {
            Streak currentStreak;
            currentStreak.length = highest_streak;
            streaks[streakCount] = currentStreak;
            streakCount++;

            //Calculate the rank of the current streak
            //Converts the streak array into a vector
            vector<Streak> streaksVector(streaks, streaks + streakCount);

            sort(streaksVector.begin(), streaksVector.end(), compareStreaks);

            if (streakCount == 1){
                streaks[streakCount - 1].rank = 1;
            } else {
                // call the calculateRank void
                int rank = calculateRank(streaksVector, highest_streak);

                //overwrite the previous element in the streak array with the current streak
                streaks[streakCount - 1].rank = rank;    
            }

        }

}



void checkAnswer(char guess, char correctAnswer, int& score, int& streak, int& highest_streak){

    if (guess == correctAnswer){
        cout << "CORRECT!\n";
        score++;
        ++streak;
    } else {
        cout << "INCORRECT!\n";
        cout << "Answer: " << correctAnswer <<'\n';
        streak = 0;  
    }
    
    if (streak > highest_streak){
        highest_streak = streak;
    }
}

void Quiz_start(){

    const int MAX_STREAKS = 100;
    Streak streaks[MAX_STREAKS];
    char loop;
    char guess;
    int streakCount = 0, typeLength, gameMode, x;
    string playerName[MAX_STREAKS] = {};

    cout << "Choose the length of your quiz (1 = short || 2 = medium || 3 = long): ";
    cin >> typeLength;

    switch (typeLength){
        case 1: x = 10;
                break;
        case 2: x = 25;
                break;
        case 3: x = 50;
                break;
        default: cout << "Invalid input! Enter a valid input: ";
                 cin >> typeLength;
    }

    cout << "Choose the gamemode of your quiz (1 = short || 2 = medium || 3 = long): ";
    cin >> typeLength;
    
    do {
        int score = 0;
        int streak = 0;
        int highest_streak = 0;

        //add or remove questions
        vector<string> question = {
                                    "What is the capital of France?",
                                    "Who wrote the play 'Romeo and Juliet'?",
                                    "What is the largest planet in our solar system?",
                                    "Who painted the Mona Lisa?",
                                    "What is the smallest country in the world by area?",
                                    "In which year did the Titanic sink?",
                                    "What is the chemical symbol for gold?",
                                    "Who is known as the 'Father of Computers'?",
                                    "What is the hardest natural substance on Earth?",
                                    "What is the longest river in the world?",
                                    "Who was the first President of the United States?",
                                    "Which planet is known as the Red Planet?",
                                    "What is the largest ocean on Earth?",
                                    "Who invented the telephone?",
                                    "How many continents are there on Earth?",
                                    "In which year did World War II end?",
                                    "What is the capital of Japan?",
                                    "Which element has the atomic number 1?",
                                    "Who wrote the novel '1984'?",
                                    "What is the largest mammal in the world?",
                                    "What is the most widely spoken language in the world?",
                                    "Who was the first person to walk on the Moon?",
                                    "What is the currency of the United Kingdom?",
                                    "What is the square root of 144?",
                                    "Who discovered penicillin?",
                                    "What is the chemical formula for water?",
                                    "Which country is known as the Land of the Rising Sun?",
                                    "What is the capital city of Australia?",
                                    "In which continent is the Sahara Desert located?",
                                    "What is the main ingredient in guacamole?",
                                    "How many sides does a hexagon have?",
                                    "Who was the author of 'Harry Potter' series?",
                                    "What is the primary gas found in the Earth's atmosphere?",
                                    "Who painted the ceiling of the Sistine Chapel?",
                                    "What is the largest land animal?",
                                    "Which country is the largest by land area?",
                                    "What is the currency used in Japan?",
                                    "What is the name of the longest mountain range in the world?",
                                    "Who was the first woman to win a Nobel Prize?",
                                    "In which city is the Statue of Liberty located?",
                                    "What is the main component of the sun?",
                                    "Which planet is closest to the sun?",
                                    "Who is the author of 'Pride and Prejudice'?",
                                    "What is the largest island in the world?",
                                    "How many bones are in the adult human body?",
                                    "Which ocean is the Bermuda Triangle located in?",
                                    "Who was the British Prime Minister during World War II?",
                                    "What is the most popular sport in the world?",
                                    "Who discovered the theory of relativity?",
                                    "What is the capital of Canada?"
                                };

vector<vector<string>> answers = {
                                    {"A. Rome", "B. Berlin", "C. Paris", "D. Madrid"},
                                    {"A. Charles Dickens", "B. William Shakespeare", "C. Mark Twain", "D. Jane Austen"},
                                    {"A. Earth", "B. Mars", "C. Saturn", "D. Jupiter"},
                                    {"A. Vincent van Gogh", "B. Pablo Picasso", "C. Leonardo da Vinci", "D. Claude Monet"},
                                    {"A. Monaco", "B. Vatican City", "C. San Marino", "D. Liechtenstein"},
                                    {"A. 1905", "B. 1918", "C. 1912", "D. 1925"},
                                    {"A. Ag", "B. Au", "C. Pt", "D. Fe"},
                                    {"A. Charles Babbage", "B. Alan Turing", "C. Bill Gates", "D. Steve Jobs"},
                                    {"A. Diamond", "B. Quartz", "C. Topaz", "D. Ruby"},
                                    {"A. Amazon River", "B. The Nile River", "C. Yangtze River", "D. Mississippi River"},
                                    {"A. Thomas Jefferson", "B. John Adams", "C. George Washington", "D. Abraham Lincoln"},
                                    {"A. Venus", "B. Mars", "C. Mercury", "D. Jupiter"},
                                    {"A. The Pacific Ocean", "B. The Atlantic Ocean", "C. The Indian Ocean", "D. The Southern Ocean"},
                                    {"A. Thomas Edison", "B. Alexander Graham Bell", "C. Nikola Tesla", "D. Guglielmo Marconi"},
                                    {"A. Seven", "B. Six", "C. Five", "D. Eight"},
                                    {"A. 1939", "B. 1942", "C. 1945", "D. 1950"},
                                    {"A. Seoul", "B. Beijing", "C. Bangkok", "D. Tokyo"},
                                    {"A. Helium", "B. Oxygen", "C. Carbon", "D. Hydrogen"},
                                    {"A. Aldous Huxley", "B. George Orwell", "C. Ray Bradbury", "D. J.R.R. Tolkien"},
                                    {"A. Elephant", "B. The Blue Whale", "C. Giraffe", "D. Hippopotamus"},
                                    {"A. English", "B. Mandarin Chinese", "C. Spanish", "D. Hindi"},
                                    {"A. Buzz Aldrin", "B. Neil Armstrong", "C. Michael Collins", "D. Yuri Gagarin"},
                                    {"A. Euro", "B. Pound Sterling", "C. Dollar", "D. Franc"},
                                    {"A. 10", "B. 11", "C. 12", "D. 13"},
                                    {"A. Louis Pasteur", "B. Alexander Fleming" , "C. Marie Curie", "D. Joseph Lister"},
                                    {"A. CO₂", "B. NaCl", "C. H₂O", "D. O₂"},
                                    {"A. China", "B. South Korea", "C. Japan", "D. Thailand"},
                                    {"A. Sydney", "B. Melbourne", "C. Brisbane", "D. Canberra"},
                                    {"A. Asia", "B. South America", "C. Africa", "D. North America"},
                                    {"A. Tomato", "B. Onion", "C. Avocado", "D. Lime"},
                                    {"A. Five", "B. Six", "C. Seven", "D. Eight"},
                                    {"A. J.R.R. Tolkien", "B. George R.R. Martin", "C. J.K. Rowling", "D. C.S. Lewis"},
                                    {"A. Oxygen", "B. Nitrogen", "C. Carbon Dioxide", "D. Argon"},
                                    {"A. Raphael", "B. Michelangelo", "C. Leonardo da Vinci", "D. Donatello"},
                                    {"A. Giraffe", "B. African Elephant", "C. Rhinoceros", "D. Hippopotamus"},
                                    {"A. Russia", "B. Canada", "C. China", "D. United States"},
                                    {"A. Won", "B. Yuan", "C. Peso", "D. Yen"},
                                    {"A. Rocky Mountains", "B. The Andes", "C. The Himalayas", "D. The Alps"},
                                    {"A. Rosalind Franklin", "B. Mother Teresa", "C. Jane Addams", "D. Marie Curie"},
                                    {"A. Los Angeles", "B. Chicago", "C. New York City", "D. Washington DC"},
                                    {"A. Helium", "B. Oxygen", "C. Hydrogen", "D. Carbon"},
                                    {"A. Venus", "B. Mars", "C. Mercury", "D. Earth"},
                                    {"A. Jane Austen", "B. Emily Brontë", "C. Mary Shelley", "D. Charlotte Brontë"},
                                    {"A. Australia", "B. Greenland", "C. New Guinea", "D. Borneo"},
                                    {"A. 205", "B. 206", "C. 207", "D. 208"},
                                    {"A. Indian Ocean", "B. Atlantic Ocean", "C. Pacific Ocean", "D. Southern Ocean"},
                                    {"A. Winston Churchill", "B. Neville Chamberlain", "C. Clement Attlee", "D. Anthony Eden"},
                                    {"A. Soccer", "B. Basketball", "C. Baseball", "D. Cricket"},
                                    {"A. Isaac Newton", "B. Galileo Galilei", "C. Albert Einstein", "D. Niels Bohr"},
                                    {"A. Toronto", "B. Vancouver", "C. Montreal", "D. Ottawa"}
                                };

        // add or remove answerSheet
        vector<char> answerSheet = {
                                    'C', 'B', 'D', 'C', 'B', 'C', 'B', 'A', 'A', 'B', 'C', 'B', 'A', 'B', 'A', 'C', 'D', 'D', 'B', 
                                    'B', 'B', 'B', 'B', 'C', 'B', 'C', 'C', 'D', 'C', 'C', 'B', 'C', 'B', 'B', 'B', 'A', 'D', 'B', 
                                    'D', 'C', 'C', 'A', 'C', 'C', 'A', 'C', 'B', 'C', 'B', 'D'
                                    };

        srand((unsigned)time(NULL));

        highest_streak = 0;

        cout << "Enter your player name: ";

        // streakCount is seen as an element
        cin >> playerName[streakCount];

        for (int i = 1; i<=x; ++i){

            // randomly pick a question
            int random = rand() % question.size();

            //displays the question
            cout << "----------\n";
            cout << i << ". " << question[random] << '\n';
            cout << "----------\n";
            cout << "Score: "<< score << ", " << "Current Streak: "<<streak << "\n";


            //displays the answers for the following question
            for (int j = 0; j < answers[random].size(); j++) {
                cout << answers[random][j] << '\n';
            }
          
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
            while (!(guess == 'A'|| guess == 'B'|| guess == 'C'|| guess == 'D')){
                cout << "Invalid input. Please enter A, B, C, or D: ";
                cin >> guess;
                guess = toupper(guess); 
            }

            checkAnswer(guess, answerSheet[random], score, streak, highest_streak);
            question.erase(question.begin() + random);
            answers.erase(answers.begin() + random);
            answerSheet.erase(answerSheet.begin() + random);
        }

        // runs the streakIncrememnt void
        streakIncrement(streakCount, highest_streak, streaks);

        sort(streaks, streaks + streakCount, compareStreaks);

        // displays the final score and the highest streak of the round
        cout << "\n---------------------------------------------------\n";
        cout << "Your final score is: " << score << '\n';
        cout << "Your highest streak of the round is: " << highest_streak << '\n';
        cout << "-----------------------------------------------------\n";

        // gives option to the user if the want to play another round of the game of stop playing it
        cout << "Do you wish to continue playing this game (Y/N): ";
        cin >> loop;
        while (!(loop == 'y' || loop =='Y' || loop == 'n' || loop == 'N')){
            cout << "Invalid input. Please enter Y or N: ";
            cin >> loop;
        }

    } while (loop == 'y' || loop =='Y'); // will end if the user inputs 'N'

    // displays all the streaks of eachh
    cout << "Streaks:" << endl;
    for (int i = 0; i < streakCount; i++){
        cout << "Player name: " << playerName[i] << ": || Length: " << streaks[i].length << " || Rank: " << streaks[i].rank << endl;
    }

    // append a textfile to input all the streaks
    ofstream outputFile("streaks.txt", ios::app);
    if (outputFile.is_open()) {
        for (int i = 0; i < streakCount; i++){
            outputFile << "Player name: " << playerName[i] << ": || Length: " << streaks[i].length << " || Rank: " << streaks[i].rank << endl;
        }
        outputFile.close();
    } else {
        cout << "Unable to open file";
    }
}

int main(){
    const int BLACK_BACKGROUND = 0;
    const int ORANGE_FOREGROUND = 0xff9900;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ORANGE_FOREGROUND | BLACK_BACKGROUND);

    system("cls");
    char restart, start;

game:
    cout << "***************************\n";
    cout << "Welcome to the Quiz Game!\n";
    cout << "***************************\n";

    cout << "Do you wish to start the game (Y/N): ";
    cin >> start;
    start = toupper(start);

    switch (start){
        case 'Y': cout << "Goodluck and have fun :)\n";
                  Quiz_start();
                  break;
        
        case 'N': cout << "Thank you for visiting this game :)";
                  return 0;

        default: cout << "Invalid input. Enter a valid input please! (Y/N): ";
                 goto game;
                 break;
    }
    return 0;
}