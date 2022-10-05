from random import randint 

print("\nInitiate [GUESS THE NUMBER].\n"
"How the game works: With Trial and Error, you need to guess the number within 10 trials. [All the Best]\nTip: Number is always less than 50")

n=randint(1, 50)
c = 1

while(c<=10):
    a = int(input("Please enter your guess: "))
    if a > n:
        print("Please guess a number which is lesser")
    elif a < n:
        print("Please guess a number which is greater")
    else:
        print("Congrats, You Won")
        print("No. of guesses you took to win = " , c )
        break
    print("No. of guesses left= " , 10-c)
    c = c+1

if c > 10:

    print("Game over, the number was",n)
