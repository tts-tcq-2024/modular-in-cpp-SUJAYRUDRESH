#include "TelecomWireColorPair.hpp"

namespace TelecomColorCoding 
{
    const char* WireColorPair::majorWireColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* WireColorPair::minorWireColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

    WireColorPair::WireColorPair(MajorWireColor major, MinorWireColor minor)
        : majorWireColor(major), minorWireColor(minor)
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
            static_cast<MajorWireColor>(zeroBasedPairNumber / getNumberOfMinorWireColors());
        MinorWireColor minorWireColor =
            static_cast<MinorWireColor>(zeroBasedPairNumber % getNumberOfMinorWireColors());
        return WireColorPair(majorWireColor, minorWireColor);
    }

    int WireColorPair::getNumberFromWireColorPair(MajorWireColor major, MinorWireColor minor) {
        return static_cast<int>(major) * getNumberOfMinorWireColors() + static_cast<int>(minor) + 1;
    }


    int WireColorPair::getNumberOfMajorWireColors() {
        return sizeof(majorWireColorNames) / sizeof(majorWireColorNames[0]);
    }

    int WireColorPair::getNumberOfMinorWireColors() {
        return sizeof(minorWireColorNames) / sizeof(minorWireColorNames[0]);
    }
}
