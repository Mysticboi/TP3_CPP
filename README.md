# TP3_CPP

A C++ school project to practice coding in C++ the old way. When starting the app it prompts you with different options to use and you can type in your input.

Only available in `French`.

## Functionalities

- Adding a simple route including a start city, an end city and the means of transport (train-car-boat-plane...)
- Adding a composed route including multiple simple routes.
- All added routes make a Catalog
- Print the Catalog
- Simple search: input a start city and an end city to get all possible direct paths.
- Advanced search: input a start city and an end city to get all possible paths using DFS
- Saving the Catalog into a `.txt` file
  - Saving all routes
  - Saving only simple or composed routes
  - Saving routes that start in a specified city
  - Saving routes that end in a specified city
- Loading a Catalog from a `.txt` file
- Save your changes to be continued later

More explanation available in: `Compte-Rendu.pdf`

## Rules

Some rules are set for the project be considered as coding in C++ the old way:

- Not allowed to use the std library (vector,map...) use own implementation of LinkedList `ListeChainee.h/cpp`.
- Not allowed to use `string` use `char *` instead and the `<cstring>` library.
- All instanciated classes and their class attributes use pointers.
- Allowed to use the `<iostream>` library for `cin` and `cout`
- Since we're using pointers everywhere, the app need to delocate everything ! This is checked using `valgrind`

## Starting the project

You need to install `g++` and `make` utilities for this project to work.

- First compile the project: `make` , you'll get an executable file `exe`
- You can now run the project: `./exe`

## Cleaning up the compiled classes and executable

You can run `make clean` to clean up all the compiled `.o` classes and the `exe` executable file.
