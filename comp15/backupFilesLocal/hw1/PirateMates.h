/*
 * PirateMates.h
 * COMP15
 * Spring 2018
 *
 * Struct for holding a pirates mates
 */

#include "Pirate.h"
#include "ArrayList.h"

#ifndef PIRATEM_H_
#define PIRATEM_H_


struct PirateMates {
    Pirate pirate;
    ArrayList mates;
};

#endif