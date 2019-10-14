#include "storelist.h"
#define FNAME "storedata"

void displayMenu()
{
    puts("");
    puts("***HudsonMart Store Interface***");
    puts("============================================================");
    puts("1: Add product		2: Purchase product");
    puts("3: Check product price	4: List products");
    puts("5: Remove product	6: Find product");
    puts("7: List total inventory	8: Quit");
    puts("============================================================");
}
   
void scanName(char address[])
	{
	fflush(stdin);
        printf("Product Name: ");
        fflush(stdin);
        scanf("%s", address);
	}
void scanQuantity(float* address)
	{
	fflush(stdin);	
    	printf("Input product quantity: ");
    	fflush(stdin);
	scanf("%f", address);
	}

// main function to test the list operations
int main(int argc, char *argv[])
{
	float profit = 0;
    	product* head = NULL;
	product* node = NULL;
    	char scan1[STRMAX];
	float* scan2 = malloc(sizeof(float));
	int choice, done = 0;
 	
    	system("clear");
	head = load(head, FNAME);

    while (!done) {
        displayMenu();
        puts("What do you want to do?");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
            case 1:
		scanName(scan1);
		scanQuantity(scan2);

		node = makeNode(head, scan1, *scan2);
		if (node != NULL)
			if (head != NULL)
				head = append(head, node);
			else
				head = node;

                break;
            case 2:
                scanName(scan1);
		scanQuantity(scan2);
		node = find(head, scan1);
		if (node == NULL)
			printf("No product found.");
		else
			{
			float current_value = node->quantity_value;
			float subtract = *scan2;
			if (current_value >= subtract)
				node->quantity_value -= subtract;
			else
				subtract = current_value;

			profit += (node->price_value * subtract);
			
			if (subtract == current_value)
				deleteNode(&head, node->name);
			}
		
                break;
            case 3:
                scanName(scan1);
		node = find(head, scan1);
		if (node == NULL)
			printf("No product found.");
		else
			printf("Price: %f %s",node->price_value,node->price_unit);
                break;
            case 4:
		displayList(head);
		break;
            case 5:
                scanName(scan1);
		node = find(head, scan1);
		if (node == NULL)
			printf("No product found.");
		else
			deleteNode(&head, scan1);
                break;
            case 6:
		scanName(scan1);
                node = find(head, scan1);
		if (node == NULL)
			printf("No product found.");
		else
			displayNode(node);
                break;
            case 7:
                printf("\nTotal Profit: %f",profit);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		displayList(head);
                break;
            case 8:
                puts("Have a nice day.");
		save(head, FNAME);
                done = 1;
                break;
            default:
                puts("Wrong code. Please try again.");
                break;
        }
    }

    destroy(&head);
    return 0;
}

