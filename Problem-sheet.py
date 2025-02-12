# Problem 1:

# Write a Python program to store and print the details of a student (Name, Age, CGPA) using variables.

Name = "Yash"
Age = 21
CGPA = 6.5

print ("Student Details:")
print ("Name:",Name)
print ("Age:",Age)
print ("CGPA:",CGPA)

# Problem 2:

# Write a Python program to take two numbers as input and print their sum, difference, product, and quotient.

a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

c = (a+b)
print ("The addition of 'a' and 'b' is:", c)
d = (b-a)
print ("The difference between 'a' and 'b' is:", d)
e = (a*b)
print ("The product of 'a' and 'b' is:", e)
f = (a//b)
print ("The quotiont of 'a' and 'b' is:", f)

# Problem 3:

# Write a Python program that asks the user for their birth year and calculates their age in 2025.

ur_by = int(input("Enter your birth year: "))
ur_ag = 2025 - ur_by
print ("Your age is: ",ur_ag)

# Problem 4:

# Convert a temperature given in Celsius to Fahrenheit using the formula:
# Fahrenheit = (Celsius * 9/5) + 32
# Take Celsius as input from the user and display the result.

C = int(input("Enter Celcius in Degrees: "))
F = (C * 9/5) + 32
print (" Celcius to Fahrenheite is: ",F)

# Problem 5:

# Write a Python script that swaps two numbers without using a third variable.

a = (int(input("Enter 1st number: ")))
b = (int(input("Enter 2nd number: ")))

a, b = b, a
print (a)
print (b)

# #Write a program that asks the user for their name, age, and favorite color, then prints them

name = input("What is you name?")
dob = int(input("What is you Date Of Birth?"))
age = (2025 - dob)

print ("Hello!", name)
print ("Your age is: ", age)

#Write a program that asks the user for their name, age, and favorite color, then prints them.

age = int(input("Enter your age: "))
if age >= 18:
    print ("You are an adult")
else:
    print("You are minor")

#Take a number as input and check whether it is even or odd.

num = int(input("Enter the number: "))
if num % 2 == 0:
    print (num, "is an even number")
else:
    print (num , "is an odd number")

#Take marks as input and print "Pass" if marks >= 40, else print "Fail".
marks = int(input("Enter you marks: "))
if marks >= 40:
    print ("Congratulations!! you are passed <3")
else:
    print("paisa barbad")

