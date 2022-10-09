#include <stdio.h>
#include <stdlib.h>

struct hashTable {
    int key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}
