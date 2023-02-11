from string import ascii_lowercase, ascii_uppercase

hero = "All Might"

# Brute force using concatenation
output = ""
for char in hero:
    if "A" <= char <= "Z":
        output += chr(ord(char) - ord('A') + ord('a'))
    else:
        output += char

# Brute force using join
output = []
for char in hero:
    if "A" <= char <= "Z":
        output.append(chr(ord(char) - ord('A') + ord('a')))
    else:
        output.append(char)
output = "".join(output)

# Brute force using ASCII collections
output = []
for char in hero:
    if char in ascii_uppercase:
        output.append(ascii_lowercase[ascii_uppercase.index(char)])
    else:
        output.append(char)
output = "".join(output)

# Brute force using a list comprehension
output = [ascii_lowercase[ascii_uppercase.index(char)] if char in ascii_uppercase else char for char in hero]
output = "".join(output)

# Built-in Python solution
output = hero.lower()