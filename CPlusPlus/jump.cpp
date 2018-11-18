bool jump(vector<int> v) {
    // NUll vector case
    if (v.size() == 0) return true;

    // Single element vector case    
    if (v.size() == 1 && v[0] != 1) return false;

    for (int i = 0; i < v.size(); i++) {
        int pos = i + v[i];
        if (pos == v.size() - 1) 
	    return true;        
    }
    return false;
}
