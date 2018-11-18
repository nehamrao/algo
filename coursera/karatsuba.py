class Multiplication:

    def _split(self, number, half):
        a = number // (10**half)
        b = number % (10**half)
        return a, b

    def karatsuba(self, num_a, num_b):
        # Base case
        if num_a < 10 or num_b < 10:
            return num_a * num_b

        size = max(len(str(num_b)), len(str(num_b)))
        half = size//2
        a, b = self._split(num_a, half)
        c, d = self._split(num_b, half)

        one = self.karatsuba(a, c)
        two = self.karatsuba(b, d)
        three = self.karatsuba((a + b), (c + d))

        return (10**len(str(num_a)))*one + 10**(len(str(num_a))//2)*(three - two - one) + two


def main():
    product = Multiplication()
    print(product.karatsuba(3141592653589793238462643383279502884197169399375105820974944592, 2718281828459045235360287471352662497757247093699959574966967627))


if __name__ == '__main__':
    main()
