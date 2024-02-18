def caesar_cipher_encrypt(plaintext, shift):
    encrypted_text = ""
    for char in plaintext:
        if char.isalpha():
            shifted = ord(char) + shift
            if char.islower():
                if shifted > ord('z'):
                    shifted -= 26
                elif shifted < ord('a'):
                    shifted += 26
            elif char.isupper():
                if shifted > ord('Z'):
                    shifted -= 26
                elif shifted < ord('A'):
                    shifted += 26
            encrypted_text += chr(shifted)
        else:
            encrypted_text += char
    return encrypted_text

plaintext = "Br olzy Jnyetbdrc'g xun, V avrkkr gb sssp km frja sbv kvflsffoi Jnuc Sathrg. Wkmk gytjzyakz mj jsqvcmtoh rc bkd. Canjc kns puadlctus!"
shift = 10
ciphertext = caesar_cipher_encrypt(plaintext, shift)
print(ciphertext)
