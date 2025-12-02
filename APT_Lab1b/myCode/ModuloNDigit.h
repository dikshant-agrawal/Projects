/**
 * @file ModuloNDigit.h
 * @brief Declaration of a single-digit modulo-N counter.
 *
 * This class implements a single digit counter that wraps around
 * automatically when its maximum value (modulo base) is reached.
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

class ModuloNDigit {

private:
    int maxCount;       ///< Maximum count (modulo base)
    int currentCount;   ///< Current counter value

public:

    /**
     * @brief Default constructor.
     *
     * Initializes the counter with modulo-10 and current count = 0.
     * Required for array allocation and general safe construction.
     */
    ModuloNDigit();

    /**
     * @brief Constructor with modulo base.
     * @param n The modulo value (maximum count before wrap).
     */
    ModuloNDigit(int n);

    /**
     * @brief Destructor. No dynamic memory is used.
     */
    virtual ~ModuloNDigit();

    /**
     * @brief Prefix increment operator (++x).
     *
     * Increments the counter and wraps around using modulo.
     *
     * @return Reference to this updated object.
     */
    ModuloNDigit& operator++();

    /**
     * @brief Postfix increment operator (x++).
     *
     * Returns the object before increment.
     *
     * @param n Dummy parameter to differentiate postfix from prefix.
     * @return Copy of object before increment.
     */
    ModuloNDigit operator++(int n);

    /**
     * @brief Retrieve the current counter value.
     * @return The current value of the counter.
     */
    int getValue() const;

    /**
     * @brief Reset the counter value to zero.
     */
    void resetCounter();
};

#endif /* MODULONDIGIT_H_ */
