/*
Implement the class ProductOfNumbers that supports two methods:

1. add(int num)

Adds the number num to the back of the current list of numbers.
2. getProduct(int k)

Returns the product of the last k numbers in the current list.
You can assume that always the current list has at least k numbers.
At any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
*/

// (n * n1 * n2) * (n3 * n4 * n5) = PROD
// (n3 * n4 * n5) = PROD / (n * n1 * n2)
#include <stdbool.h>

typedef struct {
    int* numArr;
    int* prodArr;
    int size;
    int capacity;
    int prodArrValidFor; // reset if 0 is added to the array
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* prodOfNumObj = malloc(sizeof (ProductOfNumbers));
    if(prodOfNumObj == NULL) {
        printf("create 1");
        return NULL;
    }
    
    prodOfNumObj->numArr = malloc(10 * sizeof (int));
    if(prodOfNumObj->numArr == NULL) {
        printf("create 2");
        free(prodOfNumObj);
        return NULL;
    }
    
    prodOfNumObj->prodArr = malloc(10 * sizeof (long long));
    if(prodOfNumObj->prodArr == NULL) {
        free(prodOfNumObj);
        printf("create 3");
        return NULL;
    }
    
    printf("create OK");
    prodOfNumObj->size = 0;
    prodOfNumObj->capacity = 10;
    prodOfNumObj->prodArrValidFor = 0;    
    return prodOfNumObj;
    
}

bool doubleStorage(ProductOfNumbers* obj) {
    obj->capacity *= 2;
    return (realloc(obj->numArr, obj->capacity*sizeof(int)) &&
            realloc(obj->prodArr, obj->capacity*sizeof(int)));
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    printf("add %i\n", num);
    printf("obj size %i\n", obj->size);
    printf("obj cap %i\n", obj->capacity);
    
    
    if(obj->size < obj->capacity) {
        printf("add simple");
        if(num > 0){
            printf("add simple: if\n");
            obj->numArr[obj->size] = num; 
            if(obj->prodArrValidFor > 0) {
                printf("%i add - %i * %i", num * obj->prodArr[obj->size -1], num, obj->prodArr[obj->size -1]);
                obj->prodArr[obj->size] = num * obj->prodArr[obj->size -1];
            }
            else {
                obj->prodArr[obj->size] = num;
            }
            printf("add %i to prod arr\n", obj->prodArr[obj->size]);
            obj->size++;
            obj->prodArrValidFor++;
        }
        else {
            printf("add simple: else\n");
            obj->numArr[obj->size] = num;
            obj->prodArr[obj->size] = 0;
            obj->size++;
            obj->prodArrValidFor = 0;
        }
    }
    else {
        printf("add complex\n");
        doubleStorage(obj);
        productOfNumbersAdd(obj, num);
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if(k >= obj->prodArrValidFor) return 0;
    printf("k %i validFor %i\n", k, obj->prodArrValidFor);
    printf("obj->prodArr[obj->size] / obj->prodArr[obj->size - k] : %i / %i\n", obj->prodArr[obj->size - 1], obj->prodArr[obj->size - k - 1]);
    return obj->prodArr[obj->size - 1] / obj->prodArr[obj->size - k - 1];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    printf("free\n");
    free(obj->numArr);
    free(obj->prodArr);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/