import random

rng = random.SystemRandom()

def getmode() -> int:
    mode = (1, 10, 100)
    print("How hard should the equations be?\n [0/1/2]")
    inpt = int(input(">> "))
    if inpt >= 0 and not inpt > 2:
        return mode[inpt]
    else:
        print("WTF are you retarded?")
        exit()
        return 0


def main():
    ptr = getmode()
    inpt = str
    while inpt != 'X':  
        firDig = rng.randint(0,11) * ptr
        opRAN = rng.choice(["+", "-", "*", "/"])
        if opRAN != '/':
            frn = 0
        else:
            frn = 1
        secDig = rng.randint(frn,11) * ptr
        eq = str(firDig) + opRAN + str(secDig)
        print(f"Type in the outcome of {eq}")
        solution = eval(eq)
        inpt = input(">> ")
        if str(inpt) == str(solution):
            print("Great! You are not retarded.")
        elif str(inpt) == 'X':
            print("Exiting...")
        else:
            print(f"Wtf; its {solution}; are you retarded or smt?")

if __name__ == '__main__':
    main()




