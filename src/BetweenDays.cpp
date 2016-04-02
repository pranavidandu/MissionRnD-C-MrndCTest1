/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int check_leap_year(int year){
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
	{
			return 0;
	}
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
}
struct node * set_index_year(struct node *date1head, int *index){
	struct node* ptr = date1head;
	while (ptr){
		if (*index == 4)
			break;
		else{
			ptr = ptr->next;
			*index = *index + 1;
		}
	}
	return ptr;
}
int check_year(struct node *date1head, struct node *date2head){
	struct node* ptr = date1head;
	int year1 = 0, year2 = 0;
	int index = 0;
	ptr = set_index_year(date1head, &index);
	while (ptr != NULL){
		year1 = year1 * 10 + ptr->data;
		ptr = ptr->next;
	}
	index = 0;
	ptr = date2head;
	ptr = set_index_year(date2head, &index);
	while (ptr != NULL){
		year2 = year2 * 10 + ptr->data;
		ptr = ptr->next;
	}
	//Function to check leap year
	/*int leap = check_leap_year(year1);
	if (leap == 0)
		return -1;
	leap = check_leap_year(year2);
	if (leap == 0)
		return -1;
	*/
	if (year1 < year2)
		return (year2 - year1) * 365;
	else if (year1 > year2)
		return (year1 - year2) * 365;
	else if (year1 == year2)
		return 0;
	return -1;

}
struct node * set_index_month(struct node *date1head, int *index){
	struct node* ptr = date1head;
	while (ptr){
		if (*index == 2)
			break;
		else{
			ptr = ptr->next;
			*index = *index + 1;
		}
	}
	return ptr;
}
int check_month(struct node *date1head, struct node *date2head){
	struct node* ptr = date1head;
	int index = 0;
	ptr = set_index_month(date1head, &index);
	int mon1 = 0, mon2 = 0;
	while (index < 4){
		mon1 = mon1 * 10 + ptr->data;
		ptr = ptr->next;
		index++;
	}
	index = 0;
	ptr = date2head;
	ptr = set_index_month(date2head, &index);
	while (index < 4){
		mon2 = mon2 * 10 + ptr -> data;
		ptr = ptr->next;
		index++;
	}
	if (mon1 < 0 || mon1 > 12 || mon2 < 0 || mon2 > 12)
		return -1;
	printf("mon1 %d mon2 %d\n", mon1, mon2);
	if (mon1 < mon2)
		return 1;
	else if (mon1 > mon2)
		return 2;
	else if (mon1 == mon2)
		return 0;
	return -1;
}
int check_date(struct node *date1head, struct node *date2head){
	int date1 = 0, date2 = 0;
	struct node* ptr = date1head;
	int index = 0;
	while (index < 2){
		date1 = date1 * 10 + ptr ->data;
		ptr = ptr->next;
		index++;
	}
	index = 0;
	ptr = date2head;
	while (index < 2){
		date2 = date2 * 10 + ptr->data;
		ptr = ptr->next;
		index++;
	}
	printf("date1 %d date2 %d\n", date1, date2);
	if (date1 < date2)
		return date2 - date1 - 1;
	else if (date1 > date2)
		return date1 - date2 - 1;
	else if (date1 == date2)
		return 0;
	return -1;
}
int between_days(struct node *date1head, struct node *date2head){
	printf("im in main function\n");
	if (date1head == NULL || date2head == NULL)
	return -1;
	int year = check_year(date1head, date2head);
	if (year == 0)//year1 > year
	{
		printf("im in if\n");
		int mon = check_month(date1head, date2head);
		printf("mon %d\n", mon);
		if (mon == -1)
			return -1;
		if (mon == 0){
			int date = check_date(date1head, date2head);
			printf("im here\n");
			return date;
		}
	}
}