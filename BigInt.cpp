//
// Created by tprohit on 29-11-2022.
//

#include <stdexcept>
#include <iostream>

#include "BigInt.h"


BigInt::BigInt() {
    this->number = "";
}


BigInt BigInt::fromStr(const std::string &str) {
    BigInt ret = BigInt();
    ret.number = *new std::string(str);

    if (ret.number.starts_with('-')) {
        ret.negative = true;
        ret.number.erase(0, 1);
    }

    for (char c: ret.number)
        if (c > '9' || c < '0')
            throw std::exception(&"Invalid character in number string : "[c]);

    return ret;
}

std::ostream &operator<<(std::ostream &out, const BigInt &bigInt) {
    if (bigInt.negative)
        out << '-';

    out << bigInt.number;
    return out;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
    if (a.negative != b.negative) {
        if (a.negative)
            return b - (-a);
        else
            return a - (-b);
    }

    BigInt ret = BigInt();
    ret.negative = a.negative;

    std::string operand = BigInt::min(a, b).number;
    ret.number = *new std::string(BigInt::max(a, b).number);

    int carry = 0;

    for (unsigned long int i = ret.number.length() - 1; i < ret.number.length(); --i) {
        char o1 = ret.number.at(i), o2 = 0;

        if (i < operand.length())
            o2 = operand.at(i);

        short unsigned int sum = o1 + o2 - (2 * '0') + carry;
        carry = sum / 10;

        ret.number[i] = (sum % 10) + '0';
    }

    if (carry)
        ret.number = (char) (carry + '0') + ret.number;

    return ret;
}

BigInt operator-(const BigInt &a, const BigInt &b) {

    if (!a.negative && b.negative)
        return a + (-b);

    if (a.negative && !b.negative)
        return -(-a + b);

    if (a.negative && b.negative)
        return b - (-a);

    BigInt o1 = a;
    BigInt o2 = b;

    if (o2 > o1) {
        BigInt tmp = o1;
        o1 = o2;
        o2 = tmp;

        o1.negative = true;
    }

    bool borrow = false;

    for (long long unsigned int i = o2.number.length() - 1; i < o2.number.length(); i--) {
        char op1 = o1.number.at(o1.number.length() + i - o2.number.length());
        char op2 = o2.number.at(i);

        int diff = op1 - op2 - borrow;
        borrow = diff < 0;

        if (borrow)
            diff += 10;

        o1.number[o1.number.length() + i - o2.number.length()] = diff + '0';
    }

    return o1;
}

bool operator>(const BigInt &a, const BigInt &b) {
    if (a.number.length() > b.number.length())
        return true;

    if (a.number.length() < b.number.length())
        return false;

    for (unsigned long long int i = 0; i < a.number.length(); i++)
        if (a.number.at(i) > b.number.at(i))
            return true;
        else if (a.number.at(i) < b.number.at(i))
            return false;

    return false;
}

bool operator<(const BigInt &b, const BigInt &a) {
    if (a.number.length() > b.number.length())
        return true;

    if (a.number.length() < b.number.length())
        return false;

    for (unsigned long long int i = 0; i < a.number.length(); i++)
        if (a.number.at(i) > b.number.at(i))
            return true;
        else if (a.number.at(i) < b.number.at(i))
            return false;

    return false;
}

bool operator==(const BigInt &b, const BigInt &a) {
    if (a.number.length() != b.number.length())
        return false;

    for (unsigned long long int i = 0; i < a.number.length(); i++)
        if (a.number.at(i) != b.number.at(i))
            return false;

    return true;
}

BigInt BigInt::max(const BigInt &a, const BigInt &b) {
    return a > b ? a : b;
}

BigInt BigInt::min(const BigInt &a, const BigInt &b) {
    return a < b ? a : b;
}

BigInt operator-(const BigInt &a) {
    BigInt b = BigInt();
    b.number = a.number;
    b.negative = !a.negative;

    return b;
}

std::istream &operator>>(std::istream &in, BigInt &a){
    in >> a.number;

    a.negative = false;

    if (a.number.starts_with('-')) {
        a.negative = true;
        a.number.erase(0, 1);
    }

    for (char c: a.number)
        if (c > '9' || c < '0')
            throw std::exception(&"Invalid character in number string : "[c]);

    return in;
}
