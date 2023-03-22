bool check(int para){
    // do something
    return true;
}

void BinarySearch1(int l, int r){
    // template 1
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
}
void BinarySearch2(int l, int r){
    // template 2
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
}