#include <random>
#include <iostream>
#include <string>
#include "local_strings.hpp"

struct {
    std::string language = localization::determineSystemLanguage();
}Programmvalues;

struct sessionMetrics{
    unsigned int sessionID; // to track sessions for more complex expansion possibilities
    unsigned int AmountOfEquations;
    unsigned int AmountOfRightSolutions;
    unsigned int AmountOfWrongSolutions;
    float PercentageOfRightSolutions;
    float PercentageOfWrongSolutions; 

};

unsigned long keepTrackOfSessions(){
    static unsigned long sessionCounter = 0;
    return sessionCounter++;
    
}

void createNewSession(sessionMetrics* Metrics) {
    Metrics -> sessionID = keepTrackOfSessions();
    Metrics -> AmountOfEquations = 0;
    Metrics -> AmountOfRightSolutions = 0;
    Metrics -> AmountOfWrongSolutions = 0; 
    Metrics -> PercentageOfRightSolutions = 0.0;
    Metrics -> PercentageOfWrongSolutions = 0.0;
    // adding timestamps in the future !
}

void calculatePercentagesInSession(sessionMetrics* Metrics) {
    if (Metrics->AmountOfEquations == 0) {
        Metrics->PercentageOfRightSolutions = 0.0f;
        Metrics->PercentageOfWrongSolutions = 0.0f;
        return;
    }
    //Metrics -> PercentageOfRightSolutions = ((float)(Metrics -> AmountOfRightSolutions) / (float)(Metrics -> AmountOfEquations)) * 100;
    Metrics->PercentageOfRightSolutions =(Metrics->AmountOfRightSolutions * 100.0f) / Metrics->AmountOfEquations;
    //Metrics -> PercentageOfWrongSolutions = 100.0 - (Metrics -> PercentageOfRightSolutions);
    Metrics->PercentageOfWrongSolutions = (Metrics->AmountOfWrongSolutions * 100.0f) / Metrics->AmountOfEquations;
}

void outputUserSessionStats(sessionMetrics * Metrics) {
    std::cout << "\n\n\n\n\n\n\n\n\n"; // effectivly 'clearing' the screen, but who the hell needs curses :)
    //
    if((Metrics ->PercentageOfRightSolutions) > (Metrics ->PercentageOfWrongSolutions)) {
        //std::cout you were right
        std::cout << (Metrics -> PercentageOfRightSolutions) << " % right\n";
    } else if((Metrics ->PercentageOfRightSolutions) < (Metrics ->PercentageOfWrongSolutions)) {
        std::cout << (Metrics -> PercentageOfWrongSolutions) << " % wrong\n";
    } else {
        std::cout << "50 %\n";
    }


}

int randint(int min, int max) {
    // Create a random number engine
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    
    // Create a distribution in the specified range
    std::uniform_int_distribution<> dis(min, max);
    
    return dis(gen);
}

std::string choice(const std::string actualString) {
    int lenOfString = actualString.length();
    int choiceAsIndex = randint(0, lenOfString - 1);
    return std::string(1,actualString[choiceAsIndex]);
}

int getmode() {
    int inpt = 0;
    int new_modes[3] = {1, 2, 3}; 
    std::cout << localization::getTranslation("STRING_LEVEL",Programmvalues.language) << "[0/1/2]\t"; // string level
    std::cin >> inpt;
    if(inpt >= 0 && inpt <= 2) {
        return new_modes[inpt];
    } else {
        std::cerr << localization::getTranslation("STRING_ERROR", Programmvalues.language); // string for error 
        return 8;
    }

}

int eval(int x, const std::string y, int z) {
	if ("+" == y) { // add
		return x + z;
	}
	else if ("-" == y) { // subtract
		return x - z;
	}
	else if ("*" == y || "x" == y) { // multiply
		return x * z;
	}
	else if ("/" == y || ":" == y) { // divide
        if(z != 0) {
		return  x / z; // frn already provides protection
        } else {
            return 0;
        }
	}
    return 0;
}


int gen_num(int para, int frn) {
    int counter = 0;
    std::string substr = "";
    while(counter < para) {
        int random_num = randint(frn, 10); // 10 is better than 9 for the easiest mode, but not exclusively
        substr += std::to_string(random_num);
        counter++;
    }
    int number = std::stoi(substr);
    return number;  // Replace with actual return value
}

int main() {
    sessionMetrics* new_session = new sessionMetrics;
    createNewSession(new_session);
    
    int ptr = 0;
    int frn = 0;
    int solution = 0;
    
    do {ptr = getmode();
    } while(ptr == 8);
    
    std::string input = "";
    while(input != "X" && input != "x") {
        
        int firDig = gen_num(ptr, 0);
        std::string opRAN = choice("+-*x/:");
        if(opRAN == "/") {
            frn = 1;
        } else {
            frn = 0;
        }
        int secDig = gen_num(ptr, frn);

        std::cout << localization::getTranslation("STRING_RETRIEVING", Programmvalues.language) << firDig << opRAN << secDig<<"\n"; // string for retrieving
        solution = eval(firDig,opRAN,secDig);
        std::cout << ">> ";
        std::cin >> input;
        if("x" == input || "X" == input) {
            calculatePercentagesInSession(new_session);
            outputUserSessionStats(new_session);
            std::cout << localization::getTranslation("STRING_BEFOREEXIT", Programmvalues.language); // string before exit
            delete(new_session);
            return 0;
        }

        new_session ->AmountOfEquations++;
        if(std::to_string(solution) == input){
            new_session ->AmountOfRightSolutions++;
            std::cout << localization::getTranslation("STRING_POSITIVFEEDBACK", Programmvalues.language); // string for positiv feedback
        } else {
            new_session -> AmountOfWrongSolutions++;
            std::cout << localization::getTranslation("STRING_TRYHARD1", Programmvalues.language) << solution << localization::getTranslation("STRING_TRYHARD2", Programmvalues.language); // string tryhard 
        }
        

    }
    return -1;
    
}
