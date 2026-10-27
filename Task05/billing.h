#ifndef BILLING_H
#define BILLING_H

#define FIXED_CHARGE_PAISE 5000L
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

long compute_bill(int units);

#endif
