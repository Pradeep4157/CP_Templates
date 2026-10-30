vector<int>lst, nl;
for(int left = n - 1; left >= 0; left--) {
    nl.clear();
    nl.push_back(left);
    for(auto &a : lst) {
        if(arr[a] != arr[left]) {
            nl.push_back(a);
        }
    }
    swap(lst, nl);
}
