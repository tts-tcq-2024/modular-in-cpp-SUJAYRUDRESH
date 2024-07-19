#ifndef TELECOM_WIRE_COLOR_PAIR_HPP
#define TELECOM_WIRE_COLOR_PAIR_HPP

#include <string>

namespace TelecomColorCoding 
{
    enum class MajorWireColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum class MinorWireColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    class WireColorPair {
        private:
            MajorWireColor majorWireColor;
            MinorWireColor minorWireColor;
        public:
            WireColorPair(MajorWireColor major, MinorWireColor minor);
            MajorWireColor getMajorWireColor() const;
            MinorWireColor getMinorWireColor() const;
            std::string toString() const;
    };

    WireColorPair getWireColorPairFromNumber(int wirePairNumber);
    int getNumberFromWireColorPair(MajorWireColor major, MinorWireColor minor);
    std::string formatColorCodingReferenceManual();
}

#endif // TELECOM_WIRE_COLOR_PAIR_HPP
