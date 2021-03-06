/*******************************************************************************
 * Begin of file BitOperations_UnitTest.h
 * Author: jdebruijn
 * Created on December 24, 2015, 6:24 PM
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 *
 * Copyright (c) 2015  Jeroen de Bruijn  <vidavidorra@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Unit test for the BitOperations project.
 *
 * The purpose of this unit test is not to verify that the arithmetic is
 * correct, because Sean Eron Anderson already tested that thoroughly.
 * This unit test verifies that the implementation is correct.
 *
 * @note
 * The INT32_MIN and INT32_MAX that are used for the tests are originated in
 * stdint.h and they have the values -2147483648 and 2147483647, respectively.
 *
 ******************************************************************************/

#ifndef BITOPERATIONS_UNITTEST_H_
#define BITOPERATIONS_UNITTEST_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Global variables
 ******************************************************************************/
/** @brief Correct bit mask for 1 to 64 bits. */
const uint64_t correctBitMasksUpTo64Bit[] = {
    0b0000000000000000000000000000000000000000000000000000000000000001,
    0b0000000000000000000000000000000000000000000000000000000000000010,
    0b0000000000000000000000000000000000000000000000000000000000000100,
    0b0000000000000000000000000000000000000000000000000000000000001000,
    0b0000000000000000000000000000000000000000000000000000000000010000,
    0b0000000000000000000000000000000000000000000000000000000000100000,
    0b0000000000000000000000000000000000000000000000000000000001000000,
    0b0000000000000000000000000000000000000000000000000000000010000000,
    0b0000000000000000000000000000000000000000000000000000000100000000,
    0b0000000000000000000000000000000000000000000000000000001000000000,
    0b0000000000000000000000000000000000000000000000000000010000000000,
    0b0000000000000000000000000000000000000000000000000000100000000000,
    0b0000000000000000000000000000000000000000000000000001000000000000,
    0b0000000000000000000000000000000000000000000000000010000000000000,
    0b0000000000000000000000000000000000000000000000000100000000000000,
    0b0000000000000000000000000000000000000000000000001000000000000000,
    0b0000000000000000000000000000000000000000000000010000000000000000,
    0b0000000000000000000000000000000000000000000000100000000000000000,
    0b0000000000000000000000000000000000000000000001000000000000000000,
    0b0000000000000000000000000000000000000000000010000000000000000000,
    0b0000000000000000000000000000000000000000000100000000000000000000,
    0b0000000000000000000000000000000000000000001000000000000000000000,
    0b0000000000000000000000000000000000000000010000000000000000000000,
    0b0000000000000000000000000000000000000000100000000000000000000000,
    0b0000000000000000000000000000000000000001000000000000000000000000,
    0b0000000000000000000000000000000000000010000000000000000000000000,
    0b0000000000000000000000000000000000000100000000000000000000000000,
    0b0000000000000000000000000000000000001000000000000000000000000000,
    0b0000000000000000000000000000000000010000000000000000000000000000,
    0b0000000000000000000000000000000000100000000000000000000000000000,
    0b0000000000000000000000000000000001000000000000000000000000000000,
    0b0000000000000000000000000000000010000000000000000000000000000000,
    0b0000000000000000000000000000000100000000000000000000000000000000,
    0b0000000000000000000000000000001000000000000000000000000000000000,
    0b0000000000000000000000000000010000000000000000000000000000000000,
    0b0000000000000000000000000000100000000000000000000000000000000000,
    0b0000000000000000000000000001000000000000000000000000000000000000,
    0b0000000000000000000000000010000000000000000000000000000000000000,
    0b0000000000000000000000000100000000000000000000000000000000000000,
    0b0000000000000000000000001000000000000000000000000000000000000000,
    0b0000000000000000000000010000000000000000000000000000000000000000,
    0b0000000000000000000000100000000000000000000000000000000000000000,
    0b0000000000000000000001000000000000000000000000000000000000000000,
    0b0000000000000000000010000000000000000000000000000000000000000000,
    0b0000000000000000000100000000000000000000000000000000000000000000,
    0b0000000000000000001000000000000000000000000000000000000000000000,
    0b0000000000000000010000000000000000000000000000000000000000000000,
    0b0000000000000000100000000000000000000000000000000000000000000000,
    0b0000000000000001000000000000000000000000000000000000000000000000,
    0b0000000000000010000000000000000000000000000000000000000000000000,
    0b0000000000000100000000000000000000000000000000000000000000000000,
    0b0000000000001000000000000000000000000000000000000000000000000000,
    0b0000000000010000000000000000000000000000000000000000000000000000,
    0b0000000000100000000000000000000000000000000000000000000000000000,
    0b0000000001000000000000000000000000000000000000000000000000000000,
    0b0000000010000000000000000000000000000000000000000000000000000000,
    0b0000000100000000000000000000000000000000000000000000000000000000,
    0b0000001000000000000000000000000000000000000000000000000000000000,
    0b0000010000000000000000000000000000000000000000000000000000000000,
    0b0000100000000000000000000000000000000000000000000000000000000000,
    0b0001000000000000000000000000000000000000000000000000000000000000,
    0b0010000000000000000000000000000000000000000000000000000000000000,
    0b0100000000000000000000000000000000000000000000000000000000000000,
    0b1000000000000000000000000000000000000000000000000000000000000000
};

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** Flag for printing debug messages. */
#define FDEBUG 1

