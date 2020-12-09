#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
    //print out
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secret server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    //call function
    PrintIntroduction(Difficulty);

    //function body

    //declare variables with values that becomes initialized
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //putting variables into sum & product
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print out the CodeSum and CodeProduct
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct;
    std::cout << std::endl;

    //declare variables, store player guess
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    //std::cout << "You entered: " << GuessA << GuessB << GuessC;

    //declare variables
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check guess
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    } else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{   

    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels completed
    {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
     {
                // increase the level difficulty
        ++LevelDifficulty;

     }
    
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get of there! ***\n";
    return 0;
}