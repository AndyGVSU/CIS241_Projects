#include "storelist.h"
#include <string.h>

// create a list and return the pointer to it.

/* product* create()
{
    return makeNode();
}*/

// make a node and return a pointer to the node
// return a NULL pointer if failed.
product* makeNode(product* head, char name[], float pvalue)
{
    	char scan_char[STRMAX], scan_char2[STRMAX];
    	float scan_float, scan_float2;
    
    	product* productExists = find(head, name); 
    	if (productExists != NULL)
    		{
		printf("Product with name exists.");
		productExists->quantity_value += pvalue;
    		return NULL;
		}

    	fflush(stdin);
    	printf("Input product quantity unit: ");
    	scanf("%s", &scan_char);
    	fflush(stdin);
    	printf("Input product price value: ");
    	scanf("%f", &scan_float2);
    	fflush(stdin);
    	printf("Input product price unit: ");
    	scanf("%s", &scan_char2);
    	fflush(stdin);

	productExists = buildNode(name, pvalue, scan_char, scan_float2, scan_char2);
    	productExists->next = NULL;

    	return productExists;
}

// display a list
void displayList(product* l)
{
	//Display all the node on the list l.
	//for each node, diplay first name, last name and id
	while (l != NULL)
	{
		displayNode(l);
		l = l->next;
	}
}

void displayNode(product* l)
	{
	printf("\nProduct Name: %s\nQuantity: %.3f %s \nPrice: %.2f %s \n",
		l->name,l->quantity_value,l->quantity_unit,
		l->price_value,l->price_unit);
	}

// append a node at the end of a list
// return the updated list
product* append(product* l, product* p)
{
	//append a node that this pointed by p to the end of a list named l if 
	//the list is not empty. Otherwise, make this node as the first node
	//of this list.
	//return the upated list.
	product* temp = l;
	if (temp == NULL)
		temp = p;
	else
		{
		while (temp->next != NULL)
			temp = (temp->next);
		temp->next = p;
		}

	return l;
}

/* Save all the data on current list to a file named fn */
void save(product* l, char fn[])
{
    FILE * fout = fopen(fn, "w");
    if(fout == NULL) {
        printf("InSave: File open failed (%s)\n", fn);
        return;
    }
    product* current = l;
    while (current != NULL) {
        fprintf(fout, "%s %f %s %f %s\n", 
                current->name, current->quantity_value, current->quantity_unit,
		current->price_value, current->price_unit);
        current = current->next;
    }
    fclose(fout);
}

/*create a node with first name (fname), last name (lname) and ID, return it*/
product* buildNode(char name[], float qvalue, char qunit[], 
				float pvalue, char punit[])
{
    product* p = (product*) malloc(sizeof(product));
    if(p == NULL) {
        puts("InBuildNode: Memory Allocation Failed!");
        exit(1);
    }
    strcpy(p->name, name);
    strcpy(p->quantity_unit, qunit);
    strcpy(p->price_unit, punit);
    p->price_value = pvalue;
    p->quantity_value = qvalue;

    return p;
}

/*load(): Load data from file fn, append the data to l
 *        and return the resulting list.
 */
product* load(product* head, char fn[])
{
    char name[STRMAX], qunit[STRMAX], punit[STRMAX];
    float pvalue, qvalue;
    int rt;
    FILE * fin = fopen(fn, "r");
    if(fin == NULL) {
        printf("InLoad: File open failed (%s)\n", fn);
        return NULL;
    }

    while (1) {
        rt = fscanf(fin, "%s %f %s %f %s\n", 
			name, &qvalue, qunit, &pvalue, punit);
	if (rt < 5)
            break;

	product* newNode = buildNode(name, qvalue, qunit, pvalue, punit);
        if (head == NULL)
            head = newNode;
        else
            head = append(head, newNode);
    }
    fclose(fin);
    return head;
}

/* destroy a list and release memory to the system */
void destroy (product** l)
{
    if(!(*l))
        return;
    destroy (&((*l)->next));
    free(*l);
    *l = NULL;
}

/* find a person with ID and return it */
product* find (product* l, char name[])
{
	// find a person with the id from the list l and return 
	// a pointer to the found person.
	// if the person not found, return NULL pointer.
	while (l != NULL)
		{
		if (strcmp(l->name,name) == 0)
			return l;
		l = l->next;
		}
	return NULL;
}

/*Delete a node and release memory to system */
void deleteNode(product** l, char name[])
{
    product* current = *l;
    product* previous = current;
    while(current != NULL) {
        if (strcmp((current->name),name) == 0) {
            if(previous == current)  // the first node
                *l = (current->next);
            else // not the first one
                previous->next = current->next;
            
            free (current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
