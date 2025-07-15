import random
import string

def gerar_palindromo(n: int) -> str:
    # Gera metade da string
    metade = random.choices(string.ascii_lowercase, k=n // 2)
    # Se n for ímpar, escolhe um caractere central
    meio = [random.choice(string.ascii_lowercase)] if n % 2 else []
    # Concatena: metade + possível meio + metade invertida
    return ''.join(metade + meio + list(reversed(metade)))

if __name__ == "__main__":
    N = 500_000
    palindromo = gerar_palindromo(N)
    print(palindromo)