/** Flag for printing debug expected and got messages on success for each
 * assertion using @ref GREATEST_ASSERT_EQ.
 * */
#define FDEBUG_EXP_AND_GOT 0

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/** @brief Print formatted debugging message. */
#define DEBUG_PRINTF(fmt, args...)if(FDEBUG) printf(fmt "\n", ##args)

/** @brief Print an unsigned number with zero padding @ref putBits. This also
 * prints a prefix message.
 */
#define DEBUG_PUTBITS(v, n, msg, args...)                                      \
    do {                                                                       \
        if(FDEBUG || FDEBUG_EXP_AND_GOT) {                                     \
            printf(msg, ##args);                                               \
            putBits((v), (n));                                                 \
            printf("\n");                                                      \
        }                                                                      \
    } while (0)

/** @brief Print a 64-bit unsigned number with "  Expected: " as prefix message.
 */
#define DEBUG_PUTBITS64_EXP(v)                                                 \
    DEBUG_PUTBITS(v, 64, "  Expected: ")

/** @brief Print a 64-bit unsigned number with "  Got     : " as prefix message.
 */
#define DEBUG_PUTBITS64_GOT(v)                                                 \
    DEBUG_PUTBITS(v, 64, "  Got     : ")

/** @brief Print a 64-bit unsigned number with "  Expected and got: " as prefix
 * message.
 */
#define DEBUG_PUTBITS64_EXP_AND_GOT(v)                                         \
    DEBUG_PUTBITS(v, 64, "  Expected and got: ")

#undef GREATEST_ASSERT_EQm
/** @brief Overwrite of the greatest GREATEST_ASSERT_EQm macro.
 *
 * This allows to print the expected and got values after the assertion has
 * succeeded or failed.
 *
 * @note    Description from greatest: "Fail if EXP != GOT (equality comparison
 * by ==).".
 */
#define GREATEST_ASSERT_EQm(MSG, EXP, GOT)                                     \
    do {                                                                       \
        greatest_info.assertions++;                                            \
        if ((EXP) != (GOT)) {                                                  \
            DEBUG_PUTBITS64_EXP(EXP);                                          \
            DEBUG_PUTBITS64_GOT(GOT);                                          \
            GREATEST_FAILm(MSG);                                               \
        } else {                                                               \
            if (FDEBUG_EXP_AND_GOT) {                                          \
                DEBUG_PUTBITS64_EXP_AND_GOT(EXP);                              \
            }                                                                  \
        }                                                                      \
    } while (0)

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief   Generate a 64-bit pseudo random number.
 *
 * @pre     This requires that the rand() is seeded. For example using
 * <code>srand(time(NULL));</code>
 */
uint64_t
rand64();

/**
 * @brief Print an unsigned number with zero padding.
 *
 * Writes an unsigned number with zero padding to the standard stream.
 *
 * @param   _num Number to send.
 * @param   _nBits Number of bits to send.
 */
void
putBits(uint64_t const _num, uint8_t const _nBits);

#ifdef __cplusplus
extern "C" {
#endif

#endif /* BITOPERATIONS_UNITTEST_H_ */
/* End of file BitOperations_UnitTest.c */
