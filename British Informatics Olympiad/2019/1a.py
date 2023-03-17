n = int(input())

def is_palindrome(n):
    return (n := str(n))[::-1] == n

while True:
    n += 1

    if is_palindrome(n):
        print(n)
        exit()