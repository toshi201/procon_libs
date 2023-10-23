int sumOfDigits(int x) {
    int result = 0;

    while (x > 0) {
        result += (x % 10);
        x /= 10;
    }
    return result;
}
