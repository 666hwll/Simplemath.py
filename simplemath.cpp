#include <iostream>
#include <string>
#include <random>

int randint(int min, int max) {
    // Create a random number engine
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    // Create a distribution in the specified range
    std::uniform_int_distribution<> dis(min, max);
    
    return dis(gen);
}

std::string choice(std::string actualString) {
    int lenOfString = actualString.length();
    int choiceAsIndex = randint(0, lenOfString - 1);
    return std::string(1,actualString[choiceAsIndex]);
}

int getmode() {
    int inpt = 0;
    int new_modes[3] = {1, 2, 3}; 
    std::cout << "How hard should the equations be?\n [0/1/2]\t";
    std::cin >> inpt;
    if(inpt >= 0 && inpt <= 2) {
        return new_modes[inpt];
    } else {
        std::cout << "Something doesn't seem to work out...";
        return 19;
    }

}

int eval(int x, std::string y, int z, int a) {
	if ("+" == y) { // add
		a = x + z;
	}
	else if ("-" == y) { // subtract
		a = x - z;
	}
	else if ("*" == y || "x" == y) { // multiply
		a = x * z;
	}
	else if ("/" == y || ":" == y) { // divide
		a = x / z; // frn already provides protection
		
	}
	return a;
}


int gen_num(int para, int frn) {
    int counter = 0;
    std::string substr = "";
    while(counter < para) {
        std::string s = "";
        int random_num = randint(frn, 10);
        substr += std::to_string(random_num);
        counter++;
    }
    int number = std::stoi(substr);
    return number;  // Replace with actual return value
}

int main() {
    //std::string equation = "";
    int solution = 0;
    int frn = 1;
    int ptr = 0;
    do {ptr = getmode();
    } while(ptr == 19);
    std::string input = "";
    while(input != "X") {
        int firDig = gen_num(ptr, 0);
        std::string opRAN = choice("+-*x/:");
        if(opRAN == "/") {
            frn = 1;
        }
        int secDig = gen_num(ptr, frn);

        //equation += std::to_string(firDig);
        //equation += opRAN;
        //equation += std::to_string(secDig);
        std::cout << "Type outcome of " << firDig << opRAN << secDig<<"\n";
        solution = eval(firDig,opRAN,secDig,solution);
        std::cout << ">> ";
        std::cin >> input;
        if(std::to_string(solution) == input){
            std::cout << "Great! You rock.";
        } else {
            std::cout << "It is " << solution << "; try harder next time!\n";
            input = "X"; 
        }
        
        //std::cout << opRAN << "\n";
        //input = "X";

    }

    return 0;
}