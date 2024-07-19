#include "TelecomWireColorPair.hpp"
#include <string>

namespace TelecomColorCoding 
{
    std::string WireColorPair::formatColorPair(const WireColorPair& colorPair) {
        return colorPair.toString() + " - " + std::to_string(getNumberFromWireColorPair(colorPair.getMajorWireColor(), colorPair.getMinorWireColor())) + "\n";
    }

    std::string WireColorPair::formatColorPairsForMajorColor(MajorWireColor majorWireColor) {
        std::string formattedPairs;
        for (int minor = 0; minor < numberOfMinorWireColors; ++minor) {
            WireColorPair colorPair = getWireColorPairFromNumber(static_cast<int>(majorWireColor) * numberOfMinorWireColors + minor + 1);
            formattedPairs += formatColorPair(colorPair);
        }
        return formattedPairs;
    }

    std::string WireColorPair::formatColorCodingReferenceManual() {
        std::string referenceManual;
        for (int major = 0; major < sizeof(majorWireColorNames) / sizeof(majorWireColorNames[0]); ++major) {
            referenceManual += formatColorPairsForMajorColor(static_cast<MajorWireColor>(major));
        }
        return referenceManual;
    }
}
