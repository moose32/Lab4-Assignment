//
// Created by cpryan on 2/18/2019.
//
#include <stdio.h>

typedef struct LinkedList{
    int Value;
    struct LinkedList* Next;
}LinkedList;

void printList(LinkedList* list);

int sumList(LinkedList* list);

void removeCell(LinkedList* list, int data);

void testOne();
void testTwo();




void printList(LinkedList* list){
    while(list != NULL){
        if(list->Next != NULL){
            printf("%d->", list->Value);
        }
        else{
            printf("%d\n", list->Value);
        }

        list = list->Next;
    }
}

int sumList(LinkedList* list){
    int sum = 0;
    while(list!= NULL){
        sum += list->Value;
        list = list->Next;
    }
    return sum;
}

void removeCell(LinkedList* list, int data){

    LinkedList* temp=list;
    while(list->Next != NULL){
        if(list->Value != data) {
            temp = list;
            list = list->Next;

        }else{
            break;
        }
    }

    if(list->Value == data && temp != list) {
        temp->Next = list->Next;
        printf("Removed %d\n", data);
    }
    else{
        printf("%d not found\n", data);
    }
}

void testOne(){
    //Create a linked list here that looks like: 1->2->3->4->3->NULL
    //the variable 'first' should be the first cell in the list
    struct LinkedList first, second, third, fourth, fifth;
    first.Value = 1;
    second.Value = 2;
    third.Value = 3;
    fourth.Value = 4;
    fifth.Value = 3;
    first.Next = &second;
    second.Next = &third;
    third.Next = &fourth;
    fourth.Next = &fifth;
    fifth.Next = NULL;

    printList(&first);
    printf("\nSum: %d\n", sumList(&first));
    removeCell(&first, 3);
    printList(&first);
    printf("\nSum: %d\n", sumList(&first));
}

void testTwo() {
    printf("\n");
    LinkedList first;
    LinkedList cell2;

    first.Value = 2;
    first.Next = &cell2;
    cell2.Value = 8;
    cell2.Next = NULL;

    printList(&first);
    printf("\nSum: %d\n", sumList(&first));
    removeCell(&first, 2);
    removeCell(&first, 5);
    removeCell(&first, 8);

    printList(&first);
    printf("\nSum: %d\n", sumList(&first));
}

int main(void){
    testOne();
    testTwo();
}
