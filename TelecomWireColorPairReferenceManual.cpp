#include "TelecomWireColorPair.hpp"
#include <iostream>

namespace TelecomColorCoding 
{
    std::string formatColorPair(const WireColorPair& colorPair) {
        return colorPair.toString() + " - " + std::to_string(getNumberFromWireColorPair(colorPair.getMajorWireColor(), colorPair.getMinorWireColor())) + "\n";
    }

    std::string formatColorPairsForMajorColor(MajorWireColor majorWireColor) {
        std::string formattedPairs;
        for (int minor = 0; minor < (sizeof(minorWireColorNames) / sizeof(minorWireColorNames[0])); ++minor) {
            WireColorPair colorPair = getWireColorPairFromNumber(static_cast<int>(majorWireColor) * (sizeof(minorWireColorNames) / sizeof(minorWireColorNames[0])) + minor + 1);
            formattedPairs += formatColorPair(colorPair);
        }
        return formattedPairs;
    }

    std::string formatColorCodingReferenceManual() {
        std::string referenceManual;
        for (int major = 0; major < (sizeof(majorWireColorNames) / sizeof(majorWireColorNames[0])); ++major) {
            referenceManual += formatColorPairsForMajorColor(static_cast<MajorWireColor>(major));
        }
        return referenceManual;
    }
}
