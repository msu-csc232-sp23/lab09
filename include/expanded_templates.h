/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2023
 *
 * @file    expanded_templates.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Class template expansions.
 */

#ifndef MSU_CSC232_EXPANDED_TEMPLATES_H_
#define MSU_CSC232_EXPANDED_TEMPLATES_H_

#include <string>

/* Include class template implementation files as needed */
#include "ArrayList.cpp"
#include "LinkedList.cpp"
#include "Node.cpp"

/* Declare template usage next */
template
class ArrayList<std::string>;

template
class LinkedList<std::string>;

template
class Node<std::string>;

#endif // MSU_CSC232_EXPANDED_TEMPLATES_H_
