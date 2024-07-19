#include <iostream>
#include <cassert>
#include "TelecomWireColorPair.hpp"
#include "TelecomColorCodingReferenceManualTest.cpp"

void testNumberToPair(int pairNumber,
    TelecomColorCoding::MajorWireColor expectedMajor,
    TelecomColorCoding::MinorWireColor expectedMinor)
{
    TelecomColorCoding::WireColorPair colorPair =
        TelecomColorCoding::WireColorPair::getWireColorPairFromNumber(pairNumber);
    std::cout << "Got pair " << colorPair.toString() << std::endl;
    assert(colorPair.getMajorWireColor() == expectedMajor);
    assert(colorPair.getMinorWireColor() == expectedMinor);
}

void testPairToNumber(
    TelecomColorCoding::MajorWireColor major,
    TelecomColorCoding::MinorWireColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelecomColorCoding::WireColorPair::getNumberFromWireColorPair(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelecomColorCoding::MajorWireColor::WHITE, TelecomColorCoding::MinorWireColor::BROWN);
    testNumberToPair(5, TelecomColorCoding::MajorWireColor::WHITE, TelecomColorCoding::MinorWireColor::SLATE);

    testPairToNumber(TelecomColorCoding::MajorWireColor::BLACK, TelecomColorCoding::MinorWireColor::ORANGE, 12);
    testPairToNumber(TelecomColorCoding::MajorWireColor::VIOLET, TelecomColorCoding::MinorWireColor::SLATE, 25);

    return 0;
}
