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
            static const char* majorWireColorNames[];
            static const char* minorWireColorNames[];

        public:
            WireColorPair(MajorWireColor major, MinorWireColor minor);
            MajorWireColor getMajorWireColor() const;
            MinorWireColor getMinorWireColor() const;
            std::string toString() const;

            static WireColorPair getWireColorPairFromNumber(int wirePairNumber);
            static int getNumberFromWireColorPair(MajorWireColor major, MinorWireColor minor);
            static std::string formatColorPair(const WireColorPair& colorPair);
            static std::string formatColorPairsForMajorColor(MajorWireColor majorWireColor);
            static std::string formatColorCodingReferenceManual();

            static int getNumberOfMajorWireColors();
            static int getNumberOfMinorWireColors();
    };

}

#endif // TELECOM_WIRE_COLOR_PAIR_HPP
