#!/usr/bin/env python3

import random

rng = random.SystemRandom()


def getmode() -> int:
    #mode = (1, 10, 100)
    new_modes = (1, 2, 3)
    print("How hard should the equations be?\n [0/1/2]")
    inpt = int(input(">> "))
    if inpt >= 0 and not inpt > 2:
        return new_modes[inpt]
    else:
        print("Something doesn't seem to work out...")
        exit()
        return 0

def gen_num(para: int, frn) -> int:
    enum = 0
    substr = ""
    while enum < para:
        s = str(rng.randint(frn,10)) 
        substr += s
        enum += 1
    return int(substr)


def main():
    ptr = getmode()
    inpt = str
    while inpt != 'X':
        ####
        #firDig = rng.randint(0,11) * ptr
        firDig = gen_num(ptr, 0)
        opRAN = rng.choice(["+", "-", "*", "/"])
        if opRAN != '/':
            frn = 0
        else:
            frn = 1
        #secDig = rng.randint(frn,11) * ptr
        secDig = gen_num(ptr, frn)
        ####
        eq = str(firDig) + opRAN + str(secDig)
        print(f"Type in the outcome of {eq}")
        solution = eval(eq)
        inpt = input(">> ")
        if str(inpt) == str(solution):
            print("Great! You rock.")
        elif str(inpt) == 'X':
            print("Exiting...")
        else:
            print(f"It is {solution}; try harder next time!")

if __name__ == '__main__':
    main()




