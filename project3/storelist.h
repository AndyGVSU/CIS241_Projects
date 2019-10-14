/* define a structure and functions to implement a linear linked list */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRMAX 20

struct product {
    char name[STRMAX];
    char quantity_unit[STRMAX];
    char price_unit[STRMAX];
    float quantity_value;
    float price_value;
    struct product * next;
};

typedef struct product product;

// make a node and return a pointer to the node
product* makeNode(product* head, char name[], float pvalue);

// display a list
void displayList(product *l);

// display one node
void displayNode(product* l);

// append a node to the tail of a list
// return the updated list
product* append(product* l, product* p);

// save list: save the data to a file
void save(product* l, char fn[]);

// load list: load data from a file, appending to the list l, return it.
product* load(product* l, char fn[]);

//build a node
product* buildNode(char name[], float qvalue, char qunit[], 
				float pvalue, char punit[]);
//count a list
int count(product* l);

//destroy a list
void destroy(product** l);

//found a person with id
product* find (product* l, char name[]);

//delete a node
void deleteNode(product** l, char name[]);
