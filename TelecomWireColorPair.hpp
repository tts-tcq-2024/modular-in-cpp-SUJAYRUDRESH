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
            static int getNumberOfMajorWireColors();
            static int getNumberOfMinorWireColors();
            static std::string formatColorPair(const WireColorPair& colorPair);
            static std::string formatColorPairsForMajorColor(MajorWireColor majorWireColor);
            WireColorPair(MajorWireColor major, MinorWireColor minor);
            

        public:
            std::string toString() const;
            MajorWireColor getMajorWireColor() const;
            MinorWireColor getMinorWireColor() const;
            static WireColorPair getWireColorPairFromNumber(int wirePairNumber);
            static int getNumberFromWireColorPair(MajorWireColor major, MinorWireColor minor);
            static std::string formatColorCodingReferenceManual();

    };

}

#endif // TELECOM_WIRE_COLOR_PAIR_HPP
