#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 100


char* vigenere_encoding(char* message, char* key) {
    int ALPHABET_SIZE = 26;
    int message_len = strlen(message);
    int key_len = strlen(key);
    for (int i = 0, j = 0; i < message_len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + tolower(key[j % key_len]) - 'a') % ALPHABET_SIZE;
            } else {
                message[i] = 'a' + (message[i] - 'a' + tolower(key[j % key_len]) - 'a') % ALPHABET_SIZE;
            }
            j++;
        }
        printf("%c - %d\n", message[i], message[i]);
    }
    return message;
}

char* vigenere_decode(char *message, const char *key) {
    int message_length = strlen(message);
    int ALPHABET_SIZE = 26;
    int key_length = strlen(key);
    for (int i = 0, j = 0; i < message_length; i++, j = (j + 1) % key_length) {
        int shift = tolower(key[j]) - 'a';
        if (isupper(message[i])) {
            message[i] = 'A' + (message[i] - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
        } else if (islower(message[i])) {
            message[i] = 'a' + (message[i] - 'a' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
        }
        printf("%c(%d) ", message[i], message[i]);
    }
    return message;
}

char* caesar_encode(char message[], int shift, int cipher_type) {
    int ALPHABET_SIZE = 26;
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int ascii_value_before = message[i];
            printf("Before encoding: ASCII value of %c is %d\n", message[i], ascii_value_before);
            if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + shift) % ALPHABET_SIZE;
            } else {
                message[i] = 'a' + (message[i] - 'a' + shift) % ALPHABET_SIZE;
            }
            int ascii_value_after = message[i];
            printf("After encoding: ASCII value of %c is %d\n", message[i], ascii_value_after);
        }
    }
}

char* caesar_decode(char message[], int shift, int cipher_type) {
    int ALPHABET_SIZE = 26;
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + ALPHABET_SIZE - shift) % ALPHABET_SIZE;
            } else {
                message[i] = 'a' + (message[i] - 'a' + ALPHABET_SIZE - shift) % ALPHABET_SIZE;
            }
        }
    }
}


int main() {
    int cipher_type, shift, action;
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    
 while (1) {
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        printf("Enter the cipher type (1 for Caesar, 2 for Vigenère, 3 to exit): ");
        scanf("%d", &cipher_type);
if(cipher_type == 3){
            break;
        }
        else{
        printf("Enter 1 to encode, 2 to decode: ");
        scanf("%d", &action);
        
            if (action == 1) {
            if (cipher_type == 1) {
                printf("Enter the shift value: ");
                scanf("%d", &shift);
                caesar_encode(message, shift, cipher_type);
                printf("Encoded message: %s\n", message);
            } else if (cipher_type == 2) {
                printf("Enter the key: ");
                fgets(key, sizeof(key), stdin);
                printf("Result of encoding:\n");
                printf("%s\n", vigenere_encoding(message, key));
            } else {
                printf("Invalid cipher type\n");
            }
        } else if (action == 2) {
            if (cipher_type == 1) {
                printf("Enter the shift value: ");
                scanf("%d", &shift);
                caesar_decode(message, shift, cipher_type);
                printf("Decoded message: %s\n", message);
            } else if (cipher_type == 2) {
                printf("Enter the key: ");
                fgets(key, sizeof(key), stdin);
                printf("Result of decoding:\n");
                printf("%s\n", vigenere_decode(message, key));
            } else {
                printf("Invalid cipher type\n");
            }
        } else {
            printf("Invalid choice\n");
        }
            
        }
    }
    return 0;
}