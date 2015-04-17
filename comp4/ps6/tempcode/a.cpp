 " 
    x = input.substr(pos,kk);
    findAmount(x);
    x.append(input.substr(0,1)); //K+1
    findAmount(x);
    pos = 0;
    j = 1;
    
    for (i = input.size()-k; i< szofinpt; i++) {
      kk--;
      x = input.substr(i,kk);
      x.append(input.substr(pos,j));
      pos++; j++;
      findAmount(x);
      
      x.append(input.substr(pos,1));
      findAmount(x);//K+!	
    }"
