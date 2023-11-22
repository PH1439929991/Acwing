while(1){
        next_permutation(v0.begin(),v0.end());
        if(is(v,v0)){
            for(int i = 0 ;i < v0.size() ;i++){
                cout << v0[i] << " ";
            }
            break;
        }
    }
    return 0;