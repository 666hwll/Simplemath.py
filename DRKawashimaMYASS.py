import random

inpt = ""

while inpt != 'X':
    firDig = random.randint(0,999)
    opRAN = random.choice(["+", "-", "*", "/"])
    secDig = random.randint(1,999)
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




