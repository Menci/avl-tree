#include "avl-tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef size_t *ufs_t;

ufs_t ufs_create(int n) {
    ufs_t ufs = malloc(sizeof(size_t) * n);
    for (int i = 0; i < n; i++) ufs[i] = i;
    return ufs;
}

void ufs_destroy(ufs_t ufs) {
    free(ufs);
}

size_t ufs_find(ufs_t ufs, size_t x) {
    return ufs[x] == x ? x : ufs[x] = ufs_find(ufs, ufs[x]);
}

void ufs_merge(ufs_t ufs, size_t x, size_t y) {
    ufs[ufs_find(ufs, x)] = ufs_find(ufs, y);
}

bool ufs_check(ufs_t ufs, size_t x, size_t y) {
    return ufs_find(ufs, x) == ufs_find(ufs, y);
}

#define data_type_from_int(x) ((void *)(long)(x))
#define data_type_to_int(x)   ((int)(long)(x))

int compare(void *a, void *b) {
    return data_type_to_int(a) - data_type_to_int(b);
}

int main() {
    int n, m;
    assert(scanf("%d %d", &n, &m) == 2);

    ufs_t ufs = ufs_create(n);
    avl_teee_t tree = avl_create(compare, NULL);

    while (m--) {
        int option;
        assert(scanf("%d", &option) == 1);
        if (option == 0) {
            int x, y;
            assert(scanf("%d %d", &x, &y) == 2);

            avl_node_t nx = avl_find()

            ufs_merge(ufs, x, y);
        }
    }

    avl_destroy(tree);
    ufs_destroy(ufs);
}
