//
// Created by tproh on 29-11-2022.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H


class BigInt {
public:
    BigInt();

    static BigInt fromStr(const std::string&);
    static BigInt max(const BigInt&, const BigInt&);
    static BigInt min(const BigInt&, const BigInt&);
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
    friend std::istream& operator>>(std::istream&, BigInt&);
    friend BigInt operator+(const BigInt&, const BigInt&);
    friend BigInt operator-(const BigInt&, const BigInt&);
    friend BigInt operator-(const BigInt&);
    friend bool operator>(const BigInt&, const BigInt&);
    friend bool operator<(const BigInt&, const BigInt&);
    friend bool operator==(const BigInt&, const BigInt&);
private:
    std::string number;
    bool negative = false;
};


#endif //BIGINT_BIGINT_H
