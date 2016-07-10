#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

// Splay tree implementation
const int MODULO = 1000000001;

// Vertex of a splay tree
struct Vertex {
  int key;
  // Sum of all the keys in the subtree - remember to update
  // it after each operation that changes the tree.
  long long sum;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex(int key, long long sum, Vertex* left, Vertex* right, Vertex* parent) 
  : key(key), sum(sum), left(left), right(right), parent(parent) {}
};

void update(Vertex* v) {
  if (v == NULL) return;
  v->sum = v->key + (v->left != NULL ? v->left->sum : 0ll) + (v->right != NULL ? v->right->sum : 0ll);
  if (v->left != NULL) {
    v->left->parent = v;
  }
  if (v->right != NULL) {
    v->right->parent = v;
  }
}

void small_rotation(Vertex* v) {
  Vertex* parent = v->parent;
  if (parent == NULL) {
    return;
  }
  Vertex* grandparent = v->parent->parent;
  if (parent->left == v) {
    Vertex* m = v->right;
    v->right = parent;
    parent->left = m;
  } else {
    Vertex* m = v->left;
    v->left = parent;
    parent->right = m;
  }
  update(parent);
  update(v);
  v->parent = grandparent;
  if (grandparent != NULL) {
    if (grandparent->left == parent) {
      grandparent->left = v;
    } else {
      grandparent->right = v;
    }
  }
}

void big_rotation(Vertex* v) {
  if (v->parent->left == v && v->parent->parent->left == v->parent) {
    // Zig-zig
    small_rotation(v->parent);
    small_rotation(v);
  } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
    // Zig-zig
    small_rotation(v->parent);
    small_rotation(v);
  } else {
    // Zig-zag
    small_rotation(v);
    small_rotation(v);
  }  
}

// Makes splay of the given vertex and makes
// it the new root.
void splay(Vertex*& root, Vertex* v) {
  if (v == NULL) return;
  while (v->parent != NULL) {
    if (v->parent->parent == NULL) {
      small_rotation(v);
      break;
    }
    big_rotation(v);
  }
  root = v;
}

// Searches for the given key in the tree with the given root
// and calls splay for the deepest visited node after that.
// If found, returns a pointer to the node with the given key.
// Otherwise, returns a pointer to the node with the smallest
// bigger key (next value in the order).
// If the key is bigger than all keys in the tree, 
// returns NULL.
Vertex* find(Vertex*& root, int key) {
  Vertex* v = root;
  Vertex* last = root;
  Vertex* next = NULL;
  while (v != NULL) {
    if (v->key >= key && (next == NULL || v->key < next->key)) {
      next = v;
    }
    last = v;
    if (v->key == key) {
      break;      
    }
    if (v->key < key) {
      v = v->right;
    } else {
      v = v->left;
    }
  }
  splay(root, last);
  return next;
}

void split(Vertex* root, int key, Vertex*& left, Vertex*& right) {
  right = find(root, key);
  if (right == NULL) {
    left = root;
    return;
  }
  splay(root, right);

  left = right->left;
  right->left = NULL;
  if (left != NULL) {
    left->parent = NULL;
  }
  update(left);
  update(right);
}

Vertex* merge(Vertex* left, Vertex* right) {
  if (left == NULL) return right;
  if (right == NULL) return left;
  Vertex* min_right = right;
  while (min_right->left != NULL) {
    min_right = min_right->left;
  }
  splay(right, min_right);
  right->left = left;
  update(right);
  return right;
}

// Code that uses splay tree to solve the problem

Vertex* root = NULL;

void insert(int x) {
  Vertex* left = NULL;
  Vertex* right = NULL;
  Vertex* new_vertex = NULL;  
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Vertex(x, x, NULL, NULL, NULL);
  }
  root = merge(merge(left, new_vertex), right);
  //cout << "+ " << root->sum << endl;
}


void erase(int x) {                   
  // Implement erase yourself
  Vertex * left, * middle, * right;
  split(root, x, left, middle);
  split(middle, x + 1, middle, right);
  root = merge(left, right);
}

