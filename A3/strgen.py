import random
import string

def generate_strings(n):
    strings = []
    for _ in range(n):
        # Generate the first four capital English alphabet letters
        prefix = ''.join(random.choice(string.ascii_uppercase) for _ in range(4))

        # Generate 7 random integers
        numbers1 = ''.join(random.choice(string.digits) for _ in range(7))

        # Generate an underscore character
        underscore = "_"

        # Generate 10 random integers
        numbers2 = ''.join(random.choice(string.digits) for _ in range(10))

        # Concatenate all parts to form the final string
        final_string = prefix + numbers1 + underscore + numbers2

        strings.append(final_string)

    return strings

# Specify the number of strings you want to generate
n = int(input("Enter n"))
result = generate_strings(n)

# Write the generated strings to a text file
with open("generated_strings.txt", "w") as file:
    for s in result:
        file.write(s + "\n")

print(f"{n} strings have been written to 'generated_strings.txt'")
