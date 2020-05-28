#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
const int DIED = 7;
const int LINES = 30;
//------------------------------------------------- List
const string Country_List[] = {
	"vietnam", "thailand", "china", "japan", "america","potugal","argentina","brazil","cambodia",
	"cameroon","canada","england","germany","monaco"
};
const string Animal_List[]={
	"dog", "cat", "chicken", "hen", "pig", "duck", "tiger", "lion", "buffalo", "bull",
	"sheep", "snake", "zibra", "elephant", "frog", "tuna", "parrot", "eagle", "crow"
};
const string Province_List[] = {
 "thaibinh", "hanoi", "bacninh", "bacgiang", "ninhbinh","hochiminh", "vinh","nghean","hue",
 "namdinh","quangninh","haiphong"
};
const string Anime_List[]={
 "doremon", "onepiece", "naruto", "dragonball", "attackontian", "bleach", "pokemon", "fairytail",
 "onepunchman"
};
//--------------------------------------------------------------
const int Country_Count = sizeof(Country_List) / sizeof(string);
const int Animal_Count = sizeof(Animal_List) / sizeof(string);
const int Province_Count = sizeof(Province_List) / sizeof(string);
const int Anime_Count = sizeof(Anime_List) / sizeof(string);

const int word[] = {Country_Count, Animal_Count, Province_Count, Anime_Count};
const string chooseTopic[] = {"Country", "Animal", "Province", "Anime"};

//---------------------------------------------

const string STATUS[] = {
	"  ------------   \n"
    "   |             \n"
    "   |             \n"
    "   |             \n"
    "   |             \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |        |    \n"
    "   |             \n"
    "   |             \n"
    "   |             \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |        |    \n"
    "   |        O    \n"
    "   |             \n"
    "   |             \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |        |    \n"
    "   |        O    \n"
    "   |        |    \n"
    "   |             \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |        |    \n"
    "   |        O    \n"
    "   |       /|    \n"
    "   |             \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |        |    \n"
    "   |        O    \n"
    "   |       /|\\  \n"
    "   |             \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |        |    \n"
    "   |        O    \n"
    "   |       /|\\  \n"
    "   |       /     \n"
    "   |   \n"
    " ------\n",
    
    "  ------------   \n"
    "   |       |     \n"
    "   |       O     \n"
    "   |      /|\\   \n"
    "   |      / \\    \n"
    "   |   \n"
    " ------\n"
};
//--------------------------------------Functions
void printBackground();															// Print background of the game
string choosedWordRand(int numberOfTopic);									// Choose the word
void renderGame(string guessedWord, string badGuess, int badGuessCount);	// Render game
string updateWord(string guessedWord, string chosseWord, char guess);		// Update
bool contains(string chooseWord, char guess);								// Check your word

//------------------------------------
void printBackground(){
	cout << "Welcome to HangMan !" << endl;
    cout << endl;
    cout << "Topic: " << endl
         << "(1) Country" << endl
         << "(2) Animal" << endl
         << "(3) Provinces of Vietnam" << endl
         << "(4) The Name of Anime" << endl;
    cout << endl;
    cout << "CHOOSE YOUR FAVORITE TOPIC ";
    return;
}


string chooseWordRand(int numberOfTopic){
	srand(time(NULL));
	int randomIndex = rand() % word[numberOfTopic - 1];
	if (numberOfTopic == 1) return Country_List[randomIndex];
	if (numberOfTopic == 2) return Animal_List[randomIndex];
	if (numberOfTopic == 3) return Province_List[randomIndex];
	if (numberOfTopic == 4) return Anime_List[randomIndex];
}


void renderGame(string guessedWord, string badGuess, int badGuessCount){
	cout << STATUS[badGuessCount] << endl;
	cout << "The previous word: " << guessedWord << endl;
	if (badGuessCount > 0){
	    cout << "Number of wrong guesses: " << badGuessCount;
		cout << " . They are: " <<  badGuess << endl;
	}
}


string updateWord(string guessedWord, string chooseWord, char guess){
	for (int i = 0; i < guessedWord.size(); i++){
		if (guess == chooseWord[i])
		    guessedWord[i] = guess;
	}
	return guessedWord;
}


bool contains(string chooseWord, char guess){
	for (int i = 0; i < chooseWord.size(); i++){
		if (guess == chooseWord[i])
		    return true;
	}
	return false;
}
 
// -------------------------------------------- Main Fuction
int main (){ 

    printBackground();
    
    int numberOfTopic;
    cin >> numberOfTopic;
    const string chooseWord = chooseWordRand(numberOfTopic);          
    
    
    string guessedWord;
    for (int i = 0; i < chooseWord.size(); i++){
    	guessedWord += '-';
	}
	
	int badGuessCount = 0;
    char guess;
    string badGuess = "";
    
    
    while (badGuessCount < DIED && guessedWord != chooseWord){
	    for (int i = 1; i < LINES; i++)
	        cout << endl;
    	cout << "Topic: " << chooseTopic[numberOfTopic - 1] << endl;
    	
    	renderGame(guessedWord, badGuess, badGuessCount);
    	cout << "Let's guess the word what you think right : ";
        cin >> guess;	
    	cout << endl;
    	if (contains(chooseWord, guess) == false){
    		badGuessCount++;
    	    badGuess = badGuess + guess + " ";
		}
    	else {
    	    guessedWord = updateWord(guessedWord, chooseWord, guess);
		}
	}
	
	
	if (badGuessCount == DIED){
		for (int i = 1; i < LINES; i++)
	        cout << endl;
		renderGame(guessedWord, badGuess, badGuessCount);
		cout << endl;
		cout << "OH NO! YOU LOST :<" << endl;
	}
	else 
	    cout << endl << "CONGRATIONS!!!!! YOU WIN <3" << endl; 
	
	
	cout << "The answer is: " << chooseWord;
    return 0;
}
