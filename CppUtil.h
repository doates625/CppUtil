/**
 * @file CppUtil.h
 * @brief Collection of common useful C++ functions.
 * @author Dan Oates (WPI Class of 2020)
 */

// Floating-Point Operations
float clamp_limit(float val, float val_min, float val_max);
float mod_limit(float val, float val_min, float val_max);
float fadd(float a, float b);
float fsub(float a, float b);
float fmul(float a, float b);
float fdiv(float a, float b);
float fsq(float n);
float mean(float arr[], uint32_t len);
float var(float arr[], float mean, uint32_t len);
float std(float arr[], float mean, uint32_t len);

// Integer Operations
int min(int a, int b);
int max(int a, int b);