bool find(int x) {  
  // Implement find yourself

  Vertex* v = find(root, x);
  if (v == NULL)
    return false;
  if (v->key == x)
    return true;
  return false;
}

long long sum(int from, int to) {
  Vertex* left = NULL;
  Vertex* middle = NULL;
  Vertex* right = NULL;
  if (root==NULL)
    return 0;
  split(root, from, left, middle);
  if (middle == NULL && left == NULL)
    return 0;
  if (middle == NULL)
  {
    root = left;
    return 0;
  }
  split(middle, to + 1, middle, right);
  long long ans = 0;
  // Complete the implementation of sum
  if (middle)
    ans = middle->sum;
//  cout <<  " m = " <<  ans << endl;

  root = merge(merge(left, middle), right);
  return ans;  
}


int test(int n){
  cout << "n = " << n << endl;
  vector<long long> value;
  if (root != NULL)
  {
    delete root;
    root = NULL;
  }
  int last_sum_result = 0;
  for (int i = 0; i <= n; i++) {
    int choice = rand()%4;
    switch (choice) {
      case 0: {
        int x = rand()%MODULO;
        insert((x + last_sum_result) % MODULO);
        value.push_back((x + last_sum_result) % MODULO);
      } break;
      case 1 : {
        int x = rand()%MODULO;
        erase((x + last_sum_result) % MODULO);
        vector<long long>::iterator itr;
        itr = std::find(value.begin(), value.end(), (x + last_sum_result) % MODULO);
        if (itr != value.end())
        {
          value.erase(itr); 
        }
      } break;            
      case 2 : {
        int x = rand()%MODULO;
        bool bf = find((x + last_sum_result) % MODULO); 
        printf(bf ? "Found\n" : "Not found\n");
        vector<long long>::iterator itr;
        itr = std::find(value.begin(), value.end(), (x + last_sum_result) % MODULO);
        if (bf && itr == value.end())
          throw("error in found");
        if (!bf && itr != value.end())
        {
          throw("error in found"); 
        }
        if (itr != value.end())
          printf("Found\n");
        else
          printf("Not found\n");
      } break;
      case 3 : {
        int l, r;
        l = rand()%MODULO;
        r = rand()%MODULO;
        if (l > r)
        {
          int t = l;
          l = r;
          r = t;
        }
        long long lft = (l + last_sum_result) % MODULO;
        long long rgt = (r + last_sum_result) % MODULO;
        if (lft > rgt)
        {
          long long t = rgt;
          rgt = lft;
          lft = t;
        }
        long long res = sum(lft, rgt);
        printf("%lld\n", res);
        last_sum_result = int(res % MODULO);

        vector<long long>::iterator itr;
        long long this_res = 0;
        for (auto& p : value)
        {
          long long v = p % MODULO;
          if (v >= lft && v <= rgt)
              this_res += v;
        }
        this_res = this_res % MODULO;
        printf("%lld\n", this_res);
        if (last_sum_result != this_res)
        {
          for (auto& p: value)
            cout << p << " ";
          cout << endl;
          throw("error \n");
        }

      }
    }
  }
  return 0;
}

int main(){

//  for (int n = 0; n < 100000; n++)
//    test(n);

  int n;
  scanf("%d", &n);
  int last_sum_result = 0;
  for (int i = 0; i < n; i++) {
    char buffer[10];
    scanf("%s", buffer);
    char type = buffer[0];
    switch (type) {
      case '+' : {
        int x;
        scanf("%d", &x);
        insert((x + last_sum_result) % MODULO);
      } break;
      case '-' : {
        int x;
        scanf("%d", &x);
        erase((x + last_sum_result) % MODULO);
      } break;            
      case '?' : {
        int x;
        scanf("%d", &x);
        printf(find((x + last_sum_result) % MODULO) ? "Found\n" : "Not found\n");
      } break;
      case 's' : {
        int l, r;
        scanf("%d %d", &l, &r);
        long long res = sum((l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO);
        printf("%lld\n", res);
        last_sum_result = int(res % MODULO);
      }
    }
  }
  return 0;
}

