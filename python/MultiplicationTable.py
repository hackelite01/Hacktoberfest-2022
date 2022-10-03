
#purpose: to multiply a specific number given by the user till the number the user wants the number to be multiplied to
#time, changes and date of updation
#   1. 2022-10-03 15:24:14: Created this project
#   2. 2022-10-04 00:02:08: Completed it

###################################################



print("----------------")
print("created by: ")
print("https://github.com/ChefYeshpal")
print("for: hacktober")
print("----------------")

a = int(input("which numbers multiplication table do you want?: ")) 

print("----------------")

b = int(input("till which number do you want the multiplication table?: "))
print("----------------")
d = b+1 #if we put 12 in b then it would print only till 11, this is to counter that

c = range(1, d)


for b in c:
    result = a * b
    print(a, " x ", b, "=", result) #prints "a x b = x" where x is the product of the 2 numbers 

print("----------------")




