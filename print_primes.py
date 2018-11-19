def primes(n):
    sqrt = 1
    while (sqrt*sqrt) < n:
        sqrt += 1
    primes_list = list()
    if n >= 2:
        for i in range(2, n+1):
            is_prime = True
            for j in primes_list:
                if not i%j:
                    is_prime = False
                    break
                if j > sqrt:
                    break
            if is_prime:
                primes_list.append(i)
    return primes_list

def primes_eratosthenes(n):
    primes = [True] * (n+1)
    primes[0] = primes[1] = False
    for i in range(2,n+1):
        if primes[i]:
            for j in range(i*i,n+1,i):
                primes[j] = False
    return [i for i, prime in enumerate(primes) if prime]

def main():
    n = 200
    print(primes(n))
    print(primes_eratosthenes(n))

if __name__ == "__main__":
    main()
