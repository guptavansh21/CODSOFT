import random
import string

def generate_password():
    print("\n--- PASSWORD GENERATOR (CODSOFT) ---")
    
    while True:
        try:
            # 1. User se length pucho
            length = int(input("\nEnter the desired length for the password: "))
            
            if length < 4:
                print("⚠️  Password too short! Please enter length at least 4.")
                continue
            
            # 2. Characters define karo (Letters, Digits, Symbols)
            lower = string.ascii_lowercase
            upper = string.ascii_uppercase
            digits = string.digits
            symbols = string.punctuation
            
            # Har category se kam se kam ek character lelo
            all_chars = lower + upper + digits + symbols
            password = [
                random.choice(lower),
                random.choice(upper),
                random.choice(digits),
                random.choice(symbols)
            ]
            
            # Baaki random characters bhar do
            for _ in range(length - 4):
                password.append(random.choice(all_chars))
            
            # Password ko shuffle karo taaki pattern na dikhe
            random.shuffle(password)
            
            # List ko string mein convert karo
            result = "".join(password)
            
            print(f"🔐 Generated Password: {result}")
            
            # 3. Dobara generate karna hai?
            again = input("\nGenerate another? (y/n): ")
            if again.lower() != 'y':
                print("Exiting... Stay Safe! 👋")
                break
                
        except ValueError:
            print("❌ Invalid Input! Please enter a number.")

if __name__ == "__main__":
    generate_password()