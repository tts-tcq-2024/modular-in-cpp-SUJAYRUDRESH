#include "TelecomWireColorPair.hpp"
#include <iostream>

namespace TelecomColorCoding 
{
    const char* majorWireColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorWireColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    const int WireColorPair::numberOfMajorWireColors = sizeof(WireColorPair::majorWireColorNames) / sizeof(WireColorPair::majorWireColorNames[0]);
    const int WireColorPair::numberOfMinorWireColors = sizeof(WireColorPair::minorWireColorNames) / sizeof(WireColorPair::minorWireColorNames[0]);

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

    WireColorPair WireColorPair::getWireColorPairFromNumber(int wirePairNumber) {
        int zeroBasedPairNumber = wirePairNumber - 1;
        MajorWireColor majorWireColor = 
            static_cast<MajorWireColor>(zeroBasedPairNumber / numberOfMinorWireColors);
        MinorWireColor minorWireColor =
            static_cast<MinorWireColor>(zeroBasedPairNumber % numberOfMinorWireColors);
        return WireColorPair(majorWireColor, minorWireColor);
    }

    int WireColorPair::getNumberFromWireColorPair(MajorWireColor major, MinorWireColor minor) {
        return static_cast<int>(major) * numberOfMinorWireColors + static_cast<int>(minor) + 1;
    }
}
