#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int* array;     
    size_t size;   
    size_t capacity; 
} DynamicArray;

void initDynamicArray(DynamicArray* dArray, size_t initialCapacity) {
    dArray->array = (int*)malloc(initialCapacity * sizeof(int));
    if (dArray->array == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    dArray->size = 0;
    dArray->capacity = initialCapacity;
}


void resizeDynamicArray(DynamicArray* dArray) {
    dArray->capacity *= 2;
    int* newArray = (int*)realloc(dArray->array, dArray->capacity * sizeof(int));
    if (newArray == NULL) {
        printf("Error when increasing array size!\n");
        free(dArray->array);
        exit(1);
    }
    dArray->array = newArray;
}

void addElement(DynamicArray* dArray, int value) {
    if (dArray->size == dArray->capacity) {
        resizeDynamicArray(dArray); 
    }
    dArray->array[dArray->size] = value;
    dArray->size++;
}


void removeLastElement(DynamicArray* dArray) {
    if (dArray->size == 0) {
        printf("The array is empty! Unable to delete element.\n");
        return;
    }
    dArray->size--;
}

int getElement(DynamicArray* dArray, size_t index) {
    if (index >= dArray->size) {
        printf("Error: index is out of array!\n");
        exit(1);
    }
    return dArray->array[index];
}


void setElement(DynamicArray* dArray, size_t index, int value) {
    if (index >= dArray->size) {
        printf("Error: index is out of array!\n");
        exit(1);
    }
    dArray->array[index] = value;
}


void printDynamicArray(DynamicArray* dArray) {
    if (dArray->size == 0) {
        printf("array is empty.\n");
        return;
    }
    for (size_t i = 0; i < dArray->size; i++) {
        printf("%d ", dArray->array[i]);
    }
    printf("\n");
}


void freeDynamicArray(DynamicArray* dArray) {
    free(dArray->array);
    dArray->array = NULL;
    dArray->size = 0;
    dArray->capacity = 0;
}


int findElement(DynamicArray* dArray, int value) {
    for (size_t i = 0; i < dArray->size; i++) {
        if (dArray->array[i] == value) {
            return i; 
        }
    }
    return -1; 
}


void clearArray(DynamicArray* dArray) {
    dArray->size = 0; 
}


size_t getSize(DynamicArray* dArray) {
    return dArray->size;
}


size_t getCapacity(DynamicArray* dArray) {
    return dArray->capacity;
}


void demoDynamicArray() {
    DynamicArray dArray;
    initDynamicArray(&dArray, INITIAL_CAPACITY);

    printf("Adding elements to an array:\n");
    addElement(&dArray, 10);
    addElement(&dArray, 20);
    addElement(&dArray, 30);
    addElement(&dArray, 40);
    addElement(&dArray, 50);

    printDynamicArray(&dArray);  

    printf("\nRemoving the last element of the array:\n");
    removeLastElement(&dArray);
    printDynamicArray(&dArray);

    printf("\nGetting element by index:\n");
    int value = getElement(&dArray, 2);
    printf("Index element with 2: %d\n", value);

    printf("\nreplacing an element in an array:\n");
    setElement(&dArray, 2, 100);
    printDynamicArray(&dArray);
    printf("\nSearching for elements in an array:\n");
    int index = findElement(&dArray, 20);
    if (index != -1) {
        printf("Element 20 found at index %d\n", index);
    }
    else {
        printf("Element 20 not found at index\n");
    }

    printf("\nArray size and capacity:\n");
    printf("Array size: %zu\n", getSize(&dArray));
    printf("Array capacity: %zu\n", getCapacity(&dArray));

    printf("\nArray clearing:\n");
    clearArray(&dArray);
    printDynamicArray(&dArray);

}

int main() {
    demoDynamicArray();
    return 0;
}