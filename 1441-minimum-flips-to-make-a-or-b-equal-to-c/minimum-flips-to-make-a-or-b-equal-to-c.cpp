class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;

        int bit_length = sizeof(int) * 8; // Typically 32 bits for an int

        for (int i = 0; i < bit_length; ++i) {
            bool a_bit = a & (1 << i);
            bool b_bit = b & (1 << i);
            bool c_bit = c & (1 << i);

            if (c_bit) {
                // c's bit is 1; at least one of a's or b's bits must be 1
                if (!a_bit && !b_bit) {
                    count++; // Need to flip one bit to 1
                }
            } else {
                // c's bit is 0; both a's and b's bits must be 0
                if (a_bit) count++; // Flip a's bit to 0
                if (b_bit) count++; // Flip b's bit to 0
            }
        }

        return count;
    }
};
