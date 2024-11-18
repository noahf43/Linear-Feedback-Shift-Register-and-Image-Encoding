# Linear Feedback Shift Register (LFSR) Simulator and Image Encryptor

## Overview
This project simulates a Linear Feedback Shift Register (LFSR) to produce pseudo-random bits. It uses the `FibLFSR` class to perform single or multiple LFSR steps and provides functionality to encrypt and decrypt images using bit manipulation.

## Features
- **LFSR Simulation:** Generate pseudo-random bits using a seed and configurable tap positions.
- **Image Encryption:** Encrypt and decrypt images by XORing pixel values with generated pseudo-random bits.
- **Reversible Transformation:** Encrypted images can be restored using the same seed.

## How It Works
1. **LFSR Functionality:** 
   - A vector is used to store the LFSR seed bit by bit.
   - The leftmost bit is XORed with a tap bit, and the result is shifted into the rightmost bit.
2. **Image Encryption:**
   - The `transform` function iterates over all pixels in an image.
   - Pixel values (R, G, B) are XORed with newly generated 8-bit integers.
   - Decryption is performed by repeating the encryption process with the same seed.
3. **Efficiency:** The vector structure simplifies bit manipulation and swapping.

## For questions or feedback, contact:
Noah Fay
Email: noahfay43@gmail.com@gmail.com
