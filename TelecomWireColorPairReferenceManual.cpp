#include "TelecomWireColorPair.hpp"
#include <string>

namespace TelecomColorCoding 
{
std::string WireColorPair::formatColorPair(const WireColorPair& colorPair) {
        return colorPair.toString() + " - " + std::to_string(getNumberFromWireColorPair(colorPair.getMajorWireColor(), colorPair.getMinorWireColor())) + "\n";
    }

    std::string WireColorPair::formatColorPairsForMajorColor(MajorWireColor majorWireColor) {
        std::string formattedPairs;
        for (int minor = 0; minor < getNumberOfMinorWireColors(); ++minor) {
            WireColorPair colorPair = getWireColorPairFromNumber(static_cast<int>(majorWireColor) * getNumberOfMinorWireColors() + minor + 1);
            formattedPairs += formatColorPair(colorPair);
        }
        return formattedPairs;
    }

    std::string WireColorPair::formatColorCodingReferenceManual() {
        std::string referenceManual;
        for (int major = 0; major < getNumberOfMajorWireColors(); ++major) {
            referenceManual += formatColorPairsForMajorColor(static_cast<MajorWireColor>(major));
        }
        return referenceManual;
    }
}
