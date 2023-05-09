import string
ciphertext = "BUBUBBBBUUUBBUBUBUBUBUBUBUBUBUBBU"
alphabet = string.ascii_uppercase

freqs = {letter: ciphertext.count(letter) for letter in alphabet}

sorted_letters = sorted(freqs, key=freqs.get, reverse=True)

most_frequent = sorted_letters[0]
second_most_frequent = sorted_letters[1]

a = (alphabet.index(most_frequent) - alphabet.index(second_most_frequent)) % 26
b = (alphabet.index(most_frequent) - 1) % 26

def decrypt(ciphertext, a, b):
    plaintext = ""
    for c in ciphertext:
        if c in alphabet:
            plaintext += alphabet[(a * (alphabet.index(c) - b)) % 26]
        else:
           
            plaintext += c
    return plaintext

plaintext = decrypt(ciphertext, a, b)
print(plaintext)
