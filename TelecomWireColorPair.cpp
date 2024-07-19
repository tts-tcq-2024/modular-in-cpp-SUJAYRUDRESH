#include "TelecomWireColorPair.hpp"
#include <iostream>

namespace TelecomColorCoding 
{
    const char* majorWireColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};

    const char* minorWireColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    WireColorPair::WireColorPair(MajorWireColor major, MinorWireColor minor):
        majorWireColor(major), minorWireColor(minor)
    {}

    MajorWireColor WireColorPair::getMajorWireColor() const {
        return majorWireColor;
    }

    MinorWireColor WireColorPair::getMinorWireColor() const {
        return minorWireColor;
    }

    std::string WireColorPair::toString() const {
        std::string colorPairStr = majorWireColorNames[static_cast<int>(majorWireColor)];
        colorPairStr += " ";
        colorPairStr += minorWireColorNames[static_cast<int>(minorWireColor)];
        return colorPairStr;
    }

    WireColorPair getWireColorPairFromNumber(int wirePairNumber) {
        int zeroBasedPairNumber = wirePairNumber - 1;
        MajorWireColor majorWireColor = 
            static_cast<MajorWireColor>(zeroBasedPairNumber / (sizeof(minorWireColorNames) / sizeof(minorWireColorNames[0])));
        MinorWireColor minorWireColor =
            static_cast<MinorWireColor>(zeroBasedPairNumber % (sizeof(minorWireColorNames) / sizeof(minorWireColorNames[0])));
        return WireColorPair(majorWireColor, minorWireColor);
    }

    int getNumberFromWireColorPair(MajorWireColor major, MinorWireColor minor) {
        return static_cast<int>(major) * (sizeof(minorWireColorNames) / sizeof(minorWireColorNames[0])) + static_cast<int>(minor) + 1;
    }
}
