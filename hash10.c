#define MAX_KEY 1000000

typedef struct {
    bool* set;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    obj->set = (bool*)calloc(MAX_KEY + 1, sizeof(bool));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->set[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->set[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->set[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->set);
    free(obj);
}