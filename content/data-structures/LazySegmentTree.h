/**
 * Author: Ezzeldin
 * Date: 2025-6-14
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things. Use with a bump allocator for better performance.
 * Time: O(\log N). Usage: Node* tr = new Node(v, 0,sz(v));
 * Status: stress-tested a bit
 */
#pragma once

#include "../various/BumpAllocator.h"

const int inf = 1e9;

struct Node {
  Node *l = 0, *r = 0;
  int lo, hi;
  int mx = -inf, mn = inf, sum = 0;
  int la = 1, lb = 0;

  Node(int lo, int hi) : lo(lo), hi(hi) {}

  Node(vector<int> &v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      mx = max(l->mx, r->mx);
      mn = min(l->mn, r->mn);
      sum = l->sum + r->sum;
    } else {
      mx = mn = sum = v[lo];
    }
  }

  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (la != 1 || lb != 0) {
      l->apply(la, lb);
      r->apply(la, lb);
      la = 1;
      lb = 0;
    }
  }

  void apply(int a, int b) {
    int t1 = mx * a + b;
    int t2 = mn * a + b;

    mx = max(t1, t2);
    mn = min(t2, t1);
    sum = sum * a + b * (hi - lo);

    la = la * a;
    lb = lb * a + b;
  }

  void update(int L, int R, int a, int b) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R) {
      apply(a, b);
    } else {
      push();
      l->update(L, R, a, b);
      r->update(L, R, a, b);
      mx = max(l->mx, r->mx);
      mn = min(l->mn, r->mn);
      sum = l->sum + r->sum;
    }
  }

  int query(int L, int R) {
    if (R <= lo || hi <= L)
      return -inf;
    if (L <= lo && hi <= R)
      return mx;
    push();
    return max(l->query(L, R), r->query(L, R));
  }

  void set(int L, int R, int x) { update(L, R, 0, x); }
  void add(int L, int R, int x) { update(L, R, 1, x); }
  void mult(int L, int R, int x) { update(L, R, x, 0); }
};
