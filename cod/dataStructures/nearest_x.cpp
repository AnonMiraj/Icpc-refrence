// Find the element nearest to x:

auto it = s.lower_bound(x);
if (it == s.begin()) {
    cout << *it << "\n";
} else if (it == s.end()) {
    it--;
    cout << *it << "\n";
} else {
    int a = *it; it--;
    int b = *it;
    if (x-b < a-x) cout << b << "\n";
    else cout << a << "\n";
}

/*
  <----- lower_bound and upper_bound ------>
lower_bound(x) : returns an iterator to the smallest element in the set whose value is at least x

upper_bound(x) : returns an iterator to the smallest element in the set whose value is larger than x

In both functions, if such an element does not exist, the return value is end. 

These functions are not supported by the unordered_set structure which does not maintain the order of the elements.
*/
