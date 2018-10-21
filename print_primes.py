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
    print(primes_list)


def main():
    n = 20
    primes(n)

if __name__ == "__main__":
    main()
