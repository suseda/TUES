def contains_digits(number, digits):
    number_as_string = str(number)
    for digit in digits:
        digit_as_string = str(digit)
        if digit_as_string not in number_as_string:
            return False

    return True

print(contains_digits(402123, [0, 3, 4]))
print(contains_digits(666, [6, 4]))
print(contains_digits(123456789, [1, 2, 3, 0]))
print(contains_digits(456, []))