#include <iostream>
#include <cassert>
#include "TelecomWireColorPair.hpp"


void testColorCodingReferenceManual() {
    std::string referenceManual = TelecomColorCoding::WireColorPair::formatColorCodingReferenceManual();

    std::string expectedManual =
        "White Blue - 1\n"
        "White Orange - 2\n"
        "White Green - 3\n"
        "White Brown - 4\n"
        "White Slate - 5\n"
        "Red Blue - 6\n"
        "Red Orange - 7\n"
        "Red Green - 8\n"
        "Red Brown - 9\n"
        "Red Slate - 10\n"
        "Black Blue - 11\n"
        "Black Orange - 12\n"
        "Black Green - 13\n"
        "Black Brown - 14\n"
        "Black Slate - 15\n"
        "Yellow Blue - 16\n"
        "Yellow Orange - 17\n"
        "Yellow Green - 18\n"
        "Yellow Brown - 19\n"
        "Yellow Slate - 20\n"
        "Violet Blue - 21\n"
        "Violet Orange - 22\n"
        "Violet Green - 23\n"
        "Violet Brown - 24\n"
        "Violet Slate - 25\n";

    std::cout << "Reference Manual:\n" << referenceManual << std::endl;
    assert(referenceManual == expectedManual);
}
